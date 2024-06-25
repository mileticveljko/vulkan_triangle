#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGHT 600
#define UNUSED(x) (void)x

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

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();  	
	}

	glfwTerminate();
  
	return 0;
}
