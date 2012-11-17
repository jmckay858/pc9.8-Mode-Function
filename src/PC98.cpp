//============================================================================
// PC 9.8 - Mode Function
// -------------------------
// Programmer: Jeremy F McKay
// Date: November 13, 2012
// -------------------------
// This program will determine the mode of an array of integers
// ---------1---------2---------3---------4---------5---------6---------7
// 1234567890123456789012345678901234567890123456789012345678901234567890

#include <iostream>
using namespace std;
int calc_mode( int *array, int n );
void sortNumbers(int *list, int SIZE);
void displayArray(int *list, int SIZE);

int main() {
	int mode;
	int list1[] = {  2,  5,  8,  5,  3,
	                 9,  4,  8,  4,  5,
	                 7,  8,  7,  9, 10,
	                 0,  8,  6,  9,  3 };

	int list2[] = { 85, 75, 86, 95, 93,
	                79, 84, 78, 84, 85,
	                87, 98, 87, 79, 79 };

	int list3[] = { 18, 19, 12, 20, 15, 11, 17 };

	sortNumbers(list1, 20);
	displayArray(list1, 20);
	mode = calc_mode(list1, 20);
	if (mode > 0)
	{
		cout << "\n   "
			 << "The mode is " << mode << endl;
	} else {
		cout << "\n   "
			 << "There is no mode" << endl ;
	}
	sortNumbers(list2, 15);
	displayArray(list2, 15);
	mode = calc_mode(list2, 15);
	if (mode > 0)
	{
		cout << "\n   "
			 << "The mode is " << mode << endl;
	} else {
		cout << "\n   "
			 << "There is no mode" << endl ;
	}
	sortNumbers(list3, 7);
	displayArray(list3, 7);
	mode = calc_mode(list3, 7);
	if (mode > 0)
	{
		cout << "\n   "
			 << "The mode is " << mode << endl;
	} else {
		cout << "\n   "
			 << "There is no mode" << endl ;
	}


	return 0;
}

int calc_mode( int *array, int n )
{
    int count[101];
    int largest;
    int number, mode;

    // zero out the counters
    for( int i=0; i<=100; i++ )
        count[i] = 0;

    // count up the numbers
    for( int i=0; i<n; i++ ) {
        number = *(array+i);
        count[number]++;
    }

    // find the largest value in count

    largest = count[0];

    for( number=1; number<=100; number++ )
        if( count[number] > largest ) {
            largest = count[number];
            mode = number;
        }

    if( largest == 1 )
        // then no mode
        return -1;
    else
        return mode;

}

void sortNumbers(int *list, int SIZE)
{
	int startScan, minIndex, minValue;

	for (startScan = 0; startScan < (SIZE - 1); startScan++)
	{
		minIndex = startScan;
		minValue = *(list+startScan);
		for(int index = startScan + 1; index < SIZE; index++)
		{
			if (*(list+index) < minValue)
			{
				minValue = *(list+index);
				minIndex = index;
			}
		}
		*(list+minIndex) = *(list+startScan);
		*(list+startScan) = minValue;
	}
}

void displayArray(int *list, int SIZE)
{
	cout	 << "\n   Listed Numbers Sorted"
			 << "\n  "
			 << "-----------------------"
			 << "\n";
	for (int index = 0; index < SIZE; index++)
		{
			cout << "   "

				 <<	*(list+index) << endl;
		}
}



