#include <iostream>
#include <cstring>
using namespace std;
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