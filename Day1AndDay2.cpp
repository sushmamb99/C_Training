
//// C Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Header.h"
#include"../StaticLib1/pch.h"
#pragma warning(disable:4996)//imp
//#pragma pack (1)
using namespace std;

int val = 1000;
int myapi();
extern const int val1 = 1;
void myfile(int* val)
{

}
struct Emp
{
    int id;
    char name;
    float asal;
};
int main(int argc, char* argv[])
{
    cout << "hello world!" << endl;
    cout << add(10, 20) << endl; //normal function
    cout << multiply(10, 20) << endl; //normal function
    function(); //normal function
    foo(); //static function
    myfoo; //macro defintion
    cout << val << endl; //extern variable
    cout << pi << endl; //macro 
    cout << value << endl; // sat
    cout << val1 << endl; //const int 
    bar();
    float f = 0.7;
    if (f < 0.7)
        cout << "hello\n";
    else
        cout << "bye\n";
    const int c = 10;
    int* ptr = const_cast<int*>(&c); //type cast (int *)( & c);
    myfile((int*)&c);
    *ptr = 11;
    cout << *ptr << endl;
    cout << c << endl;



    printf("%d", printf("hello"));


    int x = 3;
    int y = x++ * --x * x++;
    cout << x << " " << y << endl;

    /*int w, x, y, z;
    x = y = z = 1;
    w = ++x || ++x && ++y && ++z;
    cout << x << y << z << w << endl;
    while (1, 0, 1, 0) //last digit is loop will not execute
    {
        cout << "hello";
    }*/
    /*while (1, 0, 1, 1) //last digit is loop will execute and infinite loop
    {
        cout << "hello";
    }*/
    cout << myapi() << endl;
    /*char str1[] = "hello";
     str1[1] = 'o';
     char str2[] = { 'h','e','l','l','\0' };
     str2[2] = 'm';
     int a[][2] = {1,2,3,4};
     cout << a <<" " << a + 1 <<" "<<  1[a] <<" "<< &a[0] << " "<<*(1+a);
     cout << str1 << " " << str2;*/

     /* int x = 10;
      const int* p = &x; //intger to const integer pointer
      x++;
      int x = 10;
      int* const p = &x;
      const int x = 10;
      int* const p = &x;*/
      /* int a[] = {1,2,3,4};
       int* p1 = a;
       int* p2 = a + 1;
       cout << p2<<endl;
       cout << p1<<endl;
       printf("%u\n", p2 - p1);
       int *brr[] = { a,a + 1,a + 2,a + 3,a + 5 };
       int** ptr = brr;
       **ptr++;
       printf("%u %u %u %u\n", ptr - brr, *ptr - a, **ptr,ptr);
       *++* ptr;
       printf("%u %u %u %u\n", ptr - brr, *ptr - a, **ptr,ptr);
       ++** ptr;
       printf("%u %u %u %u\n", ptr - brr, *ptr - a, **ptr,ptr);*/


       /* int no = 5;
        int* arr  = (int *)malloc(sizeof(int) * 5);
        int* arr1 = (int*)calloc(sizeof(int), 5);
        arr1 = (int*)realloc(arr1, sizeof(int)*8);*/
    realloc(arr1, 8);
    /* if (arr == null)
     {
         cout << "memory is not allocated" << endl;
     }*/
    int* arr2 = (int*)realloc(arr1, 8);
    /* cout << arr << endl;
     cout << arr1 << endl;
     cout << &arr << endl;
     cout << &arr1 << endl;
     cout << *arr << endl; //malloc is not intialize the arrary
     cout << *arr1 << endl;
     cout << *&arr << endl;
     cout << *&arr1 << endl;*/
    for (int i = 0; i < no; i++)
        cout << *(arr + i) << endl;
    for (int i = 0; i < 8; i++)
        *(arr1 + i) = i;
    for (int i = 0; i < 8; i++)
        cout << *(arr1 + i) << endl;
    int* newptr = arr; //dangling pointer // avoid shwalow copy // avoid shallow copy to dangling pointers

    int* newptr1 = (int*)malloc(sizeof(int) * no); //deep copy
    for (int i = 0; i < no; i++)
        *(newptr1 + 1) = *(arr + i);


    free(newptr);//this will work
    newptr = null;
    free(arr1);
    arr1 = null;
    free(newptr1);

    int row, col;
    cin >> row >> col;
    int** ptr = (int**)calloc(sizeof(int*), row);
    for (int i = 0; i < col; i++)
        *(ptr + i) = (int*)calloc(sizeof(int), col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            *(*(ptr + i) + j) = i + 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << *(*(ptr + i) + j) << " ";
        cout << endl;
    }

    char** ptr;
    int row = 3;
    ptr = (char**)malloc(sizeof(char*) * row);
    char* mystring = (char*)malloc(20);
    // newptr1 = null;
    for (int i = 0; i < row; i++)
    {
        cin >> mystring;
        *(ptr + i) = (char*)malloc(sizeof(char) * (strlen(mystring) + 1));
        strcpy(ptr[i], mystring);
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = i + 1; j < row; j++)

            if (strcmp(ptr[i], ptr[j]) > 0)
            {
                char* tmp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = tmp;
            }

    }
    for (int i = 0; i < row; i++)
    {
        cout << *(ptr + i) << endl;
    }


    for (int i = 0; i < row; i++)
    {
        free(*(ptr + i));
        *(ptr + i) = null;
    }



    free(ptr);
    ptr = null;
    free(newptr);
    struct emp e1;
    struct emp* eptr;
    eptr = &e1;
    cout << sizeof(e1) << " " << sizeof(eptr) << endl;
    printf("leaks=%d\n", _crtdumpmemoryleaks()); /*important*/

    return 0;

}

int myapi()
{
    cout << "in myapi" << endl;
    return 10, 20, 30;
}
//
//// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
//// Debug program: F5 or Debug > Start Debugging menu
//
//// Tips for Getting Started: 
////   1. Use the Solution Explorer window to add/manage files
////   2. Use the Team Explorer window to connect to source control
////   3. Use the Output window to see build output and other messages
////   4. Use the Error List window to view errors
////   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
////   6. In the future, to open this project again, go to File > Open > Project and select the .sln file