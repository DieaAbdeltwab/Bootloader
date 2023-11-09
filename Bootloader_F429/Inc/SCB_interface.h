/**
 ******************************************************************************
 * @file           : SCB_interface.h
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
#ifndef  SCB_INTERFACE_H
#define  SCB_INTERFACE_H
/******************************************************************************/
/************************* @SCB_InterruptPriority_t ***************************/
/******************************************************************************/
typedef enum{
	        GROUP3 =3,
			GROUP4   ,
			GROUP5   ,
			GROUP6   ,
			GROUP7
}SCB_InterruptPriority_t;

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
uint8_t   MSCB_u8InterruptPriority ( SCB_InterruptPriority_t Copy_NVICGroubSubDistribution  );

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
uint8_t   MSCB_u8VectorTableAddress ( uint32_t Copy_u32VectorTableAddress  );

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
#endif
