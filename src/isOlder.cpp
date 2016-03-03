#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {

	int i, j,year1 = 0, year2 = 0;

	for (i = 0; dob1[i] && ((9 >= (int)(dob1[i] - '0')) || (dob1[i] == '-')); i++); if (i != 10) return -1;
	for (j = 0; dob2[j] && ((9 >= (int)(dob2[i] - '0')) || (dob2[i] == '-')); j++); if (j != 10) return -1;

	for (i = 6; i<10; i++)
	{
		year1 *= 10;
		year2 *= 10;
		year1 += dob1[i] - '0';
		year2 += dob2[i] - '0';


	}

	

	int mon1= 0, mon2 = 0;
	for (i = 3; i < 5; i++)
	{
		mon1 *= 10;
		mon2 *= 10;
		mon1 += dob1[i] - '0';
		mon2 += dob2[i] - '0';
	}
	if (mon1 >12 || mon2> 12) return -1;
	

  int	day1 = 0, day2 = 0;
	for (i = 0; i < 2; i++)
	{
        day1 *= 10;
		day2 *= 10;
		day1 += dob1[i] - '0';
		day2 += dob2[i] - '0';
	}
	

	if (((year1 % 4) == 0 && mon1 == 2 && day1>29) || ((year1 % 4) != 0 && mon1== 2 && day1>28)) return -1;
	if (((year2 % 4) == 0 && mon2 == 2 && day2>29) || ((year2 % 4) != 0 && mon2== 2 && day2>28)) return -1;

	if (day1 >31 || day2 > 31) return -1;

	if (year1 < year2)
	{
		return 1;
	}
	else if (year1 > year2)
		return 2;
	printf("%d . %d \n", year1, year2);
	if (mon1 < mon2)
	{
		return 1;
	}
	else if (mon2 < mon1)
		return 2;


	if (day1 < day2)
	{
		return 1;
	}
	else if (day2 < day1)
		return 2;


	








	return 0;
}
