#include "Application.h"



Application::Application()
{
}


Application::~Application()
{
}
/// <summary>
///Author:��ΰ��
///Description:Application������
/// </summary>
void Application::Run()
{
	InitWindow();
	InitVulkan();
	MainLoop();
	Cleanup();
}
/// <summary>
///Author:��ΰ��
///Description:����ĳ�ʼ��������ΪGLM�Ĵ��ڣ�
/// </summary>
void Application::InitWindow()
{
	//���ô���ص�
	glfwSetErrorCallback(error_callback);
	/* Initialize the library */
	if (!glfwInit())
	{
		//��ʼ��ʧ��
		std::cout << " glfwInit() ʧ��" << std::endl;
	}
	

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", NULL, NULL);
	if (!window)
	{
		//��ʼ��ʧ��
		std::cout << " glfwCreateWindow ʧ��" << std::endl;
		glfwTerminate();
	}
	glfwSetKeyCallback(window, key_callback);
	//glfwMakeContextCurrent(window);
}
/// <summary>
///Author:��ΰ��
///Description:Vulkan��ʼ��
/// </summary>
/// <param name=""></param>
void Application::InitVulkan()
{
}
/// <summary>
///Author:��ΰ��
///Description:��ѭ��
/// </summary>
void Application::MainLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
}
/// <summary>
///Author:��ΰ��
///Description���������
/// </summary>
void Application::Cleanup()
{
	//���ٴ���
	glfwDestroyWindow(window);
	glfwTerminate();
}

/// <summary>
///Author:��ΰ��
///Description��GLDFW����ʧ�ܺ�ĵĴ���ص�
/// </summary>
void Application::error_callback(int error, const char * description)
{

	std::cout << description << std::endl;
	
	
}

/// <summary>
///Author:��ΰ��
///Description��GLDFW�����ص�
/// </summary>
void Application::key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}
