// Aidan Houck
// CIS 1202 502
// November 18, 2021
// Create and test a new "character" function using try/catch blocks

#include <iostream>

char character(char, int);

int main() 
{

	try
	{
		// Should return 'b'
		std::cout << character('a', 1) << '\n';
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage << '\n';
	}

	try
	{
		// Should return an exception
		std::cout << character('a', -1) << '\n';
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage << '\n';
	}

	try
	{
		// Should return 'Y'
		std::cout << character('Z', -1) << '\n';
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage << '\n';
	}

	try
	{
		// Should return an exception
		std::cout << character('?', 5) << '\n';
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage << '\n';
	}

	try
	{
		// Should return an exception
		std::cout << character('A', 32) << '\n';
	}
	catch (std::string errorMessage)
	{
		std::cout << errorMessage << '\n';
	}


	std::cout << '\n';
	system("pause");
	return 0;
}

char character(char start, int offset)
{
	std::string badRange = "invalidRangeException";
	std::string badChar = "invalidCharacterException";
	std::string badCase = "invalidCaseException";

	if (isalpha(start) == false)
	{
		// The char given is not an alphabetic character
		throw(badChar);
	}

	char newchar = static_cast<char>(start + offset);

	if (isalpha(newchar) == false)
	{
		// The new char given is no longer an alphabetic character
		throw(badRange);
	}

	if ((isupper(start) == false && isupper(newchar) == true) || (isupper(start) == true && isupper(newchar) == false))
	{
		// Input and output are not the same case (e.g. input A output b)
		throw(badCase);
	}


	return newchar;
}