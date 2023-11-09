/**
 ******************************************************************************
 * @file           : FLASH_program.c
 * @author         : Diea Abdeltwab
 * @layer          : MCAL
 * @brief          : Version 1 For STM32F411RE Drivers
 * @date           : 27/10/2023
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */

/******************************************************************************/
/************************ LIB Layer *******************************************/
/******************************************************************************/
#include <stdint.h>
#include "ERROR_STATE.h"
#include "BIT_MATH.h"
#include "stm32f429xx.h"
/******************************************************************************/
/************************ MCAL Layer ******************************************/
/******************************************************************************/

/******************************************************************************/
/************************ HAL Layer *******************************************/
/******************************************************************************/

/******************************************************************************/
/************************ SERVIES Layer ***************************************/
/******************************************************************************/
#include "FLASH_interface.h"
#include "FLASH_config.h"
#include "FLASH_private.h"
/******************************************************************************/
/************************ Global **********************************************/
/******************************************************************************/

/*************************************************************************************************************************************/
/********************************************************* Functions implementations *************************************************/
/*************************************************************************************************************************************/
/**
 ******************************************************************************
 * @fn             : MFLASH_voidUnlock
 * @brief          : UnLock Flash
 * @param          : void
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void MFLASH_voidUnlock(void)
{
  if(READ_BIT(FLASH->CR, FLASH_CR_LOCK) != FLASH_FLAG_LOW )
  {
    /* Authorize the FLASH Registers access */
    WRITE_REG(FLASH->KEYR, FLASH_KEY1);
    WRITE_REG(FLASH->KEYR, FLASH_KEY2);

  }
}
/**
 ******************************************************************************
 * @fn             : MFLASH_voidLock
 * @brief          : Lock Flash
 * @param          : void
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void MFLASH_voidLock(void)
{
  /* Set the LOCK Bit to lock the FLASH Registers access */
  FLASH->CR |= FLASH_CR_LOCK;
}
/**
 ******************************************************************************
 * @fn             : MFLASH_u8Erase
 * @brief          : Erase Sector Or Mass Erase
 * @param[in]      : Copy_pEraseInit --> Get Option From from @FLASH_EraseInitTypeDef struct
 * @param[out]     : Local_pu32SectorError --> Sector Error  // NOT ADD YET
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t MFLASH_u8Erase(FLASH_EraseInitTypeDef *Copy_pEraseInit, uint32_t *Local_pu32SectorError)
{
	uint8_t Local_u8ErrorStatus = ERROR_STATE_OK;
	if (Local_u8ErrorStatus == ERROR_STATE_OK)
	{
		/*Initialization of SectorError variable*/
		*Local_pu32SectorError = 0xFFFFFFFFU;
		if (Copy_pEraseInit->TypeErase == FLASH_TYPEERASE_MASSERASE)
		{
			/*Mass erase to be done*/
			voidMassErase((uint8_t) Copy_pEraseInit->VoltageRange, Copy_pEraseInit->Banks);
			/* if the erase operation is completed, disable the MER Bit */
			FLASH->CR &= (~(FLASH_CR_MER_Msk << FLASH_CR_MER_Pos));
		}
		else
		{
			/* Erase by sector by sector to be done*/
			for ( uint32_t Local_u8Index = Copy_pEraseInit->Sector; Local_u8Index < (Copy_pEraseInit->NbSectors + Copy_pEraseInit->Sector); Local_u8Index++)
			{
				voidEraseSector(Local_u8Index, (uint8_t) Copy_pEraseInit->VoltageRange);
				/* If the erase operation is completed, disable the SER and SNB Bits */
				CLEAR_BIT(FLASH->CR, ((FLASH_CR_SER_Msk << FLASH_CR_SER_Pos) | (FLASH_CR_SNB_Msk << FLASH_CR_SNB_Pos)));
			}
		}
	}
	return Local_u8ErrorStatus;
}
/**
 ******************************************************************************
 * @fn             : MFLASH_u8WriteProgram
 * @brief          : Write On Flash
 * @param[in]      : Copy_u32TypeProgram --> Get Option From from @@ref FLASH_TypeProgram
 * @param[in]      : Copy_u32Address --> Set Address
 * @param[in]      : Copy_u64Data --> Set Data
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t MFLASH_u8WriteProgram(uint32_t Copy_u32TypeProgram, uint32_t Copy_u32Address, uint64_t Copy_u64Data)
{
	uint8_t Local_u8ErrorStatus = ERROR_STATE_OK;
	if(Local_u8ErrorStatus == ERROR_STATE_OK)
	{
		if(Copy_u32TypeProgram == FLASH_TYPEPROGRAM_BYTE)
		{
			/*Program byte (8-bit) at a specified address.*/
			voidProgramByte(Copy_u32Address, (uint8_t) Copy_u64Data);
		}
		else if(Copy_u32TypeProgram == FLASH_TYPEPROGRAM_HALFWORD)
		{
			/*Program halfword (16-bit) at a specified address.*/
			voidProgramHalfWord(Copy_u32Address, (uint16_t) Copy_u64Data);
		}
		else if(Copy_u32TypeProgram == FLASH_TYPEPROGRAM_WORD)
		{
			/*Program word (32-bit) at a specified address.*/
			voidProgramWord(Copy_u32Address, (uint32_t) Copy_u64Data);
		}
		else
		{
			/*Program double word (64-bit) at a specified address.*/
			voidProgramDoubleWord(Copy_u32Address, Copy_u64Data);
		}
		/* If the program operation is completed, disable the PG Bit */
		FLASH->CR &= (~(FLASH_CR_PG_Msk << FLASH_CR_PG_Pos));
	}
	return Local_u8ErrorStatus;
}
/**
 ******************************************************************************
 * @fn             : MFLASH_u8WriteProtection
 * @brief          : Sector Write Protection
 * @param[in]      : Copy_u8SectorNumber --> This parameter must be a value of @ref FLASHEx_Sectors
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t MFLASH_u8WriteProtection(uint32_t Copy_u32SectorNumber )
{
	uint8_t Local_u8ErrorStatus = ERROR_STATE_OK;
	if(Local_u8ErrorStatus == ERROR_STATE_OK)
	{
		/* Wait bsy flag */
		while(FLASH_FLAG_LOW != (FLASH->SR & FLASH_SR_BSY));
		if (Copy_u32SectorNumber >= 12 )
		{
			Copy_u32SectorNumber = Copy_u32SectorNumber - 12 ;
			/* Bank 2 */
			FLASH->OPTCR1 &= ~(( FLASH_OPTCR_NWRP_Msk << Copy_u32SectorNumber) << FLASH_OPTCR_NWRP_Pos);

		}
		else
		{
			/* Bank 1 */
			FLASH->OPTCR &= ~(( FLASH_OPTCR_NWRP_Msk << Copy_u32SectorNumber) << FLASH_OPTCR_NWRP_Pos);
		}
		/* Start sector write protection */
		FLASH->OPTCR |= FLASH_OPTCR_OPTSTRT;
		/* Wait bsy flag */
		while(FLASH_FLAG_LOW != (FLASH->SR & FLASH_SR_BSY));
	}
	return Local_u8ErrorStatus;
}
/**
 ******************************************************************************
 * @fn             : MFLASH_u8MaskAllSectorsWriteProtection
 * @brief          : Mask All Sectors Write Protection
 * @param[in]      : Copy_u32SectorsMask --> Set Mask
 * @param[in]      : Copy_u8BankIndex --> Get Option From @ref FLASHEx_Banks
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *     Copy_u32SectorsMask = 0b00000100 ;
 *     Write Protection at Sector 2
 ******************************************************************************
 */
