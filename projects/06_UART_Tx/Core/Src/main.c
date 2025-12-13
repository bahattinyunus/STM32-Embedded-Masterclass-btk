/*
 * 06_UART_Tx
 * Hedef: STM32F100RBT6 (STM32VLDISCOVERY)
 *
 * Açıklama:
 * UART1 üzerinden (PA9=TX) saniyede bir "Merhaba Dunya" mesajı gönderir.
 * Not: Bu mesajı PC'de görmek için USB-TTL Dönüştürücü gerekebilir.
 */

#include "main.h"
#include <string.h> // strlen için gerekli

UART_HandleTypeDef huart1;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART1_UART_Init();

  char *msg = "Merhaba STM32 Dunyasi!\r\n";

  while (1)
  {
    /* UART üzerinden mesaj gönder */
    // (UART Handle, Veri, Veri Uzunluğu, Zaman Aşımı)
    HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), 100);

    HAL_Delay(1000);
  }
}

static void MX_USART1_UART_Init(void)
{
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
}

static void MX_GPIO_Init(void)
{
  // USART1 PA9 (TX) ve PA10 (RX) pinlerini kullanır.
  // HAL_UART_Init içinde otomatik yapılandırılır (MSP Init).
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_USART1_CLK_ENABLE();
  
  /* Manuel Pin Yapılandırması (Eğer CubeMX oluşturmazsa diye) */
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = GPIO_PIN_9; // TX
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void SystemClock_Config(void) { }
void Error_Handler(void) { __disable_irq(); while (1) { } }
