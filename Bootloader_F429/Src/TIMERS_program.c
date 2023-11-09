/**
 ******************************************************************************
 * @file           : TIMERS_program.c
 * @author         : Diea Abdeltwab
 * @layer          : SERVIES
 * @brief          : Version 1 For STM32F103C8T6 Drivers
 * @date           : 19/9/2023
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
/******************************************************************************/
/************************ MCAL Layer ******************************************/
/******************************************************************************/
#include "GPTIMER_interface.h"

/******************************************************************************/
/************************ HAL Layer *******************************************/
/******************************************************************************/

/******************************************************************************/
/************************ SERVIES Layer ***************************************/
/******************************************************************************/
#include "TIMERS_interface.h"
#include "TIMERS_config.h"
#include "TIMERS_private.h"
/******************************************************************************/
/************************ Global **********************************************/
/******************************************************************************/


/*************************************************************************************************************************************/
/********************************************************* Functions implementations *************************************************/
/*************************************************************************************************************************************/

/**
 ******************************************************************************
 * @fn             : TIMERS_voidDelayMS
 * @brief          : Delay Milliseconds
 * @param[in]      : Copy_u32Milliseconds --> Set Time MS
 * @retval         : void
 ******************************************************************************
 * @attention
 *   This Function not Depend on Any timer , This Dumb Function
 *
 ******************************************************************************
 */

void STIMERS_voidDelayMS(uint32_t Copy_u32Milliseconds)
{
	double Local_u32Milliseconds=Copy_u32Milliseconds;
	double Local_u32ProcessingTimeTemp=(160.5/16000);
    while( Local_u32Milliseconds > Local_u32ProcessingTimeTemp)
    {
    	Local_u32Milliseconds=Local_u32Milliseconds-Local_u32ProcessingTimeTemp;
    }
}

/**
 ******************************************************************************
 * @fn             : MGPTIMER_u8GeneratePWM
 * @brief          : Set Counter
 * @param[in]      : Copy_GPTIMERindex  --> get option from @GPTIMERindex_t enum
 * @param[in]      : Copy_Channelindex  --> get option from @Channelindex_t enum
 * @param[in]      : Copy_u16frequencyValue --> Set frequency Value 50000
 * @param[in]      : Copy_u16DutyCycleValue --> Set Duty Value      20
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *  this Function set Prescaler  1024
 *
 ******************************************************************************
 */
uint8_t  STIMERS_u8GeneratePWM ( GPTIMERindex_t Copy_GPTIMERindex ,  Channelindex_t Copy_Channelindex , uint16_t Copy_u16Prescaler ,uint16_t Copy_u16frequencyValue , uint8_t Copy_u8DutyCycleValue )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK ;
	if ( Copy_GPTIMERindex <= TMR_5   )
	{
		uint16_t Local_u8Temp = F_COLCK / Copy_u16Prescaler;
		 uint16_t AutoReload   = (uint16_t)((Local_u8Temp * 1000)  /    (Copy_u16frequencyValue));
		 uint16_t CompareValue = (uint16_t)((Copy_u8DutyCycleValue)*AutoReload/(100));

		 MGPTIMER_u8SetPrescaler    ( Copy_GPTIMERindex , Copy_u16Prescaler );
		 MGPTIMER_u8SetAutoReload   ( Copy_GPTIMERindex , AutoReload );
		 MGPTIMER_u8SetChannelOutput( Copy_GPTIMERindex , Copy_Channelindex ,  OCM_PWM_MODE1 , OCPE_ENABLE  );
		 MGPTIMER_u8SetCompareValue ( Copy_GPTIMERindex , Copy_Channelindex , CompareValue);
		 MGPTIMER_u8CounterStatus   ( Copy_GPTIMERindex , COUNTER_ENABLE );
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK ;
	}
	return Local_u8ErrorState ;
}
/**
 ******************************************************************************
 * @fn             : MGPTIMER_u8SetPeriodicInterval
 * @brief          : Set Interval Counter
 * @param[in]      : Copy_GPTIMERindex  --> get option from @GPTIMERindex_t enum
 * @param[in]      : Copy_u32Ticks -->  Set Number of ticks  uint32_t
 * @param[  ]      : Copy_pFun         --> Set Call back function
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 * this Function set Prescaler  1024
 *
 ******************************************************************************
 */
uint8_t STIMERS_u8SetPeriodicInterval   ( GPTIMERindex_t Copy_GPTIMERindex , uint16_t Copy_u16Prescaler , uint32_t Copy_u32Ticks , void(*Copy_pFun)(void) )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK ;
	if ( Copy_GPTIMERindex <= TMR_5 && Copy_pFun != NULL )
	{

		MGPTIMER_u8SetAutoReload          ( Copy_GPTIMERindex  , Copy_u32Ticks );
		MGPTIMER_u8SetPrescaler           ( Copy_GPTIMERindex  , Copy_u16Prescaler );
		MGPTIMER_u8SetCallBack            ( Copy_GPTIMERindex  , Copy_pFun );
		MGPTIMER_u8CompareInterruptStatus ( Copy_GPTIMERindex  , CCIE_1  , CCIE_ENABLE  );
		MGPTIMER_u8CounterStatus          ( Copy_GPTIMERindex  , COUNTER_ENABLE );
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK ;
	}
	return Local_u8ErrorState ;
}
/*************************************************************************************************************************************/
/********************************************************* Static Functions implementations ******************************************/
/*************************************************************************************************************************************/

/*************************************************************************************************************************************/
/********************************************************* Handlers implementations **************************************************/
/*************************************************************************************************************************************/

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
