/**
 ******************************************************************************
 * @file           : stm32f103xx.h
 * @author         : Diea Abdeltwab
 * @brief          : Version 1 For STM32F103C8T6 Drivers
 * @date           : 25/3/2023
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
#ifndef STM32F446re_h
#define STM32F446re_h
/************************************************************************************************/
/******************************** RCC Registers *************************************************/
/************************************************************************************************/
#define RCC_BASE_ADDRESS                              0x40023800UL

typedef struct
{
  volatile uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  volatile uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  volatile uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  volatile uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  volatile uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  volatile uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  volatile uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
  volatile uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
  volatile uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  volatile uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  volatile uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
  volatile uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  volatile uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  volatile uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  volatile uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  volatile uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  volatile uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  volatile uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  volatile uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  volatile uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  volatile uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  volatile  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  volatile uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  volatile uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  volatile uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  volatile uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  volatile uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  volatile uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  volatile uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  volatile uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
  volatile uint32_t PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                           Address offset: 0x88 */
  volatile uint32_t DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */

}RCC_REG;

#define RCC                              ((RCC_REG*)RCC_BASE_ADDRESS)

/************************************************************************************************/
/************************************* GPIO Registers *******************************************/
/************************************************************************************************/
#define GPIOA_BASE_ADDRESS		0X40020000UL
#define GPIOB_BASE_ADDRESS		0X40020400UL
#define GPIOC_BASE_ADDRESS		0X40020800UL
#define GPIOD_BASE_ADDRESS		0X40020C00UL
#define GPIOE_BASE_ADDRESS		0X40021000UL
#define GPIOF_BASE_ADDRESS		0X40021400UL
#define GPIOG_BASE_ADDRESS		0X40021800UL
#define GPIOH_BASE_ADDRESS		0X40021C00UL

typedef struct
{
  volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  volatile uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  volatile uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  volatile uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
}GPIO_TypeDef;

#define GPIOA			                ((GPIO_TypeDef*)GPIOA_BASE_ADDRESS)
#define GPIOB							((GPIO_TypeDef*)GPIOB_BASE_ADDRESS)
#define GPIOC							((GPIO_TypeDef*)GPIOC_BASE_ADDRESS)
#define GPIOD							((GPIO_TypeDef*)GPIOD_BASE_ADDRESS)
#define GPIOE							((GPIO_TypeDef*)GPIOE_BASE_ADDRESS)
#define GPIOF							((GPIO_TypeDef*)GPIOF_BASE_ADDRESS)
#define GPIOG							((GPIO_TypeDef*)GPIOG_BASE_ADDRESS)
#define GPIOH							((GPIO_TypeDef*)GPIOH_BASE_ADDRESS)
/************************************************************************************************/
/********************************* SYSTICK Registers ********************************************/
/************************************************************************************************/
#define STK_BASE_ADDRESS                                  0xE000E010UL


typedef struct
{
	volatile uint32_t CTRL;
	volatile uint32_t LOAD;
	volatile uint32_t VAL;
	volatile uint32_t CALIB;
}STK_REG;

#define STK                                  ((STK_REG*)STK_BASE_ADDRESS)

/************************************************************************************************/
/******************************** NVIC Registers ************************************************/
/************************************************************************************************/
#define NVIC_u32_BASE_ADDRESS                               0xE000E100UL

typedef struct
{
	volatile uint32_t ISER[8];		/*Interrupt set-enable register*/
	uint32_t Reserved1[24];
	volatile uint32_t ICER[8];		/*Interrupt clear-enable register*/
	uint32_t Reserved[24];
	volatile uint32_t ISPR[8];		/*Interrupt set-pending register*/
	uint32_t Reserved2[24];
	volatile uint32_t ICPR[8];		/*Interrupt clear-pending register*/
	uint32_t Reserved4[24];
	volatile uint32_t IABR[8];		/*Interrupt active bit register*/
	uint32_t Reserved3[32];
	volatile uint8_t IPR[240];		/*Interrupt priority register*/
}NVIC_REG;

#define NVIC                                  ((NVIC_REG*)NVIC_u32_BASE_ADDRESS)
/************************************************************************************************/
/******************************** SCB Registers *************************************************/
/************************************************************************************************/
#define SCB_BASE                                 0xE000ED00UL               /*!< System Control Block Base Address */


