#include <iostream>

#include "NumObj.h"

int main()
{
	NumberedObject::testMode = true;

	NumberedObject numObjX; //... is generated
	std::cout << "The serial number of the numObjX is: " << numObjX.serialNumber() << '\n';

	//Beginning of a new block
	{
		NumberedObject numObjY; //... is generated

		std::cout << NumberedObject::amount() << " objects active" << '\n';

		//*p is generated dynamically:
		NumberedObject* p{ new NumberedObject };

		std::cout << NumberedObject::amount() << " objects active" << '\n';
		delete p; //*p is deleted

		std::cout << NumberedObject::amount() << " objects active" << '\n';

		//std::cout << "ERROR! too often called delete!" << '\n'; 
		//delete p;
		//End of block: numObjY is deleted
	}

	std::cout << "Copyconstructor:" << '\n';
	const NumberedObject& numObjX1 = numObjX;

	std::cout << "The serial number of numObjX is: " << numObjX.serialNumber() << '\n';

	std::cout << "The serial number of numObjX1 is: " << numObjX1.serialNumber() << '\n';

	//Assignment is prohibited by the compiler because of consistency of the serialNo
	//numObjX1 = numObjX; //Error

	std::cout << "Press Enter to continue . . . ";
	std::cin.get();
	return 0;
} //numObjX is deleted