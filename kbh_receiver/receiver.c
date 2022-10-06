#include <stdio.h>
#include <Ws2tcpip.h>
#include <windows.h>
#include "..\\c_keyboardhacc\\buttons.h"


#define DEF_PORT 27015
#define DEF_BUFFLEN (4096)

extern const char* buttons[];



//#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib,"WS2_32")		//error LNK2019 майже у всіх функціях

SOCKET GetListener(const char* addr, const int port)
{
	int res;
	char* strport = (char*)malloc(6 * sizeof(char));
	if (strport == NULL)
		return GetListener(addr, port);
	_itoa_s((int)port, strport, 6, 10);


	WSADATA wsaData;
	SOCKET ListenSocket = INVALID_SOCKET;
	struct addrinfo* result = NULL;
	struct addrinfo hints;

	//Ініціалізую сокет
	res = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (res != 0) {
		printf("WSAStartup failed (%d)\n", res);
		return INVALID_SOCKET;
	}

	ZeroMemory(&hints, sizeof(hints));
	//memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	//Отримуєм адресу серверу і порт
	res = getaddrinfo(	//https://docs.microsoft.com/en-us/windows/win32/api/ws2tcpip/nf-ws2tcpip-getaddrinfo
		NULL,				//Адреса
		strport,			//Порт
		&hints,				//Рекомендації по сокету (що ми хочем)
		&result				//Інформація по сокету (що ми отримали)
	);
	if (res != 0) {
		printf("getaddrinfo failed (%d)\n", res);
		WSACleanup();
		return INVALID_SOCKET;
	}

	//Створюю сокет для з'єднання з сервером
	ListenSocket = socket(//https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-socket
		result->ai_family,
		result->ai_socktype,
		result->ai_protocol
	);
	if (ListenSocket == INVALID_SOCKET) {
		printf("socket failed (%d)\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return INVALID_SOCKET;
	}

	//Встановлюю прослуховуючий (Listening) сокет
	res = bind(//https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-bind
		ListenSocket,			//Дескриптор сокета
		result->ai_addr,		//Адреса (і всяке таке)
		(int)result->ai_addrlen	//Довжина, в байтах, значення імені (костиль - інфа сотка)
	);
	if (res == SOCKET_ERROR) {
		printf("bind failed (%d)\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return INVALID_SOCKET;
	}
	freeaddrinfo(result);
	free(strport);

	return ListenSocket;
}


SOCKET AcceptClient(SOCKET ListenSocket)
{
	printf("Waiting for client...\n");
	int res;
	SOCKET ClientSocket = INVALID_SOCKET;
	res = listen(//https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-listen
		ListenSocket,	//Сокет
		SOMAXCONN		//Довжина черги
	);
	if (res == SOCKET_ERROR) {
		printf("listen failed (%d)\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return INVALID_SOCKET;
	}
	struct sockaddr_in client_addrinfo;
	ZeroMemory(&client_addrinfo, sizeof(client_addrinfo));
	int tmp = sizeof(client_addrinfo);

	//Приймаю з'єднання
	ClientSocket = accept(//https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-accept
		ListenSocket,
		(struct sockaddr*)&client_addrinfo,
		&tmp
	);
	if (ClientSocket == INVALID_SOCKET) {
		printf("accept failed (%d)\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return INVALID_SOCKET;
	}

	//getpeername(ClientSocket, (struct sockaddr*)&client_addrinfo, &tmp);

	char cliIP[INET_ADDRSTRLEN];
	inet_ntop(client_addrinfo.sin_family, &(client_addrinfo.sin_addr), cliIP, INET_ADDRSTRLEN);
	printf("Cient's ip is: %s\n", cliIP); //inet_ntoa(client_addrinfo.sin_addr)



	return ClientSocket;
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

	UINT res = SendInput((UINT)length2, inputs, sizeof(INPUT));

	free(inputs);
	return res;
}
*/

void printinputs(LPINPUT inputs, int length)
{
	int i = 0, tmpbeg = 0;
	while (i < length){
		tmpbeg = i;
		printf("%s", buttons[inputs[i].ki.wVk]);
		while (inputs[++i].ki.dwFlags != KEYEVENTF_KEYUP){
			printf("+%s", buttons[inputs[i].ki.wVk]);
		}
		i += i - tmpbeg;
		putchar('\n');
	}
}



int main(int argc, char* argv[])
{
	short port = DEF_PORT;


	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;
	ListenSocket = GetListener("", (int)port);

	//Чекаю з'єднання
	ClientSocket = AcceptClient(ListenSocket);

	closesocket(ListenSocket);

	BYTE* buffer = calloc(DEF_BUFFLEN, sizeof(INPUT));
	if (!buffer)
		return 0;
	int bytestoreceive;
	while (1) {
		if (recv(ClientSocket, (void*)&bytestoreceive, sizeof(bytestoreceive), MSG_WAITALL) < 1)
			break;
		if (recv(ClientSocket, buffer, (int)bytestoreceive, MSG_WAITALL) < 1)
			break;
		//input_buff(buffer, bytestoreceive);
		SendInput((UINT)bytestoreceive / sizeof(INPUT), (LPINPUT)buffer, sizeof(INPUT));
		printinputs((LPINPUT)buffer, (UINT)bytestoreceive / sizeof(INPUT));
	}

	closesocket(ClientSocket);
	WSACleanup();

	return 0;
}