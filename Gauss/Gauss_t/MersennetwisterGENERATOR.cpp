
#include "MersenneTwisterGENERATOR.h"

MersenTw* MersenTw::s_pInstance = NULL;
unsigned long MersenTw::x[N];
int MersenTw::mti=N+1;

MersenTw::MersenTw()
{
}

MersenTw::~MersenTw()
{
}

MersenTw* MersenTw::getInstance()
{
	if (NULL == s_pInstance)
	{
		s_pInstance = new MersenTw();
	}
	
	return s_pInstance;
}

void MersenTw::release()
{
	if (NULL != s_pInstance)
	{
		delete s_pInstance;
		s_pInstance = NULL;
	}
}


float MersenTw::getFloat()
{
	return (float)genrand_real1();
}

void MersenTw::changeSeed(unsigned long a_ulSeed)
{
	init_genrand(a_ulSeed);
}

//Mersenne Twister

/* инициализация x[N] */

void MersenTw::init_genrand(unsigned long s)
{
	x[0]= s & 0xffffffffUL; //максимальное unsigned long long число и битовая конъюнкция с сидом

	for (mti = 1; mti < N; mti++)
	{
		x[mti] = (1812433253UL * (x[mti-1] ^ (x[mti-1] >> 30)) + mti);
		x[mti] &= 0xffffffffUL;
    }
}

unsigned long MersenTw::genrand_int32(void)
{
	unsigned long y;
	static unsigned long mag01[2]={0x0UL, MATRIX_A};

	if (mti >= N)
	{
		int kk;

		if (mti == N+1)	init_genrand(5489UL);	//использование обычного сида, если не был задан свой

		for (kk = 0; kk < N-M; kk++)
		{
			y = (x[kk]&UP_MASK)|(x[kk+1]&LOW_MASK);
			x[kk] = x[kk+M] ^ (y >> 1) ^ mag01[y & 0x1UL];
		}

		for (; kk < N-1; kk++)
		{
			y = (x[kk]&UP_MASK)|(x[kk+1]&LOW_MASK);
			x[kk] = x[kk + (M-N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
		}

		y = (x[N-1]&UP_MASK)|(x[0]&LOW_MASK);
		x[N-1] = x[M-1] ^ (y >> 1) ^ mag01[y & 0x1UL];

		mti = 0;
	}

	y = x[mti++];

	y ^= (y >> 11);
	y ^= (y << 7) & 0x9d2c5680UL;
	y ^= (y << 15) & 0xefc60000UL;
	y ^= (y >> 18);

	return y;
}

long MersenTw::genrand_int31(void)
{
	return (long)(genrand_int32()>>1);
}

double MersenTw::genrand_real1(void)
{
	return genrand_int32()*((1000.0/4294967295.0))-250; 
}
