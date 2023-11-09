/**
 ******************************************************************************
 * @file           : BIT_MATH.h
 * @author         : Diea Abdeltwab
 * @layer          : Library
 * @brief          : Version 2 For STM32F103C8T6 Drivers
 * @date           : 25/7/2023
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
#ifndef BIT_MATH_H
#define BIT_MATH_H



#define SET_BIT(REG , BITNUM) REG |= 0b1<<BITNUM
#define CLR_BIT(REG , BITNUM) REG &= ~(0b1<<BITNUM)
#define TOG_BIT(REG , BITNUM) REG ^= 0b1<<BITNUM
#define GET_BIT(REG , BITNUM) ( (REG >> BITNUM) & 0b1 )


#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))



#endif
