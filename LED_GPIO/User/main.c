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

    Delay_Init();   // ��ʱ������ʼ��
    LED_Init();     // LED ��ʼ��
    while (1) {
        Delay_Ms(250); // ��ʱ 250ms
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, (i == 0) ? (i = Bit_SET) : (i =
                                                            Bit_RESET)); // ���� PA0����״̬Ϊ�͵�ƽ
        Delay_Ms(250); // ��ʱ 250ms
        GPIO_WriteBit(GPIOA, GPIO_Pin_1, (j == 0) ? (j = Bit_SET) : (j =
                                                            Bit_RESET)); // ���� PA1����״̬Ϊ�͵�ƽ
    }
}
