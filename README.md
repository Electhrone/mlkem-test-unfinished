### Oryginalny cel projektu nie został zrealizowany prez limit czasowy
- **Pierwotny cel projektu:** osadzić [implementację ML-KEM napisaną w C90]([url](https://github.com/pq-code-package/mlkem-native/tree/main)) w Pythonie, jako aplikację dokonującą wymiany kluczy między dwiema stronami przez sieć.
- **Co udało się zrobić:** jest aplikacja napisana w Pythonie do komunikacji na zasadzie serwera i klienta, gdzie klient wysyła wiadomość, a serwer odsyła ją z powrotem jako potwierdzenie jej otrzymania. Jeśli klient wyśle liczbę, to serwer zwróci kwadrat danej liczby (funkcja napisana w C).

# Instalacja 
To właśnie instalowanie pakietów było dla mnie wyzwaniem - ten pakiet działał, ten nie, a tego system nie wykrywał, a ten w ogóle nie był do tego co sugeruje internet. Postaram się jednak zapisać wszystko po kolei, jako dokumentację swojej pracy, i być może będzie to rzeczywiście działało.

## System
Aplikacja była budowana na **Manjaro linux**, dla tej też dystrybucji będą zamieszczone tutaj instrukcje.
Jako IDE zalecam CLion, z którego też korzystałem

## Wymagane pakiety
