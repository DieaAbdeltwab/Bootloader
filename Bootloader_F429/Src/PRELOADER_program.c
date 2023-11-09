/**
 ******************************************************************************
 * @file           : PRELOADER_program.c
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
#include <stdio.h>
#include <string.h>
#include "ERROR_STATE.h"
#include "BIT_MATH.h"
#include "stm32f429xx.h"

/******************************************************************************/
/************************ MCAL Layer ******************************************/
/******************************************************************************/
#include "GPIO_INTERFACE.h"
#include "USART_interface.h"

/******************************************************************************/
/************************ HAL Layer *******************************************/
/******************************************************************************/
#include "FLASH_interface.h"

/******************************************************************************/
/************************ SERVIES Layer ***************************************/
/******************************************************************************/
#include "BOOTLOADER_interface.h"

#include "PRELOADER_interface.h"
#include "PRELOADER_config.h"
#include "PRELOADER_private.h"
/******************************************************************************/
/************************ Global **********************************************/
/******************************************************************************/
static uint8_t Local_u8AppIndexFlag = 1 ;
/*************************************************************************************************************************************/
/********************************************************* Functions implementations *************************************************/
/*************************************************************************************************************************************/
/**
 ******************************************************************************
 * @fn             : SPRELOADER_voidInit
 * @brief          : Preloader Switch ( APP or Bootloader )
 * @param          : void
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */

void SPRELOADER_voidSwitch ( void )
{
	uint8_t Local_u8Btn ;
	MGPIO_u8GetPinValue(PRELOADER_BTN_PORT, PRELOADER_BTN_PIN , &Local_u8Btn);
	if (Local_u8Btn == PRELOADER_PRESSED_BTN_STATUS )
	{
		voidGOToBootloader();
	}
	else if ( Local_u8AppIndexFlag == 2 )
	{
		//voidJumpToUserApp(PRELOADER_USER_APP2_BASE_ADDRESS);
		voidJumpToUserApp_2();
	}
	else
	{
		//voidJumpToUserApp(PRELOADER_USER_APP1_BASE_ADDRESS);
		voidJumpToUserApp_1();
	}
}
/*************************************************************************************************************************************/
/********************************************************* Static Functions implementations ******************************************/
/*************************************************************************************************************************************/
static void  voidGOToBootloader( void )
{
	uint8_t Local_u8CmdPacket[255]={0};
	while(1)
	{
		memset(Local_u8CmdPacket,0,255);
		/* 1- Length to Follow */
		MUSART_u8ReceiveArraySynch(PRELOADER_UART_INDEX , &Local_u8CmdPacket[0], 1);
		/* 2- Command */
		MUSART_u8ReceiveArraySynch(PRELOADER_UART_INDEX , &Local_u8CmdPacket[1], Local_u8CmdPacket[0] );
		/* 2- Decode Command */
		switch (Local_u8CmdPacket[1])
		{
		case BOOTLOADER_GET_VER                :      BOOTLOADER_voidHandleGetVerCmd            (Local_u8CmdPacket)    ; break ;
		case BOOTLOADER_GET_HELP               :      BOOTLOADER_voidHandleGetHelpCmd           (Local_u8CmdPacket)    ; break ;
		case BOOTLOADER_GET_CID                :      BOOTLOADER_voidHandleGetCIDCmd            (Local_u8CmdPacket)    ; break ;
		case BOOTLOADER_GET_RDP_STATUS         :      BOOTLOADER_voidHandleGetRDPStatusCmd      (Local_u8CmdPacket)    ; break ;
		case BOOTLOADER_GO_TO_ADDR             :      BOOTLOADER_voidHandleGotoAddressCmd       (Local_u8CmdPacket)    ; break ;
		case BOOTLOADER_FLASH_ERASE            :      BOOTLOADER_voidHandleFlashEraseCmd        (Local_u8CmdPacket)    ; break ;
		case BOOTLOADER_MEM_WRITE              :      BOOTLOADER_voidHandleMemWriteCmd          (Local_u8CmdPacket)    ; break ;
		case BOOTLOADER_EN_R_W_PROTECT         :      BOOTLOADER_voidHandleEnableRWProtectCmd   (Local_u8CmdPacket)    ; break ;
		case BOOTLOADER_MEM_READ               :      BL_voidHandleMemReadCmd                   (Local_u8CmdPacket)    ; break ;
		case BOOTLOADER_READ_SECTOR_P_STATUS   :      BOOTLOADER_voidHandleReadSectorStatusCmd  (Local_u8CmdPacket)    ; break ;
		case BOOTLOADER_OTP_READ               :      BL_voidHandleOTPReadCmd                   (Local_u8CmdPacket)    ; break ;
		case BOOTLOADER_DIS_R_W_PROTECT        :      BOOTLOADER_voidHandleDisableRWProtectCmd  (Local_u8CmdPacket)    ; break ;
		default                                :      /* invalid Command */                                              break ;
		}
	}
}
static void  voidJumpToUserApp ( uint32_t Copy_32UserAppAddress )
{
	void (* Local_pFunResetHandlar)(void);
	uint32_t Local_u8ResetHandlerAddress , Local_u32MSPVal ;

	Local_u32MSPVal = *((volatile uint32_t *)Copy_32UserAppAddress );
	__asm volatile("MSR MSP , %0"::"r"(Local_u32MSPVal));

	Local_u8ResetHandlerAddress  =  *((volatile uint32_t *)(Copy_32UserAppAddress + 4) );
	Local_pFunResetHandlar = (void *)Local_u8ResetHandlerAddress;
	Local_pFunResetHandlar();
}

static void  voidJumpToUserApp_1 ( void )
{
	void (* Local_pFunResetHandlar)(void);
	uint32_t Local_u8ResetHandlerAddress , Local_u32MSPVal ;

	Local_u32MSPVal = *((volatile uint32_t *)FLASH_SECTOR2_BASE_ADDRESS );
	__asm volatile("MSR MSP , %0"::"r"(Local_u32MSPVal));

	Local_u8ResetHandlerAddress  =  *((volatile uint32_t *)(FLASH_SECTOR2_BASE_ADDRESS + 4) );
	Local_pFunResetHandlar = (void *)Local_u8ResetHandlerAddress;
	Local_pFunResetHandlar();
}
static void  voidJumpToUserApp_2 ( void )
{
	void (* Local_pFunResetHandlar)(void);
	uint32_t Local_u8ResetHandlerAddress , Local_u32MSPVal ;

	Local_u32MSPVal = *((volatile uint32_t *)FLASH_SECTOR8_BASE_ADDRESS );
	__asm volatile("MSR MSP , %0"::"r"(Local_u32MSPVal));

	Local_u8ResetHandlerAddress  =  *((volatile uint32_t *)(FLASH_SECTOR8_BASE_ADDRESS + 4) );
	Local_pFunResetHandlar = (void *)Local_u8ResetHandlerAddress;
	Local_pFunResetHandlar();
}


/*************************************************************************************************************************************/
/********************************************************* Handlers implementations **************************************************/
/*************************************************************************************************************************************/

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
