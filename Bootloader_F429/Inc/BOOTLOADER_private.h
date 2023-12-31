#ifndef  BOOTLOADER_PRIVATE_H
#define  BOOTLOADER_PRIVATE_H


/*************************************************************************************/
/******************************* VERSION *********************************************/
/*************************************************************************************/
#define  BOOTLOADER_VERSION           1u

/*************************************************************************************/
/******************************* Status **********************************************/
/*************************************************************************************/
#define  CRC_SUCCESS         0u
#define  CRC_FAIL            1u

#define  WRITING_SUCCESS     0u
#define  WRITING_ERROR       1u

#define  READING_SUCCESS     0u
#define  READING_ERROR       1u

#define  VALID_ADDRESS       0u
#define  INVALID_ADDRESS     1u

/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/
#define  MAX_SECTORS_BANK_NUMBER  12

#define  MAX_SECTORS_NUMBER       24

#define  MASS_ERASE_MASK          0xff

#define  CRC_LENGTH_CMD           4

/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/

/*************************************************************************************************************************************/
/********************************************************* Static Functions Prototype ************************************************/
/*************************************************************************************************************************************/

static void    voidSendNAck ( void );
static void    voidSendAck (uint8_t Copy_u8ReplyLength );
static uint8_t u8VerifyCRC(uint8_t * Copy_pu8DataArray , uint8_t Copy_u8Length , uint32_t Copy_u8HostCRC );
static uint8_t u8ValidateAddress ( uint32_t Copy_u32Address );
static uint8_t u8ExecuteMemoryWrite ( uint8_t *Copy_u8Buffer , uint32_t Copy_u32Address , uint8_t Copy_u8Length );
static uint8_t u8ExecuteFlashErase ( uint8_t Copy_u8SectorIndex , uint8_t Copy_u8NumberOfSector );
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/








#endif
