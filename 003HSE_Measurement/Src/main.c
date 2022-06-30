#include <stdint.h>

//RCC AHB Enable Address
#define RCC_BASE_ADDR				0x40021000UL
#define RCC_AHBENR_REG_OFFSET		0x14UL
#define RCC_AHBENR_REG_ADDR			(RCC_BASE_ADDR + RCC_AHBENR_REG_OFFSET)

#define RCC_CFGR_REG_OFFSET			0x04UL
#define RCC_CFGR_REG_ADDR			(RCC_BASE_ADDR + RCC_CFGR_REG_OFFSET)

//GPIOA
#define GPIOA_BASE_ADDR			0x48000000UL
#define GPIOx_MODER_REG_OFFSET	0x00UL
#define GPIOA_MODER_REG_ADDR	(GPIOA_BASE_ADDR + GPIOx_MODER_REG_OFFSET)

#define GPIOx_AFHR_REG_OFFSET	0x24
#define GPIOA_AFRH_REG_ADDR		(GPIOA_BASE_ADDR + GPIOx_AFHR_REG_OFFSET)

int main(void)
{
	/*enable GPIOA clock (and AHB peripheral)*/
	uint32_t *pRccAhbEnReg = (uint32_t *)RCC_AHBENR_REG_ADDR;
	*pRccAhbEnReg |= (1<<17);//Bit 17 IOPAEN: I/O port A clock enable


	/*change GPIO PA8 pin functionality to MCO*/
	//a)change PA8 mode to AF
	uint32_t *pGpioaModeReg = (uint32_t *)GPIOA_MODER_REG_ADDR;
	int pinNumber = 8;
	*pGpioaModeReg |= ( 1 << (2*pinNumber+1) );
	*pGpioaModeReg &= ~( 1 << (2*pinNumber) );

	//b)configure alternate function register to set mode 0 for PA8 (AF0 for PA8 is MCO)
	uint32_t * pGpioaAfhReg = (uint32_t *)GPIOA_AFRH_REG_ADDR;
	*pGpioaAfhReg &= ~(1 << 0);
	*pGpioaAfhReg &= ~(1 << 1);
	*pGpioaAfhReg &= ~(1 << 2);
	*pGpioaAfhReg &= ~(1 << 3);

	//select MCO source as HSI and set its prescalar if needed
	uint32_t *pRccCfgReg = (uint32_t *)RCC_CFGR_REG_ADDR; //Bits 26:24 MCO: Microcontroller clock output [HSI: 101]
	*pRccCfgReg |= (1<<26);
	*pRccCfgReg &= ~(1<<25);
	*pRccCfgReg |= (1<<24);


    /* Loop forever */
	for(;;);
}
