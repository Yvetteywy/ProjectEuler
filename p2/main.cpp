// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

#include <iostream>
using namespace std;

int main()
{
	int sum = 2;
	int s1 = 1, s2 = 2;
	int max = 4000000;
	int pre = 1, cur = 2;
	while (cur < max){
		int i = 3;
		while ( i > 0){
			int temp = cur;
			cur = temp + pre;
			pre = temp;
			i--;
		}
		cout << "cur = " << cur << ", sum = " << sum << endl;
		if ( cur < max)	sum += cur;
	}
	cout << "sum = " << sum << endl;
}
