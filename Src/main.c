// 
//  This file is a part of the Open Source Design456App
//  MIT License
// 
//  Copyright (c) 2025
// 
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
// 
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
// 
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
// 
//   Author :Mariwan Jalal    mariwan.jalal@gmail.com
// 


//#include <stdint.h>

#include "stm32f767xx.h"

void Delay_ms(int ms){
	//Not accurate, implement it by yourself
	if (ms<=0)
		return;
	while (ms>0){
		ms;;
	}
}

void toggle_LED(uint16_t ms){
	GPIOB->BSRR|=1<<16;
	Delay_ms(ms);
	GPIOB->BSRR|=1<<0;
    Delay_ms(ms);
}
void gpoi_cfg(){

	/*
	1. Enable the GPIO CLOCK
	2. Set the Pin as OUTPUT
	3. Configure the OUTPUT MODE

	*/
	// Enable clock for GPIOB
	RCC->AHB1ENR |= (1 << 1); // Enable GPIOB clock

	// Set PB0 to output mode
	//GPIOB->MODER &= ~(0x3 << 0); // Clear mode bits for PB0
	GPIOB->MODER |= (0x1 << 0);  // Set PB0 to output mode

	// Set output type to push-pull (default)
	GPIOB->OTYPER &= ~(1 << 0); // PB0 is push-pull

	// Set output speed (optional)
	GPIOB->OTYPER=0;
	GPIOB->OSPEEDR=2<<0;	//very high
}



int main(){
	 
	 
	while(1){
	toggle_LED(500);
 
	}
}
