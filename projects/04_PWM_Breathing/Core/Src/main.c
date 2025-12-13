/*
 * 04_PWM_Breathing
 * Hedef: STM32F100RBT6 (STM32VLDISCOVERY)
 *
 * Açıklama: 
 * TIM3 Channel 3 (PC8) üzerindeki LED'in parlaklığını
 * PWM (Pulse Width Modulation) ile yavaşça artırıp azaltır.
 */

#include "main.h"

TIM_HandleTypeDef htim3;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM3_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_TIM3_Init();

  /* PWM Sinyal Üretimini Başlat (Kanal 3 - PC8) */
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);

  int16_t pwm_value = 0;
  int8_t step = 10; // Artış/Azalış miktarı

  while (1)
  {
    /* PWM Doluluk Oranını (Duty Cycle) Ayarla */
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, pwm_value);

    /* Parlaklığı değiştir */
    pwm_value += step;

    /* Sınırlara ulaşıldıysa yönü tersine çevir */
    if (pwm_value >= 1000) // Period değerimiz 999
    {
      pwm_value = 1000;
      step = -10; // Azalmaya başla
    }
    else if (pwm_value <= 0)
    {
      pwm_value = 0;
      step = 10; // Artmaya başla
    }

    /* Gözün algılayabilmesi için küçük gecikme */
    HAL_Delay(10);
  }
}

static void MX_TIM3_Init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  htim3.Instance = TIM3;
  
  /*
   * PWM Frekansı Ayarı:
   * Hedef: Göz kırpmayı engellemek için > 60Hz. 
   * 8 MHz / (79+1) = 100 kHz Timer Hızı
   * 100 kHz / (999+1) = 100 Hz PWM Frekansı
   */
  htim3.Init.Prescaler = 79;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 999; 
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  
  HAL_TIM_Base_Init(&htim3);
  
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig);
  
  HAL_TIM_PWM_Init(&htim3);

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig);

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0; // Başlangıç doluluk oranı %0
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3);
}

void SystemClock_Config(void) { } // Varsayılan

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  __HAL_RCC_GPIOC_CLK_ENABLE();
  
  /* PC8, TIM3 tarafından kontrol edilecek (Alternate Function) */
  /* Bu yüzden GPIO Init kısmında sadece Clock Enable yeterlidir */
  /* Ancak CubeMX bazen buraya da kod ekler. Biz manuel olarak AF modunu TIM3 Init içinde hallediyoruz */
  
  // Sadece PC9 (Yeşil LED) sönük kalsın diye ekleyebiliriz
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void Error_Handler(void) { __disable_irq(); while (1) { } }
