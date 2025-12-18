# 📂 04-Timer_PWM

## 🎯 Amaç
Timer (Zamanlayıcı) birimini kullanarak PWM (Pulse Width Modulation) sinyali üretmeyi ve bu sinyal ile bir LED'in parlaklığını kontrol etmeyi (Breathing LED) öğreniyoruz.

## 🛠 Kullanılan Donanımlar
- [x] STM32F407G-DISC1

## 📝 Teorik Bilgi
- **Timer:** Hassas zamanlama işlemleri yapan donanımdır.
- **PWM:** Sinyalin "açık" kalma süresini (Duty Cycle) değiştirerek ortalama voltajı kontrol etme yöntemidir.
- **Duty Cycle:** Sinyalin periyodunun ne kadarında yüksek (logic 1) olduğunu belirten oran (örneğin %50).

## 💻 Kod Özeti
```c
// PWM Sinyalini başlat
HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);

// Duty Cycle'ı değiştirerek parlaklığı ayarla
__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, dutyCycle);
```
