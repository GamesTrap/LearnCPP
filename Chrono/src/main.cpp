#include <iostream>
#include <chrono>
#include <thread>

int main()
{
	std::chrono::seconds almostADay = std::chrono::hours(23) + std::chrono::minutes(59) + std::chrono::seconds(59);
	std::cout << "23h 59min 59s are " << almostADay.count() << " Seconds" << '\n';

	//Time measurement
	auto start = std::chrono::system_clock::now();
	//Calculation to pass time ...
	std::cout << "Calculation running ..." << std::endl;
	double sum{ 0.0 };
	for (long i = 0; i < 200000000L; ++i)
		sum += i / 1000000.0;
	//Output so that the loop is not optimized away
	std::cout << "Result = " << sum << '\n';
	//Calculation completed, spend duration:
	std::chrono::nanoseconds ns = std::chrono::system_clock::now() - start;
	std::cout << "Duration [ns] = " << ns.count() << '\n' << "Duration [us] = " << std::chrono::duration_cast<std::
				chrono::microseconds>(ns).count() << '\n' << "Duration [ms] = " << std::chrono::duration_cast<std::
				chrono::
				milliseconds>(ns).count() << '\n' << "Duration [s] = " << std::chrono::duration_cast<std::chrono::
				seconds>(ns).
				count() << '\n';

	std::cout << "Wait 1500 ms ..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));

	std::cout << "Again wait until (now + 5 seconds) ..." << std::endl;
	auto then = std::chrono::system_clock::now() + std::chrono::seconds(5);
	std::this_thread::sleep_until(then);

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}