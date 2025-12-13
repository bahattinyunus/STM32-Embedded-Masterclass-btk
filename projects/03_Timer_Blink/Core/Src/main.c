/*
 * 03_Timer_Blink
 * Hedef: STM32F100RBT6 (STM32VLDISCOVERY)
 *
 * Açıklama: 
 * TIM2 zamanlayıcısını kullanarak her 1 saniyede bir kesme (interrupt) oluşturur.
 * Kesme fonksiyonu (Callback) içinde Mavi LED (PC8) durumu değiştirilir.
 */

#include "main.h"

TIM_HandleTypeDef htim2;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);

int main(void)
{
  /* MCU Yapılandırması */
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_TIM2_Init();

  /* Timer'ı Kesme (Interrupt) modunda başlat */
  HAL_TIM_Base_Start_IT(&htim2);

  /* Sonsuz döngü - İşlemci burada başka işler yapabilir */
  while (1)
  {
    /* 
     * LED yakıp söndürme işlemi burada YAPILMAZ.
     * Bu işlem tamamen Timer Interrupt tarafından arka planda halledilir.
     * Burası boştur, işlemci uyku moduna alınabilir.
     */
  }
}

/* Timer Periyodu Tamamlandığında Çağrılan Fonksiyon (Interrupt Callback) */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  // Eğer kesmeyi oluşturan TIM2 ise
  if (htim->Instance == TIM2)
  {
    // Mavi LED'i (PC8) toggle et (durumunu değiştir)
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
  }
}

static void MX_TIM2_Init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  htim2.Instance = TIM2;
  
  /*
   * HESAPLAMA:
   * Hedef Frekans = 1 Hz (1 Saniye)
   * Sistem Saati (Varsayılan HSI) = 8 MHz (veya standart konfigürasyonda 24 MHz)
   * 
   * Formül: Update Event = TIM_CLK / ((Prescaler + 1) * (Period + 1))
   * 
   * Varsayalım Clock = 8 MHz (8,000,000 Hz)
   * Prescaler = 7999 (Yani 8000'e böl) -> Timer Sayacı Hızı = 1 kHz (1000 Hz)
   * Period = 999 (Yani 1000 sayım yap) -> 1000 Hz / 1000 = 1 Hz (1 Saniye)
   */
  
  htim2.Init.Prescaler = 7999; 
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
}

void SystemClock_Config(void) { } // Varsayılan

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /* LED Pini (PC8) Yapılandırması */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
  
  GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void Error_Handler(void) { __disable_irq(); while (1) { } }
