# 📂 01-GPIO_Blinky

## 🎯 Amaç
Bu bölümde STM32F4 Discovery kartı üzerindeki dahili LED'leri kullanarak GPIO (General Purpose Input Output) biriminin çıkış olarak nasıl yapılandırılacağını ve kontrol edileceğini öğreniyoruz. Temel hedef, "Merhaba Dünya" niteliğindeki LED yakıp söndürme (Blink) uygulamasını gerçekleştirmektir.

## 🛠 Kullanılan Donanımlar
- [x] STM32F407G-DISC1

## 📝 Teorik Bilgi
- **GPIO (General Purpose Input/Output):** Mikrodenetleyicinin dış dünya ile iletişim kurmasını sağlayan en temel birimidir.
- **RCC (Reset and Clock Control):** Çevre birimlerinin çalışabilmesi için gerekli saat sinyalini sağlar. GPIO kullanmadan önce ilgili portun saat hattı aktif edilmelidir.

## 🔌 Bağlantı Şeması
Discovery kartı üzerindeki dahili LED pinleri:
| STM32 Pin | Renk | Açıklama |
| :---: | :---: | :--- |
| PD12 | Yeşil | Kullanıcı LED 1 |
| PD13 | Turuncu| Kullanıcı LED 2 |
| PD14 | Kırmızı| Kullanıcı LED 3 |
| PD15 | Mavi | Kullanıcı LED 4 |

## 💻 Kod Özeti
```c
// PD12 pinini tersle (Yak/Söndür)
HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
// 1000 ms (1 saniye) bekle
HAL_Delay(1000);
```
