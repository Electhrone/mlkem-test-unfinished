import socket

def client_program():
    host = '192.168.211.132'  # ustawić na adres IP, na który się chcemy łączyć
    port = 5454               # ustawić ten sam port, co na serwerze

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # łączenie się na podanym IP i porcie.
    # w razie nieznalezionego połączenia wyświetli się błąd
    client_socket.connect((host, port))

    # Funkcjonalność połączenia z serwerem.
    # Z każdą wysłaną wiadomością otrzymujemy od serwera odpowiedź
    # w postaci tego, co wysłaliśmy, chyba że daliśmy mu liczbę,
    # wtedy otrzymamy kwadrat naszej liczby.
    message = input(" -> ")
    while message.lower().strip() != 'q':
        client_socket.send(message.encode())
        data = client_socket.recv(1024).decode()
        print("Otrzymano od serwera: ", data)
        message = input(" -> ")

    client_socket.close()

if __name__ == '__main__':
    client_program()