#include <stdint.h>


//GPIOA
#define GPIOA_BASE_ADDR 			0x48000000UL
#define GPIOx_MODER_REG_OFFSET		0x00UL
#define GPIOx_MODER_REG_ADDR		(GPIOA_BASE_ADDR + GPIOx_MODER_REG_OFFSET)

int main(void)
{
	uint32_t *pGpioModerReg = (uint32_t *)GPIOx_MODER_REG_ADDR;
	*pGpioModerReg |= (0b11 << 0);
    /* Loop forever */
	//test
	for(;;);
}
