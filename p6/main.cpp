// difference between sq sum and sum of sq.

#include <iostream>
#include <math.h>

// from 1 ~ MAX
#define MAX 100

using namespace std;

int main()
{
	/*
	   the diff should be sum of double products of each pair of numbers
	   */
	int i, j;
	int sum = 0;
	for ( i = 1; i < MAX ; i++ ) {
		for ( j = i + 1; j < MAX + 1; j ++ ) {
			sum += i * j;
		}
	}
	cout << "answer = " << 2 * sum << endl;
	return 0;
}
