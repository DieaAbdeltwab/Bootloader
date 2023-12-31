/******************************************************************************/
/************************ LIB Layer *******************************************/
/******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
/******************************************************************************/
/************************ CORE Layer ******************************************/
/******************************************************************************/
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "SCB_interface.h"
/******************************************************************************/
/************************ MCAL Layer ******************************************/
/******************************************************************************/
#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "EXTI_interface.h"
#include "SYSCFG_interface.h"
#include "USART_interface.h"
#include "GPTIMER_interface.h"
#include "CRC_interface.h"

/******************************************************************************/
/************************ HAL Layer *******************************************/
/******************************************************************************/

/******************************************************************************/
/************************ SERVIES Layer ***************************************/
/******************************************************************************/
#include "TIMERS_interface.h"
#include "PRELOADER_interface.h"

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/********************************************************************************************************************************************/
/**************************************************** Global Variables **********************************************************************/
/********************************************************************************************************************************************/

/********************************************************************************************************************************************/
/**************************************************** Functions *****************************************************************************/
/********************************************************************************************************************************************/

/********************************************************************************************************************************************/
/**************************************************** Call Back Functions *******************************************************************/
/********************************************************************************************************************************************/

/********************************************************************************************************************************************/
/**************************************************** Main Function  ************************************************************************/
/********************************************************************************************************************************************/

int main(void)
{
	/********************************************************************************************************************************************/
	/**************************************************** Local Variables ***********************************************************************/
	/********************************************************************************************************************************************/

	/********************************************************************************************************************************************/
	/**************************************************** CORE Configurations *******************************************************************/
	/********************************************************************************************************************************************/
	MSTK_u8ClockConfig(STK_AHB_DIV_8);
	/********************************************************************************************************************************************/
	/**************************************************** RCC Configurations ********************************************************************/
	/********************************************************************************************************************************************/

	/********************************************************************************************************************************************/
	MRCC_u8SetClockState(HSI,ENABLE);
	MRCC_u8SetSystemClock(HSI);
	MRCC_u8AHB1PeripheralsClockState(PER_GPIOA,ENABLE);
	MRCC_u8AHB1PeripheralsClockState(PER_GPIOG,ENABLE);
	MRCC_u8APB2PeripheralsClockState(PER_USART1,ENABLE);
	MRCC_u8AHB1PeripheralsClockState(PER_CRC,ENABLE);

	/********************************************************************************************************************************************/
	/**************************************************** MCAL Configurations *******************************************************************/
	/********************************************************************************************************************************************/

    /****************************************************************************************************************/
	PinConfig_t DISCOVERY_led1 = {PORTG, PIN13 ,OUTPUT,SPEED_LOW,PUSH_PULL,NO_PULL,AF0};
	MGPIO_u8PinInit(&DISCOVERY_led1);
	PinConfig_t DISCOVERY_led2 = {PORTG, PIN14 ,OUTPUT,SPEED_LOW,PUSH_PULL,NO_PULL,AF0};
	MGPIO_u8PinInit(&DISCOVERY_led2);
	PinConfig_t DISCOVERY_btn =  {PORTA, PIN0  ,INPUT ,SPEED_LOW,PUSH_PULL,NO_PULL,AF0};
	MGPIO_u8PinInit(&DISCOVERY_btn);
    /****************************************************************************************************************/
	PinConfig_t UART1_PIN1 ={PORTA , PIN9  , ALTERNATE_FUNCTION , SPEED_LOW , PUSH_PULL , NO_PULL , AF7};
	MGPIO_u8PinInit(&UART1_PIN1);
	PinConfig_t UART1_PIN2 ={PORTA , PIN10 , ALTERNATE_FUNCTION , SPEED_LOW , PUSH_PULL , NO_PULL , AF7};
	MGPIO_u8PinInit(&UART1_PIN2);
	USARTconfig_t UART1 = {USART_1,RECEIVER_ENABLE,TRANSMITTER_ENABLE,RXNE_INTERRUPT_DISABLE
						  ,TRANSMITTER_COMPLETE_INTERRUPT_DISABLE,TXE_INTERRUPT_DISABLE
						  ,PARITY_SELECTION_EVEN,PARITY_CONTROL_DISABLE,DATA_8_BITS,BY_16,ONE_BIT
						  ,INHIBITED,DMAR_DISABLE,DMAT_DISABLE};
	MUSART_u8SetConfiguration(&UART1);
	MUSART_u8UsartStatus(USART_1, USART_ENABLE);

	/********************************************************************************************************************************************/
	/**************************************************** HAL Configurations ********************************************************************/
	/********************************************************************************************************************************************/

	/********************************************************************************************************************************************/
	/**************************************************** SERVIES Configurations ****************************************************************/
	/********************************************************************************************************************************************/
	SPRELOADER_voidSwitch();

	/********************************************************************************************************************************************/
	/**************************************************** Loop **********************************************************************************/
	/********************************************************************************************************************************************/


	while (1)
	{

	}
}
