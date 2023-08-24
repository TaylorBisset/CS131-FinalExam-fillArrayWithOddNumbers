/*
Write a program the does the following:

Create a function named fillArrayWithOddNumbers that fills the array with odd random numbers in the range 1-50000. 
    Function's signature is as follows:  (4 pt)
void fillArrayWithOddNumbers( int ptr[ ], int size);  // It fills array with odd random numbers
In main:
Use dynamic memory to create a int array of size 5000. (2 pts)
Call the above function passing the array you created above (the int array of size 5000 in dynamic memory) as an argument. (1 pt)
After the function call, calculate the average of the elements in the array and print this average to two decimal points. (2 pts)
Give the memory back. (1 pts)

Suggestion: Read the question fully and carefully before you begin answering.
*/

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void fillArrayWithOddNumbers(int ptr[], int size)
{
    srand(time(0));
    for (int i = 0; i < size;)
    {
        int oddNumber = rand() % 5000 + 1;
        if (oddNumber % 2 != 0)
        {
            ptr[i] = oddNumber;
            i++;
        }
    }
}

int main()
{
    int arraySize = 5000;
    int* dynamicArray = new int[arraySize];
    fillArrayWithOddNumbers(dynamicArray, arraySize);

    double sum = 0;

    for (int i = 0; i < arraySize; i++)
    {
        sum += dynamicArray[i];
    }

    double average = sum / arraySize;

    cout << "Average: " << fixed << setprecision(2) << average << endl;

    delete[] dynamicArray;

    return 0;
}
