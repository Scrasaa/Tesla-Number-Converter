#include <iostream>
#include <windows.h>
#include <string>

long long getintlength(long long input)
{
	return std::to_string(input).length();
}

long long getnumber(long long input)
{
    int num = input % 10; // This extracts the last digit
	int num2 = num + num;

	if (num2 >= 10)
	{
		num2 = num2 % 10 + (num2 / 10) % 10;
	}

	//std::cout << "[DEBUG] Num2 is " << num2 << '\n';

	long long retValue = input * num2;
	retValue /= num;

	int length = getintlength(input);
	//std::cout << "[DEBUG]The number " << input << " has " << length << " digits.\n";

	int length2 = getintlength(retValue);
	//std::cout << "[DEBUG]The number " << retValue << " has " << length2 << " digits.\n";

	if (length2 < length) { retValue *= 2; }

	while (length2 > length) {
		retValue /= 10; // Divide retValue by 10
		length2--; // Decrement the length since we removed a digit
	}

    return retValue;
}

void mainlogic()
{
	bool leave = true;
	while (leave)
	{
		long long input;
		std::cout << "Input number: ";
		std::cin >> input;
		std::cout << "Number received!\nStarting calculations...\n";
		std::cout << "Done!\n";
		std::cout << "The calculated number is: " << getnumber(input) << "\n";
		std::cout << "You want to exit? (y/n): ";
		char exit; std::cin >> exit;
		if (exit == 'y' || exit == 'Y') {
			leave = false;
		}
		else {
			leave = true;
		}
	}
	std::cout << "Goodbye!\n";
	Sleep(5000);
}
int main()
{
	mainlogic();
   
	return 0;
}
