# Proje 06: UART ile Veri Gönderme (Serial TX)

Bu proje, mikrodenetleyicinin dış dünya ile konuşmasını sağlar. **UART (Universal Asynchronous Receiver-Transmitter)** protokolü kullanılarak saniyede bir mesaj gönderilir.

## Donanım Bağlantısı
- **TX Pini (Gönderen)**: PA9 (USART1_TX)
- **RX Pini (Alan)**: PA10 (USART1_RX)
- **Önemli Not**: STM32VLDISCOVERY üzerindeki USB portu, doğrudan sanal seri port (VCP) desteklemez. Bu mesajları bilgisayarda görmek için harici bir **USB-TTL Dönüştürücü** (örneğin CH340 veya FTDI) kullanmanız ve PA9 pinini dönüştürücünün RX pinine bağlamanız gerekir.

## Nasıl Çalıştırılır?

1.  STM32CubeIDE'de **Yeni STM32 Projesi** başlatın.
2.  **.ioc Dosyası Ayarları**:
    - **Connectivity > USART1**:
        - **Mode**: Asynchronous.
        - **Baud Rate**: 9600 Bits/s.
3.  Projeyi oluşturun (Generate Code).
4.  `Core/Src/main.c` dosyasını verilen kodla güncelleyin.
5.  Kodu yükleyin.

## Kodun Mantığı
- `HAL_UART_Transmit`: Belirlenen kanaldan (USART1), belirlenen veriyi (msg) gönderir.
- `\r\n`: Satır sonu karakterleridir (Carriage Return + New Line).
