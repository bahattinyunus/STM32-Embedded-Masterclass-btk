![STM32 Learning Hub Banner](assets/banner_v2.png)

<div align="center">

# STM32 İleri Seviye Öğrenme Merkezi
### STM32VLDISCOVERY (MB913) Geliştirme Platformu

[![License](https://img.shields.io/badge/lisans-MIT-blue?style=for-the-badge&logo=github)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-STM32-green?style=for-the-badge&logo=stmicroelectronics)](https://www.st.com)
[![Status](https://img.shields.io/badge/durum-aktif-success?style=for-the-badge)](https://github.com/)
[![Language](https://img.shields.io/badge/dil-C-blue?style=for-the-badge&logo=c)](Core/Src/main.c)

*STM32 dünyasına profesyonel bir adım atın. Bu repo, gömülü sistemler geliştirme, donanım kontrolü ve MCU mimarisi üzerine kapsamlı bir kaynak sunar.*

[Projeler](#-proje-kataloğu) • [Donanım](#-donanım-özeti) • [Başlangıç](#-hızlı-başlangıç) • [Katkıda Bulun](#-katkıda-bulunma)

</div>

---

## 🎯 Proje Amacı

Bu depo, **STM32F100RBT6** mikrodenetleyicisi üzerinde derinlemesine uzmanlaşmak isteyenler için tasarlanmıştır. Her proje, sadece kodu değil, altında yatan donanım prensibini de öğretmeyi hedefler. Basit GPIO işlemlerinden karmaşık çevresel birim (Peripheral) kontrollerine kadar geniş bir yelpaze sunar.

## 📚 Proje Kataloğu

Aşağıdaki projeler, basitten karmaşığa doğru sıralanmıştır. Her biri kendi içinde detaylı açıklamalara sahiptir.

| ID | Proje İsmi | Kategori | Açıklama |
|:--:|:---|:---|:---|
| **01** | [**Blinky (PC9)**](projects/01_Blinky_PC9) | `GPIO` | Temel "Hello World". PC9 pinindeki yeşil LED'i yakıp söndürür. |
| **02** | [**Buton Kontrolü**](projects/02_Button_Control) | `GPIO` | PA0 butonunu okuyarak LED durumunu değiştirir. Input/Output mantığı. |
| **03** | [**Timer Interrupt**](projects/03_Timer_Blink) | `TIM` | Donanım zamanlayıcıları (TIM2) ile hassas zamanlama ve kesme (interrupt) yönetimi. |
| **04** | [**PWM Breathing**](projects/04_PWM_Breathing) | `PWM` | LED parlaklığını Pulse Width Modulation ile nefes alma efekti şeklinde kontrol eder. |
| **05** | [**Dahili Sıcaklık (ADC)**](projects/05_ADC_InternalTemp) | `ADC` | MCU'nun dahili sıcaklık sensörünü okuyarak dijital veriye dönüştürür. |
| **06** | [**UART İletişimi**](projects/06_UART_Tx) | `COMM` | Bilgisayar ile seri haberleşme (Printf ile debugging). |

## 🛠 Donanım Özeti

**Kart:** STM32VLDISCOVERY (MB913)
**MCU:** STM32F100RBT6 (Cortex-M3 @ 24MHz)

| Bileşen | Pin | Not |
|:---|:---:|:---|
| **Yeşil LED** | `PC9` | Aktif Yüksek |
| **Mavi LED** | `PC8` | Aktif Yüksek |
| **User Buton** | `PA0` | Floating Input |
| **ST-LINK** | `SWD` | Dahili Debugger |

> 🔍 Detaylı pin diyagramları ve şemalar için [**Donanım Kılavuzu**](docs/hardware_guide.md) sayfasını ziyaret edin.

## 🚀 Hızlı Başlangıç

Bu depoyu kullanarak geliştirmeye başlamak için:

1.  **Repoyu Klonlayın**:
    ```bash
    git clone https://github.com/KULLANICI_ADINIZ/stm_learning.git
    cd stm_learning
    ```
2.  **STM32CubeIDE'yi Başlatın**:
    *   `File > Import > General > Existing Projects into Workspace` yolunu izleyin.
    *   `projects/` klasörünü seçin ve ilgilendiğiniz projeyi iş alanınıza dahil edin.
3.  **Derle ve Yükle**:
    *   Kartınızı USB ile bağlayın.
    *   Debug butonuna (böcek simgesi) basarak kodu yükleyin.

## 🤝 Katkıda Bulunma

Her türlü katkıya açığız! Hata düzeltmeleri, yeni proje örnekleri veya dökümantasyon iyileştirmeleri için lütfen [CONTRIBUTING.md](CONTRIBUTING.md) dosyasını inceleyin.

## 📄 Lisans

Bu proje MIT Lisansı ile lisanslanmıştır. Detaylar için [LICENSE](LICENSE) dosyasına bakınız.

---
<div align="center">
<sub>Gömülü Sistemler Tutkusuyla Hazırlanmıştır ❤️ Bahattin Yunus </sub>
</div>
