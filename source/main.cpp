#include <iostream>
#include <cstring>
#include <sys/types.h>
using namespace std;
int jugde(pid_t status) {
    if (-1 == status)
    {
        printf("system error!");
    }
    else
    {
        printf("exit status value = [0x%x]\n", status);
 
        if (WIFEXITED(status))
        {
            if (0 == WEXITSTATUS(status))
            {
                printf("run shell script successfully.\n");
            }
            else
            {
                printf("run shell script fail, script exit code: %d\n", WEXITSTATUS(status));
            }
        }
        else
        {
            printf("exit status = [%d]\n", WEXITSTATUS(status));
        }
    }
}
int Help();
int Menu();
int BrookInstall();
int BrookManagement();
int v2rayInstall();
int v2rayManagement();
int main(int argc, char const *argv[]) {
    /* code */
    if (argc == 0)
        Help();
    if (argc >= 1) {
        if (strcmp(argv[0], "menu") == 0) {
            Menu();
        }
        else if (strcmp(argv[0], "bi") == 0) {
            BrookInstall();
        }
    }
    return 0;
}
int Help() {
    cout << "menu 菜单 / Menu \
    bi 安装brook / brook install \
    bm 管理brook / brook management \
    vi 安装v2ray / v2ray install \
    vm 管理v2ray / v2ray management\n";
    exit(0);
}
int BrookInstall() {
    system("wget -O ~/brook https://github.com/MistyAir/brook-to-vmess/blob/main/brook/brook");
    system("ln -s /usr/local/bin/brook ~/brook");

    return 0;
}
int Menu() {
    cout << "1. 安装brook / brook install \
    2. 管理brook / brook management \
    3. 安装v2ray / v2ray install \
    4. 管理v2ray / v2ray management\n";
    cout << "Choice:";
    int choice;
    cin >> choice;
    return 0;
}