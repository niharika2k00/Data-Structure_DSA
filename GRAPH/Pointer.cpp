
// Pointer
#include <iostream>
#include <vector>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

void func1(int dynArray[])
{
    printf("func1: dynArray = %p, &dynArray[0] = %p, dynArray[0] = %d\n", dynArray, &dynArray[0], dynArray[0]);
}

void func2(int *intPtr)
{
    printf("func2: intPtr = %p, &intPtr[0] = %p, intPtr[0] = %d\n", intPtr, &intPtr[0], intPtr[0]);
}

void func3(int intVal)
{
    printf("func3: intVal = %d, &intValue = %p\n", intVal, &intVal);
}

int main()
{
    int mainArray[3] = {1, 2, 3};
    int mainInt = 10;

    printf("mainArray = %p, &mainArray[0] = %p, mainArray[0] = %d\n", mainArray, &mainArray, mainArray[0]);
    func1(mainArray);
    func2(mainArray);

    printf("mainInt = %d, &mainInt = %p\n", mainInt, &mainInt);
    func3(mainInt);

    return 0;
}