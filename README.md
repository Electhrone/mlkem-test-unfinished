### Oryginalny cel projektu nie został zrealizowany ze względu na ograniczony czas praktyk
- **Pierwotny cel projektu:** osadzić [implementację ML-KEM napisaną w C90](https://github.com/pq-code-package/mlkem-native/tree/main) w Pythonie, jako aplikację dokonującą wymiany kluczy między dwiema stronami przez sieć.
- **Co udało się zrobić:** jest aplikacja napisana w Pythonie do komunikacji na zasadzie serwera i klienta, gdzie klient wysyła wiadomość, a serwer odsyła ją z powrotem jako potwierdzenie jej otrzymania. Jeśli klient wyśle liczbę, to serwer zwróci kwadrat danej liczby (funkcja napisana w C).

# Instalacja 
To właśnie instalowanie pakietów było dla mnie wyzwaniem - ten pakiet działał, ten nie, a tego system nie wykrywał, a ten w ogóle nie był do tego co sugeruje internet. Postaram się jednak zapisać wszystko po kolei, jako dokumentację swojej pracy, i być może będzie to rzeczywiście działało.

## System
Aplikacja była budowana na [Manjaro linux](https://manjaro.org/products), dla tej też dystrybucji będą zamieszczone tutaj instrukcje.
Jako IDE zalecam [CLion](https://www.jetbrains.com/clion/promo/?source=google&medium=cpc&campaign=EMEA_en_PL_Clion_Branded&term=clion&content=489240780926&gad_source=1&gad_campaignid=11964013648&gclid=CjwKCAjwx8nCBhAwEiwA_z__0-upK10OFEpL5FxG3pSe78igvoyCamHVOX1z3w0e3cwm421y9eXmShoCBIwQAvD_BwE), z którego też korzystałem.

## instalacja wymaganych pakietów
Przed instalacją wymaganych pakietów należy się upewnić, że wszystkie pobierane pakiety będą w najnowszej wersji:
```
sudo pacman -Syu
```
Następnie można zainstalować Pythona oraz potrzebne narzędzia:
```
sudo pacman -S base-devel python python-pip python-setuptools
```

## Pobranie repozytorium
