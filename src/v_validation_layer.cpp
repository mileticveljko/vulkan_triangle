#include "v_core.hpp"
#include "v_types.hpp"

#include <stdio.h>
#include <stdlib.h>

namespace V
{
    void Core::CreateDebugMessenger()
    {
        VkDebugUtilsMessengerCreateInfoEXT MessangerCreateInfo = 
        {
            .sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,
            .pNext = nullptr,
            .flags = 0,
            .messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
                                VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
                                VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
                                VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,
            .messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
                            VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
                            VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,
            .pfnUserCallback = nullptr,
            .pUserData = nullptr
        };

        PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessenger = VK_NULL_HANDLE;
        vkCreateDebugUtilsMessenger = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(
            m_Instance->vulkan_instance,
            "vkCreateDebugUtilsMessengerEXT");
        if(!vkCreateDebugUtilsMessenger)
        {
            fprintf(stderr, "[ERROR] Unable to find proc address of \"vkCreateDebugUtilsMessengerEXT\" function!\n");
            exit(2);
        }

        VkResult res = vkCreateDebugUtilsMessenger(m_Instance->vulkan_instance,
            &MessangerCreateInfo,
            nullptr, &m_Dbg->vulkan_dbg);
        if(res != VK_SUCCESS)
        {
            fprintf(stderr, "[ERROR] Unable to create Debug Messenger! Error code: %d\n", res);
            exit(2);
        }

        fprintf(stdout, "[INFO] Vulkan validation layer created!\n");
    }


    void Core::DestroyDebugMessenger()
    {
        
    }
}
