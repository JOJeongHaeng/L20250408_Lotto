#include <iostream>
#include <algorithm>

#define MAX_NUMBER	45

using namespace std;

int Balls[MAX_NUMBER] = { 0, };
int MyNumber[6] = { 0, };
int RandomNumber[6] = { 0, };

void Initialize()
{
	srand((unsigned int)time(NULL));

	for (int Index = 0; Index < MAX_NUMBER; Index++)
	{
		Balls[Index] = Index + 1;
	}
}

void Shuffle()
{
	int Temp = 0;
	for (int Count = 0; Count < MAX_NUMBER * 100; Count++)
	{
		int First = rand() % MAX_NUMBER;
		int Second = rand() % MAX_NUMBER;
		Temp = Balls[First];
		Balls[First] = Balls[Second];
		Balls[Second] = Temp;
	}
}

void SetRandomNumber()
{
	for (int Index = 0; Index < 6; Index++) 
	{
		RandomNumber[Index] = Balls[Index];
	}
}

void Drawing()
{
	for (int Index = 0; Index < 6; Index++)
	{
		MyNumber[Index] = Balls[Index];
	}
}

int main()
{
	Initialize();
	Shuffle();
	SetRandomNumber();
	Shuffle();
	Drawing();
	for (int i = 0; i < 6; i++) 
	{
		cout << RandomNumber[i] << "\t";
	}
	cout <<endl << "================" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << MyNumber[i] << "\t";
	}

	return 0;
}