#pragma once

namespace V
{
    class Instance;
    class DebugMessenger;
    
    class Core
    {
    public:
        ~Core();
        static Core* CreateVulkanCore(const char*);
    
    private:
        Core(const char* appName);

        void CreateInstance(const char* appName);
        void CreateDebugMessenger();

        void DestroyInstance();
        void DestroyDebugMessenger();

    private:
        static Core* s_Core;

        Instance* m_Instance;
        DebugMessenger* m_Dbg;
    };
}
