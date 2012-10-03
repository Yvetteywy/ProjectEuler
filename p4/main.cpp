// Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>
#include <math.h>
using namespace std;
// change the number here to find more x-digit product as palindrome
#define M 999
#define N 999

int digit(int num)
{
	int d = 0;
	while (num > 0) {
		num /= 10;
		d ++;
	}
	return d;
}

bool palindrome(int number)
{
	int num = number;
	int d = digit(num), dig = d;
	int i = ( d + d % 2)/2;
	while ( i > 0) {
		int l = num / pow(10.0, d-1);
		int r = num % int(pow(10.0, dig - (d-1)));
		if ( l != r ) {
			return false;
		}else{
			num -= l * pow(10.0, d-1) + r * pow(10.0, dig - d);
			num /= 10;
			d -= 2;
			dig -= 2;
			i --;
		}
	}
	return true;
}

int composite(int num)
{
	int c = (M+1)/10;
	while ( c < (M+1) )
	{
		if ( num % c == 0 )
		{
			int f = num / c;
			if ( f < (M+1))
				return c;
		}
		c ++;
	}
	return -1;
}


// this is not the best way to do it.
// should consider it from Math aspect...
int main()
{
	int num = M * N;
	int base = M/10 * N/10;
	while (num > base) {
		// find palindrome first
		// then try to composite it
		if ( palindrome(num) ) {
			int factor = composite(num);
			if (factor > 0 ){
				cout << "palindrome: " << num<< " = " << factor<< " * "<< num/factor << endl;
				break;
			}
		}
		num --;
	}
	return 1;
}