uint8_t MFLASH_u8MaskAllSectorsWriteProtection( uint8_t Copy_u32SectorsMask , uint8_t Copy_u8BankIndex )
{
	uint8_t Local_u8ErrorStatus = ERROR_STATE_OK;
	if(Local_u8ErrorStatus == ERROR_STATE_OK)
	{
		/* Wait bsy flag */
		while(FLASH_FLAG_LOW != (FLASH->SR & FLASH_SR_BSY));
		if (Copy_u8BankIndex == 2 )
		{
			/* Bank 2 */
			FLASH->OPTCR1 &= ~(( Copy_u32SectorsMask ) << FLASH_OPTCR_NWRP_Pos);
		}
		else
		{
			/* Bank 1 */
			FLASH->OPTCR &= ~(( Copy_u32SectorsMask ) << FLASH_OPTCR_NWRP_Pos);
		}
		/* Start sector write protection */
		FLASH->OPTCR |= FLASH_OPTCR_OPTSTRT;
		/* Wait bsy flag */
		while(FLASH_FLAG_LOW != (FLASH->SR & FLASH_SR_BSY));
	}
	return Local_u8ErrorStatus;
}
/**
 ******************************************************************************
 * @fn             : MFLASH_u8RemoveWriteProtection
 * @brief          : Remove Sector Write Protection
 * @param[in]      : Copy_u8SectorNumber --> This parameter must be a value of @ref FLASHEx_Sectors
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t MFLASH_u8RemoveWriteProtection (uint32_t Copy_u32SectorNumber )
{
	uint8_t Local_u8ErrorStatus = ERROR_STATE_OK;
	if(Local_u8ErrorStatus == ERROR_STATE_OK)
	{
		/* Wait bsy flag */
		while(FLASH_FLAG_LOW != (FLASH->SR & FLASH_SR_BSY));
		if (Copy_u32SectorNumber >= 12 )
		{
			Copy_u32SectorNumber = Copy_u32SectorNumber - 12 ;
			/* Bank 2 */
			FLASH->OPTCR1 |= ((FLASH_OPTCR_NWRP_Msk << Copy_u32SectorNumber) << FLASH_OPTCR_NWRP_Pos);
		}
		else
		{
			/* Bank 1 */
			FLASH->OPTCR |= ((FLASH_OPTCR_NWRP_Msk << Copy_u32SectorNumber) << FLASH_OPTCR_NWRP_Pos);
		}
		/* Start sector write protection */
		FLASH->OPTCR |= FLASH_OPTCR_OPTSTRT;
		/* Wait bsy flag */
		while(FLASH_FLAG_LOW != (FLASH->SR & FLASH_SR_BSY));
	}
	return Local_u8ErrorStatus;
}
/**
 ******************************************************************************
 * @fn             : MFLASH_u8RemoveAllSectorsWriteProtection
 * @brief          : Remove All Sectors Write Protection
 * @param[in]      : Copy_u8BankIndex --> Get Option From @ref FLASHEx_Banks
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t MFLASH_u8RemoveAllSectorsWriteProtection ( uint8_t Copy_u8BankIndex )
{
	uint8_t Local_u8ErrorStatus = ERROR_STATE_OK;
	if(Local_u8ErrorStatus == ERROR_STATE_OK)
	{
		/* Wait bsy flag */
		while(FLASH_FLAG_LOW != (FLASH->SR & FLASH_SR_BSY));
		if (Copy_u8BankIndex == 2 )
		{
			/* Bank 2 */
			FLASH->OPTCR1 |= ((FLASH_OPTCR_NWRP_MASK)  << FLASH_OPTCR_NWRP_Pos);
		}
		else
		{
			/* Bank 1 */
			FLASH->OPTCR |= ((FLASH_OPTCR_NWRP_MASK)  << FLASH_OPTCR_NWRP_Pos);
		}
		/* Start sector write protection */
		FLASH->OPTCR |= FLASH_OPTCR_OPTSTRT;
		/* Wait bsy flag */
		while(FLASH_FLAG_LOW != (FLASH->SR & FLASH_SR_BSY));
	}
	return Local_u8ErrorStatus;
}
/**
 ******************************************************************************
 * @fn             : MFLASH_u8ReadSectorsWriteProtection
 * @brief          : Read Sectors Write Protection
 * @param[in]      : Copy_u8BankIndex --> Get Option From @ref FLASHEx_Banks
 * @retval         : Read Mask for Sectors Write Protection
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint32_t MFLASH_u8ReadSectorsWriteProtection ( uint8_t Copy_u8BankIndex  )
{
	uint32_t Local_u32EReadSectorWriteProtection ;
	if ( Copy_u8BankIndex == 2 )
	{
		Local_u32EReadSectorWriteProtection = FLASH->OPTCR1 ;
	}
	else
	{
		Local_u32EReadSectorWriteProtection = FLASH->OPTCR ;
	}
	CLR_BIT(Local_u32EReadSectorWriteProtection,FLASH_OPTCR_DB1M_Pos  );
	CLR_BIT(Local_u32EReadSectorWriteProtection,FLASH_OPTCR_SPRMOD_Pos);
	Local_u32EReadSectorWriteProtection = Local_u32EReadSectorWriteProtection >> FLASH_OPTCR_NWRP_Pos ;
	return Local_u32EReadSectorWriteProtection;
}

/**
 ******************************************************************************
 * @fn             : MFLASH_voidOptionBytesUnlock
 * @brief          : Option Bytes Unlock
 * @param          : void
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void MFLASH_voidOptionBytesUnlock(void)
{
	/* Write OPTKEY1 */
	FLASH->OPTKEYR = FLASH_OPTKEYR1;
	/* Write OPTKEY2 */
	FLASH->OPTKEYR = FLASH_OPTKEYR2;
}
/**
 ******************************************************************************
 * @fn             : MFLASH_voidOptionBytesLock
 * @brief          : Option Bytes Lock
 * @param          : void
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void MFLASH_voidOptionBytesLock(void)
{
  /* Set the LOCK Bit to lock the FLASH Registers access */
    FLASH->OPTCR |= FLASH_OPTCR_OPTLOCK;
}
/*************************************************************************************************************************************/
/********************************************************* Static Functions implementations ******************************************/
/*************************************************************************************************************************************/

