#ifndef  FLASH_PRIVATE_H
#define  FLASH_PRIVATE_H


/*************************************************************************************/
/******************************* ACCSESS *********************************************/
/*************************************************************************************/
#define FLASH_FLAG_LOW                 0U
/*************************************************************************************/
/******************************* MASKS ***********************************************/
/*************************************************************************************/
#define FLASH_CR_LOCK                 ((uint32_t)0x80000000)
#define FLASH_SR_BSY                  ((uint32_t)0x00010000)
#define FLASH_OPTCR_OPTSTRT           ((uint32_t)0x00000002)
#define FLASH_OPTCR_OPTLOCK           ((uint32_t)0x00000001)


#define FLASH_PSIZE_BYTE               0x00000000U
#define FLASH_PSIZE_HALF_WORD   	   0x00000100U
#define FLASH_PSIZE_WORD               0x00000200U
#define FLASH_PSIZE_DOUBLE_WORD        0x00000300U



/*************************************************************************************/
/******************************** Flash Key ******************************************/
/*************************************************************************************/
#define FLASH_KEY1                     0x45670123U
#define FLASH_KEY2                     0xCDEF89ABU


#define FLASH_OPTKEYR1                 0x08192A3BU
#define FLASH_OPTKEYR2                 0x4C5D6E7FU
/*************************************************************************************/
/******************************* BITS ************************************************/
/*************************************************************************************/

#define FLASH_CR_PG_Pos                (0U)
#define FLASH_CR_PG_Msk                (0x1UL)               /*!< 0x00000001 */

#define FLASH_CR_MER_Pos               (2U)
#define FLASH_CR_MER_Msk               (0x1UL)               /*!< 0x00000004 */

#define FLASH_CR_PSIZE_Pos             (8U)
#define FLASH_CR_PSIZE_Msk             (0x3UL)               /*!< 0x00000300 */

#define FLASH_CR_SNB_Pos               (3U)
#define FLASH_CR_SNB_Msk               (0x1FU)               /*!< 0x000000F8 */

#define FLASH_CR_SER_Pos               (1U)
#define FLASH_CR_SER_Msk               (0x1UL)               /*!< 0x00000002 */

#define FLASH_CR_STRT_Pos              (16U)
#define FLASH_CR_STRT_Msk              (0x1UL)               /*!< 0x00010000 */

#define FLASH_OPTCR_NWRP_Pos           (16U)
#define FLASH_OPTCR_NWRP_Msk           (0x1UL)               /*!< 0x00010000 */
#define FLASH_OPTCR_NWRP_MASK          (0b11111111)

#define FLASH_OPTCR_DB1M_Pos           (30U)
#define FLASH_OPTCR_SPRMOD_Pos         (31U)

/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/

/*************************************************************************************************************************************/
/********************************************************* Static Functions Prototype ************************************************/
/*************************************************************************************************************************************/
static void voidProgramDoubleWord (uint32_t Copy_u32Address, uint64_t Copy_u64Data);
static void voidProgramWord       (uint32_t Copy_u32Address, uint32_t Copy_u32Data);
static void voidProgramHalfWord   (uint32_t Copy_u32Address, uint16_t Copy_u16Data);
static void voidProgramByte       (uint32_t Copy_u32Address, uint8_t  Copy_u8Data);
static void voidMassErase         (uint8_t Copy_u8VoltageRange , uint32_t Copy_u32Banks);
static void voidEraseSector       (uint32_t Copy_u32Sector     , uint8_t Copy_u8VoltageRange);
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/








#endif
