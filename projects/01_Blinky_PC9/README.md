# Proje 01: Blinky (Yanıp Sönen LED)

Bu proje, gömülü sistemlerin "Merhaba Dünya"sıdır. Kart üzerindeki Kullanıcı LED'lerini yakıp söndürür.

## Hedef Donanım
- **Kart**: STM32VLDISCOVERY
- **MCU**: STM32F100RBT6
- **LED'ler**:
    - **Yeşil**: PC9
    - **Mavi**: PC8

## Nasıl İçe Aktarılır (Import)
1.  STM32CubeIDE'yi açın.
2.  Yeni bir STM32 Projesi başlatın (Start a new STM32 Project).
3.  Board Selector'dan "STM32VLDISCOVERY"yi veya MCU Selector'dan "STM32F100RB"yi seçin.
4.  Sıfırdan oluşturuyorsanız:
    - RCC'yi etkinleştirin (High Speed Clock).
    - PC9 ve PC8'i GPIO_Output olarak ayarlayın.
    - Kodu Oluşturun (Generate Code).
5.  `main.c` içindeki sağlanan kod parçacığını kullanıyorsanız, içeriği oluşturulan projenizin `Src/main.c` dosyasındaki `while(1)` döngüsüne ve ilgili fonksiyon tanımlarına kopyalayın.

## Kod Açıklaması
- `HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9)`: C Portu üzerindeki 9. Pinin durumunu değiştirir (Açıksa kapatır, kapalıysa açar).
- `HAL_Delay(500)`: Yürütmeyi 500 milisaniye duraklatır.