static void voidProgramDoubleWord(uint32_t Copy_u32Address, uint64_t Copy_u64Data)
{

  /* If the previous operation is completed, proceed to program the new data */
  CLEAR_BIT(FLASH->CR, (FLASH_CR_PSIZE_Msk << FLASH_CR_PSIZE_Pos));
  FLASH->CR |= FLASH_PSIZE_DOUBLE_WORD;
  FLASH->CR |= (FLASH_CR_PG_Msk << FLASH_CR_PG_Pos);

  /* Program first word */
  *(volatile uint32_t*)Copy_u32Address = (uint32_t)Copy_u64Data;

  *(volatile uint32_t*)(Copy_u32Address+4) = (uint32_t)(Copy_u64Data >> 32);
}

static void voidProgramWord(uint32_t Copy_u32Address, uint32_t Copy_u32Data)
{
  /* If the previous operation is completed, proceed to program the new data */
  CLEAR_BIT(FLASH->CR, (FLASH_CR_PSIZE_Msk << FLASH_CR_PSIZE_Pos));
  FLASH->CR |= FLASH_PSIZE_WORD;
  FLASH->CR |= (FLASH_CR_PG_Msk << FLASH_CR_PG_Pos);

  *(volatile uint32_t*)Copy_u32Address = Copy_u32Data;
}

