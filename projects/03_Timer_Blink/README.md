# Proje 03: Timer ile LED Yakma (Interrupt)

Bu proje, işlemciyi bloklamadan (durdurmadan) periyodik işlerin nasıl yapılacağını öğretir. `HAL_Delay` kullanmak yerine donanımsal **Timer (Zamanlayıcı)** kullanılır.

## Hedef
- Mavi LED (PC8), her 1 saniyede bir yanıp sönecek.
- `main` döngüsü (`while(1)`) tamamen boş olacak!

## Donanım Bağlantısı
- **LED**: PC8 (Mavi LED)

## Nasıl Çalıştırılır?

1.  STM32CubeIDE'de **Yeni STM32 Projesi** başlatın.
2.  **.ioc Dosyası Ayarları**:
    - **PC8**: `GPIO_Output` olarak ayarlayın.
    - **Timers > TIM2**:
        - **Clock Source**: `Internal Clock`.
        - **Prescaler**: `7999` (8 MHz varsayılan saat hızı için).
        - **Counter Period**: `999`.
        - **NVIC Settings**: `TIM2 global interrupt` kutucuğunu işaretleyin (Enable).
3.  Projeyi oluşturun (Generate Code).
4.  `Core/Src/main.c` dosyasını verilen kodla güncelleyin.
5.  Kodu yükleyin.

## Kodun Mantığı
- **Prescaler (Ön Bölücü)**: İşlemci saatini böler. 8 MHz / 8000 = 1000 Hz (Timer saniyede 1000 kez sayar).
- **Period (Periyot)**: Timer kaça kadar sayacak? 1000'e kadar (0-999).
- **Sonuç**: Saniyede 1 kez `HAL_TIM_PeriodElapsedCallback` fonksiyonu çağrılır ve LED durumu değiştirilir.
