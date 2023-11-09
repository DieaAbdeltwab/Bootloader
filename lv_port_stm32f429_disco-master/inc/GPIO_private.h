#ifndef  GPIO_PRIVATE_H
#define  GPIO_PRIVATE_H



/*************************************************************************************/
/******************************* ACCSESS *********************************************/
/*************************************************************************************/
#define MODE_PIN_ACCSESS             2
#define PUPDR_PIN_ACCSESS            2
#define OSPEEDER_PIN_ACCSESS         2
#define AFR_PIN_ACCSESS              4
/*************************************************************************************/
/******************************* MASKS ***********************************************/
/*************************************************************************************/
#define MODER_MASK           	    0b11
#define PUPDR_MASK           	    0b11
#define OTYPER_MASK           	    0b1
#define OSPEEDER_MASK          	    0b11
#define AFR_MASK          	    	0b1111


#define PIN_MASK                    0b1
#define PORT_POSITION_LOW_MASK     	0xFF00
#define PORT_POSITION_HIGH_MASK     0x00FF





#define AFR_PIN_SHIFTING              8


#endif