static void voidProgramHalfWord(uint32_t Copy_u32Address, uint16_t Copy_u16Data)
{
  /* If the previous operation is completed, proceed to program the new data */
  CLEAR_BIT(FLASH->CR, (FLASH_CR_PSIZE_Msk << FLASH_CR_PSIZE_Pos));
  FLASH->CR |= FLASH_PSIZE_HALF_WORD;
  FLASH->CR |= (FLASH_CR_PG_Msk << FLASH_CR_PG_Pos);

  *(volatile uint16_t*)Copy_u32Address = Copy_u16Data;
}

static void voidProgramByte(uint32_t Copy_u32Address, uint8_t Copy_u8Data)
{
  /* If the previous operation is completed, proceed to program the new data */
  CLEAR_BIT(FLASH->CR, (FLASH_CR_PSIZE_Msk << FLASH_CR_PSIZE_Pos));
  FLASH->CR |= FLASH_PSIZE_BYTE;
  FLASH->CR |= (FLASH_CR_PG_Msk << FLASH_CR_PG_Pos);

  *(volatile uint8_t*)Copy_u32Address = Copy_u8Data;
}

static void voidMassErase(uint8_t Copy_u8VoltageRange, uint32_t Copy_u32Banks)
{
  /* If the previous operation is completed, proceed to erase all sectors */
  CLEAR_BIT(FLASH->CR, (FLASH_CR_PSIZE_Msk << FLASH_CR_PSIZE_Pos));
  FLASH->CR |= (FLASH_CR_MER_Msk << FLASH_CR_MER_Pos);
  FLASH->CR |= (FLASH_CR_STRT_Msk << FLASH_CR_STRT_Pos) | ((uint32_t)Copy_u8VoltageRange << 8U);
}

static void voidEraseSector(uint32_t Copy_u32Sector, uint8_t Copy_u8VoltageRange)
{
  uint32_t Local_p32Size = 0U;

  if (Copy_u8VoltageRange == FLASH_VOLTAGE_RANGE_1)
  {
	  Local_p32Size = FLASH_PSIZE_BYTE;
  }
  else if (Copy_u8VoltageRange == FLASH_VOLTAGE_RANGE_2)
  {
	  Local_p32Size = FLASH_PSIZE_HALF_WORD;
  }
  else if (Copy_u8VoltageRange == FLASH_VOLTAGE_RANGE_3)
  {
	  Local_p32Size = FLASH_PSIZE_WORD;
  }
  else
  {
	  Local_p32Size = FLASH_PSIZE_DOUBLE_WORD;
  }
  /* If the previous operation is completed, proceed to erase the sector */
  CLEAR_BIT(FLASH->CR, (FLASH_CR_PSIZE_Msk << FLASH_CR_PSIZE_Pos));
  FLASH->CR |= Local_p32Size;
  CLEAR_BIT(FLASH->CR, (FLASH_CR_SNB_Msk << FLASH_CR_SNB_Pos));

  FLASH->CR |= (FLASH_CR_SER_Msk << FLASH_CR_SER_Pos) | (Copy_u32Sector << FLASH_CR_SNB_Pos);
  FLASH->CR |= (FLASH_CR_STRT_Msk << FLASH_CR_STRT_Pos);
}
/*************************************************************************************************************************************/
/********************************************************* Handlers implementations **************************************************/
/*************************************************************************************************************************************/

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
