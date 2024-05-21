#include "stm32f407xx.h"

USART_HandleTypeDef_t USART_Handle;

static void GPIO_Config(void);
static void UART_Config(void);

void USART2_IRQHandler()
{
	USART_InterruptHandler(&USART_Handle);

}

int main(void)
{

	char msgToSend[] = "Hey how are you \n" ;
	char receiveData[30];

	GPIO_Config();
	UART_Config();

	USART_TransmitData_IT(&USART_Handle, (uint8_t*)msgToSend, strlen(msgToSend));
	USART_ReceiveData_IT(&USART_Handle, (uint8_t*)receiveData, 20);

	while(1);

}

static void UART_Config(void)
{
	RCC_USART2_CLK_ENABLE();

	USART_Handle.Instance = USART2;
	USART_Handle.Init.BaudRate = 115200;
	USART_Handle.Init.HardWareFlowControl = USART_HW_NONE;
	USART_Handle.Init.Mode = USART_MODE_Tx_Rx;
	USART_Handle.Init.OverSampling = USART_OVERSAMPLE_16;
	USART_Handle.Init.Parity = USART_PARITY_NONE;
	USART_Handle.Init.StopBits = USART_STOPBITS_1;
	USART_Handle.Init.WordLength = USART_WORDLENGTH_8Bits;

	USART_Init(&USART_Handle);

	NVIC_EnableInterrupt(USART2_IRQn);

	USART_PeriphCmd(&USART_Handle, ENABLE);

}
static void GPIO_Config(void)
{
	GPIO_InitTypeDef_t GPIO_InitStruct = { 0 };

	RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.pinNumber = GPIO_PIN_2 | GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_AF;
	GPIO_InitStruct.Otype = GPIO_OTYPE_PP;
	GPIO_InitStruct.PuPdr = GPIO_PUPD_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_VERY;
	GPIO_InitStruct.Alternate = GPIO_AF7;

	GPIO_Init(GPIOA, &GPIO_InitStruct);

}
