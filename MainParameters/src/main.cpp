#include <iostream>

int main(int argc, char* argv[], char* env[])
{
	std::cout << "Calling the program = " << argv[0] << '\n';

	std::cout << (argc - 1) << " additional arguments were passed to main():" << '\n';

	int i{ 1 };
	while (argv[i])
		std::cout << argv[i++] << '\n';

	std::cout << '\n' << "*** Environment variables: ***" << '\n';
	i = 0;
	while (env[i])
		std::cout << env[i++] << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}