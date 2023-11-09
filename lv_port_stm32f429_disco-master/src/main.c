/******************************************************************************/
/************************ LIB Layer *******************************************/
/******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
/******************************************************************************/
/************************ CORE Layer ******************************************/
/******************************************************************************/
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

/******************************************************************************/
/************************ HAL Layer *******************************************/
/******************************************************************************/

/******************************************************************************/
/************************ SERVIES Layer ***************************************/
/******************************************************************************/
#include "TIMERS_interface.h"

#include "stm32f4xx.h"
#include "hal_stm_lvgl/stm32f429i_discovery.h"

#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"

#include "hal_stm_lvgl/tft/tft.h"
#include "hal_stm_lvgl/touchpad/touchpad.h"

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/********************************************************************************************************************************************/
/**************************************************** Global Variables **********************************************************************/
/********************************************************************************************************************************************/
/******************************************************************************/
/***************************** BUTTON *****************************************/
/*****************************************************************************
typedef enum
{
	BUTTON_1 =0 ,
	BUTTON_2    ,
	BUTTON_3
}BUTTON_t ;
typedef struct
{
	BUTTON_t   BUTTON_INDEX  ;
    lv_obj_t * label         ;
    lv_obj_t * btn           ;
}lv_btns_t;

lv_btns_t btn1 , btn2  ;*/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/********************************************************************************************************************************************/
/**************************************************** Functions *****************************************************************************/
/********************************************************************************************************************************************/

/********************************************************************************************************************************************/
/**************************************************** Call Back Functions *******************************************************************/
/********************************************************************************************************************************************/
/******************************************************************************/
/******************************************************************************/
/*****************************************************************************

void EXTI_voidCallBack (void )
{

}*/
/******************************************************************************/
/***************************** BUTTON *****************************************/
/*****************************************************************************
static void event_handler_btn(lv_event_t * e)
{
	//lv_event_code_t code  = lv_event_get_code(e);
	//lv_obj_t*  target_btn = lv_event_get_target(e);
	lv_btns_t* data_btn   = lv_event_get_user_data(e);

	if (data_btn->BUTTON_INDEX == BUTTON_1 )
	{
		MGPIO_u8TogPinValue(PORTG, PIN13);
	}
	else if  (data_btn->BUTTON_INDEX == BUTTON_2 )
	{
		MGPIO_u8TogPinValue(PORTG, PIN14);
	}
}*/
/******************************************************************************/
/******************************************************************************/
/*****************************************************************************
static void event_handler_arc(lv_event_t * e)
{
	lv_obj_t*  target = lv_event_get_target(e);
	lv_obj_t* Label = lv_event_get_user_data(e);
	int16_t value = lv_arc_get_value(target);

	lv_label_set_text_fmt(Label, "#0000ff %d#", value );
	STIMERS_u8GeneratePWM(TMR_2, TMR_CHANNEL_1, 1024, 49000, value );
}*/
/********************************************************************************************************************************************/
/**************************************************** Main Function  ************************************************************************/
/********************************************************************************************************************************************/