typedef struct{
	  volatile  uint32_t CPUID;                   /*!< Offset: 0x000 (R/ )  CPUID Base Register                                   */
	  volatile uint32_t ICSR;                    /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register                  */
	  volatile uint32_t VTOR;                    /*!< Offset: 0x008 (R/W)  Vector Table Offset Register                          */
	  volatile uint32_t AIRCR;                   /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register      */
	  volatile uint32_t SCR;                     /*!< Offset: 0x010 (R/W)  System Control Register                               */
	  volatile uint32_t CCR;                     /*!< Offset: 0x014 (R/W)  Configuration Control Register                        */
	  volatile uint8_t  SHP[12];                 /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
	  volatile uint32_t SHCSR;                   /*!< Offset: 0x024 (R/W)  System Handler Control and State Register             */
	  volatile uint32_t CFSR;                    /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register                    */
	  volatile uint32_t HFSR;                    /*!< Offset: 0x02C (R/W)  HardFault Status Register                             */
	  volatile uint32_t DFSR;                    /*!< Offset: 0x030 (R/W)  Debug Fault Status Register                           */
	  volatile uint32_t MMFAR;                   /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register                      */
	  volatile uint32_t BFAR;                    /*!< Offset: 0x038 (R/W)  BusFault Address Register                             */
	  volatile uint32_t AFSR;                    /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register                       */
	  volatile  uint32_t PFR[2];                  /*!< Offset: 0x040 (R/ )  Processor Feature Register                            */
	  volatile  uint32_t DFR;                     /*!< Offset: 0x048 (R/ )  Debug Feature Register                                */
	  volatile  uint32_t ADR;                     /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register                            */
	  volatile  uint32_t MMFR[4];                 /*!< Offset: 0x050 (R/ )  Memory Model Feature Register                         */
	  volatile  uint32_t ISAR[5];                 /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register                   */
	       uint32_t RESERVED0[5];
	  volatile uint32_t CPACR;                   /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register                   */

}SCB_Type;

#define SCB                 ((SCB_Type       *)     SCB_BASE      )   /*!< SCB configuration struct */
/************************************************************************************************/
/********************************* SYSCFG Registers *********************************************/
/************************************************************************************************/
#define SYSCFG_BASE_ADDRESS		        0x40013800UL

typedef struct
{
  volatile  uint32_t MEMRMP;       /*!< SYSCFG memory remap register,                      Address offset: 0x00      */
  volatile  uint32_t PMC;          /*!< SYSCFG peripheral mode configuration register,     Address offset: 0x04      */
  volatile  uint32_t EXTICR[4];    /*!< SYSCFG external interrupt configuration registers, Address offset: 0x08-0x14 */
  volatile  uint32_t RESERVED[2];  /*!< Reserved, 0x18-0x1C                                                          */
  volatile  uint32_t CMPCR;        /*!< SYSCFG Compensation cell control register,         Address offset: 0x20      */ 

}SYSCFG_RegDef_t;

#define SYSCFG					((SYSCFG_RegDef_t*)SYSCFG_BASE_ADDRESS)

/************************************************************************************************/
/********************************* EXTI Registers ***********************************************/
/************************************************************************************************/
#define EXTI_u32_BASE_ADDRESS                0x40013C00U

typedef struct
{
  volatile uint32_t IMR;    /*!< EXTI Interrupt mask register,            Address offset: 0x00 */
  volatile uint32_t EMR;    /*!< EXTI Event mask register,                Address offset: 0x04 */
  volatile uint32_t RTSR;   /*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
  volatile uint32_t FTSR;   /*!< EXTI Falling trigger selection register, Address offset: 0x0C */
  volatile uint32_t SWIER;  /*!< EXTI Software interrupt event register,  Address offset: 0x10 */
  volatile uint32_t PR;     /*!< EXTI Pending register,                   Address offset: 0x14 */
}EXTI_TypeDef;

