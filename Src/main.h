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

#ifndef MAIN_H
#define MAIN_H

#include "../lib/CMSIS/Device/stm32f767xx.h"

//Set bit and clear bit
#define SET_BIT (x, n)  ((x)  |=  (1U << (n)))
#define CLEAR_BIT(x, n) ((x)  &= ~(1U << (n)))


// Check if bit N in VAR is set
#define BIT_IS_SET(VAR, N)    (((VAR) & (1U << (N))) != 0)

// Check if bit N in VAR is clear
#define BIT_IS_CLEAR(VAR, N)  (((VAR) & (1U << (N))) == 0)


#endif
