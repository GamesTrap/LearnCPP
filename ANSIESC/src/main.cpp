#include <iostream>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
//Only for windows SRY Linux & macOS users
#include <Windows.h>

const auto H_OUT = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD dwMode = 0;
#endif

int main()
{
	//Set output mode to handle virtual terminal sequences	
	GetConsoleMode(H_OUT, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(H_OUT, dwMode);

	char eingabe;
	std::cout << "Press the Enter key for each test!" << '\n'
		      << "Clear screen (console window): " << '\n';
	std::cin.get(eingabe);
	std::cout << "\33[2J" //Clear the screen
		         "Not to be deleted line" << '\n';
	std::cout << "DELETE THIS SECOND LINE: ";
	std::cin.get(eingabe);
	std::cout << "\33[" << 1 << "A" //Cursor up 1
		         "\33[K"; //Delete line
	std::cout << "Cursor home position: ";
	std::cin.get(eingabe);
	std::cout << "\33[H"  //Cursor go home!
		         "H" << '\n' << "Con";
	std::cin.get(eingabe);
	std::cout << "\33[" << 5 << ";" << 10 << "H... here it goes on" << '\n';
	std::cout << "\33[1;31m" //Red signs
		         "red signs\33[42m" //Green background
		         "on a green background" << '\n';
	std::cout << "\33[1;45m" //Violet background
		         "\33[1;33m" //Yellow signs
		         "yellow on violet" << '\n';
	std::cout << "\33[44m" //Blue background
		         "\33[36m" //Cyan blue signs
		         "cyan blue on blue" << '\n';
	std::cout << "\33[0;40m" //Black background
		         "\33[1;37m" //White signs
		         "White signs on black background" << '\n';
	std::cout << "\33[0m"  //Switch back to normal presentation
		         "normal presentation" << '\n' << "End of program" << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}