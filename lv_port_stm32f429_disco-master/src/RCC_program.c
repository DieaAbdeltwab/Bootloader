/**
 ******************************************************************************
 * @file           : RCC_program.c
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
#include "stm32f429xxx.h"
/******************************************************************************/
/************************ MCAL Layer ******************************************/
/******************************************************************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


/*************************************************************************************************************************************/
/********************************************************* Functions implementations *************************************************/
/*************************************************************************************************************************************/
/**
 ******************************************************************************
 * @fn             : MRCC_u8SetClockState
 * @brief          : Set Clock State
 * @param[in]      : Copy_ClockType  --> get option from @ClockType_t  enum
 * @param[in]      : Copy_ClockState --> get option from @ClockState_t enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t   MRCC_u8SetClockState		(  ClockType_t       Copy_ClockType , ClockState_t Copy_ClockState )
{
          uint8_t Local_u8ErrorState = ERROR_STATE_OK;
          if ( Copy_ClockType <= PLLSAI  &&  Copy_ClockState <= RCC_ENABLE )
          {
    		  uint32_t Local_u32TimeOut = 0 ;
              switch ( Copy_ClockType )
              {
              	  	  case HSI :  RCC->CR &=~( RCC_CLOCK_STATE_MASK<<(RCC_CR_HSION));
  	  	  	  	  	  	  	  	  RCC->CR |= (Copy_ClockState<<(RCC_CR_HSION));
  	  	  	  	  	  	  	  	  while( (  RCC_CLK_NOT_RDY == (RCC->CR >> RCC_CR_HSIRDY) & 0x1 ) && ( Local_u32TimeOut < RCC_TIME_OUT ) )
  	  	  	  	  	  	  	  	  {
  	  	  	  	  	  	  	  		  Local_u32TimeOut++;
  	  	  	  	  	  	  	  	  }
  	  	  	  	  	  	  	  	  if( Local_u32TimeOut >= RCC_TIME_OUT )
  	  	  	  	  	  	  	  	  {
  	  	  	  	  	  	  	  		  Local_u8ErrorState = ERROR_STATE_NOK;
  	  	  	  	  	  	  	  	  }
  	  	  	  	  	  	  	  	  break;

              	  	  case HSE :  RCC->CR &=~( RCC_CLOCK_STATE_MASK<<(RCC_CR_HSEON));
              	  	  	  	  	  RCC->CR |= (Copy_ClockState<<(RCC_CR_HSEON));
              	  	  	  	  	  while( (  RCC_CLK_NOT_RDY == (RCC->CR >> RCC_CR_HSERD) & 0x1 ) && ( Local_u32TimeOut < RCC_TIME_OUT ) )
              	  	  	  	  	  {
              	  	  	  	  		  	 Local_u32TimeOut++;
              	  	  	  	  	  }
              	  	  	  	  	  if( Local_u32TimeOut >= RCC_TIME_OUT )
              	  	  	  	  	  {
              	  	  	  	  		  	 Local_u8ErrorState = ERROR_STATE_NOK;
              	  	  	  	  	  }
              	  	  	  	  	  break;

              	  	  case PLL :  RCC->CR &=~( RCC_CLOCK_STATE_MASK<<(RCC_CR_PLLON));
              	  	  	  	  	  RCC->CR |= (Copy_ClockState<<(RCC_CR_PLLON));
              	  	  	  	  	  while( (  RCC_CLK_NOT_RDY == (RCC->CR >> RCC_CR_PLLRDY) & 0x1 ) && ( Local_u32TimeOut < RCC_TIME_OUT ) )
              	  	  	  	  	  {
              	  	  	  	  		  Local_u32TimeOut++;
              	  	  	  	  	  }
              	  	  	  	  	  if( Local_u32TimeOut >= RCC_TIME_OUT )
              	  	  	  	  	  {
              	  	  	  	  		  Local_u8ErrorState = ERROR_STATE_NOK;
              	  	  	  	  	  }
              	  	  	  	  	  break;
              	  	  case PLLI2S:RCC->CR &=~( RCC_CLOCK_STATE_MASK<<(RCC_CR_PLLI2SON));
              	  	  	  	  	  RCC->CR |= (Copy_ClockState<<(RCC_CR_PLLI2SON));
              	  	  	  	  	  while( (  RCC_CLK_NOT_RDY == (RCC->CR >> RCC_CR_PLLI2SRDY) & 0x1 ) && ( Local_u32TimeOut < RCC_TIME_OUT ) )
              	  	  	  	  	  {
              	  	  	  	  		  Local_u32TimeOut++;
              	  	  	  	  	  }
              	  	  	  	  	  if( Local_u32TimeOut >= RCC_TIME_OUT )
              	  	  	  	  	  {
              	  	  	  	  		  Local_u8ErrorState = ERROR_STATE_NOK;
              	  	  	  	  	  }
              	  	  	  	  	  break;
              	  	  case PLLSAI:RCC->CR &=~( RCC_CLOCK_STATE_MASK<<(RCC_CR_PLLSAION));
              	  	  	  	  	  RCC->CR |= (Copy_ClockState<<(RCC_CR_PLLSAION));
              	  	  	  	  	  while( (  RCC_CLK_NOT_RDY == (RCC->CR >> RCC_CR_PLLSAIRDY) & 0x1 ) && ( Local_u32TimeOut < RCC_TIME_OUT ) )
              	  	  	  	  	  {
              	  	  	  	  		  Local_u32TimeOut++;
              	  	  	  	  	  }
              	  	  	  	  	  if( Local_u32TimeOut >= RCC_TIME_OUT )
              	  	  	  	  	  {
              	  	  	  	  		  Local_u8ErrorState = ERROR_STATE_NOK;
              	  	  	  	  	  }
              	  	  	  	  	  break;
              	  	  default  :  Local_u8ErrorState = ERROR_STATE_NOK;
              	  	  	  	  	  break;
              }
          }
          else
          {
          	Local_u8ErrorState = ERROR_STATE_NOK;
          }
          return Local_u8ErrorState;
}
/**
 ******************************************************************************
 * @fn             : MRCC_u8HSEClockBypassConfiguration
 * @brief          : Set HSE Clock Bypass Configuration
 * @param[in]      : Copy_Bypass --> get option from @HSEBypass_t  enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t   MRCC_u8HSEClockBypassConfiguration   (  HSEBypass_t  Copy_Bypass  )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_Bypass <= BYP )
	{
	  	  RCC->CR &=~( RCC_HSE_BYP_MASK<<(RCC_CR_HSEBYP));
	  	  RCC->CR |= ( Copy_Bypass<<(RCC_CR_HSEBYP));
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK;
	}
	return Local_u8ErrorState;

}

/**
 ******************************************************************************
 * @fn             : MRCC_u8ClockSecurityState
 * @brief          : Set Clock Security State
 * @param[in]      : Copy_ClockState --> get option from @ClockSecuritySys_t    enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */

