# Donanım Kılavuzu: STM32VLDISCOVERY (MB913)

## Genel Bakış
STM32VLDISCOVERY, STM32 "value line" serisini keşfetmek için düşük maliyetli ve hızlı bir yoldur. Hem yeni başlayanlar hem de deneyimli kullanıcılar için hızlı bir başlangıç yapmak adına gereken her şeyi içerir.

## Pin Tanımları

Kart, pinleri standart 2.54mm başlıklar (header) aracılığıyla dışarı verir.

### LED'ler
| LED Adı | Pin | Renk | Durum |
| :--- | :--- | :--- | :--- |
| **LD3** | **PC9** | Yeşil | Yüksek (High) = AÇIK, Düşük (Low) = KAPALI |
| **LD4** | **PC8** | Mavi | Yüksek (High) = AÇIK, Düşük (Low) = KAPALI |

### Kullanıcı Butonu
| Buton | Pin | Fonksiyon |
| :--- | :--- | :--- |
| **USER** | **PA0** | Giriş (Floating/Boşta). Basıldığında Yüksek (VDD), Bırakıldığında Düşük (GND). *Not: Pull-up/down yapılandırması için şematiği kontrol edin.* |

## Genişletme Başlıkları (Headers)

Başlıklar genellikle doğrudan MCU portlarına eşleşir.
- **Başlık P1**: VDD, GND, NRST, PC0-PC5, PB0-PB2, PA0-PA7.
- **Başlık P2**: PB10-PB15, PC6-PC9, PA8-PA15, PC10-PC12, PD2.

*Bu pinlerdeki alternatif fonksiyonlar (UART, SPI, I2C) için STM32F100RB veri sayfasına (datasheet) başvurun.*

## Güç Kaynağı
Kart, USB kablosu (CN1) üzerinden güç alır.
- **5V**: USB tarafından sağlanır.
- **3.3V**: MCU için kart üzerinde regüle edilir.

## Programlama Arayüzü
- **CN1 (USB)**: Hem güç hem de ST-LINK/V1 hata ayıklama/programlama için kullanılır.
- **CN2 (SWD)**: Kart üzerindeki ST-LINK'i *harici* STM32 hedeflerini programlamak için kullanmanızı sağlar (CN3 jumper'larını çıkarmayı gerektirir).

**Varsayılan CN3 Jumper Yapılandırması**: Kart üzerindeki STM32F100 MCU'yu programlamak için her iki jumper da **TAKILI** olmalıdır.
