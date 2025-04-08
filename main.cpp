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
	sort(RandomNumber, RandomNumber + 6);
}

void Drawing()
{
	for (int Index = 0; Index < 6; Index++)
	{
		MyNumber[Index] = Balls[Index];
	}
	sort(MyNumber, MyNumber + 6);
}

void result()
{
	cout << endl;
	int correct = 0;
	for (int i = 0; i < 6; i++)
	{
		if (RandomNumber[i] == MyNumber[i])
		{
			correct += 1;
		}
	}
	if (correct < 3)
	{
		cout << "¾Æ½±°Ôµµ ³«Ã· µÇ¼Ì½À´Ï´Ù.";
	}
	else 
	{
		cout << (7 - correct) << "%dµî ´çÃ·! ÃàÇÏµå¸³´Ï´Ù.";
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
	result();

	return 0;
}