uint8_t MRCC_u8ClockSecurityState ( ClockSecuritySys_t Copy_ClockSecuritySys )
{
    uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_ClockSecuritySys <= SECURITY_ENABLE )
	{
		 RCC->CR &=~( RCC_CLOCK_SEC_MASK<<(RCC_CR_CSSON));
		 RCC->CR |= (Copy_ClockSecuritySys<<(RCC_CR_CSSON));
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK;
	}
	return Local_u8ErrorState;
}
/**
 ******************************************************************************
 * @fn             : MRCC_u8SetSystemClock
 * @brief          : Set System Clock
 * @param[in]      : Copy_ClockType  --> get option from @ClockType_t  enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *                 @ClockType_t ( HSE OR HSI OR PLL )
 *
 ******************************************************************************
 */
uint8_t   MRCC_u8SetSystemClock		(  ClockType_t       Copy_ClockType  )
{
          uint8_t Local_u8ErrorState = ERROR_STATE_OK;
          if ( Copy_ClockType <= PLL  )
          {
        	  	  RCC->CFGR &=~( RCC_SYS_CLOCK_MASK<<(RCC_CFGR_SW));
	  	  	  	  RCC->CFGR |= ( Copy_ClockType<<(RCC_CFGR_SW));
          }
          else
          {
          	Local_u8ErrorState = ERROR_STATE_NOK;
          }
          return Local_u8ErrorState;
}

/**
 ******************************************************************************
 * @fn             : MRCC_u8AHBClockPrescalerConfiguration
 * @brief          : Set AHB Clock Prescaler Configuration
 * @param[in]      : Copy_Prescaler  --> get option from @AHBprescaler_t   enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */

