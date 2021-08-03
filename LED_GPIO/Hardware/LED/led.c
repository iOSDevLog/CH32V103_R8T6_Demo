#include "led.h"

void LED_Init(void) {
    GPIO_InitTypeDef GPIO_InitStructure;           // ����һ��GPIO_InitTypeDef���͵Ľṹ��

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);   // ʹ����LED��ص�GPIO�˿�ʱ��

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1; // ����GPIO����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     // ����GPIOģʽΪ�������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;    // ����GPIO������ٶ�
    GPIO_Init(GPIOA, &GPIO_InitStructure);               // ���ÿ⺯������ʼ��GPIOA

    GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1);           // ������������ߵ�ƽ
}
