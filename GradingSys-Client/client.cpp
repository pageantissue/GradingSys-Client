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
            printf("%sYour content will be saved from the new line. Stop input by enterring STOP and press ENTER!\n\n", recvbuf);
            fflush(stdout);
            char eachline[1024]; memset(eachline, '\0', 1024);
            char result[1024]; memset(result, '\0', 1024);
            while (1)
            {
                std::cin.getline(eachline, 1024);
                // 检查输入是否包含 "STOP"
                if (strstr(eachline, "STOP") != nullptr) {
                    break;
                }
                strcat(result, eachline);
                strcat(result, "\n"); // 添加换行符，以便区分每一行
            }
            memset(sendbuf, '\0', sizeof(sendbuf));
            strcpy(sendbuf, result);
            send(client_sock, sendbuf, strlen(sendbuf), 0);
            continue;
        }
        else
        {
            printf(recvbuf);
            fflush(stdout);
            fgets(sendbuf, sizeof(sendbuf), stdin);
            if (strcmp(sendbuf, "exit\n") == 0)
            {
                cout << "Exit Grading System. Bye!\n";
                break;
            }
            sendbuf[strlen(sendbuf) - 1] = '\0'; //strip \n
            send(client_sock, sendbuf, strlen(sendbuf), 0);
        }
    }
    close(client_sock);
    return 0;
}
