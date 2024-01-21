/*
 * uart.h
 *
 *  Created on: Feb 3, 2023
 *      Author: pusedu03
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "main.h"

// prototype 선언
void initUart(UART_HandleTypeDef *);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
uint8_t getChar();

#endif /* INC_UART_H_ */
