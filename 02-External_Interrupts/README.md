# 📂 02-External_Interrupts

## 🎯 Amaç
Bu projede, harici bir buton kullanarak STM32'nin kesme (interrupt) mekanizmasını öğreniyoruz. Butona basıldığında ana döngüyü (main loop) bloklamadan bir LED'in durumunu değiştireceğiz.

## 🛠 Kullanılan Donanımlar
- [x] STM32F407G-DISC1

## 📝 Teorik Bilgi
- **Interrupt (Kesme):** İşlemcinin o anki işini bırakıp daha öncelikli bir olaya cevap vermesidir.
- **EXTI (External Interrupt):** GPIO pinlerindeki voltaj değişimlerini (yükselen/düşen kenar) algılayarak kesme üretir.
- **NVIC (Nested Vectored Interrupt Controller):** Kesmelerin önceliklerini ve yönetimini sağlayan birimdir.

## 🔌 Bağlantı Şeması
| STM32 Pin | Bağlantı | Açıklama |
| :---: | :---: | :--- |
| PA0 | Buton | Kart üzerindeki Mavi (User) Buton |
| PD12 | LED | Yeşil LED |

## 💻 Kod Özeti
```c
// Kesme Geri Çağırma Fonksiyonu (Callback)
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == GPIO_PIN_0) {
        // Butona basıldığında LED durumunu değiştir
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
    }
}
```
