/**
 ******************************************************************************
 * @file           : RCC_interface.h
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
#ifndef  RCC_INTERFACE_H
#define  RCC_INTERFACE_H
/************************************************************************************/
/******************************* @ClockType_t ***************************************/
/************************************************************************************/
typedef enum{
	        HSI  =0,
  	        HSE    ,
	        PLL    ,
			PLLI2S ,
			PLLSAI
}ClockType_t;
/************************************************************************************/
/***************************** @ClockState_t ****************************************/
/************************************************************************************/
typedef enum{
			DISABLE=0,
			ENABLE

}ClockState_t;
/************************************************************************************/
/******************************** @HSEBypass_t **************************************/
/************************************************************************************/
typedef enum{
			NOT_BYP =0,
	        BYP
}HSEBypass_t;
/*******************************************************************************************/
/***************************** @ClockSecuritySys_t *****************************************/
/*******************************************************************************************/
typedef enum{
			SECURITY_DISABLE=0,
			SECURITY_ENABLE
}ClockSecuritySys_t;
/************************************************************************************/
/******************************** @AHBprescaler_t ***********************************/
/************************************************************************************/
typedef enum{
			SYS_CLK_DIV_2 =0,
			SYS_CLK_DIV_4   ,
			SYS_CLK_DIV_8   ,
			SYS_CLK_DIV_16  ,
			SYS_CLK_DIV_64  ,
			SYS_CLK_DIV_128  ,
			SYS_CLK_DIV_256  ,
			SYS_CLK_DIV_512

}AHBprescaler_t;
/************************************************************************************/
/******************************** @APBClockPRE_t ***********************************/
/************************************************************************************/
typedef enum{
	        APB_LOW_SPEED ,
			APB_HIGH_SPEED
}APBClockPRE_t;
/************************************************************************************/
/******************************** @APBprescaler_t ***********************************/
/************************************************************************************/
typedef enum{
			AHB_DIV_2 =0,
			AHB_DIV_4   ,
			AHB_DIV_8   ,
			AHB_DIV_16
}APBprescaler_t;
/************************************************************************************/
/******************************* @PLLtype_t ***************************************/
/************************************************************************************/
typedef enum{
			PLLM  =0,
			PLLP    ,
			PLLQ    ,
			PLLR
}PLLtype_t;
/************************************************************************************/
/******************************** @PLLinput_t ***************************************/
/************************************************************************************/
typedef enum{
		    PLL_HSI =0,
		    PLL_HSE
}PLLinput_t;
/******************************************************************************/
/************************ @BUSS_t *********************************************/
/******************************************************************************/
typedef enum{
			 AHB1=0,
			 AHB2 ,
			 AHB3 ,
             APB1 ,
             APB2
}BUSS_t;
/******************************************************************************/
/************************* @AHB1peripherals_t **********************************/
/******************************************************************************/
typedef enum{
			PER_GPIOA        =0,
			PER_GPIOB          ,
			PER_GPIOC          ,
			PER_GPIOD          ,
			PER_GPIOE          ,
			PER_GPIOF          ,
			PER_GPIOG          ,
			PER_GPIOH          ,
			PER_GPIOJ          ,
			PER_GPIOK          ,
			PER_CRC         =12,
			PER_BKPSRAM     =18,
			PER_CCMDATARAM  =20,
			PER_DMA1           ,
			PER_DMA2           ,
			PER_DMA2D          ,
			PER_ETHMAC      =25,
			PER_ETHMACTX       ,
			PER_ETHMACRX       ,
			PER_ETHMACPTP      ,
			PER_OTGHS          ,
			PER_OTGHSULPI 
}AHB1peripherals_t;
/******************************************************************************/
/************************* @AHB2peripherals_t **********************************/
/******************************************************************************/
typedef enum{
			PER_DCMI     =0,
			PER_CRYP     =4,
			PER_HASH       ,
			PER_RNG        ,
			PER_OTGFS
}AHB2peripherals_t;
/******************************************************************************/
/************************* @AHB3peripherals_t **********************************/
/******************************************************************************/
typedef enum{
			PER_FMC      =0,
}AHB3peripherals_t;
/******************************************************************************/
/************************* @APB1peripherals_t *********************************/
/******************************************************************************/
typedef enum{
			PER_TIM2             =0,
			PER_TIM3               ,
			PER_TIM4               ,
			PER_TIM5               ,
			PER_TIM6               ,
			PER_TIM7               ,
			PER_TIM12              ,
			PER_TIM13              ,
			PER_TIM14              ,
			PER_WWDG            =11,
			PER_SPI2            =14,
			PER_SPI3               ,
			PER_UART2           =17,
			PER_UART3              ,
			PER_UART4              ,
			PER_UART5              ,
			PER_I2C1               ,
			PER_I2C2               ,
			PER_I2C3               ,
			PER_CAN1            =25,
			PER_CAN2               ,
			PER_PWR             =28,
			PER_DAC                ,
			PER_UART7              ,
			PER_UART8

			
}APB1peripherals_t;
/******************************************************************************/
/************************* @APB2peripherals_t *********************************/
/******************************************************************************/
typedef enum{
			PER_TIM1             =0,
			PER_TIM8               ,
			PER_USART1           =4,
			PER_USART6             ,
			PER_ADC1             =8,
			PER_ADC2               ,
			PER_ADC3               ,
			PER_SDIO               ,
			PER_SPI1               ,
			PER_SPI4               ,
			PER_SYSCFG             ,
			PER_TIM9            =16,
			PER_TIM10              ,
			PER_TIM11              ,
			PER_SPI5            =20,
			PER_SPI6               ,
			PER_SAI1               ,
			PER_LTDC            =26,
}APB2peripherals_t;

