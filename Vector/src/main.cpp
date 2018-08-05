#include <iostream>
#include <vector>
#include <algorithm>

int main() //Program with typical vector operations
{
	std::vector<float> costs(12); //Table with 12 float values

	//Fill the table with any data, type conversion int -> float
	for (std::size_t i = 0; i < costs.size(); ++i)
		costs[i] = static_cast<float>(150 - i * i) / 10.0f;

	//Output table
	for (std::size_t i = 0; i < costs.size(); ++i)
		std::cout << i << ": " << costs[i] << '\n';

	//Calculation and display of sum and mean
	float sum = 0.0;
	for (auto cost : costs)
		sum += cost;

	std::cout << "Sum = " << sum << '\n';

	//Display mean value
	std::cout << "Mean value = " << sum / costs.size() << '\n';

	//Show maximum
	float maximum{ costs[0] };
	for (std::size_t i = 1; i < costs.size(); ++i)
		if (maximum < costs[i])
			maximum = costs[i];
	std::cout << "Maximum = " << maximum << '\n';

	//Declase second table sortedCosts and initialize with the first one
	std::vector<float> sortedCosts{ costs };

	//Sort second table in ascending order
	std::sort(sortedCosts.begin(), sortedCosts.end());

	//and output with the serial number
	for (std::size_t i = 0; i < sortedCosts.size(); ++i)
		std::cout << i << ": " << sortedCosts[i] << '\n';

	//Short form, if the number is not needed
	for (auto costs : sortedCosts)
		std::cout << costs << '\n';

	std::cout << "Press any key to continue . . . ";
	std::cin.ignore(1000, '\n');
	std::cin.get();
	return 0;
}
