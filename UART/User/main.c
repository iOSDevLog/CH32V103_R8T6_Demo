/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2020/10/20
 * Description        : Main program body.
 *******************************************************************************/
#include "debug.h"
#include "usart.h"

/*******************************************************************************
 * Function Name  : main
 * Description    : Main program.
 * Input          : None
 * Return         : None
 *******************************************************************************/
int main(void) {
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

    USARTx_CFG();

    USARTx_SendStr(USART2, "This is a test data.\n");

    while (1)
        ;
}
