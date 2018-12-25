#include <iostream>
#include "Worker.h"
#include "CallWrapper.h"

int main()
{
	Worker worker;
	CallWrapper<Worker> caller(worker);
	std::thread t(caller);
	int hours{ 8 };
	while(!worker.IsTerminated())
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << ++hours << " o'clock: ";
		switch(hours)
		{
		case 10:
			worker.Wait(); //Pause
			break;
		case 13:
			worker.Continue(); //Continue
			break;
		case 16:
			worker.Terminate(); //End
			t.join(); //Wait for end
			break;

		default:
			if (hours > 16)
				throw "Error!";
		}
	}

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}
