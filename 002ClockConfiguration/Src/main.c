#include <stdint.h>

//GPIOA
#define GPIOA_BASE_ADDR 			0x48000000UL
#define GPIOx_MODER_REG_OFFSET		0x00UL
#define GPIOx_MODER_REG_ADDR		(GPIOA_BASE_ADDR + GPIOx_MODER_REG_OFFSET)

//RCC
#define RCC_BASE_ADDR 				0x40021000UL
#define RCC_AHBENR_REG_OFFSET		0x14UL
#define RCC_AHBENR_REG_ADDR			(RCC_BASE_ADDR + RCC_AHBENR_REG_OFFSET)



int main(void)
{
	//enable GPIOA clock
	uint32_t *pRccAhbenrReg = (uint32_t *)RCC_AHBENR_REG_ADDR;
	*pRccAhbenrReg |= (1 << 17);

	//change the 0th pin of the GPIOA mode to AF
	uint32_t *pGpioModerReg = (uint32_t *)GPIOx_MODER_REG_ADDR;
	*pGpioModerReg |= (0b11 << 0);
    /* Loop forever */
	//test
	for(;;);
}
