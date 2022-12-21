#include "func.h"


int prime_page = -1;
uint NUM_PRIMES;
Value *PRIMES;

void createPrimes(uint num){

	PRIMES = malloc(sizeof(Value)*num);

	FILE *fp = open("res/primes.txt");

	int prime_page = new_page();//create page to store prime values
	int mem = new_page();//create page for computations

	Value one = fromUlong(1);
	Value count = fromUlong(2);


	while(NUM_PRIMES<=num){

		if(brute_force(count)==Y){
			write_value(fp,count);

			seek_page(prime_page);
			Value p = cpy(count);
			PRIMES[i] = p;
			NUM_PRIMES++;
			seek_page(mem);
		}

		count = add(count,one,Y);

	}

}

bool brute_force(Value q){
	Value sqrt = sqrt(q);
	Value remainder;
	bool ret = Y;

	for(int i=0;i<NUM_PRIMES;i++){

		if(max_cmp(PRIMES[i],sq_rt) != B){

			remainder = mod(q,PRIMES[i]);
			if(isZero(remainder) == Y) ret=N; break;

		}else
			break;

	}

	return ret;
}

void load_primes(){

}

/*

// This function is called for all k trials. It returns
// false if n is composite and returns true if n is
// probably prime.
// d is an odd number such that d*2 = n-1
// for some r >= 1
bool miillerTest(Value d, Value n)
{
	// Pick a random number in [2..n-2]
	// Corner cases make sure that n > 4
	Value a = 2 + rand() % (n - 4);

	// Compute a^d % n
	Value x = pwr_mod(a, d, n);

	if (x == 1 || x == n-1)
		return true;

	// Keep squaring x while one of the following doesn't
	// happen
	// (i) d does not reach n-1
	// (ii) (x^2) % n is not 1
	// (iii) (x^2) % n is not n-1
	while (d != n-1)
	{
		x = (x * x) % n;
		d *= 2;

		if (x == 1)	 return false;
		if (x == n-1) return true;
	}

	// Return composite
	return false;
}


*/
