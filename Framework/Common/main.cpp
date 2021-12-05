#include <stdio.h>
#include "BaseApplication.hpp"

using namespace My;

namespace My {
    extern BaseApplication* g_pApp;
}

int main(int argc, char** argv) {
    int ret;

    if ((ret = g_pApp->Initialize()) != 0) {
        printf("App initialize failed, will exit now");
        return ret;
    }

    while (!g_pApp->IsQuit()) {
        g_pApp->Tick();
    }

    g_pApp->Finalize();
    printf("Hello Engine!\n");

    return 0;
}
