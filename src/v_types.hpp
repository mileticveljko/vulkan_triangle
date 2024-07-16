#pragma once

#include <vulkan/vulkan.h>

namespace V
{
    struct Instance
    {
        VkInstance vulkan_instance;
    };

    struct DebugMessenger
    {
        VkDebugUtilsMessengerEXT vulkan_dbg;
    };
}
