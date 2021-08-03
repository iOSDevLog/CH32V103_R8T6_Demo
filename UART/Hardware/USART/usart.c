#include "usart.h"

void USART2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

/*******************************************************************************
 * Function Name  : USARTx_CFG
 * Description    : Initializes the USART2  peripheral.
 * Input          : None
 * Return         : None
 *******************************************************************************/
void USARTx_CFG(void) {
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); // ʹ�� ����2 ʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  // ʹ�� GPIOA ʱ��

    USART_DeInit(USART2);

    /* USART2 TX-->A.2   RX-->A.3 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;              // ����PA2Ϊ�����������
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;        // ����PA3Ϊ��������
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 115200;               // ���ô��ڲ�����Ϊ115200
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;  // �ֳ�Ϊ8λ���ݸ�ʽ
    USART_InitStructure.USART_StopBits = USART_StopBits_1;       // 1��ֹͣλ
    USART_InitStructure.USART_Parity = USART_Parity_No;          // ����żУ��λ
    USART_InitStructure.USART_HardwareFlowControl =
    USART_HardwareFlowControl_None;          // ��Ӳ��������
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // ���ͺͽ���ģʽ
    USART_Init(USART2, &USART_InitStructure);                    // ��ʼ������

    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;      // ��ռ���ȼ�Ϊ1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;           // �����ȼ�Ϊ1
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;              // IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);                              // �ж����ȼ���ʼ��

    USART_Cmd(USART2, ENABLE);                                   // ʹ�ܴ���
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);               // �����ж�
}

void USARTx_SendByte(USART_TypeDef* pUSARTx, uint8_t data) {
    USART_SendData(pUSARTx, data);
    while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET)
        ;
}

void USARTx_SendStr(USART_TypeDef* pUSARTx, char *str) {
    uint8_t i = 0;
    do {
        USARTx_SendByte(pUSARTx, *(str + i));
        i++;
    } while (*(str + i) != '\0');
    while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET)
        ;
}

/*******************************************************************************
 * Function Name  : USART2_IRQHandler
 * Description    : This function handles USART2 global interrupt request.
 * Input          : None
 * Return         : None
 *******************************************************************************/
void USART2_IRQHandler(void) {
    uint8_t ucTemp;
    if (USART_GetITStatus(USART2, USART_IT_RXNE) != RESET) // �жϲ���
            {
        USART_ClearITPendingBit(USART2, USART_IT_RXNE);    // ����жϱ�־
        ucTemp = USART_ReceiveData(USART2);               // ��������
        USART_SendData(USART2, ucTemp);                   // ��������
    }
}
