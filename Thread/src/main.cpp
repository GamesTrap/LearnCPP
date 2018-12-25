#include <iostream>
#include <chrono>

#include <thread>

void F(int t)
{
	std::this_thread::sleep_for(std::chrono::seconds(t));
	std::cout << "Thread " << std::this_thread::get_id() << ": Function finished! Running time = " << t << 's' << '\n';
}

int main()
{
	std::thread t1(F, 4);
	std::thread t2(F, 6);
	std::thread t3(F, 2);

	std::cout << "t1.get_id(): " << t1.get_id() << '\n';
	std::cout << "t2.get_id(): " << t2.get_id() << '\n';
	std::cout << "t3.get_id(): " << t3.get_id() << std::endl;

	t1.join(); //Wait for completion
	std::cout << "t1.join() ok" << std::endl;
	t2.join(); //Wait for completion
	std::cout << "t2.join() ok" << std::endl;
	t3.join(); //Wait for completion
	std::cout << "t3.join() ok" << '\n' 
			  << "t1.get_id(): " << t1.get_id() << '\n' 
			  << "main() is finished" << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}