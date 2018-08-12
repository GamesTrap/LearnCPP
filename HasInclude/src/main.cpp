#include <iostream>

#include <string>

#if __has_include(<filesystem>)
    #include <filesystem>
    std::string message = "<filesystem> included.";
#elif __has_include(<experimental/filesystem>)
    #include <experimental/filesystem>
    std::string message = "<experimental/filesystem> included.";
#else
    std::string message = "filesystem-Header not found";
#endif

int main()
{
	std::cout << message << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}