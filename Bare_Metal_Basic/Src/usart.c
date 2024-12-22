/*
 * usart.c
 *
 *  Created on: Dec 18, 2024
 *      Author: jacob
 */

#include "usart.h"

/* Enable bits */

#define USART2EN (1U<<17)

#define SR_RXNE (1U<<5)
#define SR_TXE  (1U<<7)

#define CR1_UE  (1U<<13)
#define CR1_RE  (1U<<2)
#define CR1_TE  (1U<<3)

#define PERIPHERAL_CLOCK (16000000) // The system frequency
#define BAUDRATE (115200)

void usart2Init(void) {
	// Allow clock access to USART2
		RCC_APB1ENR |= USART2EN;
	// Set USART2 alternate function in gpio.c
	// AF07 - USART2_TX = PA2, USART2_RX = PA3

	// Configure baudrate
		setBaudrateUSART2(PERIPHERAL_CLOCK, BAUDRATE);

	// Enable TX and RX Transfer Function in CR1
		USART2_CR1 |= CR1_TE;
		USART2_CR1 |= CR1_RE;

	// Enable USART2 Module
		USART2_CR1 |= CR1_UE;
}

void writeUSART2(int ch) {
	// make sure the transmit data register is not empty
	while (!(USART2_SR & SR_TXE))
		;
	USART2_DR = (ch & 0xFF);
}

char readUSART2(void) {
	// make sure the receive data register is not empty
	while (!(USART2_SR & SR_RXNE))
		;
	return USART2_DR;
}

void setBaudrateUSART2(uint32_t peripheralClock, uint32_t baudrate) {
	USART2_BRR = ((peripheralClock + (baudrate/2U))/ baudrate);
}
