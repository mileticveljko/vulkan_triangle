#include "v_core.hpp"
#include "v_types.hpp"

#include <stdio.h>

namespace V
{
    Core* Core::s_Core = nullptr;

    Core* Core::CreateVulkanCore(const char* appName)
    {
        if(!s_Core)
        {
            s_Core = new Core(appName);
        }
        return s_Core;
    }

    Core::Core(const char* appName)
        : m_Instance(nullptr)
    {
        m_Instance = new Instance();
        m_Dbg = new DebugMessenger();

        CreateInstance(appName);
        CreateDebugMessenger();
    }

    Core::~Core()
    {
        printf("---------------------------\n");

        DestroyDebugMessenger();
        DestroyInstance();

        delete m_Instance;
        delete m_Dbg;
    }  
}