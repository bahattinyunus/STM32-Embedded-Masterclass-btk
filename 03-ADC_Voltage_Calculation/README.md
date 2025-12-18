# 📂 03-ADC_Voltage_Calculation

## 🎯 Amaç
STM32'nin ADC (Analog-to-Digital Converter) birimini kullanarak analog sinyalleri dijital verilere dönüştürmeyi ve gerçek voltaj/sıcaklık değerlerini hesaplamayı öğreniyoruz.

## 🛠 Kullanılan Donanımlar
- [x] STM32F407G-DISC1
- [ ] Dahili Sıcaklık Sensörü (Internal Temperature Sensor)

## 📝 Teorik Bilgi
- **ADC:** Analog sinyalleri (voltaj), işlemcinin anlayabileceği dijital sayılara dönüştürür.
- **Çözünürlük (Resolution):** STM32F4 ADC'si 12-bit çözünürlüğe sahiptir (0 - 4095 arası değerler).
- **Referans Voltajı:** Genellikle 3.3V (VDD) referans alınır.

## 💻 Kod Özeti
```c
// ADC dönüşümünü başlat
HAL_ADC_Start(&hadc1);
// Dönüşümün tamamlanmasını bekle
if (HAL_ADC_PollForConversion(&hadc1, 100) == HAL_OK) {
    uint32_t adcValue = HAL_ADC_GetValue(&hadc1);
    // Voltaj hesabı (3.3V Referans, 12-bit)
    float voltage = (adcValue * 3.3) / 4095.0;
}
```
