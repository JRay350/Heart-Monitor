/*
 * gpio.h
 *
 *  Created on: Dec 13, 2024
 *      Author: jacob
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "base.h"

#define GPIOA_MODER_OFFSET (0x00)
#define GPIOA_MODER (*(volatile unsigned int*) (GPIOA_PERIPHERAL + GPIOA_MODER_OFFSET))

#define GPIOB_MODER_OFFSET (0x00)
#define GPIOB_MODER (*(volatile unsigned int*) (GPIOB_PERIPHERAL + GPIOB_MODER_OFFSET))

#define GPIOC_MODER_OFFSET (0x00)
#define GPIOC_MODER (*(volatile unsigned int*) (GPIOC_PERIPHERAL + GPIOC_MODER_OFFSET))

#define GPIOA_ODR_OFFSET (0x14)
#define GPIOA_ODR (*(volatile unsigned int*) (GPIOA_PERIPHERAL + GPIOA_ODR_OFFSET))

#define GPIOB_ODR_OFFSET (0x14)
#define GPIOB_ODR (*(volatile unsigned int*) (GPIOB_PERIPHERAL + GPIOB_ODR_OFFSET))

#define GPIOC_ODR_OFFSET (0x14)
#define GPIOC_ODR (*(volatile unsigned int*) (GPIOC_PERIPHERAL + GPIOC_ODR_OFFSET))

#define GPIOC_IDR_OFFSET (0x10)
#define GPIOC_IDR (*(volatile unsigned int*) (GPIOC_PERIPHERAL + GPIOC_IDR_OFFSET))

#define RCC_AHB1ENR_OFFSET (0x30)
#define RCC_AHB1ENR (*(volatile unsigned int*) (RCC_PERIPHERAL + RCC_AHB1ENR_OFFSET))


// Function Prototypes

void gpioInit(void);
void setOnGreenLED(void);
void setOffGreenLED(void);
void setOnRedLED(void);
void setOffRedLED(void);
void toggleLED(void);
void setProgramState(int* programState);
void displayProgramState(int* programState);
void delay(void);


#endif /* GPIO_H_ */
