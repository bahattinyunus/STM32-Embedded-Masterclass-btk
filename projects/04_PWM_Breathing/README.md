# Proje 04: PWM ile Nefes Alan LED (Breathing LED)

Bu proje, LED'in parlaklığını **PWM (Pulse Width Modulation)** yöntemiyle kontrol eder. LED aniden yanıp sönmek yerine, yavaşça parlayıp solar ("Nefes Alma" efekti).

## Hedef
- Mavi LED (PC8), parlaklığını %0'dan %100'e çıkarıp tekrar düşürecek.

## Donanım Bağlantısı
- **LED**: PC8 (STM32F100RB'de TIM3_CH3 pinine bağlıdır).

## Nasıl Çalıştırılır?

1.  STM32CubeIDE'de **Yeni STM32 Projesi** başlatın.
2.  **.ioc Dosyası Ayarları**:
    - **Timers > TIM3**:
        - **Clock Source**: `Internal Clock`.
        - **Channel 3**: `PWM Generation CH3`.
        - **Configuration > Parameter Settings**:
            - **Prescaler**: `79` (100 Hz PWM Frekansı için).
            - **Counter Period**: `999` (Adım hassasiyeti).
3.  Projeyi oluşturun (Generate Code).
4.  `Core/Src/main.c` dosyasını verilen kodla güncelleyin.
5.  Kodu yükleyin.

## Kodun Mantığı
- **Duty Cycle (Görev Döngüsü)**: PWM sinyalinin ne kadar süre "Yüksek" (High) kaldığını belirler.
- `__HAL_TIM_SET_COMPARE`: Bu değer değiştikçe LED'e giden ortalama voltaj değişir, böylece parlaklık değişir.
