# Proje 05: ADC ile Dahili Sıcaklık Okuma

Bu proje, işlemcinin içinde gömülü olan sıcaklık sensörünü **ADC (Analog-Digital Converter)** kullanarak okur.

## Hedef
- Çipin çekirdek sıcaklığını (°C) hesaplamak.
- `adc_raw_value` ve `temperature_c` değişkenlerini izleyerek sonucu görmek.

## Donanım Bağlantısı
- **Sensör**: Dahili (İşlemcinin içinde). Dışarıdan bir şey bağlamanıza gerek yok.

## Nasıl Çalıştırılır?

1.  STM32CubeIDE'de **Yeni STM32 Projesi** başlatın.
2.  **.ioc Dosyası Ayarları**:
    - **Analog > ADC1**:
        - **Temperature Sensor Channel**: İşaretleyin (IN16).
        - **Configuration > Parameter Settings**:
            - **Scan Conversion Mode**: Disabled.
            - **Continuous Conversion Mode**: Disabled.
            - **Rank 1**: Channel 16, Sampling Time: **239.5 Cycles** (Çok önemli! Sıcaklık sensörü yavaştır, en uzun süreyi seçin).
3.  Projeyi oluşturun (Generate Code).
4.  `Core/Src/main.c` dosyasını verilen kodla güncelleyin.
5.  Kodu yükleyin (Debug Butonu / Böcek simgesi).

## Nasıl Gözlemlenir? (Live Expressions)
Bu projede LED yanıp sönmez. Sonucu görmek için IDE'nin Debug özelliklerini kullanmalısınız:

1.  Debug modunda kodu çalıştırın.
2.  Sağ üstteki **Live Expressions** sekmesine gelin (yoksa *Window > Show View > Live Expressions*).
3.  `temperature_c` yazıp Enter'a basın.
4.  Kodu *Resume* (F8) ile koşturun.
5.  Sıcaklık değerini canlı olarak göreceksiniz!
