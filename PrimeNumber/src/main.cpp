#include <iostream>

template<int p, int i>
struct IsPrimeNumber
{
	//p is only prime if p is not divisible by i nor by all other divisors between 2 and i.
	//If i == 2, then IsPrimeNumber<0, 1>::prime is requested, i.e. Cancellation of recursion
	static const int prime{ (p % i) && IsPrimeNumber<(i > 2 ? p : 0), i - 1>::prime };
};

template<int i>
struct PrintPrimeNumbersTill
{
	//The following constructor call ensures that even the smaller primes are output recursively.
	PrintPrimeNumbersTill<i - 1> a;
	static const int primeNumber{ IsPrimeNumber<i, i - 1>::prime };
	PrintPrimeNumbersTill()
	{
		if (primeNumber)
			std::cout << i << '\n';
	}
};

//
template<>
struct IsPrimeNumber<0, 1>
{
	static const int prime = 1;
};

template<>
struct PrintPrimeNumbersTill<2>
{
	PrintPrimeNumbersTill()
	{
		std::cout << 2 << '\n';
	}
};

int main()
{
	PrintPrimeNumbersTill<17> a;

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}