#define EXTI                                  ((EXTI_TypeDef*)EXTI_u32_BASE_ADDRESS)
/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
#define USART1_u32_BASE_ADDRESS                                0x40011000U
#define USART2_u32_BASE_ADDRESS                                0x40004400U
#define USART3_u32_BASE_ADDRESS                                0x40004800U
#define  UART4_u32_BASE_ADDRESS                                0x40004C00U
#define  UART5_u32_BASE_ADDRESS                                0x40005000U
#define USART6_u32_BASE_ADDRESS                                0x40011400U

typedef struct
{
	volatile uint32_t SR;         /*!< USART Status register,                   Address offset: 0x00 */
	volatile uint32_t DR;         /*!< USART Data register,                     Address offset: 0x04 */
	volatile uint32_t BRR;        /*!< USART Baud rate register,                Address offset: 0x08 */
	volatile uint32_t CR1;        /*!< USART Control register 1,                Address offset: 0x0C */
	volatile uint32_t CR2;        /*!< USART Control register 2,                Address offset: 0x10 */
	volatile uint32_t CR3;        /*!< USART Control register 3,                Address offset: 0x14 */
	volatile uint32_t GTPR;       /*!< USART Guard time and prescaler register, Address offset: 0x18 */
} USART_TypeDef;


#define  USART1                     ( (  USART_TypeDef *) USART1_u32_BASE_ADDRESS )
#define  USART2                     ( (  USART_TypeDef *) USART2_u32_BASE_ADDRESS )
#define  USART3                     ( (  USART_TypeDef *) USART3_u32_BASE_ADDRESS )
#define   UART4                     ( (  USART_TypeDef *) UART4_u32_BASE_ADDRESS  )
#define   UART5                     ( (  USART_TypeDef *) UART5_u32_BASE_ADDRESS  )
#define  USART6                     ( (  USART_TypeDef *) USART6_u32_BASE_ADDRESS )

/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/
#define TMR2_u32_BASE_ADDRESS                                0x40000000U
#define TMR3_u32_BASE_ADDRESS                                0x40000400U
#define TMR4_u32_BASE_ADDRESS                                0x40000800U
#define TMR5_u32_BASE_ADDRESS                                0x40000C00U



typedef struct
{
	volatile uint32_t CR1;         /*!< TIM control register 1,              Address offset: 0x00 */
	volatile uint32_t CR2;         /*!< TIM control register 2,              Address offset: 0x04 */
	volatile uint32_t SMCR;        /*!< TIM slave mode control register,     Address offset: 0x08 */
	volatile uint32_t DIER;        /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
	volatile uint32_t SR;          /*!< TIM status register,                 Address offset: 0x10 */
	volatile uint32_t EGR;         /*!< TIM event generation register,       Address offset: 0x14 */
	volatile uint32_t CCMR[2];       /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
	volatile uint32_t CCER;        /*!< TIM capture/compare enable register, Address offset: 0x20 */
	volatile uint32_t CNT;         /*!< TIM counter register,                Address offset: 0x24 */
	volatile uint32_t PSC;         /*!< TIM prescaler,                       Address offset: 0x28 */
	volatile uint32_t ARR;         /*!< TIM auto-reload register,            Address offset: 0x2C */
	volatile uint32_t RCR;         /*!< TIM repetition counter register,     Address offset: 0x30 */
	volatile uint32_t CCR[4];        /*!< TIM capture/compare register 1,      Address offset: 0x34 */
	volatile uint32_t BDTR;        /*!< TIM break and dead-time register,    Address offset: 0x44 */
	volatile uint32_t DCR;         /*!< TIM DMA control register,            Address offset: 0x48 */
	volatile uint32_t DMAR;        /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
	volatile uint32_t OR;          /*!< TIM option register,                 Address offset: 0x50 */

}GPTIMER_REG;



#define TMR2		(( GPTIMER_REG *)(TMR2_u32_BASE_ADDRESS))
#define TMR3		(( GPTIMER_REG *)(TMR3_u32_BASE_ADDRESS))
#define TMR4		(( GPTIMER_REG *)(TMR4_u32_BASE_ADDRESS))
#define TMR5		(( GPTIMER_REG *)(TMR5_u32_BASE_ADDRESS))

/************************************************************************************************/
/************************************************************************************************/
/************************************************************************************************/


#endif
