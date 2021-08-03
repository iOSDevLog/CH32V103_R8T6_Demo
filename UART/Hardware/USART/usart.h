#ifndef __USART_H
#define __USART_H

#include "ch32v10x_conf.h"

void USARTx_CFG(void);
void USARTx_SendByte(USART_TypeDef* pUSARTx, uint8_t data);
void USARTx_SendStr(USART_TypeDef* pUSARTx, char *str);
void USART2_IRQHandler(void);

#endif
