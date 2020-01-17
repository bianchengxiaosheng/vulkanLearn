#include "Application.h"



Application::Application()
{
}


Application::~Application()
{
}
/// <summary>
///Author:郭伟龙
///Description:Application的启动
/// </summary>
void Application::Run()
{
	InitWindow();
	InitVulkan();
	MainLoop();
	Cleanup();
}
/// <summary>
///Author:郭伟龙
///Description:窗体的初始化（这里为GLM的窗口）
/// </summary>
void Application::InitWindow()
{
	//设置错误回调
	glfwSetErrorCallback(error_callback);
	/* Initialize the library */
	if (!glfwInit())
	{
		//初始化失败
		std::cout << " glfwInit() 失败" << std::endl;
	}
	

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", NULL, NULL);
	if (!window)
	{
		//初始化失败
		std::cout << " glfwCreateWindow 失败" << std::endl;
		glfwTerminate();
	}
	glfwSetKeyCallback(window, key_callback);
	//glfwMakeContextCurrent(window);
}
/// <summary>
///Author:郭伟龙
///Description:Vulkan初始化
/// </summary>
/// <param name=""></param>
void Application::InitVulkan()
{
}
/// <summary>
///Author:郭伟龙
///Description:主循环
/// </summary>
void Application::MainLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
}
/// <summary>
///Author:郭伟龙
///Description：清除操作
/// </summary>
void Application::Cleanup()
{
	//销毁窗体
	glfwDestroyWindow(window);
	glfwTerminate();
}

/// <summary>
///Author:郭伟龙
///Description：GLDFW调用失败后的的错误回调
/// </summary>
void Application::error_callback(int error, const char * description)
{

	std::cout << description << std::endl;
	
	
}

/// <summary>
///Author:郭伟龙
///Description：GLDFW按键回调
/// </summary>
void Application::key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}
