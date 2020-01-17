#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
class Application
{
public:
	Application();
	~Application();
	void Run();

private:
	void InitWindow();
	void InitVulkan();

	void MainLoop();

	void Cleanup();

	static void error_callback(int error, const char* description);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


private:
	//GLM的窗体
	GLFWwindow* window;
	//窗体的宽
	const int WIDTH = 800;
	//窗体的高
	const int HEIGHT = 600;

};

