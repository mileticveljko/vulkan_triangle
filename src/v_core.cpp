#include "v_core.hpp"

#include "v_instance.hpp"

namespace V
{
    Core::Core(const char* appName)
        : m_Instance(nullptr)
    {
        m_Instance = new Instance(appName);
    }

    Core::~Core()
    {
        delete m_Instance;
    }
}