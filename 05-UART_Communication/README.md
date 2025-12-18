# 📂 05-UART_Communication

## 🎯 Amaç
Mikrodenetleyici ile bilgisayar arasında UART (Universal Asynchronous Receiver-Transmitter) protokolü üzerinden seri haberleşme kurmayı öğreniyoruz.

## 🛠 Kullanılan Donanımlar
- [x] STM32F407G-DISC1
- [x] USB Kablo (Sanal COM Port üzerinden)

## 📝 Teorik Bilgi
- **UART:** Asenkron seri haberleşme protokolüdür. İki cihaz (TX ve RX hatları) arasında veri akışı sağlar.
- **Baud Rate:** Saniyedeki veri transfer hızıdır (Örn: 9600, 115200 bps).

## 💻 Kod Özeti
```c
char msg[] = "Merhaba STM32!\r\n";
// Veri Gönderme
HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), 100);

// Veri Alma
HAL_UART_Receive(&huart2, rxBuffer, 10, 100);
```