/*************************************************************************************************************************************/
/********************************************************* Functions Prototype *******************************************************/
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
uint8_t   MRCC_u8SetClockState		(  ClockType_t       Copy_ClockType , ClockState_t Copy_ClockState );
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
uint8_t   MRCC_u8HSEClockBypassConfiguration   (  HSEBypass_t  Copy_Bypass  );

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

uint8_t MRCC_u8ClockSecurityState ( ClockSecuritySys_t Copy_ClockSecuritySys );
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
uint8_t   MRCC_u8SetSystemClock		(  ClockType_t       Copy_ClockType  );
/**
 ******************************************************************************
 * @fn             : MRCC_u8AHBClockPrescalerConfiguration
 * @brief          : Set AHB Clock Prescaler Configuration
 * @param[in]      : Copy_u8Prescaler  --> get option from @AHBprescaler_t   enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */

uint8_t   MRCC_u8AHBClockPrescalerConfiguration   (  AHBprescaler_t  Copy_u8Prescaler );
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

uint8_t   MRCC_u8APBClockPrescalerConfiguration   (  APBClockPRE_t  Copy_ClockPRE , APBprescaler_t  Copy_Prescaler );
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

uint8_t   MRCC_u8PLLDivFactorConfiguration   (  PLLtype_t  Copy_PLLtype , uint8_t  Copy_u8PLLdiv );
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
uint8_t   MRCC_u8PLLNMulFactorConfiguration   (  uint8_t  Copy_u8PLLmul  );
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
uint8_t   MRCC_u8PLLInputConfiguration   (  PLLinput_t Copy_PLLinput );

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
uint8_t   MRCC_u8PeripheralsClockState     (  BUSS_t Copy_Bus , uint8_t  Copy_PerID , ClockState_t Copy_ClockState );
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
uint8_t   MRCC_u8AHB1PeripheralsClockState     (  AHB1peripherals_t  Copy_PerID , ClockState_t Copy_ClockState );
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
uint8_t   MRCC_u8AHB2PeripheralsClockState     (  AHB2peripherals_t  Copy_PerID , ClockState_t Copy_ClockState );
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
uint8_t   MRCC_u8AHB3PeripheralsClockState     (  AHB3peripherals_t  Copy_PerID , ClockState_t Copy_ClockState );
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
uint8_t   MRCC_u8APB1PeripheralsClockState    (  APB1peripherals_t Copy_PerID , ClockState_t Copy_ClockState );

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
uint8_t   MRCC_u8APB2PeripheralsClockState    (  APB2peripherals_t Copy_PerID , ClockState_t Copy_ClockState );


/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/


#endif
