#include "Random.h"
#include <stdlib.h>


using namespace std;

int Random(DamageRange A)
{
	return A.mLowDamage + rand() % ((A.mHighDamage + 1) - A.mLowDamage);
}

int Random(int A, int B)
{
	return A + rand() % ((B + 1) - A);
}

int RandomPosition(int Min, int Max){
	return Min + rand() % ( Max - Min + 1 );
}