/*
 * usart.h
 *
 *  Created on: Dec 18, 2024
 *      Author: jacob
 */

#ifndef USART_H_
#define USART_H_

#include "base.h"
#include <stdint.h>

#define USART2_CR1_OFFSET (0x0C)
#define USART2_CR1 (*(volatile unsigned int*) (USART2_PERIPHERAL + USART2_CR1_OFFSET))

#define USART2_BRR_OFFSET (0x08)
#define USART2_BRR (*(volatile unsigned int*) (USART2_PERIPHERAL + USART2_BRR_OFFSET))

#define USART2_SR_OFFSET (0x00)
#define USART2_SR (*(volatile unsigned int*) (USART2_PERIPHERAL + USART2_SR_OFFSET))

#define USART2_DR_OFFSET (0x04)
#define USART2_DR (*(volatile unsigned int*) (USART2_PERIPHERAL + USART2_DR_OFFSET))

#define RCC_APB1ENR_OFFSET (0x40)
#define RCC_APB1ENR (*(volatile unsigned int*) (RCC_PERIPHERAL + RCC_APB1ENR_OFFSET))

/* Function Prototypes */
void usart2Init(void);
void writeUSART2(int ch);
char readUSART2(void);
void setBaudrateUSART2(uint32_t peripheralClock, uint32_t baudrate);

#endif /* USART_H_ */
