#include "client.h"

int main()
{
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);//建立客户端socket

    // 设置服务器地址信息
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);  // 服务器监听端口
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");  // 服务器 IP 地址

    // 连接到服务器
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
        // 接收服务器端发送的信息
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
            // 如果包含换行符，则认为是无需回复的信息，不需要用户输入，跳过后续逻辑
            continue;
        }

        fgets(sendbuf, sizeof(sendbuf), stdin);
        // 输入exit退出系统
        if (strcmp(sendbuf, "exit\n") == 0)
            break;
        sendbuf[strlen(sendbuf) - 1] = '\0';
        // 发送用户命令到服务器端
        send(client_sock, sendbuf, strlen(sendbuf), 0);
    }
    close(client_sock);//关闭客户端socket
    return 0;
}
