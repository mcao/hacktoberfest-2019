#include "mylib.h"
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void binaryTester(int array[], int test[], int size)
{
    int i;
    for(i = 0; i < size; i++){
        assert(array[i] == test[i]);
    }
    printf("\n");
}

int main(){
    printf("\t-----------------------------------\n");
	printf("\t-   Part1 : String Manipulation   -\n");  
    printf("\t-----------------------------------\n");

	char haystack[][20] = {"chocolate","vanilla","caramel","strawberry","banana","cherry"};
	char needle[][20] = {"choc","lla","am","strawberry","na","terrible"};
    char buffer[255];

    printf("\n\t=========Testing myStrStr with '%s' and substring '%s'===========\n\n", haystack[0], needle[0]);
    int result = myStrStr(haystack[0],needle[0],buffer);
    assert(result == 1 && strcmp(needle[0], buffer) == 0);
    printf("\n\t\t....Test Passed\n");

    printf("\n\t=========Testing myStrStr with '%s' and substring '%s'===========\n\n", haystack[1], needle[1]);
    result = myStrStr(haystack[1],needle[1],buffer);
    printf("needle: %s, buffer: %s\n", needle[1], buffer );
    assert(result == 1 && strcmp(needle[1], buffer) == 0);
    printf("\n\t\t....Test Passed\n");

    printf("\n\t=========Testing myStrStr with 'blueberry' and substring 'ueber'===========\n\n");
    result = myStrStr(haystack[2],needle[2],buffer);
    assert(result == 1 && strcmp(needle[2], buffer) == 0);
    printf("\n\t\t....Test Passed\n");

    printf("\n\t=========Testing myStrStr with 'strawberry' and substring 'strawberry'===========\n\n");
    result = myStrStr(haystack[3],needle[3],buffer);
    assert(result == 1 && strcmp(needle[3], buffer) == 0);
    printf("\n\t\t....Test Passed\n");

    printf("\n\t=========Testing myStrStr with 'banana' and substring 'na'===========\n\n");
    result = myStrStr(haystack[4],needle[4],buffer);
    assert(result == 1 && strcmp(needle[4], buffer) == 0);
    printf("\n\t\t....Test Passed\n");

    printf("\n\t=========Testing myStrStr with 'grapefruit' and substring 'terrible'===========\n\n");
    result = myStrStr(haystack[5],needle[5],buffer);
    assert(result == 0);
    printf("\n\t\t....Test Passed\n");

//////////////////////////////////////////////////////////////////////////////
    printf("\t-----------------------------------\n");
    printf("\t-   Part2 : Working with Binary   -\n");
    printf("\t-----------------------------------\n");

    printf("\n\t=========Test Counting Ones===========\n\n");
    assert(countOnes(1) == 1);
    assert(countOnes(7) == 3);
    assert(countOnes(0) == 0);
    assert(countOnes(0x10) == 1);
    assert(countOnes(-1) == sizeof(int)*8);
    printf("\n\t\t....Counting 1's passed\n");

    int size = sizeof(int) * 8;
    int array[size], i;

    printf("\n\t=========Testing Conversion of 2===========\n\n");
    binaryArray(2, array, size);
    binaryPrinter(array, size);
    int test1[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0};
    binaryTester(array, test1, size);
    printf("\n\t\t....Converting 2 Passed\n");

    printf("\n\t=========Testing Conversion of 255===========\n\n");
    binaryArray(255, array, size);
    binaryPrinter(array, size);
    int test2[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
    binaryTester(array, test2, size);
    printf("\n\t\t....Converting 255 Passed\n");

    printf("\n\t=========Testing Conversion of -1===========\n\n");
    binaryArray(-1, array, size);
    binaryPrinter(array, size);
    int test3[32] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    binaryTester(array, test3, size);
    printf("\n\t\t....Converting -1 Passed\n");

    printf("\n\t=========Testing Conversion of INT_MAX===========\n\n");
    binaryArray(INT_MAX, array, size);
    binaryPrinter(array, size);
    int test4[32] = {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    binaryTester(array, test4, size);
    printf("\n\t\t....Converting INT_MAX Passed\n");

    printf("\n\t=========Testing Conversion of INT_MIN===========\n\n");
    binaryArray(INT_MIN, array, size);
    binaryPrinter(array, size);
    int test5[32] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    binaryTester(array, test5, size);
    printf("\n\t\t....Converting INT_MIN Passed\n");

    printf("\n\t=========All Tests Passed. Don't forget to submit!===========\n\n");

	return 0;
}
