#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <fstream>
using namespace std;
int judge(pid_t status) {
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
    return WEXITSTATUS(status);
}
int Help();
int BrookInstall();
int BrookManagement();
int v2rayInstall();
int v2rayManagement();
int main(int argc, char const *argv[]) {
    /* code */
    if (argc == 1) {
        Help();
    }
    if (argc >= 2) {
        if (strcmp(argv[1], "bi") == 0) {
            BrookInstall();
        }
        else if (strcmp(argv[1], "rb") == 0) {
            BrookManagement();
        }
        else if (strcmp(argv[1], "vi") == 0) {
            v2rayInstall();
        }
        else if (strcmp(argv[1], "rv") == 0) {
            v2rayManagement();
        }
    }
    return 0;
}
int Help() {
    cout << "bi 安装brook / brook installation \n\
rb 启动brook / run brook \n\
vi 安装v2ray / v2ray installation \n\
rv 管理v2ray / run v2ray\n";
    exit(0);
}
int BrookInstall() {
    int returnValue = judge(
        system("ls /usr/local/bin | grep -w brook")
    );
    if (!returnValue) {
        returnValue = judge(
            system("rm /usr/local/bin/brook")
        );
    }
    returnValue = judge(
        system("wget -O /usr/local/bin/brook https://github.com/MistyAir/brook-to-vmess/blob/main/brook/brook")
    );
    cout << "file 'brook' is stored in /usr/local/bin/ \n";
    return 0;
}
int BrookManagement() {
    cout << "listen port:";
    string port;
    cin >> port;
    cout << "destination address or domain:";
    string addr;
    cin >> addr;
    cout << "destination port:";
    string desPort;
    cin >> desPort;
    system(("/usr/local/bin/brook relay -f :" + port + " -t " + addr + ":" + desPort + " &").c_str());
    return 0;
}
int v2rayInstall() {
    system("bash <(curl -L https://raw.githubusercontent.com/v2fly/fhs-install-v2ray/master/install-release.sh)");
    system("systemctl enable v2ray;systemctl start v2ray");
    return 0;
}
int v2rayManagement() {
    ofstream outfile;
    outfile.open("/usr/local/etc/v2ray/config.json");
    outfile << "{\
\"inbounds\": [{\
\"port\": 10086, // 服务器监听端口，必须和上面的一样\
\"protocol\": \"vmess\",\
\"settings\": {\
\"clients\": [{ \"id\": \"b831381d-6324-4d53-ad4f-8cda48b30811\" }]\
}\
}],\
\"outbounds\": [{\
\"protocol\": \"freedom\",\
\"settings\": {}\
}]\
}";
    outfile.close();
    cout << "id:b831381d-6324-4d53-ad4f-8cda48b30811\n\
protocol:vmess\n\
port:10086\n";
    system("systemctl restart v2ray");
    return 0;
}