uint8_t   MRCC_u8AHBClockPrescalerConfiguration   (  AHBprescaler_t  Copy_Prescaler )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	uint8_t Local_u8Prescaler = Copy_Prescaler + RCC_HPRE_MIN ;
	if (   Copy_Prescaler <= SYS_CLK_DIV_512 )
	{
	  	  RCC->CFGR &=~( RCC_HPRE_MASK <<(RCC_CFGR_HPRE));
  	  	  RCC->CFGR |= ( Local_u8Prescaler <<(RCC_CFGR_HPRE));
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK;
	}
	return Local_u8ErrorState;
}
/**
 ******************************************************************************
 * @fn             : MRCC_u8APBClockPrescalerConfiguration
 * @brief          : Set APB Clock Prescaler Configuration
 * @param[in]      : Copy_ClockPRE  --> get option from @APBClockPRE_t   enum
 * @param[in]      : Copy_Prescaler --> get option from @APBprescaler_t  enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */

uint8_t   MRCC_u8APBClockPrescalerConfiguration   (  APBClockPRE_t  Copy_ClockPRE , APBprescaler_t  Copy_Prescaler )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	uint8_t Local_u8Prescaler = Copy_Prescaler + RCC_PPRE_MIN ;
    if ( Copy_ClockPRE == APB_LOW_SPEED  && Copy_Prescaler <= AHB_DIV_16 )
	{
	  	  RCC->CFGR &=~( RCC_PPRE_MASK <<(RCC_CFGR_PPRE1));
  	  	  RCC->CFGR |= ( Local_u8Prescaler <<(RCC_CFGR_PPRE1));
	}
	else if ( Copy_ClockPRE == APB_HIGH_SPEED && Copy_Prescaler <= AHB_DIV_16 )
	{
	  	  RCC->CFGR &=~( RCC_PPRE_MASK <<(RCC_CFGR_PPRE2));
  	  	  RCC->CFGR |= ( Local_u8Prescaler <<(RCC_CFGR_PPRE2));
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK;
	}
	return Local_u8ErrorState;
}
/**
 ******************************************************************************
 * @fn             : MRCC_u8PLLDivFactorConfiguration
 * @brief          : Set PLL Division Factor Configuration
 * @param[in]      : Copy_PLLtype  --> get option from @PLLtype_t    enum
 * @param[in]      : Copy_u8PLLdiv  --> Set  Division Factor
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *                  2 ≤ PLLR ≤ 7
 *					2 ≤ PLLQ ≤ 15
 *					PLLP = 2, 4, 6, or 8
 *					2 ≤ PLLM ≤ 63
 *
 ******************************************************************************
 */

uint8_t   MRCC_u8PLLDivFactorConfiguration   (  PLLtype_t  Copy_PLLtype , uint8_t  Copy_u8PLLdiv )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_PLLtype == PLLM &&  Copy_u8PLLdiv <= RCC_DIVF_PLLM_MAX &&  Copy_u8PLLdiv >= RCC_DIVF_MIN )
	{
	  	  RCC->PLLCFGR &=~( RCC_DIVF_PLLM_MASK<<(RCC_PLLCFGR_PLLM));
  	  	  RCC->PLLCFGR |= ( Copy_u8PLLdiv<<(RCC_PLLCFGR_PLLM));
	}
	else if ( Copy_PLLtype == PLLP &&  Copy_u8PLLdiv <= RCC_DIVF_PLLP_MAX  )
	{
		  Copy_u8PLLdiv = (float)(Copy_u8PLLdiv / 2.5);
	  	  RCC->PLLCFGR &=~( RCC_DIVF_PLLP_MASK<<(RCC_PLLCFGR_PLLP));
	  	  RCC->PLLCFGR |= ( Copy_u8PLLdiv<<(RCC_PLLCFGR_PLLP));
	}
	else if ( Copy_PLLtype == PLLQ &&  Copy_u8PLLdiv <= RCC_DIVF_PLLQ_MAX &&  Copy_u8PLLdiv >= RCC_DIVF_MIN )
	{
	  	  RCC->PLLCFGR &=~( RCC_DIVF_PLLQ_MASK<<(RCC_PLLCFGR_PLLQ));
	  	  RCC->PLLCFGR |= ( Copy_u8PLLdiv<<(RCC_PLLCFGR_PLLQ));
	}
	else if ( Copy_PLLtype == PLLR &&  Copy_u8PLLdiv <= RCC_DIVF_PLLR_MAX &&  Copy_u8PLLdiv >= RCC_DIVF_MIN )
	{
	  	  RCC->PLLCFGR &=~( RCC_DIVF_PLLR_MASK<<(RCC_PLLCFGR_PLLR));
	  	  RCC->PLLCFGR |= ( Copy_u8PLLdiv<<(RCC_PLLCFGR_PLLR));
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK;
	}
	return Local_u8ErrorState;
}
/**
 ******************************************************************************
 * @fn             : MRCC_u8PLLNMulFactorConfiguration
 * @brief          : Set PLLN Multiplication Factor
 * @param[in]      : Copy_u8PLLmul    --> Set  Multiplication Factor
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *					50 ≤ PLLN ≤ 432
 *
 ******************************************************************************
 */
