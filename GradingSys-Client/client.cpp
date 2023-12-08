#include "client.h"

int main()
{
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);//�����ͻ���socket

    // ���÷�������ַ��Ϣ
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);  // �����������˿�
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");  // ������ IP ��ַ

    // ���ӵ�������
    if (connect(client_sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Connection failed");
        close(client_sock);
        exit(EXIT_FAILURE);
    }
    char sendbuf[BUF_SIZE];
    char recvbuf[BUF_SIZE];
    while (1)
    {
        memset(recvbuf, 0, sizeof(recvbuf));
        // ���շ������˷��͵���Ϣ
        ssize_t len = recv(client_sock, recvbuf, sizeof(recvbuf), 0);
        if (len <= 0) {
            printf("Nothing received or failures ocurred!\n");
            break;
        }
        if (strcmp(recvbuf, "help") == 0)
        {
            help();
            continue;
        }
        printf(recvbuf);

        if (strchr(recvbuf, '\n') != NULL)
        {
            // ����������з�������Ϊ������ظ�����Ϣ������Ҫ�û����룬���������߼�
            continue;
        }

        fgets(sendbuf, sizeof(sendbuf), stdin);

        // ����exit�˳�ϵͳ
        if (strcmp(sendbuf, "exit\n") == 0)
            break;

        sendbuf[strlen(sendbuf) - 1] = '\0';
        // �����û������������
        send(client_sock, sendbuf, strlen(sendbuf), 0);
    }
    close(client_sock);//�رտͻ���socket
    return 0;
}