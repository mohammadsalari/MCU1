/*
 * stm32f303xx.h
 *
 *  Created on: Aug 2, 2022
 *      Author: salari
 */

#ifndef INC_STM32F303XX_H_
#define INC_STM32F303XX_H_


#include <stdint.h>


#define __vo volatile

/*
 * base addresses of SRAM and FLASH memories
 */
#define FLASH_BASEADDR						0x08000000UL	//256KB
#define SRAM_BASEADDR						0x20000000UL	//40KB
#define ROM_BASEADDR /*=system memory*/		0x1FFFD800UL	//8KB


/*
 * base addresses of different peripheral buses
 */
#define APB1_BASEADDR						0x40000000U
#define APB2_BASEADDR						0x40010000U
#define AHB1_BASEADDR						0x40020000U
#define AHB2_BASEADDR						0x48000000U
#define AHB3_BASEADDR						0x50000000U

/*
 * base addresses of peripherals hanging on AHB1 bus
 * TODO: complete for other peripherals
 */
#define RCC_BASEADDR						0x40021000



/*
 * base addresses of peripherals hanging on AHB2 bus
 * TODO: complete for other peripherals
 */
#define GPIOA_BASEADDR						0x48000000U
#define GPIOB_BASEADDR						0x48000400U
#define GPIOC_BASEADDR						0x48000800U
#define GPIOD_BASEADDR						0x48000C00U
#define GPIOE_BASEADDR						0x48001000U
#define GPIOF_BASEADDR						0x48001400U


/*
 * base addresses of peripherals hanging on APB1 bus
 * TODO: complete for other peripherals
 */
#define SPI2_BASEADDR						0x40003800U
#define SPI3_BASEADDR						0x40003C00U
#define USART2_BASEADDR						0x40004400U
#define USART3_BASEADDR						0x40004800U
#define UART4_BASEADDR						0x40004C00U
#define UART5_BASEADDR						0x40005000U



/*
 * base addresses of peripherals hanging on APB2 bus
 * TODO: complete for other peripherals
 */
#define SPI1_BASEADDR						0x40013000U
#define USART1_BASEADDR						0x40013800U
#define EXTI_BASEADDR						0x40010400U
#define SYSCFG_BASEADDR						0x40010000U


/*
 * peripheral register definition structure
 */
typedef struct {
	__vo uint32_t MODER;	/*GPIOx MODE Register. 					OFFSET: 0x00 */
	__vo uint32_t OTYPER;	/*GPIOx Output TYPE Register. 			OFFSET: 0x04 */
	__vo uint32_t OSPEEDR;	/*GPIOx Output SPEED Register. 			OFFSET: 0x08 */
	__vo uint32_t PUPDR;	/*GPIOx Pull-Up/Pull-Down Register. 	OFFSET: 0x0c */
	__vo uint32_t IDR;		/*GPIOx Input Data Register. 			OFFSET: 0x10 */
	__vo uint32_t ODR;		/*GPIOx Output Data Register. 			OFFSET: 0x14 */
	__vo uint32_t BSRR;		/*GPIOx Bit Set/Reset Register. 		OFFSET: 0x18 */
	__vo uint32_t LCKR;		/*GPIOx configuration LoCK Register. 	OFFSET: 0x1c */

	__vo uint64_t AFR;		/*GPIOx Alternate Function Register.	OFFSET: 0x20
	 	 	 	 	 	 	 *(GPIOx_AFRL and GPIOx_AFRH registers are merged into one register)
	 	 	 	 	 	 	 */

	__vo uint32_t BRR;		/*GPIOx Bit Reset Register. 			OFFSET: 0x28 */
}GPIO_RegDef_t;




/*
 * peripherals' dereferences
 */
#define GPIOA		((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB		((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC		((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD		((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE		((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF		((GPIO_RegDef_t *)GPIOF_BASEADDR)

#endif /* INC_STM32F303XX_H_ */
