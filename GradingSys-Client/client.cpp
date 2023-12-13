#include "client.h"

int main()
{
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);
    serverAddress.sin_addr.s_addr = inet_addr("10.37.240.154");

    if (connect(client_sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Connection failed");
        close(client_sock);
        exit(EXIT_FAILURE);
    }
    char sendbuf[BUF_SIZE];
    char recvbuf[BUF_SIZE];
    while (1)
    {
        memset(recvbuf, '\0', sizeof(recvbuf));
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
        fflush(stdout);
        fflush(stdin);
        if (strchr(recvbuf, '\n') != NULL)
        {
            continue;
        }
        printf("准备接收用户输入\n");
        fgets(sendbuf, sizeof(sendbuf), stdin);
        printf(sendbuf);
        if (strcmp(sendbuf, "exit\n") == 0)
            break;
        //sendbuf[strlen(sendbuf) - 1] = '\0';
        send(client_sock, sendbuf, strlen(sendbuf), 0);
    }
    close(client_sock);
    return 0;
}
