#include "v_instance.hpp"

#include <vector>
#include <stdio.h>

namespace V
{
    Instance::Instance(const char* appName)
    {
        std::vector<const char*> Layers = {
            "VK_LAYER_KHRONOS_validation"
        };

        std::vector<const char*> Extensions = {
            VK_KHR_SURFACE_EXTENSION_NAME,
            "VK_KHR_xcb_surface",
            VK_EXT_DEBUG_UTILS_EXTENSION_NAME,
            VK_EXT_DEBUG_REPORT_EXTENSION_NAME
        };

        const VkApplicationInfo AppInfo = {
            .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
            .pNext = nullptr,
            .pApplicationName = appName,
            .applicationVersion = VK_MAKE_API_VERSION(0, 0, 1, 0),
            .pEngineName = "Vulkan Tutorials",
            .engineVersion = VK_MAKE_API_VERSION(0, 0, 1, 0),
            .apiVersion = VK_API_VERSION_1_0
        };

        VkInstanceCreateInfo CreateInfo = {
            .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
            .pNext = nullptr,
            .flags = 0,
            .pApplicationInfo = &AppInfo,
            .enabledLayerCount = (uint32_t)Layers.size(),
            .ppEnabledLayerNames = Layers.data(),
            .enabledExtensionCount = (uint32_t)Extensions.size(),
            .ppEnabledExtensionNames = Extensions.data()
        };

        VkResult res = vkCreateInstance(&CreateInfo, nullptr, &m_Instance);
        if(res != VK_SUCCESS)
        {
            fprintf(stderr, "[ERROR] Unable to create instance! Error core: %d\n", res);
            exit(2);
        }
    }

    Instance::~Instance()
    {

    }

    const VkInstance& Instance::GetInstance() const 
    {
        return m_Instance;
    }
}