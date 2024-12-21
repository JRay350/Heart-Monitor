/*
 * gpio.c
 *
 *  Created on: Dec 13, 2024
 *      Author: jacob
 */

#include "gpio.h"

#define GPIOAEN (1U<<0)
#define GPIOBEN (1U<<1)
#define GPIOCEN (1U<<2)

#define GPIOA5  (1U<<5)
#define GPIOB4  (1U<<4)
#define GPIOB5  (1U<<5)
#define GPIOC13 (1U<<13)

#define USER_LED (GPIOA5)
#define GREEN_LED (GPIOB4)
#define RED_LED (GPIOB5)
#define USER_BUTTON (GPIOC13)

void gpioInit(void) {

/* Enable clock access to GPIO ports */

// Enable clock access to GPIO port A
	RCC_AHB1ENR |= GPIOAEN;

// Enable clock access to GPIO port B
	RCC_AHB1ENR |= GPIOBEN;

// Enable clock access to GPIO port C
	RCC_AHB1ENR |= GPIOCEN;

/* Set the mode of the pins */

	// GPIO PA5 - 01 - General Purpose Output Mode - USER_LED
	GPIOA_MODER |= (1U<<10);
	GPIOA_MODER &= ~(1U<<11);

	// GPIO PB4 - 01 - General Purpose Output Mode - GREEN_LED
	GPIOB_MODER |= (1U<<8);
	GPIOB_MODER &= ~(1U<<9);

	// GPIO PB5 - 01 - General Purpose Output Mode - RED_LED
	GPIOB_MODER |= (1U<<10);
	GPIOB_MODER &= ~(1U<<11);

	// GPIO PC13 - 00 - Input Mode - USER_BUTTON
	GPIOC_MODER &= ~(1U<<26);
	GPIOC_MODER &= ~(1U<<27);

	// GPIOA PA2 - 10 - Alternate Function Mode - USART2_TX
	GPIOA_MODER &= ~(1U<<4);
	GPIOA_MODER |= (1U<<5);

	// GPIOA PA3 - 10 - Alternate Function Mode - USART2_RX
	GPIOA_MODER &= ~(1U<<6);
	GPIOA_MODER |= (1U<<7);

	/* Set Alternate Functions, AFI */
	// Alternate function for PA2, USART2_TX
	GPIOA_AFRL |= (1U<<8);
	GPIOA_AFRL |= (1U<<9);
	GPIOA_AFRL |= (1U<<10);
	GPIOA_AFRL &= ~(1U<<11);

	// Alternate function for PA3, USART2_RX
	GPIOA_AFRL |= (1U<<12);
	GPIOA_AFRL |= (1U<<13);
	GPIOA_AFRL |= (1U<<14);
	GPIOA_AFRL &= ~(1U<<15);

}

void setOnGreenLED(void) {
	GPIOB_ODR |= GREEN_LED;
}

void setOffGreenLED(void) {
	GPIOB_ODR &= ~(GREEN_LED);
}

void setOnRedLED(void) {
	GPIOB_ODR |= RED_LED;
}
void setOffRedLED(void) {
	GPIOB_ODR &= ~(RED_LED);
}
void toggleLED(void) {
	GPIOA_ODR ^= USER_LED;
	delay();
}
void setProgramState(int* programState) {
	if (!(GPIOC_IDR & USER_BUTTON)){ // If the button is pressed
		if (*programState == OFF) {
			*programState = ON;
			delay();
		} else if (*programState == ON) {
			*programState = OFF;
			delay();
		}
	}
}
void displayProgramState(int* programState) {
	if (*programState == OFF) {
		setOnRedLED();
		setOffGreenLED();
	} else if (*programState == ON) {
		setOffRedLED();
		setOnGreenLED();
	}
}

void delay(void) {
	for (int i = 0; i < 150000; i++) {
		// delay
	}
}