uint8_t   MRCC_u8PLLNMulFactorConfiguration   (  uint8_t  Copy_u8PLLmul  )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_u8PLLmul <= RCC_MULF_PLLN_MAX &&  Copy_u8PLLmul >= RCC_MULF_PLLN_MIN )
	{
	  	  RCC->PLLCFGR &=~( RCC_MULF_PLLN_MASK<<(RCC_PLLCFGR_PLLN));
	  	  RCC->PLLCFGR |= ( Copy_u8PLLmul<<(RCC_PLLCFGR_PLLN));
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK;
	}
	return Local_u8ErrorState;

}
/**
 ******************************************************************************
 * @fn             : MRCC_u8PLLConfiguration
 * @brief          : Set PLL Configuration
 * @param[in]      : Copy_PLLmul    --> get option from @PLLmul_t    enum
 * @param[in]      : Copy_PLLinput  --> get option from @PLLinput_t  enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t   MRCC_u8PLLInputConfiguration   (  PLLinput_t Copy_PLLinput )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_PLLinput <= PLL_HSE )
	{
		RCC->PLLCFGR &=~( RCC_PLL_INPUT_MASK<<(RCC_PLLCFGR_PLLSRC));
		RCC->PLLCFGR |= (Copy_PLLinput<<(RCC_PLLCFGR_PLLSRC));
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK;
	}
	return Local_u8ErrorState;
}

/**
 ******************************************************************************
 * @fn             : MRCC_u8PeripheralsClockState
 * @brief          : Set Clock State on AHB , APB1 &APB2 Peripherals
 * @param[in]      : Copy_PerID      --> get option from @BUSS_t , @APB1pe   enum
 * @param[in]      : Copy_PerID      --> get option from @AHBperipherals_t , @APB1peripherals_t & @APB2peripherals_t  enum
 * @param[in]      : Copy_ClockState --> get option from @ClockState_t       enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t   MRCC_u8PeripheralsClockState     (  BUSS_t Copy_Bus , uint8_t  Copy_PerID , ClockState_t Copy_ClockState )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_Bus<=APB2  && Copy_PerID <= PER_DAC &&  Copy_ClockState <= RCC_ENABLE )
	{
		switch ( Copy_Bus )
		{
			case AHB1 : RCC->AHB1ENR &=~( RCC_CLOCK_STATE_MASK<<(Copy_PerID));
					    RCC->AHB1ENR |= (Copy_ClockState)<<(Copy_PerID);
					    break;
			case AHB2 : RCC->AHB2ENR &=~( RCC_CLOCK_STATE_MASK<<(Copy_PerID));
					    RCC->AHB2ENR |= (Copy_ClockState)<<(Copy_PerID);
					    break;
			case AHB3 : RCC->AHB3ENR &=~( RCC_CLOCK_STATE_MASK<<(Copy_PerID));
					    RCC->AHB3ENR |= (Copy_ClockState)<<(Copy_PerID);
					    break;
			case APB1 : RCC->APB1ENR &=~( RCC_CLOCK_STATE_MASK<<(Copy_PerID));
					    RCC->APB1ENR |= (Copy_ClockState)<<(Copy_PerID);
					    break;
			case APB2 : RCC->APB2ENR &=~( RCC_CLOCK_STATE_MASK<<(Copy_PerID));
					    RCC->APB2ENR |= (Copy_ClockState)<<(Copy_PerID);
					    break;
			default  :  Local_u8ErrorState = ERROR_STATE_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK;
	}
	return Local_u8ErrorState;
}

/**
 ******************************************************************************
 * @fn             : MRCC_u8AHB1PeripheralsClockState
 * @brief          : Set Clock State on AHB Peripherals
 * @param[in]      : Copy_PerID      --> get option from @AHB1peripherals_t enum
 * @param[in]      : Copy_ClockState --> get option from @ClockState_t      enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t   MRCC_u8AHB1PeripheralsClockState     (  AHB1peripherals_t  Copy_PerID , ClockState_t Copy_ClockState )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_PerID <= PER_OTGHSULPI &&  Copy_ClockState <= RCC_ENABLE )
	{
		RCC->AHB1ENR &=~( RCC_CLOCK_STATE_MASK<<(Copy_PerID));
		RCC->AHB1ENR |= (Copy_ClockState)<<(Copy_PerID);
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK;
	}
	return Local_u8ErrorState;
}
/**
 ******************************************************************************
 * @fn             : MRCC_u8AHB2PeripheralsClockState
 * @brief          : Set Clock State on AHB Peripherals
 * @param[in]      : Copy_PerID      --> get option from @AHB2peripherals_t enum
 * @param[in]      : Copy_ClockState --> get option from @ClockState_t      enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t   MRCC_u8AHB2PeripheralsClockState     (  AHB2peripherals_t  Copy_PerID , ClockState_t Copy_ClockState )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_PerID <= PER_OTGFS &&  Copy_ClockState <= RCC_ENABLE )
	{
		RCC->AHB2ENR &=~( RCC_CLOCK_STATE_MASK<<(Copy_PerID));
		RCC->AHB2ENR |= (Copy_ClockState)<<(Copy_PerID);
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK;
	}
	return Local_u8ErrorState;
}
/**
 ******************************************************************************
 * @fn             : MRCC_u8AHB2PeripheralsClockState
 * @brief          : Set Clock State on AHB Peripherals
 * @param[in]      : Copy_PerID      --> get option from @AHB2peripherals_t enum
 * @param[in]      : Copy_ClockState --> get option from @ClockState_t      enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t   MRCC_u8AHB3PeripheralsClockState     (  AHB3peripherals_t  Copy_PerID , ClockState_t Copy_ClockState )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_PerID <= PER_FMC &&  Copy_ClockState <= RCC_ENABLE )
	{
		RCC->AHB3ENR &=~( RCC_CLOCK_STATE_MASK<<(Copy_PerID));
		RCC->AHB3ENR |= (Copy_ClockState)<<(Copy_PerID);
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK;
	}
	return Local_u8ErrorState;
}
/**
 ******************************************************************************
 * @fn             : MRCC_u8APB1PeripheralsClockState
 * @brief          : Set Clock State on APB1 Peripherals
 * @param[in]      : Copy_PerID      --> get option from @APB1peripherals_t enum
 * @param[in]      : Copy_ClockState --> get option from @ClockState_t      enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t   MRCC_u8APB1PeripheralsClockState    (  APB1peripherals_t Copy_PerID , ClockState_t Copy_ClockState )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_PerID <= PER_UART8 &&  Copy_ClockState <= RCC_ENABLE )
	{
		RCC->APB1ENR &=~( RCC_CLOCK_STATE_MASK<<(Copy_PerID));
		RCC->APB1ENR |= (Copy_ClockState)<<(Copy_PerID);
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK;
	}
	return Local_u8ErrorState;
}

/**
 ******************************************************************************
 * @fn             : MRCC_u8APB1PeripheralsClockState
 * @brief          : Set Clock State on APB2 Peripherals
 * @param[in]      : Copy_PerID      --> get option from @APB2peripherals_t enum
 * @param[in]      : Copy_ClockState --> get option from @ClockState_t      enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t   MRCC_u8APB2PeripheralsClockState    (  APB2peripherals_t Copy_PerID , ClockState_t Copy_ClockState )
{
	uint8_t Local_u8ErrorState = ERROR_STATE_OK;
	if ( Copy_PerID <= PER_LTDC &&  Copy_ClockState <= RCC_ENABLE )
	{
		RCC->APB2ENR &=~( RCC_CLOCK_STATE_MASK<<(Copy_PerID));
		RCC->APB2ENR |= (Copy_ClockState)<<(Copy_PerID);
	}
	else
	{
		Local_u8ErrorState = ERROR_STATE_NOK;
	}
	return Local_u8ErrorState;
}

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
