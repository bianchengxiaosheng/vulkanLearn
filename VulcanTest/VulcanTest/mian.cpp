
#include "Application.h"
#include <iostream>
//�ο���վhttps://geek-docs.com/vulkan/vulkan-tutorial/vulkan-understand-instance.html
int main() {
	
	Application app;
	try
	{
		app.Run();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what()<<	std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}