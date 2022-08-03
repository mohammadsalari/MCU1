/*
 * stm32f303xx.h
 *
 *  Created on: Aug 2, 2022
 *      Author: salari
 */

#ifndef INC_STM32F303XX_H_
#define INC_STM32F303XX_H_

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
 * base addresses of peripherals hanging on AHB2 bus
 * TODO: complete for other peripherals
 */
#define GPIOA_BASEADDR						0x48000000U
#define GPIOB_BASEADDR						0x48000400U
#define GPIOC_BASEADDR						0x48000800U
#define GPIOD_BASEADDR						0x48000C00U
#define GPIOE_BASEADDR						0x48001000U
#define GPIOF_BASEADDR						0x48001400U




#endif /* INC_STM32F303XX_H_ */
