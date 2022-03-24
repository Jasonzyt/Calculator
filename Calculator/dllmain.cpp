#include "pch.h"
#include "LLAPI.h"
#pragma comment(lib, "../SDK/Lib/bedrock_server_api.lib")
#pragma comment(lib, "../SDK/Lib/bedrock_server_var.lib")
#pragma comment(lib, "./third-party/LiteLoaderSDK/Lib/SymDBHelper_Clang_ms.lib")
#pragma comment(lib, "../SDK/Lib/LiteLoader.lib")

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        LL::registerPlugin(
            "Calculator", 
            "In-game calculator for MCBDS", 
            version, 
            std::map<std::string, std::string>{
                {"Author", "Jasonzyt"},
                {"GitHub", "https://github.com/Jasonzyt/Calculator"},
                {"License", "GNU GPL-3.0"}
            });
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern void entry();

extern "C" {
    _declspec(dllexport) void onPostInit() {
        std::ios::sync_with_stdio(false);
        entry();
    }
}
