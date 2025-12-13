# Proje 02: Buton Kontrolü

Bu projede, **GPIO Input** (Giriş) modunu kullanarak kart üzerindeki kullanıcı butonunun durumunu okuyacağız.

## Hedef
- Mavi butona (USER) basıldığında Yeşil LED (PC9) yanacak.
- Buton bırakıldığında LED sönecek.

## Donanım Bağlantısı
- **Buton**: PA0 (STM32'nin A Portu, 0. Pini)
- **LED**: PC9 (STM32'nin C Portu, 9. Pini)

## Nasıl Çalıştırılır?

1.  STM32CubeIDE'de **Yeni STM32 Projesi** başlatın (STM32F100RB için).
2.  Yapılandırma (.ioc dosyası):
    - **PC9**: `GPIO_Output` olarak ayarlayın.
    - **PA0**: `GPIO_Input` olarak ayarlayın.
3.  Projeyi oluşturun (Generate Code).
4.  `Core/Src/main.c` dosyasını açın.
5.  Bu klasördeki `main.c` dosyasının içeriğini kopyalayıp projenizdeki `main.c` içine yapıştırın.
6.  **Run** butonuna basarak kodu yükleyin.

## Kodun Mantığı
`HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)` fonksiyonu, pindeki voltaj seviyesini okur.
- Eğer **3.3V** (Lojik 1) ise `GPIO_PIN_SET` döner.
- Eğer **0V** (GND / Lojik 0) ise `GPIO_PIN_RESET` döner.
