/**
 ******************************************************************************
 * @file           : BOOTLOADER_interface.h
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
#ifndef  BOOTLOADER_INTERFACE_H
#define  BOOTLOADER_INTERFACE_H

/******************************************************************************/
/************************ BOOTLOADER Commands *********************************/
/******************************************************************************/
#define  BOOTLOADER_GET_VER                                   0x51
#define  BOOTLOADER_GET_HELP                                  0x52
#define  BOOTLOADER_GET_CID                                   0x53
#define  BOOTLOADER_GET_RDP_STATUS                            0x54
#define  BOOTLOADER_GO_TO_ADDR                                0x55
#define  BOOTLOADER_FLASH_ERASE                               0x56
#define  BOOTLOADER_MEM_WRITE                                 0x57
#define  BOOTLOADER_EN_R_W_PROTECT                            0x58
#define  BOOTLOADER_MEM_READ                                  0x59
#define  BOOTLOADER_READ_SECTOR_P_STATUS                      0x5A
#define  BOOTLOADER_OTP_READ                                  0x5B
#define  BOOTLOADER_DIS_R_W_PROTECT                           0x5C

/******************************************************************************/
/************************ BOOTLOADER Reply ************************************/
/******************************************************************************/
#define  BOOTLOADER_ACK					                      0xA5
#define  BOOTLOADER_NACK					                  0x7F
/*
 *  0 --> SUCCSSES
 *  1 --> ERROR
 */
/*************************************************************************************************************************************/
/********************************************************* Functions Prototype *******************************************************/
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
void BOOTLOADER_voidHandleGetVerCmd (uint8_t * Copy_pu8CmdPacket );
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
void BOOTLOADER_voidHandleGetHelpCmd (uint8_t * Copy_pu8CmdPacket );
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
void BOOTLOADER_voidHandleGetCIDCmd (uint8_t * Copy_pu8CmdPacket );
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
void BOOTLOADER_voidHandleGetRDPStatusCmd (uint8_t * Copy_pu8CmdPacket );
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
void BOOTLOADER_voidHandleGotoAddressCmd (uint8_t * Copy_pu8CmdPacket );
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
void BOOTLOADER_voidHandleFlashEraseCmd (uint8_t * Copy_pu8CmdPacket );
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
void BOOTLOADER_voidHandleMemWriteCmd (uint8_t * Copy_pu8CmdPacket );
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
void BOOTLOADER_voidHandleEnableRWProtectCmd (uint8_t * Copy_pu8CmdPacket );
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
void BOOTLOADER_voidHandleDisableRWProtectCmd (uint8_t * Copy_pu8CmdPacket );
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
void BOOTLOADER_voidHandleReadSectorStatusCmd (uint8_t * Copy_pu8CmdPacket );
/***********************************************************************************************************************/
/******************************************* Not Support Yet ***********************************************************/
/***********************************************************************************************************************/

void BL_voidHandleMemReadCmd (uint8_t * Copy_pu8CmdPacket );
void BL_voidHandleOTPReadCmd (uint8_t * Copy_pu8CmdPacket );
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
#endif
