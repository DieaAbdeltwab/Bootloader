#ifndef  RCC_PRIVATE_H
#define  RCC_PRIVATE_H

/*************************************************************************************/
/******************************* CR BITS *********************************************/
/*************************************************************************************/
#define  RCC_CR_HSION     				 0
#define  RCC_CR_HSIRDY                   1
#define  RCC_CR_HSEON                    16
#define  RCC_CR_HSERD                    17
#define  RCC_CR_HSEBYP                   18
#define  RCC_CR_CSSON                    19
#define  RCC_CR_PLLON                    24
#define  RCC_CR_PLLRDY                   25
#define  RCC_CR_PLLI2SON                 26
#define  RCC_CR_PLLI2SRDY                27
#define  RCC_CR_PLLSAION                 28
#define  RCC_CR_PLLSAIRDY                29
/*************************************************************************************/
/******************************* CFGR BITS *******************************************/
/*************************************************************************************/
#define  RCC_CFGR_SW                     0
#define  RCC_CFGR_HPRE                   4
#define  RCC_CFGR_PPRE1                  10
#define  RCC_CFGR_PPRE2                  13


/*************************************************************************************/
/******************************* PLLCFGR BITS ****************************************/
/*************************************************************************************/
#define  RCC_PLLCFGR_PLLM                 0
#define  RCC_PLLCFGR_PLLN                 6
#define  RCC_PLLCFGR_PLLP                 16
#define  RCC_PLLCFGR_PLLSRC               22
#define  RCC_PLLCFGR_PLLQ                 24
#define  RCC_PLLCFGR_PLLR                 28
/*************************************************************************************/
/******************************* MASKS ***********************************************/
/*************************************************************************************/
#define  RCC_CLK_NOT_RDY                 0
#define  RCC_CLOCK_STATE_MASK            0b1
#define  RCC_CLOCK_SEC_MASK              0b1
#define  RCC_SYS_CLOCK_MASK              0b11
#define  RCC_HSE_CONFIG_MASK             0b1
#define  RCC_HSE_BYP_MASK                0b1
#define  RCC_PLL_INPUT_MASK              0b1
#define  RCC_PLL_MUL_MASK                0b1111
#define  RCC_ADC_PRE_MASK                0b11
#define  RCC_DIVF_PLLM_MASK              0b111111
#define  RCC_DIVF_PLLP_MASK              0b11
#define  RCC_DIVF_PLLQ_MASK              0b1111
#define  RCC_DIVF_PLLR_MASK              0b111
#define  RCC_MULF_PLLN_MASK              0b111111111

#define  RCC_HPRE_MASK                   0b1111
#define  RCC_PPRE_MASK                   0b111
/*************************************************************************************/
/******************************* MAX *************************************************/
/*************************************************************************************/
#define  RCC_DIVF_PLLM_MAX              0b111111
#define  RCC_DIVF_PLLP_MAX              0b11
#define  RCC_DIVF_PLLQ_MAX              0b1111
#define  RCC_DIVF_PLLR_MAX              0b111
#define  RCC_DIVF_MIN                   0b10
#define  RCC_MULF_PLLN_MAX              0b110110000
#define  RCC_MULF_PLLN_MIN              0b110010

#define  RCC_HPRE_MIN                   0b1000
#define  RCC_PPRE_MIN                   0b100
/*********************************************
 *
 */
#endif