int main(void)
{
	/********************************************************************************************************************************************/
	/**************************************************** Local Variables ***********************************************************************/
	/********************************************************************************************************************************************/
	//MNVIC_u8EnableInterrupt(NVIC_EXTI0);
	/********************************************************************************************************************************************/
	/**************************************************** CORE Configurations *******************************************************************/
	/********************************************************************************************************************************************/
	HAL_Init();
	/********************************************************************************************************************************************/
	/**************************************************** RCC Configurations ********************************************************************/
	/********************************************************************************************************************************************/
	SystemClock_Config();
	//MRCC_u8AHB1PeripheralsClockState(PER_GPIOA,ENABLE);
	//MRCC_u8AHB1PeripheralsClockState(PER_GPIOG,ENABLE);
	//MRCC_u8APB2PeripheralsClockState(PER_SYSCFG,ENABLE);
	//MRCC_u8APB2PeripheralsClockState(PER_USART1,ENABLE);
	//MRCC_u8APB1PeripheralsClockState(PER_TIM2,ENABLE);
	/********************************************************************************************************************************************/
	/**************************************************** MCAL Configurations *******************************************************************/
	/********************************************************************************************************************************************/
    /***************************************************************************************************************
	PinConfig_t DISCOVERY_led1 = {PORTG, PIN13 ,OUTPUT,SPEED_LOW,PUSH_PULL,NO_PULL,AF0};
	MGPIO_u8PinInit(&DISCOVERY_led1);
	PinConfig_t DISCOVERY_led2 = {PORTG, PIN14 ,OUTPUT,SPEED_LOW,PUSH_PULL,NO_PULL,AF0};
	MGPIO_u8PinInit(&DISCOVERY_led2);
	PinConfig_t DISCOVERY_btn =  {PORTA, PIN0  ,INPUT ,SPEED_LOW,PUSH_PULL,NO_PULL,AF0};
	MGPIO_u8PinInit(&DISCOVERY_btn);*/
    /***************************************************************************************************************
	PinConfig_t UART1_PIN1 ={PORTA , PIN9  , ALTERNATE_FUNCTION , SPEED_LOW , PUSH_PULL , NO_PULL , AF7};
	MGPIO_u8PinInit(&UART1_PIN1);
	PinConfig_t UART1_PIN2 ={PORTA , PIN10 , ALTERNATE_FUNCTION , SPEED_LOW , PUSH_PULL , NO_PULL , AF7};
	MGPIO_u8PinInit(&UART1_PIN2);
	USARTconfig_t UART1 = {USART_1,RECEIVER_ENABLE,TRANSMITTER_ENABLE,RXNE_INTERRUPT_DISABLE
						  ,TRANSMITTER_COMPLETE_INTERRUPT_DISABLE,TXE_INTERRUPT_DISABLE
						  ,PARITY_SELECTION_EVEN,PARITY_CONTROL_DISABLE,DATA_8_BITS,BY_16,ONE_BIT
						  ,INHIBITED,DMAR_DISABLE,DMAT_DISABLE};
	MUSART_u8SetConfiguration(&UART1);
	MUSART_u8UsartStatus(USART_1, USART_ENABLE);*/
    /***************************************************************************************************************
	MSYSCFG_u8PortRemap(SYSCFG_LINE0 , SYSCFG_Port_A);
	EXTI_config_t EXTI_0  ={LINE0 , RISING , EXTI_ENABLE , EXTI_voidCallBack };
	MEXTI_u8Config(&EXTI_0);*/
    /****************************************************************************************************************
	PinConfig_t DISCOVERY_PWM_2_1 = {PORTA, PIN0 ,ALTERNATE_FUNCTION ,SPEED_LOW,PUSH_PULL,NO_PULL,AF1};
	MGPIO_u8PinInit(&DISCOVERY_PWM_2_1);
     */
	/********************************************************************************************************************************************/
	/**************************************************** HAL Configurations ********************************************************************/
	/********************************************************************************************************************************************/
	lv_init();
	tft_init();
	touchpad_init();
    lv_disp_set_rotation(lv_disp_get_default(), LV_DISP_ROT_270);
	/********************************************************************************************************************************************/
	/**************************************************** SERVIES Configurations ****************************************************************/
	/********************************************************************************************************************************************/
	/******************************************************************************/
    /***************************** APP 2 ******************************************/
    /*****************************************************************************
    LV_IMG_DECLARE(Flag_of_Palestine)
    static const lv_img_dsc_t* anim_imgs[3] = {
    	&Flag_of_Palestine,
    };
    lv_obj_t * animimg0 = lv_animimg_create(lv_scr_act());
    lv_obj_center(animimg0);
    lv_animimg_set_src(animimg0, (lv_img_dsc_t**) anim_imgs, 1);
    lv_animimg_set_duration(animimg0, 1000);
    lv_animimg_set_repeat_count(animimg0, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(animimg0);*/
	/******************************************************************************/
    /***************************** Style ******************************************/
    /*****************************************************************************
    lv_style_t style;
    lv_style_init(&style);
    lv_style_set_radius(&style, 5 );
    lv_style_set_bg_opa(&style, LV_OPA_COVER);
    lv_style_set_bg_color(&style, lv_palette_main(LV_PALETTE_DEEP_ORANGE));
    lv_obj_t * obj = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj, &style, 0);
    lv_obj_set_size(obj, 240 , 320 );
    lv_obj_center(obj);*/
	/******************************************************************************/
    /***************************** label ******************************************/
    /*****************************************************************************
    lv_obj_t * label1 = lv_label_create(lv_scr_act());
    lv_label_set_long_mode(label1, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_recolor(label1, true);
    lv_obj_set_width(label1, 150);
    lv_label_set_text(label1, "#0000ff Bootloader:# #000000 Advanced Embedded systems diploma#");
    lv_obj_set_style_text_font(label1, &lv_font_montserrat_16, 0);
    lv_obj_align(label1, LV_ALIGN_CENTER, 0, -130);
    lv_obj_t * label2 = lv_label_create(lv_scr_act());
    lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_recolor(label2, true);
    lv_obj_set_width(label2, 150);
    lv_label_set_text(label2, "#0000ff Thanks for : # #c1ec09 Eng.Amgad Samir#");
    lv_obj_set_style_text_font(label2, &lv_font_montserrat_18, 0);
    lv_obj_align(label2, LV_ALIGN_CENTER, 0, -90);*/
    /******************************************************************************/
    /***************************** ARC ********************************************/
    /*****************************************************************************
    lv_obj_t * arc = lv_arc_create(lv_scr_act());
    lv_obj_set_style_bg_color(arc, lv_palette_main(LV_PALETTE_GREEN), LV_PART_KNOB);
    lv_arc_set_start_angle(arc, 90 );
    lv_arc_set_end_angle(arc, 180);
    lv_arc_set_range(arc, 0, 180);
    lv_obj_center(arc);
    lv_obj_t* Label = lv_label_create(lv_scr_act());
    lv_label_set_recolor(Label, true);
    lv_label_set_text(Label, "#0000ff 0#");
    lv_obj_align_to(Label, arc , LV_ALIGN_CENTER, 0 , 0);
    lv_obj_add_event_cb(arc , event_handler_arc , LV_EVENT_VALUE_CHANGED, Label );*/
	/******************************************************************************/
    /***************************** BUTTON *****************************************/
    /******************************************************************************/
    /***************************** BUTTON_1 **************************************
    btn1.BUTTON_INDEX = BUTTON_1 ;
    btn1.btn = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn1.btn, event_handler_btn, LV_EVENT_VALUE_CHANGED, &btn1);
    lv_obj_align(btn1.btn, LV_ALIGN_CENTER, 50 , 100);
    lv_obj_add_flag(btn1.btn, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn1.btn, LV_SIZE_CONTENT);
    btn1.label = lv_label_create(btn1.btn);
    lv_label_set_text(btn1.label, "LED 3");
    lv_obj_center(btn1.label);*/
    /***************************** BUTTON_2 **************************************
    btn2.BUTTON_INDEX = BUTTON_2 ;
    btn2.btn  = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn2.btn, event_handler_btn, LV_EVENT_VALUE_CHANGED, &btn2);
    lv_obj_align(btn2.btn, LV_ALIGN_CENTER, -50 , 100);
    lv_obj_add_flag(btn2.btn, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn2.btn, LV_SIZE_CONTENT);
    btn2.label  = lv_label_create(btn2.btn);
    lv_label_set_text(btn2.label, "LED 4");
    lv_obj_center(btn2.label);*/
    /******************************************************************************/
    /******************************************************************************/
    /******************************************************************************/

	/********************************************************************************************************************************************/
	/**************************************************** Loop **********************************************************************************/
	/********************************************************************************************************************************************/


	while (1)
	{
		HAL_Delay(3);
		lv_task_handler();
	}
}