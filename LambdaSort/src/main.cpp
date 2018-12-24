#include <iostream>
#include <vector>
#include <algorithm>

template<typename T, typename Functor>
void ProcessVector(const std::vector<T>& v, const Functor& functor)
{
	for (const auto& el : v)
		functor(el);
}

int main()
{
	std::vector<double> v{ -11.0, 3.2,4.1,-7.0,8.0,1.5,2.7,-4.4 };
	for (auto value : v)
		std::cout << value << ' ';
	std::cout << '\n';
	std::sort(v.begin(), v.end(), [](auto x, auto y) {return x > y; });
	std::cout << "Sorted in reverse:" << '\n';
	for (auto value : v)
		std::cout << value << ' ';
	std::cout << '\n';
	std::sort(v.begin(), v.end(), [](auto x, auto y) {return std::abs(x) < std::abs(y); });
	std::cout << "Sorted by absolute amount:" << '\n';
	for (auto value : v)
		std::cout << value << ' ';
	std::cout << '\n';

	double sum{ 0.0 };
	ProcessVector(v, [&sum](auto el) {sum += el; });
	std::cout << "Sum = " << sum << '\n';

	//Calculate the sum of all values over a threshold:
	sum = 0.0;
	const double threshold = -1.2;
	ProcessVector(v, [=, &sum](auto el)
	{
		if(el > threshold) //Threshold is const
			sum += el;
	});
	std::cout << "Sum of all values > " << threshold << " = " << sum << '\n';

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}