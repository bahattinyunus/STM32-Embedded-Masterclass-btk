# 📂 06-I2C_DS3231_RTC

## 🎯 Amaç
I2C haberleşme protokolünü kullanarak harici bir DS3231 RTC (Real Time Clock) modülünden zaman verisi okumayı ve yazmayı öğreniyoruz.

## 🛠 Kullanılan Donanımlar
- [x] STM32F407G-DISC1
- [x] DS3231 RTC Modülü

## 📝 Teorik Bilgi
- **I2C (Inter-Integrated Circuit):** İki telli (SDA, SCL) senkron haberleşme protokolüdür. Birden fazla cihaz (Master-Slave) aynı hatta bağlanabilir.
- **RTC:** Sistemin elektriği kesilse bile (pil sayesinde) zamanı tutmaya devam eden entegredir.

## 🔌 Bağlantı Şeması
| STM32 Pin | DS3231 Pin | Açıklama |
| :---: | :---: | :--- |
| PB6 | SCL | Saat Hattı |
| PB7 | SDA | Veri Hattı |
| 3.3V | VCC | Güç |
| GND | GND | Toprak |

## 💻 Kod Özeti
```c
// I2C üzerinden veri okuma
HAL_I2C_Mem_Read(&hi2c1, DS3231_ADDR, REG_SECONDS, 1, &seconds, 1, 100);
```
