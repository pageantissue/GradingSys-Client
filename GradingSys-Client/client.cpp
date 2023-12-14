#include "client.h"

int main()
{
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);
    //serverAddress.sin_addr.s_addr = inet_addr("10.37.240.154");
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

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
        if (strcmp(recvbuf, "help1") == 0)
        { // 学生
            help1();
            continue;
        }
        else if (strcmp(recvbuf, "help2") == 0)
        { // 老师
            help2();
            continue;
        }
        else if (strcmp(recvbuf, "help") == 0)
        { // root
            help();
            continue;
        }
        char new_buffer[strlen(recvbuf)];
        strcpy(new_buffer, recvbuf);
        if ((new_buffer[strlen(new_buffer) - 1] == '\n') || (new_buffer[strlen(new_buffer) - 1] == '\t'))
        {
            printf(recvbuf);
            fflush(stdout);
            // if the last char of message recieved is \n or \t we consider it as plain output text which is no need of client's response
            continue;
        }
        else if (new_buffer[strlen(new_buffer) - 1] == '\r')
        {
            printf("%s\nYour content will be saved from the new line. Stop input by enterring STOP and press ENTER!\n", recvbuf);
            fflush(stdout);
            // 使用fgets来逐行接收用户输入
            while (fgets(sendbuf, sizeof(sendbuf), stdin) != nullptr)
                if (strcmp(sendbuf, "STOP\n") == 0) 
                    break;
              
        }
        printf(recvbuf);
        fflush(stdout);
        fgets(sendbuf, sizeof(sendbuf), stdin);
        if (strcmp(sendbuf, "exit\n") == 0)
            break;
        sendbuf[strlen(sendbuf) - 1] = '\0'; //strip \n
        send(client_sock, sendbuf, strlen(sendbuf), 0);
    }
    close(client_sock);
    return 0;
}
