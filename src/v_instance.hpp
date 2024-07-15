#pragma once

#include <vulkan/vulkan.h>

namespace V
{
    class Instance
    {
    public:
        Instance(const char* appName);
        ~Instance();

        const VkInstance& GetInstance() const;
    private:
        VkInstance m_Instance;
    };  
}
