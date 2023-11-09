/**
 ******************************************************************************
 * @file           : BOOTLOADER_program.c
 * @author         : Diea Abdeltwab
 * @layer          : Services
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
#include "GPIO_INTERFACE.h"
#include "USART_interface.h"
#include "CRC_interface.h"
#include "FLASH_interface.h"

/******************************************************************************/
/************************ HAL Layer *******************************************/
/******************************************************************************/

/******************************************************************************/
/************************ SERVIES Layer ***************************************/
/******************************************************************************/
#include "BOOTLOADER_interface.h"
#include "BOOTLOADER_config.h"
#include "BOOTLOADER_private.h"
/******************************************************************************/
/************************ Global **********************************************/
/******************************************************************************/

/*************************************************************************************************************************************/
/********************************************************* Functions implementations *************************************************/
/*************************************************************************************************************************************/
/**
 ******************************************************************************
 * @fn             : BOOTLOADER_voidHandleGetVerCmd
 * @brief          : Handle Get Version Command-->( BOOTLOADER_GET_VER )
 * @param[in]      : Copy_pu8CmdPacket --> Set Address of Packet
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void BOOTLOADER_voidHandleGetVerCmd(uint8_t * Copy_pu8CmdPacket )
{
	uint8_t  Local_u8CRCStatus , Local_u8CmdLength  ;
	uint32_t Local_u32HostCRC  ;

	Local_u8CmdLength = Copy_pu8CmdPacket [0] + 1 ;
	Local_u32HostCRC  = *((uint32_t * )(Copy_pu8CmdPacket + Local_u8CmdLength - CRC_LENGTH_CMD ));
	Local_u8CRCStatus = u8VerifyCRC (Copy_pu8CmdPacket , (Local_u8CmdLength - CRC_LENGTH_CMD) , Local_u32HostCRC );
	if( Local_u8CRCStatus == CRC_SUCCESS )
	{
		uint8_t Local_u8BlVersion ;
		voidSendAck(1u);
		Local_u8BlVersion = BOOTLOADER_VERSION ;
		MUSART_u8TransmitArraySynch( BOOTLOADER_UART_INDEX , &Local_u8BlVersion , 1 );
	}
	else
	{
		voidSendNAck();
	}
}
/**
 ******************************************************************************
 * @fn             : BOOTLOADER_voidHandleGetHelpCmd
 * @brief          : Handle Get Help Command-->( BOOTLOADER_GET_HELP )
 * @param[in]      : Copy_pu8CmdPacket --> Set Address of Packet
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void BOOTLOADER_voidHandleGetHelpCmd(uint8_t * Copy_pu8CmdPacket )
{
	uint8_t  Local_u8CRCStatus , Local_u8CmdLength  ;
	uint32_t Local_u32HostCRC  ;

	Local_u8CmdLength = Copy_pu8CmdPacket [0] + 1 ;
	Local_u32HostCRC  = *((uint32_t * )(Copy_pu8CmdPacket + Local_u8CmdLength - CRC_LENGTH_CMD ));
	Local_u8CRCStatus = u8VerifyCRC (Copy_pu8CmdPacket , (Local_u8CmdLength - CRC_LENGTH_CMD) , Local_u32HostCRC );
	if( Local_u8CRCStatus == CRC_SUCCESS )
	{
		uint8_t Local_pu8BootloaderCommands[] =
		{
				BOOTLOADER_GET_VER                 ,
				BOOTLOADER_GET_HELP                ,
				BOOTLOADER_GET_CID                 ,
				BOOTLOADER_GET_RDP_STATUS          ,
				BOOTLOADER_GO_TO_ADDR              ,
				BOOTLOADER_FLASH_ERASE             ,
				BOOTLOADER_MEM_WRITE               ,
				BOOTLOADER_EN_R_W_PROTECT          ,
				BOOTLOADER_MEM_READ                ,
				BOOTLOADER_READ_SECTOR_P_STATUS    ,
				BOOTLOADER_OTP_READ                ,
				BOOTLOADER_DIS_R_W_PROTECT
		};
		voidSendAck(sizeof(Local_pu8BootloaderCommands));
		MUSART_u8TransmitArraySynch( BOOTLOADER_UART_INDEX , Local_pu8BootloaderCommands , sizeof(Local_pu8BootloaderCommands) );
	}
	else
	{
		voidSendNAck();
	}
}
/**
 ******************************************************************************
 * @fn             : BOOTLOADER_voidHandleGetCIDCmd
 * @brief          : Handle Get CID Command-->( BOOTLOADER_GET_CID )
 * @param[in]      : Copy_pu8CmdPacket --> Set Address of Packet
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void BOOTLOADER_voidHandleGetCIDCmd(uint8_t * Copy_pu8CmdPacket )
{
	uint8_t  Local_u8CRCStatus , Local_u8CmdLength  ;
	uint32_t Local_u32HostCRC  ;

	Local_u8CmdLength = Copy_pu8CmdPacket [0] + 1 ;
	Local_u32HostCRC  = *((uint32_t * )(Copy_pu8CmdPacket + Local_u8CmdLength - CRC_LENGTH_CMD ));
	Local_u8CRCStatus = u8VerifyCRC (Copy_pu8CmdPacket , (Local_u8CmdLength - CRC_LENGTH_CMD) , Local_u32HostCRC );
	if( Local_u8CRCStatus == CRC_SUCCESS )
	{
		uint16_t Local_u16DeviceID ;
		voidSendAck(2u);
		Local_u16DeviceID = (DBGMCU->IDCODE & 0x0FFF) ;
		MUSART_u8TransmitArraySynch( BOOTLOADER_UART_INDEX , (uint8_t *)&Local_u16DeviceID , 2 );
	}
	else
	{
		voidSendNAck();
	}
}
/**
 ******************************************************************************
 * @fn             : BOOTLOADER_voidHandleGetRDPStatusCmd
 * @brief          : Handle Get RDP Status Command-->( BOOTLOADER_GET_RDP_STATUS )
 * @param[in]      : Copy_pu8CmdPacket --> Set Address of Packet
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void BOOTLOADER_voidHandleGetRDPStatusCmd(uint8_t * Copy_pu8CmdPacket )
{
	uint8_t  Local_u8CRCStatus , Local_u8CmdLength  ;
	uint32_t Local_u32HostCRC  ;

	Local_u8CmdLength = Copy_pu8CmdPacket [0] + 1 ;
	Local_u32HostCRC  = *((uint32_t * )(Copy_pu8CmdPacket + Local_u8CmdLength - CRC_LENGTH_CMD ));
	Local_u8CRCStatus = u8VerifyCRC (Copy_pu8CmdPacket , (Local_u8CmdLength - CRC_LENGTH_CMD) , Local_u32HostCRC );
	if( Local_u8CRCStatus == CRC_SUCCESS )
	{
		uint8_t Local_u8RDPStatus ;
		voidSendAck(1u);
		Local_u8RDPStatus = (uint8_t)(( RDP_USER_OPTION_WORD_REG >> 8) & 0xff );
		MUSART_u8TransmitArraySynch( BOOTLOADER_UART_INDEX , &Local_u8RDPStatus , 1 );
	}
	else
	{
		voidSendNAck();
	}
}
/**
 ******************************************************************************
 * @fn             : BOOTLOADER_voidHandleGotoAddressCmd
 * @brief          : Handle Go to Address Command-->( BOOTLOADER_GO_TO_ADDR )
 * @param[in]      : Copy_pu8CmdPacket --> Set Address of Packet
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void BOOTLOADER_voidHandleGotoAddressCmd(uint8_t * Copy_pu8CmdPacket )
{
	uint8_t  Local_u8CRCStatus , Local_u8CmdLength  ;
	uint32_t Local_u32HostCRC  ;

	Local_u8CmdLength = Copy_pu8CmdPacket [0] + 1 ;
	Local_u32HostCRC  = *((uint32_t * )(Copy_pu8CmdPacket + Local_u8CmdLength - CRC_LENGTH_CMD ));
	Local_u8CRCStatus = u8VerifyCRC (Copy_pu8CmdPacket , (Local_u8CmdLength - CRC_LENGTH_CMD) , Local_u32HostCRC );
	if( Local_u8CRCStatus == CRC_SUCCESS )
	{
		uint32_t Local_u32Addess ;
		uint8_t  Local_u8AddressStatus ;
		voidSendAck(1u);
		Local_u32Addess = *((uint32_t *) &Copy_pu8CmdPacket[2] );
		Local_u8AddressStatus = u8ValidateAddress(Local_u32Addess);
		MUSART_u8TransmitArraySynch( BOOTLOADER_UART_INDEX , &Local_u8AddressStatus , 1 );
		if ( Local_u8AddressStatus == VALID_ADDRESS )
		{
			void (* Local_pFuncPtr )(void);
			Local_u32Addess |= 1 ;
			Local_pFuncPtr   = (void *)Local_u32Addess ;
			Local_pFuncPtr   ();
		}
	}
	else
	{
		voidSendNAck();
	}
}
/**
 ******************************************************************************
 * @fn             : BOOTLOADER_voidHandleFlashEraseCmd
 * @brief          : Handle Flash Erase Command-->( BOOTLOADER_FLASH_ERASE )
 * @param[in]      : Copy_pu8CmdPacket --> Set Address of Packet
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void BOOTLOADER_voidHandleFlashEraseCmd(uint8_t * Copy_pu8CmdPacket )
{
	uint8_t  Local_u8CRCStatus , Local_u8CmdLength  ;
	uint32_t Local_u32HostCRC  ;

	Local_u8CmdLength = Copy_pu8CmdPacket [0] + 1 ;
	Local_u32HostCRC  = *((uint32_t * )(Copy_pu8CmdPacket + Local_u8CmdLength - CRC_LENGTH_CMD ));
	Local_u8CRCStatus = u8VerifyCRC (Copy_pu8CmdPacket , (Local_u8CmdLength - CRC_LENGTH_CMD) , Local_u32HostCRC );
	if( Local_u8CRCStatus == CRC_SUCCESS )
	{
		uint8_t Local_u8EraseStatus ;
		voidSendAck(1u);
		Local_u8EraseStatus = u8ExecuteFlashErase( Copy_pu8CmdPacket[2] , Copy_pu8CmdPacket[3] );
		MUSART_u8TransmitArraySynch( BOOTLOADER_UART_INDEX , &Local_u8EraseStatus , 1 );
	}
	else
	{
		voidSendNAck();
	}
}
/**
 ******************************************************************************
 * @fn             : BOOTLOADER_voidHandleMemWriteCmd
 * @brief          : Handle Memory Write Command-->( BOOTLOADER_MEM_WRITE )
 * @param[in]      : Copy_pu8CmdPacket --> Set Address of Packet
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void BOOTLOADER_voidHandleMemWriteCmd(uint8_t * Copy_pu8CmdPacket )
{
	uint8_t  Local_u8CRCStatus , Local_u8CmdLength  ;
	uint32_t Local_u32HostCRC  ;

	Local_u8CmdLength = Copy_pu8CmdPacket [0] + 1 ;
	Local_u32HostCRC  = *((uint32_t * )(Copy_pu8CmdPacket + Local_u8CmdLength - CRC_LENGTH_CMD ));
	Local_u8CRCStatus = u8VerifyCRC (Copy_pu8CmdPacket , (Local_u8CmdLength - CRC_LENGTH_CMD) , Local_u32HostCRC );
	if( Local_u8CRCStatus == CRC_SUCCESS )
	{
		uint8_t  Local_u8WritingStatus ;
		uint32_t Local_u32Address = *((uint32_t *)&Copy_pu8CmdPacket[2]);
		uint8_t  Local_u8AddressStatus = u8ValidateAddress(Local_u32Address);
		voidSendAck(1u);
		if ( Local_u8AddressStatus == VALID_ADDRESS )
		{
			uint8_t Local_u8PayloadLength = Copy_pu8CmdPacket[6];
			Local_u8WritingStatus = u8ExecuteMemoryWrite(&Copy_pu8CmdPacket[7], Local_u32Address , Local_u8PayloadLength) ;
		}
		else
		{
			Local_u8WritingStatus = WRITING_ERROR ;
		}
		MUSART_u8TransmitArraySynch( BOOTLOADER_UART_INDEX , &Local_u8WritingStatus , 1 );
	}
	else
	{
		voidSendNAck();
	}
}
/**
 ******************************************************************************
 * @fn             : BOOTLOADER_voidHandleEnableRWProtectCmd
 * @brief          : Handle Enable R\W Protect Command-->( BOOTLOADER_EN_R_W_PROTECT )
 * @param[in]      : Copy_pu8CmdPacket --> Set Address of Packet
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void BOOTLOADER_voidHandleEnableRWProtectCmd(uint8_t * Copy_pu8CmdPacket )
{
	uint8_t  Local_u8CRCStatus , Local_u8CmdLength  ;
	uint32_t Local_u32HostCRC  ;

	Local_u8CmdLength = Copy_pu8CmdPacket [0] + 1 ;
	Local_u32HostCRC  = *((uint32_t * )(Copy_pu8CmdPacket + Local_u8CmdLength - CRC_LENGTH_CMD ));
	Local_u8CRCStatus = u8VerifyCRC (Copy_pu8CmdPacket , (Local_u8CmdLength - CRC_LENGTH_CMD) , Local_u32HostCRC );
	if( Local_u8CRCStatus == CRC_SUCCESS )
	{
		uint8_t Local_u8ErrorStatus ;
		uint8_t Local_u8SectorDetails = Copy_pu8CmdPacket[2];
		voidSendAck(1u);
		MFLASH_voidOptionBytesUnlock();
		Local_u8ErrorStatus = MFLASH_u8MaskAllSectorsWriteProtection(Local_u8SectorDetails , FLASH_BANK_1 );
		MFLASH_voidOptionBytesLock();
		MUSART_u8TransmitArraySynch( BOOTLOADER_UART_INDEX , &Local_u8ErrorStatus , 1 );
	}
	else
	{
		voidSendNAck();
	}


}
/**
 ******************************************************************************
 * @fn             : BOOTLOADER_voidHandleDisableRWProtectCmd
 * @brief          : Handle Disable R\W Protect Command-->( BOOTLOADER_DIS_R_W_PROTECT )
 * @param[in]      : Copy_pu8CmdPacket --> Set Address of Packet
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void BOOTLOADER_voidHandleDisableRWProtectCmd(uint8_t * Copy_pu8CmdPacket )
{
	uint8_t  Local_u8CRCStatus , Local_u8CmdLength  ;
	uint32_t Local_u32HostCRC ;

	Local_u8CmdLength = Copy_pu8CmdPacket [0] + 1 ;
	Local_u32HostCRC  = *((uint32_t * )(Copy_pu8CmdPacket + Local_u8CmdLength - CRC_LENGTH_CMD ));
	Local_u8CRCStatus = u8VerifyCRC (Copy_pu8CmdPacket , (Local_u8CmdLength - CRC_LENGTH_CMD) , Local_u32HostCRC );
	if( Local_u8CRCStatus == CRC_SUCCESS )
	{
		uint8_t Local_u8ErrorStatus = 0 ;
		voidSendAck(1u);
		MFLASH_voidOptionBytesUnlock();
		Local_u8ErrorStatus = MFLASH_u8RemoveAllSectorsWriteProtection(FLASH_BANK_1);
		MFLASH_voidOptionBytesLock();
		MUSART_u8TransmitArraySynch( BOOTLOADER_UART_INDEX , &Local_u8ErrorStatus , 1 );
	}
	else
	{
		voidSendNAck();
	}
}
/**
 ******************************************************************************
 * @fn             : BOOTLOADER_voidHandleReadSectorStatusCmd
 * @brief          : Handle Read Sectors Status Command-->( BOOTLOADER_READ_SECTOR_P_STATUS )
 * @param[in]      : Copy_pu8CmdPacket --> Set Address of Packet
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void BOOTLOADER_voidHandleReadSectorStatusCmd(uint8_t * Copy_pu8CmdPacket )
{
	uint8_t  Local_u8CRCStatus , Local_u8CmdLength  ;
	uint32_t Local_u32HostCRC ;

	Local_u8CmdLength = Copy_pu8CmdPacket [0] + 1 ;
	Local_u32HostCRC  = *((uint32_t * )(Copy_pu8CmdPacket + Local_u8CmdLength - CRC_LENGTH_CMD ));
	Local_u8CRCStatus = u8VerifyCRC (Copy_pu8CmdPacket , (Local_u8CmdLength - CRC_LENGTH_CMD) , Local_u32HostCRC );
	if( Local_u8CRCStatus == CRC_SUCCESS )
	{
		uint8_t Local_u8ReadingSectorsStatus ;
		voidSendAck(1u);
		Local_u8ReadingSectorsStatus = (uint8_t)MFLASH_u8ReadSectorsWriteProtection(FLASH_BANK_1);
		MUSART_u8TransmitArraySynch( BOOTLOADER_UART_INDEX , &Local_u8ReadingSectorsStatus , 1 );
	}
	else
	{
		voidSendNAck();
	}
}

/***********************************************************************************************************************/
/******************************************* Not Support Yet ***********************************************************/
/***********************************************************************************************************************/

