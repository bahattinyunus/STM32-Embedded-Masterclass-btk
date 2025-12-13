/*
 * 05_ADC_InternalTemp
 * Hedef: STM32F100RBT6 (STM32VLDISCOVERY)
 *
 * Açıklama:
 * ADC1 Kanal 16'ya bağlı olan dahili sıcaklık sensörünü okur.
 * Okunan ham değeri (0-4095) formül ile sıcaklığa (°C) çevirir.
 */

#include "main.h"

ADC_HandleTypeDef hadc1;

/* İzlenecek Değişkenler (Live Watch) */
volatile uint32_t adc_raw_value = 0;
volatile float temperature_c = 0.0f;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_ADC1_Init();

  /* ADC Kalibrasyonu (Ölçüm doğruluğu için önemlidir) */
  HAL_ADCEx_Calibration_Start(&hadc1);

  while (1)
  {
    /* 1. ADC Çevrimini Başlat */
    HAL_ADC_Start(&hadc1);

    /* 2. Çevrimin bitmesini bekle (Timeout: 10ms) */
    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
    {
      /* 3. Değeri Oku */
      adc_raw_value = HAL_ADC_GetValue(&hadc1);

      /*
       * 4. Hesaplama (Datasheet'e göre yaklaşık değerler)
       * Vref = 3.3V
       * V_sense = (adc_raw / 4095) * 3.3
       * Temp = (V25 - V_sense) / Slope + 25
       *
       * STM32F100 için tipik değerler:
       * Avg_Slope = 4.3 mV/°C = 0.0043 V/°C
       * V25 = 1.43 V (25°C'deki voltaj)
       */

      float v_sense = ((float)adc_raw_value / 4095.0f) * 3.3f;
      temperature_c = ((1.43f - v_sense) / 0.0043f) + 25.0f;
    }

    /* 500ms bekle */
    HAL_Delay(500);
  }
}

static void MX_ADC1_Init(void)
{
  ADC_ChannelConfTypeDef sConfig = {0};

  /* ADC1 Temel Yapılandırma */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;   // Tek kanal okuyacağız
  hadc1.Init.ContinuousConvMode = DISABLE;      // Sürekli değil, elle tetikleyeceğiz
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START; // Yazılımla başlat
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;

  if (HAL_ADC_Init(&hadc1) != HAL_OK) { Error_Handler(); }

  /* Kanal 16 (Sıcaklık Sensörü) Yapılandırması */
  sConfig.Channel = ADC_CHANNEL_16; // Dahili Sıcaklık Sensörü
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5; // En hassas ölçüm için en uzun süre
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) { Error_Handler(); }
}

/* GPIO Init (ADC için gerekli olmayabilir ama standarttır) */
static void MX_GPIO_Init(void)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
}

void SystemClock_Config(void) { }
void Error_Handler(void) { __disable_irq(); while (1) { } }
