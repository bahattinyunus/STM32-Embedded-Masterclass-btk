# 📂 [Proje İsmi]

## 🎯 Amaç
Bu dersin/projenin temel amacını buraya yazın. (Örn: Bu bölümde GPIO pinlerinin nasıl çıkış olarak ayarlanacağını ve bir LED'in nasıl yakılıp söndürüleceğini öğreneceğiz.)

## 🛠 Kullanılan Donanımlar
- [ ] STM32F407G-DISC1
- [ ] (Varsa diğer modüller)

## 📝 Teorik Bilgi
Bu projede kullanılan çevre birimi (peripheral) hakkında kısa teorik bilgi.
- **Konu 1:** Açıklama
- **Konu 2:** Açıklama

## 🔌 Bağlantı Şeması
Varsa pin bağlantılarını listeleyin:
| STM32 Pin | Modül Pin | Açıklama |
| :---: | :---: | :--- |
| PA5 | LED | Dahili LED |
| ... | ... | ... |

## 💻 Kod Özeti
Önemli kod bloklarını veya fonksiyonları burada açıklayın.

```c
// Örnek Kod Parçası
HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
HAL_Delay(1000);
```
