### Oryginalny cel projektu nie został zrealizowany
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

## Klonowanie repozytorium
Projekt można zainstalować używając komendy:
```
git clone https://github.com/Electhrone/mlkem-test-unfinished.git
```

## Budowa i uruchamianie skryptów
Mając już otwarty projekt (w CLion, wybranym IDE bądź będąc w folderze projektu w terminalu) należy wykonać komendę:
```
python setup.py build
```
do zbudowania, następnie zainstalować całość:
```
python setup.py install
```
Po tym można uruchomić wybrany plik `server.py` bądź `client.py`.

### Przed uruchomieniem
Strona będąca serwerem musi otworzyć `server.py` i na początku pliku zmienić adres IP na swój lokalny, do tego ustawić port, na którym chce nasłuchiwać.
Strona będąca klientem musi otworzyć `client.py` i zmienić w tym pliku adres IP na adres serwera oraz port na taki, na którym chcemy się łączyć.

## Korzystanie z programu
Oba komputery muszą mieć poprawnie zainstalowany projekt. Jedna strona będzie serwerem, a druga klientem.

Najpierw **serwer** uruchamia plik `server.py` używając komendy:
```
python server.py
```
Powinien na końcu wyświetlić sie na konsoli napis "`Serwer nasluchuje na `", następnie IP i port serwera. Oznacza to, że skrypt działa.

Następnie klient uruchamia plik `client.py`:
```
python client.py
```
Jeżeli wyskoczył błąd, oznaczać to może, że nie znaleziono serwera o wybranym IP i porcie. Należy się wtedy upewnić, że adres zgadza się z adresem serwera oraz serwer uruchomił swój skrypt.

W przypadku poprawnego połączenia klientowi wyświetli się konsola do wysyłania wiadomości. Serwer wówczas dostanie komunikat "`Polaczenie od: `", następnie adres klienta.
Teraz klient może pisać wiadomości i wysyłać je przyciskiem `enter`, a serwer będzie je otrzymywał i odsyłał jako potwierdzenie.
Jeżeli klient wyśle wiadomość zawierającą tylko liczbę, to serwer odeśle mu kwadrat tej liczby, wyliczony za pomocą funkcji napisanej w C.

Aby zakończyć połączenie, na kliencie należy kliknąć kombinację klawiszy `ctrl` + `c`. Oba programy powinny wówczas zakończyć swoje działanie.
