import minos
import socket

def server_program():
    host = '192.168.211.132'  # wstawić lokalne IP komputera serwerowego
    port = 5454               # Port do nasłuchiwania

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(1)
    print(f"Serwer nasluchuje na {host}:{port}")

    # Gdy otrzymamy połączenie, przypisujemy je do zmiennych
    conn, address = server_socket.accept()
    print("Polaczenie od: ", address)

    while True:
        data = conn.recv(1024).decode()
        if not data:
            break
        print("Otrzymano od klienta: ", data)

        # Uzyjemy funkcji z C, a potem wyslemy odpowiedz
        try:
            x = int(data)
            odp = f"Kwadrat twojej liczby to {minos.multiply(x, x)}"
            conn.send(odp.encode())
        except:
            # print("Nie udalo się wyliczyc kwadratu liczby.")
            odp = f"Serwer otrzymal: {data}"
            conn.send(odp.encode())

    conn.close()

if __name__ == '__main__':
    server_program()