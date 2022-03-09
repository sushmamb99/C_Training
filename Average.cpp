#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int marks1, marks2, marks3, marks4, marks5;
	float average;

	printf("Enter the 5 marks: ");
	scanf("%d %d %d %d %d", &marks1, &marks2, &marks3, &marks4, &marks5);

	average = (marks1 + marks2 + marks3 + marks4 + marks5) / 5;
	printf("The average of 5 marks is=%f\n", average);         //implicit type casting

	average = (float)(marks1 + marks2 + marks3 + marks4 + marks5) / 5;   //explicit type casting
	printf("The average of 5 marks is=%f\n", average);

}