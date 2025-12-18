# 🤝 Katkıda Bulunma Rehberi

Öncelikle bu projeye katkıda bulunmak istediğiniz için teşekkür ederiz! Açık kaynak topluluğunun gücü, sizin gibi geliştiricilerin katkılarıyla ortaya çıkar.

Aşağıdaki adımları takip ederek projeye değer katabilir, hataları düzeltebilir veya yeni özellikler ekleyebilirsiniz.

## 🚀 Nasıl Katkıda Bulunabilirim?

### 1. Projeyi Forklayın
Sağ üst köşedeki "Fork" butonuna tıklayarak projeyi kendi GitHub hesabınıza kopyalayın.

### 2. Klonlayın
Forkladığınız projeyi yerel bilgisayarınıza indirin:

```bash
git clone https://github.com/KULLANICI_ADINIZ/stm_learning.git
cd stm_learning
```

### 3. Yeni Bir Dal (Branch) Oluşturun
Her özellik veya düzeltme için temiz bir dal oluşturmak en iyi uygulamadır:

```bash
git checkout -b feature/yeni-ozellik
# veya hata düzeltmesi için
git checkout -b fix/hata-duzeltmesi
```

### 4. Değişikliklerinizi Yapın
Kodunuzu yazın, test edin ve projenin genel yapısını bozmadığından emin olun.

### 5. Commit Kuralları
Commit mesajlarınızın net ve açıklayıcı olmasına özen gösterin. Mümkünse aşağıdaki formatı kullanın:

*   `feat: Yeni I2C sürücüsü eklendi`
*   `fix: UART baud rate hesaplama hatası giderildi`
*   `docs: README dosyası güncellendi`
*   `style: Kod formatlaması düzenlendi`

```bash
git add .
git commit -m "feat: DS3231 için alarm fonksiyonu eklendi"
```

### 6. Gönderin (Push)
Değişiklikleri kendi forkladığınız depoya gönderin:

```bash
git push origin feature/yeni-ozellik
```

### 7. Pull Request (PR) Oluşturun
GitHub sayfasında "Compare & pull request" butonunu göreceksiniz. Yaptığınız değişiklikleri açıklayan bir özet yazarak PR oluşturun.

---

## 📝 Kod Yazım Standartları

*   **Dil:** Kod yorum satırları ve dokümantasyon için **Türkçe** tercih edilmektedir.
*   **Stil:** STM32 HAL (Hardware Abstraction Layer) adlandırma kurallarına sadık kalın.
*   **Temizlik:** Gereksiz boşlukları ve kullanılmayan değişkenleri temizleyin.

## 🐛 Hata Bildirimi (Issues)

Eğer bir hata bulursanız veya bir öneriniz varsa, lütfen [Issues](https://github.com/bahattinyunus/stm_learning/issues) sekmesinden yeni bir konu açın.

Teşekkürler ve iyi kodlamalar! 🚀
