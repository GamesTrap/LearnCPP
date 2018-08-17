#include <iostream>

#include <cassert>

int main()
{
	//Required types. Assumption: 1 byte = 8 bits
	static_assert(sizeof(int_fast8_t) >= 1, "Error!");
	static_assert(sizeof(int_fast16_t) >= 2, "Error!");
	static_assert(sizeof(int_fast32_t) >= 4, "Error!");
	static_assert(sizeof(int_fast64_t) >= 8, "Error!");
	static_assert(sizeof(uint_fast8_t) >= 1, "Error!");
	static_assert(sizeof(uint_fast16_t) >= 2, "Error!");
	static_assert(sizeof(uint_fast32_t) >= 4, "Error!");
	static_assert(sizeof(uint_fast64_t) >= 8, "Error!");

	static_assert(sizeof(int_least8_t) >= 1, "Error!");
	static_assert(sizeof(int_least16_t) >= 2, "Error!");
	static_assert(sizeof(int_least32_t) >= 4, "Error!");
	static_assert(sizeof(int_least64_t) >= 8, "Error!");
	static_assert(sizeof(uint_least8_t) >= 1, "Error!");
	static_assert(sizeof(uint_least16_t) >= 2, "Error!");
	static_assert(sizeof(uint_least32_t) >= 4, "Error!");
	static_assert(sizeof(uint_least64_t) >= 8, "Error!");

	static_assert(sizeof(intmax_t) >= sizeof(size_t), "Error!");
	static_assert(sizeof(uintmax_t) >= sizeof(size_t), "Error!");

	//Optional types (i.e. Error messages from the compiler, if the types are not available)
	static_assert(sizeof(int8_t) == 1, "Error!");
	static_assert(sizeof(int16_t) == 2, "Error!");
	static_assert(sizeof(int32_t) == 4, "Error!");
	static_assert(sizeof(int64_t) == 8, "Error!");

	const char* pc = "Literal";
	const void* voidPointer = static_cast<const void*>(pc);
	//Conversion of the address into a number
	const uintptr_t uintptr_tNumber = reinterpret_cast<uintptr_t>(voidPointer);
	//The reconversion must be the same address
	assert(voidPointer == reinterpret_cast<void*>(uintptr_tNumber));

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
}
