# 📂 07-SPI_LIS3DSH_Accelerometer

## 🎯 Amaç
STM32F4 Discovery kartı üzerinde dahili olarak bulunan LIS3DSH ivmeölçer sensörü ile SPI protokolü üzerinden haberleşmeyi ve X, Y, Z eksenlerindeki ivme verilerini okumayı öğreniyoruz.

## 🛠 Kullanılan Donanımlar
- [x] STM32F407G-DISC1 (Dahili LIS3DSH Sensörü)

## 📝 Teorik Bilgi
- **SPI (Serial Peripheral Interface):** Yüksek hızlı, tam çift yönlü (Full Duplex) senkron haberleşme protokolüdür. (MOSI, MISO, SCK, CS pinleri).
- **MEMS İvmeölçer:** Hareketi ve yerçekimini algılayan sensördür.

## 🔌 Bağlantı Şeması
LIS3DSH sensörü kart üzerinde dahili olarak SPI1 hattına bağlıdır:
| STM32 Pin | LIS3DSH Pin |
| :---: | :---: |
| PA5 | SCK |
| PA6 | MISO |
| PA7 | MOSI |
| PE3 | CS (Chip Select) |

## 💻 Kod Özeti
```c
// SPI üzerinden veri okuma
HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET); // CS Low
HAL_SPI_Transmit(&hspi1, &regAddr, 1, 100);
HAL_SPI_Receive(&hspi1, &data, 1, 100);
HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);   // CS High
```