void BL_voidHandleMemReadCmd(uint8_t * Copy_pu8CmdPacket )
{
	uint8_t  Local_u8CRCStatus , Local_u8CmdLength  ;
	uint32_t Local_u32HostCRC ;

	Local_u8CmdLength = Copy_pu8CmdPacket [0] + 1 ;

	Local_u32HostCRC = *((uint32_t * )(Copy_pu8CmdPacket + Local_u8CmdLength - 4 ));

	Local_u8CRCStatus = u8VerifyCRC (Copy_pu8CmdPacket , (Local_u8CmdLength - 4) , Local_u32HostCRC );
	if( Local_u8CRCStatus == CRC_SUCCESS )
	{
		voidSendAck(1u);

	}
	else
	{
		voidSendNAck();
	}
}

void BL_voidHandleOTPReadCmd(uint8_t * Copy_pu8CmdPacket )
{
	uint8_t  Local_u8CRCStatus , Local_u8CmdLength  ;
	uint32_t Local_u32HostCRC ;

	Local_u8CmdLength = Copy_pu8CmdPacket [0] + 1 ;

	Local_u32HostCRC = *((uint32_t * )(Copy_pu8CmdPacket + Local_u8CmdLength - 4 ));

	Local_u8CRCStatus = u8VerifyCRC (Copy_pu8CmdPacket , (Local_u8CmdLength - 4) , Local_u32HostCRC );
	if( Local_u8CRCStatus == CRC_SUCCESS )
	{
		voidSendAck(1u);

	}
	else
	{
		voidSendNAck();
	}
}

