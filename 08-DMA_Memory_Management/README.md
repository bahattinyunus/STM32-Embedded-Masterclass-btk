# 📂 08-DMA_Memory_Management

## 🎯 Amaç
DMA (Direct Memory Access) birimini kullanarak işlemciyi (CPU) meşgul etmeden hafızadan hafızaya veya çevresel birimden hafızaya yüksek hızlı veri transferi yapmayı öğreniyoruz.

## 🛠 Kullanılan Donanımlar
- [x] STM32F407G-DISC1

## 📝 Teorik Bilgi
- **DMA:** İşlemci müdahalesi olmadan veri transferi sağlayan donanım birimidir. İşlemci yükünü önemli ölçüde azaltır.
- **Stream/Channel:** DMA'nın farklı kaynaklardan veri taşımasını sağlayan kanallardır.

## 💻 Kod Özeti
```c
// ADC verisini DMA ile belleğe otomatik aktar
HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adcBuffer, BUFFER_SIZE);

// İşlemci bu sırada başka işler yapabilir
while(1) {
    // ...
}
```
