/**
 ******************************************************************************
 * @file           : SCB_program.c
 * @author         : Diea Abdeltwab
 * @layer          : MCAL ( Core Peripheral )
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
#include "stm32f429xx.h"
/******************************************************************************/
/************************ MCAL Layer ******************************************/
/******************************************************************************/
#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_config.h"

/*************************************************************************************************************************************/
/********************************************************* Functions implementations *************************************************/
/*************************************************************************************************************************************/

/**
 ******************************************************************************
 * @fn             : MSCB_u8InterruptPriority
 * @brief          : Interrupt Priority
 * @param[in]      : Copy_NVICGroubSubDistribution --> init Value of Pin from @SCB_InterruptPriority_t enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */

uint8_t   MSCB_u8InterruptPriority ( SCB_InterruptPriority_t Copy_NVICGroubSubDistribution  )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_NVICGroubSubDistribution <= GROUP7 )
	{
		uint32_t Local_u32NVICGroubSubDistribution = SCB_AIRCR_KEY + (Copy_NVICGroubSubDistribution * 0x100 );
		SCB->AIRCR = Local_u32NVICGroubSubDistribution ;
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK ;
	}
	return Local_u8ErrorState ;
}


/**
 ******************************************************************************
 * @fn             : MSCB_u8VectorTableAddress
 * @brief          : Relocate Vector Table Address
 * @param[in]      : Copy_u32VectorTableAddress --> Set Vector Table Relocate Address
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t   MSCB_u8VectorTableAddress ( uint32_t Copy_u32VectorTableAddress  )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( 1 )
	{
	    SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
	    SCB->VTOR = Copy_u32VectorTableAddress; /* Vector Table Relocation in Internal SRAM */
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK ;
	}
	return Local_u8ErrorState ;
}

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
