#pragma once


namespace V
{
    class Instance;
    
    class Core
    {
    public:
        Core(const char* appName);
        ~Core();
    
    private:
        Instance* m_Instance;
    };
}