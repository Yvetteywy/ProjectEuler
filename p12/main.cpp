#include <iostream>
#include <math.h>

#define NUM 500
#define START 31

using namespace std;

long Triangle(long n)
{
	return n*(n+1)/2;
}

int main()
{
	cout << "Testing..." << endl;
	long n = START;
	long triangle;
	int num_divisor;

	while (num_divisor < NUM) {
		long divisor = 2;
		num_divisor = 2;
		n ++;
		triangle = Triangle(n);
		while ( divisor < (long)sqrt(triangle)+1) {
			if (triangle % divisor == 0 ) {
				num_divisor += 2;
				if ( divisor == sqrt(triangle))
					num_divisor --;
			}
			divisor ++;
		}
	}
	cout << "answer = " << triangle << endl;
	return 0;
}
