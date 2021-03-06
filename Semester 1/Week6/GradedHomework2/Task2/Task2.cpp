/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Svetlozar Stefanov
* @idnumber 4MI0600030
* @task 2
* @compiler VC
*
*/

#include <iostream>

using namespace std;

unsigned const MIN_PALD = 101;

unsigned powerOf(const unsigned num, const unsigned n) 
{
	unsigned result = 1;

	for (int i = 0; i < n; i++)
	{
		result *= num;
	}

	return result;
}

unsigned digitsCount(unsigned num) 
{
    unsigned count = 0;

	do
	{
		num /= 10;
		count++;
	} 
	while (num != 0);
	
	return count;
}

bool isPalindrome(const unsigned num) 
{
	bool isPalindrome = true;

	int numbOfDigits = digitsCount(num);

	if (numbOfDigits < 3)
	{
		isPalindrome = false;
		return isPalindrome;
	}

	for (int i = 0; i < numbOfDigits / 2; i++)
	{
		int firstDigit = (num / powerOf(10, numbOfDigits - 1 - i)) % 10;
		int lastDigit = (num / powerOf(10, i)) % 10;

		if (firstDigit != lastDigit)
		{
			isPalindrome = false;
			return isPalindrome;
		}
	}

	return isPalindrome;
}

int main()
{
	int N;

	if (!(cin >> N)
		|| N <= 0
		|| N > powerOf(10,9))
	{
		cout << "-1";
		return 1;
	}


	unsigned leftNum = N;
	unsigned rightNum = N;

	while (true)
	{
		if (isPalindrome(leftNum))
		{
			cout << leftNum;
			return 0;
		}
		else if (leftNum > MIN_PALD)
		{
			leftNum--;
		}

		if (isPalindrome(rightNum))
		{
			cout << rightNum;
			return 0;
		}
		else
		{
			rightNum++;
		}
	}
}