/*************************************************************************************************************************************/
/********************************************************* Static Functions implementations ******************************************/
/*************************************************************************************************************************************/
static void voidSendNAck ( void )
{
	uint8_t Local_u8NAckBuffer = BOOTLOADER_NACK;
	MUSART_u8TransmitArraySynch(BOOTLOADER_UART_INDEX ,  &Local_u8NAckBuffer , 1 );
}


static void voidSendAck ( uint8_t Copy_u8ReplyLength )
{
	uint8_t Local_u8AckBuffer [2] = {BOOTLOADER_ACK , Copy_u8ReplyLength};
	MUSART_u8TransmitArraySynch(BOOTLOADER_UART_INDEX , Local_u8AckBuffer , 2);

}
static uint8_t u8VerifyCRC(uint8_t * Copy_pu8DataArray , uint8_t Copy_u8Length , uint32_t Copy_u8HostCRC )
{
	uint8_t  Local_u8CRCStatus ;
	uint32_t Local_u32AccumulateCRC , Local_u32Temp     ;
	for (uint8_t Local_u8Iterator = 0 ; Local_u8Iterator< Copy_u8Length ; Local_u8Iterator++ )
	{
		Local_u32Temp = Copy_pu8DataArray[Local_u8Iterator];
		Local_u32AccumulateCRC = MCRC_u32Accumulate(&Local_u32Temp, 1 );
	}
	MCRC_voidDRreset();
	if (Local_u32AccumulateCRC == Copy_u8HostCRC )
	{
		Local_u8CRCStatus = CRC_SUCCESS ;
	}
	else
	{
		Local_u8CRCStatus = CRC_FAIL ;
	}
	return Local_u8CRCStatus ;
}
static uint8_t u8ValidateAddress ( uint32_t Copy_u32Address )
{
	uint8_t Local_u8AddressStatus ;
	if(( Copy_u32Address >= FLASH_BASE ) && (Copy_u32Address < FLASH_END))
	{
		Local_u8AddressStatus = VALID_ADDRESS ;
	}
	else if(( Copy_u32Address >= SRAM1_BASE ) && (Copy_u32Address  < SRAM1_END))
	{
		Local_u8AddressStatus = VALID_ADDRESS ;
	}
	else
	{
		Local_u8AddressStatus = INVALID_ADDRESS ;
	}
	return Local_u8AddressStatus ;
}
static uint8_t u8ExecuteMemoryWrite ( uint8_t *Copy_u8Buffer , uint32_t Copy_u32Address , uint8_t Copy_u8Length )
{
	uint8_t Local_u8ErrorStatus = ERROR_STATE_OK ;
	if (( Copy_u32Address >= FLASH_BASE ) && (Copy_u32Address < FLASH_END))
	{
		uint8_t Local_u8Iterator ;
		MFLASH_voidUnlock();
		for (Local_u8Iterator=0 ; Local_u8Iterator < Copy_u8Length ; Local_u8Iterator++)
		{
			Local_u8ErrorStatus = MFLASH_u8WriteProgram(FLASH_TYPEPROGRAM_BYTE, Copy_u32Address + Local_u8Iterator ,(uint64_t) Copy_u8Buffer[Local_u8Iterator]);
		}
		MFLASH_voidLock();
	}
	else
	{
		uint8_t Local_u8Iterator ;
		uint8_t* Local_pu8Destination = (uint8_t *)Copy_u32Address ;
		for (Local_u8Iterator=0 ; Local_u8Iterator < Copy_u8Length ; Local_u8Iterator++)
		{
			Local_pu8Destination[Local_u8Iterator]=Copy_u8Buffer[Local_u8Iterator];
		}
	}
	return Local_u8ErrorStatus ;
}
static uint8_t u8ExecuteFlashErase ( uint8_t Copy_u8SectorIndex , uint8_t Copy_u8NumberOfSector )
{
	uint8_t Local_u8ErrorStatus = ERROR_STATE_OK ;
	if      ((Copy_u8NumberOfSector > MAX_SECTORS_NUMBER )  && (Copy_u8SectorIndex != MASS_ERASE_MASK ))
	{
		Local_u8ErrorStatus = ERROR_STATE_NOK ;
	}
	else if ((Copy_u8SectorIndex > (MAX_SECTORS_NUMBER-1) ) && (Copy_u8SectorIndex != MASS_ERASE_MASK ))
	{
		Local_u8ErrorStatus = ERROR_STATE_NOK ;
	}
	else
	{
		FLASH_EraseInitTypeDef Local_Erase ;
		uint32_t Local_u32SectorError ;
		if (Copy_u8SectorIndex == MASS_ERASE_MASK )
		{
			Local_Erase.TypeErase = FLASH_TYPEERASE_MASSERASE ;
		}
		else
		{
			uint8_t Local_u8RamainingSector = MAX_SECTORS_NUMBER - Copy_u8SectorIndex ;
			if (Copy_u8NumberOfSector > Local_u8RamainingSector)
			{
				Copy_u8NumberOfSector = Local_u8RamainingSector ;
			}
			Local_Erase.TypeErase = FLASH_TYPEERASE_SECTORS ;
			Local_Erase.Sector    = Copy_u8SectorIndex ;
			Local_Erase.NbSectors = Copy_u8NumberOfSector ;
		}
		Local_Erase.VoltageRange = FLASH_VOLTAGE_RANGE_3 ;
		if (Copy_u8NumberOfSector > MAX_SECTORS_BANK_NUMBER )
		{
			Local_Erase.Banks        = FLASH_BANK_2 ;
		}
		else
		{
			Local_Erase.Banks        = FLASH_BANK_1 ;
		}
		MFLASH_voidUnlock();
		Local_u8ErrorStatus = MFLASH_u8Erase(&Local_Erase,&Local_u32SectorError);
		MFLASH_voidLock();
	}
	return Local_u8ErrorStatus ;
}
/*************************************************************************************************************************************/
/********************************************************* Handlers implementations **************************************************/
/*************************************************************************************************************************************/

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
