#include "win32_Debug.h"

void
Debug::DisplayCmdLine()
{
    AllocConsole();
    freopen("conin$","r",stdin);
    freopen("conout$","w",stdout);
    freopen("conout$","w",stderr);
    printf("Debugging Window:\n");
}

template<typename type> void
Debug::WriteValue(type Value, std::string Label)
{
    // TODO(tyler): Unsafe. If the value is longer than 200 characters, this will segfault.
    char DebugString[200];
    sprintf(DebugString, "%s: %9.7f\n", Label, Value);
    OutputDebugStringA(DebugString);
}

void
Debug::WriteString(std::string StringToWrite)
{
    OutputDebugStringA((LPCTSTR)StringToWrite.c_str());
}

void
Debug::WriteError(std::string StringToWrite)
{
    OutputDebugStringA((LPCTSTR)("ERROR: " + StringToWrite).c_str());    
}
