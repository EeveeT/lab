#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define reset 0
#define max 1000

enum bool {false = 0, true = 1};
typedef enum bool bool;

void testAssert(void);
bool testValidChar (char *roman, int x);
bool testValidString (int *arabic, char *roman);

int calcArabic (int *arabic, char *roman);
int romanToArabic( char *roman );

int main(int argc, char **argv){ 

	if( argc == 2 ){
			testAssert();
			printf("The roman numeral %s is equal to %d\n", \
			argv[1], romanToArabic(argv[1]));
			}

	else {
			printf("ERROR: Incorrect usage, try e.g. %s XXI\n", argv[0]);
	}

	return 0;

}

int romanToArabic( char *roman ){
/* roman[] == *roman as far as compiler is concerned */

	/* conversion arrays */
	char roman_array[] =
		{ 'I','V','X' ,'L' ,'C'  ,'D'  ,'M'};
	int arab_array[] =
		{  1 , 5 , 10 , 50 , 100 , 500 , 1000};

	char a, b;	
	int x = 0, cnt;
	int arabic[max];

	/* How many numerals are left in the list? */
	while (roman[x] != '\0'){
		
		cnt = reset;
		roman[x] = toupper(roman[x]);		

		/* Check character is valid */
		if (!testValidChar(roman, x)){
			printf("ERROR: Incorrect usage. Use roman numerals (e.g. IV).\n");
			exit (0);
		}

		/* What is the equivalence in roman array? */
		a = roman[x];
		b = roman_array[cnt];

		while (a != b){
			b = roman_array[++cnt];
		}

		/* Identify value & pass to array*/
		arabic[x] = arab_array[cnt];
		++x;
	}

return calcArabic(arabic, roman);

}

int calcArabic (int *arabic, char *roman){

	int x = 0, calc = 0;
	
	/* Check Roman string valid for calculation */
	if (!testValidString(arabic, roman)){
		printf("ERROR: Incorrect usage, invalid roman numeral.\n");
		exit (0);
			}

		/* Is this the numeral in the list? */
		while (roman[x] != '\0'){	

			/* Does a value x+1 exist, and is it greater than x? */
			if (roman[x + 1] != '\0' && arabic[x] < arabic[x+1]){

				/* Calculate roman to Arabic, e.g. IV = 5 - 1 */
				calc = calc + (arabic[x+1] - arabic[x]);

				++x;
			}

			else {
					calc = calc + arabic[x];
			}

			++x;
		}

return calc;
}

void testAssert(void){

int b[] = {5, 10};

	assert(calcArabic(&b[0],"V") != 10);
	assert(calcArabic(&b[1],"X") == 10);
/*	
	assert(romanToArabic("MCMXCIX") == 1999);
	assert(romanToArabic("MDVI") == 1506);
	assert(romanToArabic("MCMLXVII") != 1506);
*/
}

bool testValidChar ( char *roman, int x) {

	switch(roman[x]){
		case 'I' :
		case 'V' :
		case 'X' :
		case 'L' :
		case 'C' :
		case 'D' :
		case 'M' :
				return true;
	}

	return false;
}

bool testValidString (int *arabic, char *roman){

	int x = 0;
	

	while (roman[x] != '\0'){

		/* e.g. VV is not valid */
		if (roman[x + 1] != '\0' && roman[x] == roman[x+1]){
			if (arabic[x] == 50 || arabic[x] == 5 || arabic[x] == 500){

				return false;
			}
		}

		/* e.g. CMM is not valid */
		else if (roman[x + 2] != '\0' && arabic[x + 1] > arabic[x]){
			if (	arabic[x + 2]	 > arabic[x]	){

				return false;
			}
		}
		
		/* e.g. IIII is not valid */
		else if( roman[x + 3] != '\0' &&
				roman[x] == roman[x + 1]  &&
				roman[x] == roman[x + 2]  && 
				roman[x] == roman[x + 3] 	){

				return false;
		}


		++x;
	}

return true;

}
