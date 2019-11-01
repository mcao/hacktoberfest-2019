#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

void binaryArray(int n, int array[], int size)
{

    int sizeVariableForArray = 0;
    int rightShiftedValue = 0, countOne = 0;
    int remainderOfDivision = 0;
    array[size];

    //reduce size of int array by one to store binary number
    //from range 0 to 31
    size = size - 1;

    //Switch statement for decimal numbers it will go to respective case depending upon the
    //case depending upon the input number
    switch (n)
    {

    // case -1 and INT_MIN created specifically for all negative integer numbers.
    case -1:
    case INT_MIN:

        while (size >= 0)
        {

            //shift decimal number to the right side using bitwise right shift operator
            rightShiftedValue = n >> size;

            //if right shifted value & 1 then put 1 in binary array else zero in binary array
            if (rightShiftedValue & 1)
                array[sizeVariableForArray] = 1; //use sizeVariableForArray to store values from 0 location till 31
            else
                array[sizeVariableForArray] = 0;

            sizeVariableForArray++;
            size--;
        }
        break;
    // default case use for all positive integer number
    default:

        while (size >= 0)
        {

            //modulus operator gives us remainder 1 or 0 for input number
            remainderOfDivision = n % 2;
            //store the remainder in binary array which is either 1 or 0
            array[size] = remainderOfDivision;
            //used  divide by 2 method to compute the decimal to binary conversion
            n = n / 2;
            size--;
        }
        break;
    }
}

void binaryPrinter(int array[], int size)
{

    printf("\nBinary Number :");
    //set size of binary array to 0 to print the binary number from 31 to 0 in binary order
    size = 0;
    while (size <= 31)
    {

        printf("%d", array[size]);
        size++;
    }
}

unsigned int countOnes(int num)
{

    int binaryNumberArray[8 * sizeof(int)];
    int iteratorToTraverseBits = 31, rightShiftedValue = 0, numberOfOnesCounter = 0;
    int reminderOfDivisionOperation = 0;

    switch (num)
    {

    // case -1 and INT_MIN created specifically for -1 number.
    case -1:

        while (iteratorToTraverseBits >= 0)
        {

            //shift decimal number to the right side using bitwise right shift operator
            rightShiftedValue = num >> iteratorToTraverseBits;
            //if right shifted value & 1 then put 1 in binary array else zero in binary array
            if (rightShiftedValue & 1)
                binaryNumberArray[iteratorToTraverseBits] = 1;
            else
                binaryNumberArray[iteratorToTraverseBits] = 0;

            iteratorToTraverseBits--;
        }
        break;

    // default case use for all positive remaining integer number
    default:

        while (iteratorToTraverseBits >= 0)
        {

            //modulus operator gives us remainder 1 or 0 for input number
            reminderOfDivisionOperation = num % 2;
            //store the remainder in binary array which is either 1 or 0
            binaryNumberArray[iteratorToTraverseBits] = reminderOfDivisionOperation;
            //used  divide by 2 method to compute the decimal to binary conversion
            num = num / 2;
            iteratorToTraverseBits--;
        }
        break;
    }

    //set iteratorToTraverseBits to ignore previous value store in it
    iteratorToTraverseBits = 31;
    while (iteratorToTraverseBits >= 0)
    {

        //if found 1 in binary array then increment numberOfOnesCounter by 1
        if (binaryNumberArray[iteratorToTraverseBits] == 1)
            numberOfOnesCounter++;

        iteratorToTraverseBits--;
    }

    return numberOfOnesCounter;
}

int findLengthOfString(char string[])
{

    //store length of string in lengthCounter variable
    int lengthCounter = 0;

    //while loop until it reaches to end of string
    while (string[lengthCounter] != '\0')
        lengthCounter++;

    return lengthCounter;
}

int myStrStr(char haystack[], char needle[], char buffer[])
{

    int lenghtOfHaystackString, lengthOfNeedleString;
    int lengthOfBuffer;
    int iteratorForHaystackString = 0, iteratorForNeedleString = 0;
    int substringFoundFlag = 1;

    //used memset especially to empty buffer array
    memset(buffer, 0, 255);

    //calculate length of string, substring and buffer string
    lenghtOfHaystackString = findLengthOfString(haystack);
    lengthOfNeedleString = findLengthOfString(needle);
    lengthOfBuffer = findLengthOfString(buffer);

    //iterate until it reaches to end of length of string
    while (iteratorForHaystackString < lenghtOfHaystackString)
    {

        //checked if first letter of substring matches with any letter in string
        if (needle[0] == haystack[iteratorForHaystackString])
        {

            //if character matches then iterate until substring length
            while (iteratorForNeedleString < lengthOfNeedleString)
            {

                //if first character of substring matches with main string then  copy
                //those character one by one to buffer array
                if (needle[iteratorForNeedleString] == haystack[iteratorForHaystackString + iteratorForNeedleString])

                    buffer[iteratorForNeedleString] = needle[iteratorForNeedleString];
                else
                    break;
                iteratorForNeedleString++;
            }
        }
        iteratorForHaystackString++;
    }

    //used inbuild string compare function to set substring found flag
    if (strcmp(needle, buffer) == 0)
        substringFoundFlag = 0;

    //if substring found then return 1 else return 0
    if (substringFoundFlag == 0)
        return 1;
    else
        return 0;
}
