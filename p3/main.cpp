// find the largest prime factor of a compositive number

#include <iostream>
using namespace std;

int main()
{
	long num = 600851475143;
	int div = 2;
	// I'm using a 'cur' because I 
	// don't wanna ruin the original number
	long cur = num;
	while (div < cur) {
		if (cur % div == 0) {
			cur = cur / div;
			cout << "div = " << div << endl;
		}else{
			// if the small number is not a factor,
			// its multiples not, either.
			// thus ensure the factors be prime.
			div ++;
		}
	}
	cout << "ending cur = " << cur << endl;
}
