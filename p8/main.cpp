// find the greatest product of 5 consecutive numbers in 1000 digit number.

#include <iostream>

#define LENGTH 1000

using namespace std;

int makeInt(char n)
{
	return n - 48;
}

// recursively find the sequence of 5 non-zero digits
int findNonZeroProduct(char* num, int start)
{
	int left = start, right = left;
	while ( right - left < 5 && left < LENGTH && right < LENGTH) {
		if ( makeInt(num[right]) == 0 ) {
			return findNonZeroProduct(num, right + 1);
		}else {
			right ++;
		}
	}
	return left;
}

int main()
{
	char num[LENGTH + 1] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

	int right = 0, left = 0;
	int product = 1, max_product = 1;
	// get the first 5 products
	while ( right < 5 ) { product *= makeInt(num[right++]);} 
	max_product = product;
	while (right < LENGTH ) {
		if ( makeInt(num[right]) != 0 ){
			// using a sliding-window method
			product = product * \
				   makeInt(num[right]) / makeInt(num[left]);
			if ( product > max_product ) {
				max_product = product;
			}
		} else {
			// try to find a sequence of 5 non-zero numbers
			left = findNonZeroProduct(num, right + 1);
			right = left;
			product = 1;
			// calculate the products
			while ( right - left < 5 ) {
				product *= makeInt(num[right++]);
			}
			// since outside will do a right++, here minus 1.
			right --;
			// update the max-product
			if ( product > max_product )
				max_product = product ;
		}
		left ++; right ++;
	}

	cout << "answer = " << max_product<< endl;
	return 0;
}
