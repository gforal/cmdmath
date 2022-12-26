/*
	Program:	Simple commandline calculator: math.exe
	Author:		Graham Foral
	Date:		12/24/2022

	Usage:		math.exe [unsigned long long] [mathematical operator] [unsigned long long]
	Version:	0.8
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long operation_add		(long long arg1, char* oper, long long arg3);
long long operation_subtract(long long arg1, char* oper, long long arg3);
long long operation_divide	(long long arg1, char* oper, long long arg3);
long long operation_multiply(long long arg1, char* oper, long long arg3);
long long operation_modulus	(long long arg1, char* oper, long long arg3);
long long operation_power	(long long arg1, char* oper, long long arg3);

int main(int argc, char* argv[]) {
	
	int* nullptr = NULL;
	int i;
	char* oper = argv[2];
	long long arg1 = atoll(argv[1], nullptr, 10);
	long long arg3 = atoll(argv[3], nullptr, 10);


// Detect mathmatic operator, perform calculation, then output equation and answer. 

	if (strcmp(oper, "+") == 0) {
		operation_add(arg1, oper, arg3);		
	}
	else if (strcmp(oper, "-") == 0) {
		operation_subtract(arg1, oper, arg3);
	}
	else if (strcmp(oper, "/") == 0) {
		operation_divide(arg1, oper, arg3);
	}
	else if (strcmp(oper, "*") == 0) {
		operation_multiply(arg1, oper, arg3);
	} 
	else if (strcmp(oper, "%") == 0) {
		operation_modulus(arg1, oper, arg3);
	}
	else if (strcmp(oper, "^") == 0) {
		operation_power(arg1, oper, arg3);
	}


	else {
		printf("\nError: \"%s\" is not a recognized math operation. Valid operations are: \n - Addition (+) \n - Subtraction (-) \n - Multiplication (*) \n - Division (/) \n - Modulus (Remainer) (%%) \n - Power of (^)", oper);
		return 1;
	}

}

long long operation_add(long long arg1, char* oper, long long arg3) {
	long long result = arg1 + arg3;
	printf("%I64d %s %I64d = %I64d\n", arg1, oper, arg3, result);
}

long long operation_subtract(long long arg1, char* oper, long long arg3) {
	unsigned long long result = arg1 - arg3;
	printf("%I64d %s %I64d = %I64d\n", arg1, oper, arg3, result);
}

long long operation_divide(long long arg1, char* oper, long long arg3) {
	long long result = arg1 / arg3;
	printf("%I64d %s %I64d = %I64d\n", arg1, oper, arg3, result);
}

long long operation_multiply(long long arg1, char* oper, long long arg3) {
	long long result = arg1 * arg3;
	printf("%I64d %s %I64d = %I64d\n", arg1, oper, arg3, result);
}

long long operation_modulus(long long arg1, char* oper, long long arg3) {
	long long result = arg1 % arg3;
	printf("%I64d %s %I64d = %I64d\n", arg1, oper, arg3, result);
}

long long operation_power(long long arg1, char* oper, long long arg3) {
	long long result = pow(arg1, arg3);
	printf("%I64d %s %I64d = %I64d\n", arg1, oper, arg3, result);
}