/**
 ******************************************************************************
 * @file           : SYSCFG_program.c
 * @author         : Diea Abdeltwab
 * @layer          : MCAL
 * @brief          : Version 1 For STM32F446 Drivers
 * @date           : 1/8/2023
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
#include "stm32f429xxx.h"
/******************************************************************************/
/************************ MCAL Layer ******************************************/
/******************************************************************************/
#include "SYSCFG_interface.h"
#include "SYSCFG_private.h"
#include "SYSCFG_config.h"

/*************************************************************************************************************************************/
/********************************************************* Functions implementations *************************************************/
/*************************************************************************************************************************************/

/**
 ******************************************************************************
 * @fn             : MSYSCFG_u8PortRemap
 * @brief          : Remap EXTI line
 * @param[in]      : Copy_Config  --> init Value of Pin from @SYSCFG_LineNumber_t  struct
 * @param[in]      : Copy_PortMap --> init Value of Pin from @SYSCFG_PortMap_t     struct
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */

uint8_t   MSYSCFG_u8PortRemap ( SYSCFG_LineNumber_t Copy_LineNumber , SYSCFG_PortMap_t Copy_PortMap )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_LineNumber <= SYSCFG_LINE15 &&  Copy_PortMap <= SYSCFG_Port_H )
	{
		uint8_t Local_u8Reg  = Copy_LineNumber / SYSCFG_PORT_REMAP_ACCESS ;
		uint8_t Local_u8Line = Copy_LineNumber % SYSCFG_PORT_REMAP_ACCESS ;
		SYSCFG -> EXTICR[ Local_u8Reg ] &=~ ( ( SYSCFG_PORT_REMAP_MASK ) << ( Local_u8Line * SYSCFG_PORT_REMAP_ACCESS ) ) ;
		SYSCFG -> EXTICR[ Local_u8Reg ] |=  ( ( Copy_PortMap           ) << ( Local_u8Line * SYSCFG_PORT_REMAP_ACCESS ) ) ;
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK ;
	}
	return Local_u8ErrorState ;
}


