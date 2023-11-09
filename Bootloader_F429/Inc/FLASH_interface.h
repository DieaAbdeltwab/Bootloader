/**
 ******************************************************************************
 * @file           : FLASH_interface.h
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
#ifndef  FLASH_INTERFACE_H
#define  FLASH_INTERFACE_H


/******************************************************************************/
/************************* FLASHEx_Type_Erase *********************************/
/******************************************************************************/
#define FLASH_TYPEERASE_SECTORS         0x00000000U  /*!< Sectors erase only          */
#define FLASH_TYPEERASE_MASSERASE       0x00000001U  /*!< Flash Mass erase activation */
/******************************************************************************/
/************************* FLASHEx_Banks **************************************/
/******************************************************************************/
#define FLASH_BANK_1                    1U /*!< Bank 1   */
#define FLASH_BANK_2                    2U /*!< Bank 2   */
/******************************************************************************/
/************************* FLASHEx_Sectors ************************************/
/******************************************************************************/
#define FLASH_SECTOR_0                  0U /*!< Sector Number 0   */
#define FLASH_SECTOR_1                  1U /*!< Sector Number 1   */
#define FLASH_SECTOR_2                  2U /*!< Sector Number 2   */
#define FLASH_SECTOR_3                  3U /*!< Sector Number 3   */
#define FLASH_SECTOR_4                  4U /*!< Sector Number 4   */
#define FLASH_SECTOR_5                  5U /*!< Sector Number 5   */
#define FLASH_SECTOR_6                  6U /*!< Sector Number 6   */
#define FLASH_SECTOR_7    			    7U /*!< Sector Number 7   */
#define FLASH_SECTOR_8                  8U  /*!< Sector Number 8   */
#define FLASH_SECTOR_9                  9U  /*!< Sector Number 9   */
#define FLASH_SECTOR_10                 10U /*!< Sector Number 10  */
#define FLASH_SECTOR_11                 11U /*!< Sector Number 11  */

#define FLASH_SECTOR_12                 12U /*!< Sector Number 12  */
#define FLASH_SECTOR_13                 13U /*!< Sector Number 13  */
#define FLASH_SECTOR_14                 14U /*!< Sector Number 14  */
#define FLASH_SECTOR_15    			    15U /*!< Sector Number 15  */
#define FLASH_SECTOR_16                 16U /*!< Sector Number 16   */
#define FLASH_SECTOR_17                 17U /*!< Sector Number 17   */
#define FLASH_SECTOR_18                 18U /*!< Sector Number 18   */
#define FLASH_SECTOR_19                 19U /*!< Sector Number 19   */
#define FLASH_SECTOR_20                 20U /*!< Sector Number 20   */
#define FLASH_SECTOR_21                 21U /*!< Sector Number 21   */
#define FLASH_SECTOR_22                 22U /*!< Sector Number 22   */
#define FLASH_SECTOR_23    			    23U /*!< Sector Number 23   */
/******************************************************************************/
/************************* FLASHEx_Voltage_Range ******************************/
/******************************************************************************/
#define FLASH_VOLTAGE_RANGE_1           0x00000000U  /*!< Device operating range: 1.8V to 2.1V                */
#define FLASH_VOLTAGE_RANGE_2           0x00000001U  /*!< Device operating range: 2.1V to 2.7V                */
#define FLASH_VOLTAGE_RANGE_3           0x00000002U  /*!< Device operating range: 2.7V to 3.6V                */
#define FLASH_VOLTAGE_RANGE_4           0x00000003U  /*!< Device operating range: 2.7V to 3.6V + External Vpp */
/******************************************************************************/
/************************* FLASH_TypeProgram **********************************/
/******************************************************************************/
typedef struct
{
  uint32_t TypeErase;   /*!< Mass erase or sector Erase.
                             This parameter can be a value of @ref FLASHEx_Type_Erase */

  uint32_t Banks;       /*!< Select banks to erase when Mass erase is enabled.
                             This parameter must be a value of @ref FLASHEx_Banks */

  uint32_t Sector;      /*!< Initial FLASH sector to erase when Mass erase is disabled
                             This parameter must be a value of @ref FLASHEx_Sectors */

  uint32_t NbSectors;   /*!< Number of sectors to be erased.
                             This parameter must be a value between 1 and (max number of sectors - value of Initial sector)*/

  uint32_t VoltageRange; /*!< The device voltage range which defines the erase parallelism
                             This parameter must be a value of @ref FLASHEx_Voltage_Range */

} FLASH_EraseInitTypeDef;

/******************************************************************************/
/************************* FLASH_TypeProgram **********************************/
/******************************************************************************/

#define FLASH_TYPEPROGRAM_BYTE          0x00000000U  /*!< Program byte (8-bit) at a specified address           */
#define FLASH_TYPEPROGRAM_HALFWORD      0x00000001U  /*!< Program a half-word (16-bit) at a specified address   */
#define FLASH_TYPEPROGRAM_WORD          0x00000002U  /*!< Program a word (32-bit) at a specified address        */
#define FLASH_TYPEPROGRAM_DOUBLEWORD    0x00000003U  /*!< Program a double word (64-bit) at a specified address */
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/*************************************************************************************************************************************/
/********************************************************* Functions Prototype *******************************************************/
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
void MFLASH_voidUnlock(void);
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
void MFLASH_voidLock(void);
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
uint8_t MFLASH_u8Erase(FLASH_EraseInitTypeDef *Copy_pEraseInit, uint32_t *Local_pu32SectorError);
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
uint8_t MFLASH_u8WriteProgram(uint32_t Copy_u32TypeProgram, uint32_t Copy_u32Address, uint64_t Copy_u64Data);
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
uint8_t MFLASH_u8WriteProtection(uint32_t Copy_u32SectorNumber );
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
uint8_t MFLASH_u8MaskAllSectorsWriteProtection( uint8_t Copy_u32SectorsMask , uint8_t Copy_u8BankIndex );
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
uint8_t MFLASH_u8RemoveWriteProtection (uint32_t Copy_u32SectorNumber );
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
uint8_t MFLASH_u8RemoveAllSectorsWriteProtection ( uint8_t Copy_u8BankIndex );
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
uint32_t MFLASH_u8ReadSectorsWriteProtection ( uint8_t Copy_u8BankIndex  );

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
void MFLASH_voidOptionBytesUnlock(void);
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
void MFLASH_voidOptionBytesLock(void);
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
#endif

