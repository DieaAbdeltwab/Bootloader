


#ifndef  PRELOADER_CONFIG_H
#define  PRELOADER_CONFIG_H


/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/*         Options :
 *
 *         FLASH_SECTOR0_BASE_ADDRESS
 *         FLASH_SECTOR1_BASE_ADDRESS
 *         FLASH_SECTOR2_BASE_ADDRESS
 *         FLASH_SECTOR3_BASE_ADDRESS
 *         FLASH_SECTOR4_BASE_ADDRESS
 *         FLASH_SECTOR5_BASE_ADDRESS
 *         FLASH_SECTOR6_BASE_ADDRESS
 *         FLASH_SECTOR7_BASE_ADDRESS
 */

#define PRELOADER_USER_APP1_BASE_ADDRESS      FLASH_SECTOR2_BASE_ADDRESS
#define PRELOADER_USER_APP2_BASE_ADDRESS      FLASH_SECTOR8_BASE_ADDRESS

/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/*
 *****************************************
 * Should Seem in "BOOTLOADER_config.h"
 *****************************************
 */
#define  PRELOADER_UART_INDEX            USART_1  /* Get Option From @USARTindex_t */

/************************************************************************************/
/************************************************************************************/
/************************************************************************************/

#define  PRELOADER_BTN_PORT              PORTA  /* Get Option From @Port_t     */
#define  PRELOADER_BTN_PIN               PIN0   /* Get Option From @Pin_t      */
#define  PRELOADER_PRESSED_BTN_STATUS    HIGH   /* Get Option From @PinValue_t */

/************************************************************************************/
/************************************************************************************/
/************************************************************************************/

#endif
