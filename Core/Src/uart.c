/*
 * uart.c
 *
 *  Created on: Feb 3, 2023
 *      Author: pusedu03
 */

#include "uart.h"
#include <stdio.h>

UART_HandleTypeDef *huart;

#define rxBufferMax	255
int rxBufferGp;					// get pointer (read)
int rxBufferPp;					// put pointer (write)
uint8_t rxBuffer[rxBufferMax];
uint8_t rxChar;

// uart device reset (uart   jang chi   cho gi hwa)
void initUart(UART_HandleTypeDef *inHuart) {
	huart= inHuart;
	HAL_UART_Receive_IT(huart, &rxChar, 1);
}

// message recieve process(mun ja   chu ri   gwa jung)
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	rxBuffer[rxBufferPp++] = rxChar;
	rxBufferPp %= rxBufferMax;
	HAL_UART_Receive_IT(huart, &rxChar, 1);//interrupt always reset
}

// read(get?) message from buffer (buffer e su   mun ja   ga jeu o gi)
uint8_t getChar() {
	uint8_t result;
	if(rxBufferGp == rxBufferPp) return 0;
	result = rxBuffer[rxBufferGp++];
	rxBufferGp %= rxBufferMax;
	return result;
}

int _write(int file, char *p, int len) {
	HAL_UART_Transmit(huart, p, len, 1);
	return len;
}
