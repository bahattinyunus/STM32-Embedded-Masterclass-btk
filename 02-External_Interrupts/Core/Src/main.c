/*
 * 02_Button_Control
 * Hedef: STM32F100RBT6 (STM32VLDISCOVERY)
 *
 * Açıklama: 
 * Kullanıcı butonuna (PA0) basıldığında Yeşil LED'i (PC9) yakar.
 * Buton bırakıldığında LED söner.
 */

#include "main.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

int main(void)
{
  /* MCU Yapılandırması */
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  /* Sonsuz döngü */
  while (1)
  {
    // PA0 pinini oku (Buton)
    // GPIO_PIN_SET = 1 (High/VCC) -> Basılı
    // GPIO_PIN_RESET = 0 (Low/GND) -> Basılı Değil
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET) 
    {
      // Butona basıldı, LED'i yak
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
    }
    else 
    {
      // Butona basılı değil, LED'i söndür
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
    }
    
    // Küçük bir gecikme (Debounce için basit önlem)
    HAL_Delay(10);
  }
}

void SystemClock_Config(void)
{
  // Varsayılan saat yapılandırması
}

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Portları Saatini Etkinleştir */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /* LED Pini (PC9) Yapılandırması: Çıkış (Output) */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET); // Başlangıçta sönük
  
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Push-Pull Çıkış
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* Buton Pini (PA0) Yapılandırması: Giriş (Input) */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT; // Giriş Modu
  GPIO_InitStruct.Pull = GPIO_NOPULL;     // Harici pull-down direnci olduğu varsayılır (şematiğe göre değişebilir, genellikle Floating veya PullDown denenir)
                                          // VLDISCOVERY şematiğine göre PA0'da harici eleman olabilir, Floating güvenlidir.
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void Error_Handler(void)
{
  __disable_irq();
  while (1) { }
}
