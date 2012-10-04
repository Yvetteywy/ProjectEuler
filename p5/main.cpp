// smallest +num that can be divided by 1~20

#include <iostream>
#include <math.h>

#define SMALL1_10 2520

using namespace std;


/*
   2520 is min num for 1~10

   11, 13, 17, 19 are prime nums.

   15 = 3 * 5
   14 = 2 * 7 and 18 = 2 * 9, both are factors of 2520.
   so no need to consider the above

   do a brute-force to test
   */
int main()
{
	int prime = 11 * 13 * 17 * 19;
	int start = SMALL1_10 * prime;

	for ( int i = 12; i < 21; i+=2 ) {
		/* i used this int divide n remainder
		   since the double type does not work as expected
		   */
		int divide = (int)( start / i);
		int remainder = start - divide * i;
		if ( remainder != 0) {
			cout << "before: start = " << start << endl;
			start = start / remainder * i;
			cout << "after: start = " << start << endl;
		}
	}
	cout << "final answer = " << start << endl;
}

