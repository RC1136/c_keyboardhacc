#include <stdio.h>
#include <Ws2tcpip.h>
#include <windows.h>
#include "..\\c_keyboardhacc\\buttons.h"

#define DEF_PORT (27015)
#define DEF_BUFFLEN (4096)
extern const char* buttons[];

//#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib,"WS2_32")		//error LNK2019 майже у всіх функціях

SOCKET ConnectServer(char* ip, int port)
{

	char* strport = (char*)malloc(6 * sizeof(char));
	if (strport == NULL)
		return 1;
	_itoa_s((int)port, strport, 6, 10);

	WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo* result = NULL,
		hints;
	int res;

	//ініціалізую сокет
	res = WSAStartup(//https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup
		MAKEWORD(2, 2),
		&wsaData
	);
	if (res != 0) {
		printf("WSAStartup failed (%d)\n", res);
		return INVALID_SOCKET;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	//отримую адресу і порт
	res = getaddrinfo(//https://docs.microsoft.com/en-us/windows/win32/api/ws2tcpip/nf-ws2tcpip-getaddrinfo
		ip,				//адреса
		strport,		//порт
		&hints,
		&result
	);
	if (res != 0) {
		printf("getaddrinfo failed (%d)\n", res);
		WSACleanup();
		return INVALID_SOCKET;
	}
	//створюю сокет для з'єднання з сервером
	ConnectSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ConnectSocket == INVALID_SOCKET) {
		printf("socket failed (%ld)\n", WSAGetLastError());
		WSACleanup();
		return INVALID_SOCKET;
	}
	//з'єднююсь з сервером
	res = connect(ConnectSocket, result->ai_addr, (int)result->ai_addrlen);
	if (res == SOCKET_ERROR) {
		closesocket(ConnectSocket);
		return INVALID_SOCKET;
	}

	freeaddrinfo(result);
	if (ConnectSocket == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		return INVALID_SOCKET;
	}

	return ConnectSocket;
}

/*
UINT input_buff(BYTE* buffer, size_t length)
{
	size_t length2 = length * 2;
	INPUT* inputs = calloc(length2, sizeof(INPUT));
	if (!inputs)
		return 0;
	ZeroMemory(inputs, length2);
	for (size_t i = 0; i < length; i++) {
		inputs[length2 - (i + 1)].type = inputs[i].type = INPUT_KEYBOARD;
		inputs[length2 - (i + 1)].ki.wVk = inputs[i].ki.wVk = buffer[i];
		inputs[length2 - (i + 1)].ki.dwFlags = KEYEVENTF_KEYUP;
	}

	free(inputs);
	return res;
}
*/

int gen_message(BYTE* buffer, int buffsize)
{
	ZeroMemory(buffer, buffsize);
	int len = 0;
	const int maxlen = buffsize / sizeof(INPUT);
	LPINPUT inputs = (void*)buffer;
	char str[256] = { 0 };
	BYTE value = 0;
	int tmpbeg = 0;
	do
	{
		value = getchar();
		switch (value) {
		case '"':
			while ((value = getchar()) != '"') {
				inputs[len].type = INPUT_KEYBOARD;
				inputs[len].ki.wVk = value;
				inputs[len + 1] = inputs[len];
				inputs[len + 1].ki.dwFlags = KEYEVENTF_KEYUP;
				len += 2;
			}
			break;
		case 't':
			tmpbeg = len;
			do {
				int i = 0;
				value = getchar();
				while (value != ' ' && value != '\n' && value != '+') {
					str[i++] = toupper(value);
					value = getchar();
				}
				str[i] = '\0';
				//ungetc(value, stdin);
				i = 0;
				
				while (!strstr(buttons[++i], str));

				inputs[len].type = INPUT_KEYBOARD;
				inputs[len].ki.wVk = i;
				len++;
			} while (value == '+');
			for (int i = len - 1; i >= tmpbeg; i--) {
				inputs[len] = inputs[i];
				inputs[len].ki.dwFlags = KEYEVENTF_KEYUP;
				len++;
			}
			break;
		case 'x':
		single:
			tmpbeg = len;
			do {
				scanf_s("%2hhx", &value);
				inputs[len].type = INPUT_KEYBOARD;
				inputs[len].ki.wVk = value;
				len++;
				value = getchar();
			} while (value == '+');
			for (int i = len - 1; i >= tmpbeg; i--) {
				inputs[len] = inputs[i];
				inputs[len].ki.dwFlags = KEYEVENTF_KEYUP;
				len++;
			}
			break;
		}
	} while (value != '\n');


	return len * sizeof(INPUT);
}

int main(int argc, char* argv[])
{
	
	short port = DEF_PORT;
	char* ip = argc > 1 ? argv[1] : "127.0.0.1";
	SOCKET ConnectSocket;
	do {
		ConnectSocket = ConnectServer(ip, (int)port);
	} while (ConnectSocket == INVALID_SOCKET);

	BYTE* buffer = malloc(DEF_BUFFLEN);
	if (!buffer)
		return 0;
	int bytes_genered;
	while (1) {
		bytes_genered = gen_message(buffer, DEF_BUFFLEN);
		
		if(send(ConnectSocket, (void*)&bytes_genered, sizeof(bytes_genered), 0) < 1)
			break;
		if(send(ConnectSocket, buffer, (int)bytes_genered, 0) < 1)
			break;
	}

	closesocket(ConnectSocket);
	WSACleanup();
	
	return 0;
}