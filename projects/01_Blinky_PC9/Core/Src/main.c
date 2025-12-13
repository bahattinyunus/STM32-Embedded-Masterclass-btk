/*
 * 01_Blinky_PC9
 * Hedef: STM32F100RBT6 (STM32VLDISCOVERY)
 *
 * Açıklama: PC9'a bağlı Yeşil LED'i yakıp söndürür (Blink).
 *
 * Not: Bu dosya kavramsal bir şablondur. STM32CubeIDE'de, 
 * HAL başlatma kodunu genellikle .ioc dosyası aracılığıyla oluşturursunuz.
 */

#include "main.h"

// Basit gecikme fonksiyonu (hassas değildir)
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

void my_delay(volatile uint32_t count) {
    while(count--) {
        __asm("nop");
    }
}

int main(void)
{
  /* MCU Yapılandırması--------------------------------------------------------*/

  /* Tüm çevre birimlerini sıfırla, Flash arayüzünü ve Systick'i başlat. */
  HAL_Init();

  /* Sistem saatini yapılandır */
  SystemClock_Config();

  /* Yapılandırılmış tüm çevre birimlerini başlat */
  MX_GPIO_Init();

  /* Sonsuz döngü */
  while (1)
  {
    // PC9'u Değiştir (Yeşil LED)
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
    
    // PC8'i Değiştir (Mavi LED)
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
    
    // Gecikme (saat hızına bağlı olarak ~500ms)
    HAL_Delay(500);
  }
}

/**
  * @brief Sistem Saati Yapılandırması
  * @retval None
  */
void SystemClock_Config(void)
{
  // Sistem Saati Yapılandırma kodu CubeMX tarafından burada oluşturulur
  // STM32F100 (Value Line) için, genellikle HSI veya HSE kullanılır.
}

/**
  * @brief GPIO Başlatma Fonksiyonu
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Portları Saatini Etkinleştir */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*GPIO pin Çıkış Seviyesini Yapılandır */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*GPIO pinlerini yapılandır : PC8 PC9 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
}
