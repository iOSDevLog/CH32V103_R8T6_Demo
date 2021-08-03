/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2020/09/29
 * Description        : Main program body.
 *******************************************************************************/
#include "debug.h"
#include "led.h"

int main(void) {
    u8 i = 0;
    u8 j = 0;

    Delay_Init();   // 延时函数初始化
    LED_Init();     // LED 初始化
    while (1) {
        Delay_Ms(250); // 延时 250ms
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, (i == 0) ? (i = Bit_SET) : (i =
                                                            Bit_RESET)); // 设置 PA0引脚状态为低电平
        Delay_Ms(250); // 延时 250ms
        GPIO_WriteBit(GPIOA, GPIO_Pin_1, (j == 0) ? (j = Bit_SET) : (j =
                                                            Bit_RESET)); // 设置 PA1引脚状态为低电平
    }
}
