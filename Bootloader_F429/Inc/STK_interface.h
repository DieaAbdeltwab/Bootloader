/**
 ******************************************************************************
 * @file           : STK_interface.h
 * @author         : Diea Abdeltwab
 * @layer          : MCAL (Core Peripherals )
 * @brief          : Version 1 For STM32F446 Drivers
 * @date           : 1/8/2023
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
#ifndef  STK_INTERFACE_H
#define  STK_INTERFACE_H

/******************************************************************************/
/************************ @STKclock_t *****************************************/
/******************************************************************************/
typedef enum{
			STK_AHB_DIV_8=0,
			STK_AHB
}STKclock_t;
/******************************************************************************/
/************************ @Interval_t *****************************************/
/******************************************************************************/
typedef enum{
			SINGLE=0,
			PERIODIC
}Interval_t;


/*************************************************************************************************************************************/
/********************************************************* Functions Prototype *******************************************************/
/*************************************************************************************************************************************/
/**
 ******************************************************************************
 * @fn             : MSTK_u8ClockConfig
 * @brief          : Set STK Clock
 * @param[in]      : Copy_ClockType --> get option from @STKclock_t  enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t MSTK_u8ClockConfig              ( STKclock_t Copy_ClockType );
/**
 ******************************************************************************
 * @fn             : MSTK_voidStopTimer
 * @brief          : Stop Counter
 * @param          : void
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void   MSTK_voidStopTimer         ( void );
/**
 ******************************************************************************
 * @fn             : MSTK_u8BusyWait
 * @brief          : Busy Wait Counter
 * @param[in]      : Copy_u32Ticks --> Set Number of ticks  uint32_t
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t   MSTK_u8BusyWait            ( uint32_t Copy_u32Ticks );
/**
 ******************************************************************************
 * @fn             : STK_u8Delayms
 * @brief          : Delay Timer
 * @param[in]      : Copy_u32TimeMs --> Set time in Ms    uint32_t
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 * STK Clock Must be STK_AHB_DIV_8
 *
 ******************************************************************************
 */
uint8_t   STK_u8Delayms            ( uint32_t Copy_u32TimeMs );
/**
 ******************************************************************************
 * @fn             : MSTK_u8SetInterval
 * @brief          : Set Interval Counter
 * @param[in]      : Copy_u32Ticks -->  Set Number of ticks  uint32_t
 * @param[in]      : Copy_IntervalType --> get option from @Interval_t  enum
 * @param[  ]      : Copy_pFun         --> Set Call back function
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t   MSTK_u8SetInterval   ( uint32_t Copy_u32Ticks , Interval_t Copy_IntervalType ,void (* Copy_pFun)(void) );
/**
 ******************************************************************************
 * @fn             : MSTK_voidStopInterval
 * @brief          : Stop Interval
 * @param          : void
 * @retval         : void
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
void   MSTK_voidStopInterval         ( void );
/**
 ******************************************************************************
 * @fn             : MSTK_u8GetElapsedTime
 * @brief          : Get Elapsed Counter
 * @param[OUT]     : Copy_pu32Ticks -->  Get Number of ticks  uint32_t
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t   MSTK_u8GetElapsedTime      ( uint32_t * Copy_pu32Ticks );
/**
 ******************************************************************************
 * @fn             : MSTK_u8GetReminingTime
 * @brief          : Get Remining Counter
 * @param[OUT]     : Copy_pu32Ticks -->  Get Number of ticks  uint32_t
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t   MSTK_u8GetReminingTime     ( uint32_t * Copy_pu32Ticks );
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/





#endif
