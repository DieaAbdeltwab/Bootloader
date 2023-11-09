/**
 ******************************************************************************
 * @file           : GPIO_interface.h
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
#ifndef  GPIO_INTERFACE_H
#define  GPIO_INTERFACE_H
/********************************************************/
/******* @Port_t  ***************************************/
/********************************************************/
typedef enum{
			PORTA =0,
			PORTB   ,
			PORTC   ,
			PORTD   ,
			PORTE   ,
			PORTF   ,
			PORTG   ,
			PORTH
}Port_t;
/********************************************************/
/******* @Pin_t *****************************************/
/********************************************************/
typedef enum{
             PIN0=0,
             PIN1  ,
             PIN2  ,
             PIN3  ,
             PIN4  ,
             PIN5  ,
             PIN6  ,
             PIN7  ,
             PIN8  ,
             PIN9  ,
             PIN10 ,
             PIN11 ,
             PIN12 , 
             PIN13 , 
             PIN14 , 
             PIN15
}Pin_t;
/********************************************************/
/******* @Mode_t ****************************************/
/********************************************************/
typedef enum{
             INPUT               =0,
             OUTPUT                ,
			 ALTERNATE_FUNCTION    ,
			 ANALOG
}Mode_t;
/********************************************************/
/******* @OutputSpeed_t **********************************/
/********************************************************/
typedef enum{
			SPEED_LOW    =0,
			SPEED_MEDIUM   ,
			SPEED_FAST     ,
			SPEED_HIGH

}OutputSpeed_t;
/********************************************************/
/******* @OutputType_t **********************************/
/********************************************************/
typedef enum{
             PUSH_PULL    =0,
			 OPEN_DRAIN

}OutputType_t;
/********************************************************/
/******* @PullUpDowen_t **********************************/
/********************************************************/
typedef enum{
             NO_PULL    =0,
			 PULL_UP      ,
			 PULL_DOWEN
}PullUpDowen_t;
/********************************************************/
/******* @AltFunc_t **********************************/
/********************************************************/
typedef enum{
             AF0    =0,
			 AF1      ,
			 AF2      ,
			 AF3      ,
			 AF4      ,
			 AF5      ,
			 AF6      ,
			 AF7      ,
			 AF8      ,
			 AF9      ,
			 AF10     ,
			 AF11     ,
			 AF12     ,
			 AF13     ,
			 AF14     ,
			 AF15

}AltFunc_t;
/********************************************************/
/******* @PinConfig_t ***********************************/
/********************************************************/

typedef struct{
             Port_t         Port        ;
             Pin_t          PinNum      ;
             Mode_t         Mode        ;
             OutputSpeed_t  OutputSpeed ;
             OutputType_t   OutputType  ;
             PullUpDowen_t  PullType    ;
             AltFunc_t      AltFunc    ;
}PinConfig_t;

/********************************************************/
/******* @PinValue_t ************************************/
/********************************************************/
typedef enum{
			LOW=0,
			HIGH

}PinValue_t;

/********************************************************/
/******* @PortPosition_t ********************************/
/********************************************************/
typedef enum{
			PORT_LOW=0,
			PORT_HIGH

}PortPosition_t;

/*************************************************************************************************************************************/
/********************************************************* Functions Prototype *******************************************************/
/*************************************************************************************************************************************/
/**
 ******************************************************************************
 * @fn             : MGPIO_u8PinInit
 * @brief          : initialization Value of Pin
 * @param[in]      : PinConfig  --> init Value of Pin from @PinConfig_t  struct
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t MGPIO_u8PinInit ( const PinConfig_t* PinConfig );

/**
 ******************************************************************************
 * @fn             : MGPIO_u8SetPinValue
 * @brief          : Set Pin Value
 * @param[in]      : Copy_PortID --> get option from @Port_t         enum
 * @param[in]      : Copy_PinID  --> get option from @Pin_t          enum
 * @param[in]      : Copy_Value  --> get option from @PinValue_t     enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t MGPIO_u8SetPinValue     ( Port_t Copy_PortID , Pin_t Copy_PinID , PinValue_t Copy_Value   );
/**
 ******************************************************************************
 * @fn             : MGPIO_u8GetPinValue
 * @brief          : Get Pin Value
 * @param[in]      : Copy_PortID --> get option from @Port_t         enum
 * @param[in]      : Copy_PinID  --> get option from @Pin_t          enum
 * @param[out]     : Copy_Value  --> Set value in Copy_pu8Result     uint8_t
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */

uint8_t  MGPIO_u8GetPinValue    ( Port_t Copy_PortID , Pin_t Copy_PinID , uint8_t *Copy_pu8Result );
/**
 ******************************************************************************
 * @fn             : MGPIO_u8TogPinValue
 * @brief          : TOG Pin Value
 * @param[in]      : Copy_PortID --> get option from @Port_t         enum
 * @param[in]      : Copy_PinID  --> get option from @Pin_t          enum
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t MGPIO_u8TogPinValue     ( Port_t Copy_PortID , Pin_t Copy_PinID  );
/**
 ******************************************************************************
 * @fn             : MGPIO_u8SetPortValue
 * @brief          : Set Port Value
 * @param[in]      : Copy_PortID --> get option from @Port_t            enum
 * @param[in]      : Copy_Position  --> get option from @PortPosition_t enum
 * @param[in]      : Copy_u16Value  --> Set Value in Copy_u16Value      uint16_t
 * @retval         : ErrorState
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
uint8_t MGPIO_u8SetPortValue     ( Port_t Copy_PortID , PortPosition_t Copy_Position , uint16_t Copy_u16Value    );

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
#endif
