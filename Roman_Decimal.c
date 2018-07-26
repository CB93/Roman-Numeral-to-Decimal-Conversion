// Roman_Decimal.c
// Student: Caleb Brown
// Date: June 27, 2018

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#include < stdio.h > 
#include < ctype.h >



convertRoman(int * decimalNum, int * previousNum, int * bool);
checkPrevious(const int amount, int ** val, const int previousNum);

// Runs the Program
int main(void)
{
	int num = 0, decimalNum = 0, previousNum = 0, count, bool = 1, getch(void);

	printf("10 Roman numeral values will be input and converted into\n" 
		"their equivalent Hindu - Arabic numeric values.\n");

	for (count = 0; count < SIZE; count++) 
	{

		printf("\nInput Roman numeral #: %d  ", count + 1);

		convertRoman(&decimalNum, &previousNum, &bool);

	
		(bool ? printf(" = %d\n", decimalNum) : printf( 
			"Error - last character was not valid!!!\n")); 	// If TRUE
	

		decimalNum = 0, num = 0, previousNum = 0;
		bool = 1; // TRUE

	}
	printf("THATS ALL FOLKS :)");
	getch();

}


// Takes in roman numeral chars and converts into numeric values
convertRoman(int * decimalNum, int * previousNum, int * bool)
{
	int M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1;
	char input;
	while (((input) = getchar()) != '\n')
	{

		switch (toupper(input)) 
		{

		case 'I':
			*decimalNum += I; // Increment by 1
			checkPrevious(I, &decimalNum, *previousNum); *previousNum = I;
			break;

		case 'V':
			*decimalNum += V; // Increment by 5
			checkPrevious(V, &decimalNum, *previousNum); *previousNum = V;
			break;

		case 'X':
			*decimalNum += X; // Increment by 10
			checkPrevious(X, &decimalNum, *previousNum); *previousNum = X;
			break;

		case 'L': 
			*decimalNum += L; // Increment by 50
			checkPrevious(L, &decimalNum, *previousNum); *previousNum = L;
			break;

		case 'C':
			*decimalNum += C; // Increment by 100
			checkPrevious(C, &decimalNum, *previousNum); *previousNum = C;
			break;

		case 'D':
			*decimalNum += D; // Increment by 500
			checkPrevious(D, &decimalNum, *previousNum); *previousNum = D;
			break;

		case 'M':
			*decimalNum += M; // Increment by 1000
			checkPrevious(M, &decimalNum, *previousNum); *previousNum = M;
			break;

		default:
			* bool = 0; // FALSE
			break;

		}
	}

}

// Detects when to apply subtractive notation from passed previousChar and currentChar
checkPrevious(const int currentChar, int ** val, const int previousChar) 
{

	if (previousChar < currentChar) 
	{
		** val -= (2 * previousChar);
	}

}
