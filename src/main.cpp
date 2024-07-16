#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "v_core.hpp"

#define WIDTH 800
#define HEIGHT 600
#define UNUSED(x) (void)x

class Application
{
public:
	Application(const char* appName)
	{
		vulkanCore = V::Core::CreateVulkanCore(appName);
	}

	~Application()
	{ 
		delete vulkanCore;
	}

	void RenderScene()
	{

	}
private:
	V::Core *vulkanCore;
};

int main(int argc, char* argv[])
{
	UNUSED(argc);
	UNUSED(argv);

  	if(!glfwInit())
    {
    	return 1;
    }

    if(!glfwVulkanSupported())
   	{
    	return 1;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan Triangle",
                                          nullptr, nullptr);

	if(!window)
	{
		glfwTerminate();
		return 1;
	}

	Application app("Vulkan Tutorial");

    while (!glfwWindowShouldClose(window))
    {
  		glfwPollEvents();

		app.RenderScene();
    }

	glfwTerminate();
  
	return 0;
}
