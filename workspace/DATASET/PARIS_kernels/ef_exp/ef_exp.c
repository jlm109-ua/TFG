#include <stdio.h>
#include <stdint.h>

#define FLT_UWORD_IS_NAN(x) ((x) > 0x7f800000L)
#define FLT_UWORD_IS_INFINITE(x) ((x) == 0x7f800000L)
#define FLT_UWORD_LOG_MAX 0x42b17217
#define FLT_UWORD_LOG_MIN 0x42cff1b5

/* A union which permits us to convert between a float and a 32 bit
   int.  */

typedef union
{
	float value;
	uint32_t word;
} ieee_float_shape_type;

/* Get a 32 bit int from a float.  */

#define GET_FLOAT_WORD(i, d)    \
	ieee_float_shape_type gf_u; \
	gf_u.value = (d);           \
	(i) = gf_u.word;

/* Set a float from a 32 bit int.  */

#define SET_FLOAT_WORD(d, i)    \
	ieee_float_shape_type sf_u; \
	sf_u.word = (i);            \
	(d) = sf_u.value;

static const float
	one = 1.0,
	halF[2] = {
		0.5,
		-0.5,
},
	huge = 1.0e+30, twom100 = 7.8886090522e-31, /* 2**-100=0x0d800000 */
	ln2HI[2] = {
		6.9313812256e-01, /* 0x3f317180 */
		-6.9313812256e-01,
}, /* 0xbf317180 */
	ln2LO[2] = {
		9.0580006145e-06, /* 0x3717f7d1 */
		-9.0580006145e-06,
},							   /* 0xb717f7d1 */
	invln2 = 1.4426950216e+00, /* 0x3fb8aa3b */
	P1 = 1.6666667163e-01,	   /* 0x3e2aaaab */
	P2 = -2.7777778450e-03,	   /* 0xbb360b61 */
	P3 = 6.6137559770e-05,	   /* 0x388ab355 */
	P4 = -1.6533901999e-06,	   /* 0xb5ddea0e */
	P5 = 4.1381369442e-08;	   /* 0x3331bb4c */

float result;
float x;
int total_errors;
float expected = 20.085537;
void init()
{
	total_errors = 0;
	x = 3; // 2.718282 elevado a 3
}

void test() /* default IEEE double exp */
{
	float y, hi, lo, c, t;
	int32_t k = 0, xsb, sx;
	uint32_t hx;

	GET_FLOAT_WORD(sx, x);
	xsb = (sx >> 31) & 1; /* sign bit of x */
	hx = sx & 0x7fffffff; /* high word of |x| */

	/* filter out non-finite argument */
	if (FLT_UWORD_IS_NAN(hx))
		result = x + x; /* NaN */
	if (FLT_UWORD_IS_INFINITE(hx))
		result = (xsb == 0) ? x : 0.0; /* exp(+-inf)={inf,0} */
	if (sx > FLT_UWORD_LOG_MAX)
		result = huge * huge; /* overflow */
	if (sx < 0 && hx > FLT_UWORD_LOG_MIN)
		result = twom100 * twom100; /* underflow */

	/* argument reduction */
	if (hx > 0x3eb17218)
	{ /* if  |x| > 0.5 ln2 */
		if (hx < 0x3F851592)
		{ /* and |x| < 1.5 ln2 */
			hi = x - ln2HI[xsb];
			lo = ln2LO[xsb];
			k = 1 - xsb - xsb;
		}
		else
		{
			k = invln2 * x + halF[xsb];
			t = k;
			hi = x - t * ln2HI[0]; /* t*ln2HI is exact here */
			lo = t * ln2LO[0];
		}
		x = hi - lo;
	}
	else if (hx < 0x31800000)
	{ /* when |x|<2**-28 */
		if (huge + x > one)
			result = one + x; /* trigger inexact */
	}

	/* x is now in primary range */
	t = x * x;
	c = x - t * (P1 + t * (P2 + t * (P3 + t * (P4 + t * P5))));
	if (k == 0)
		result = one - ((x * c) / (c - (float)2.0) - x);
	else
		y = one - ((lo - (x * c) / ((float)2.0 - c)) - hi);
	if (k >= -125)
	{
		uint32_t hy;
		GET_FLOAT_WORD(hy, y);
		SET_FLOAT_WORD(y, hy + (k << 23)); /* add k to y's exponent */
		result = y;
	}
	else
	{
		uint32_t hy;
		GET_FLOAT_WORD(hy, y);
		SET_FLOAT_WORD(y, hy + ((k + 100) << 23)); /* add k to y's exponent */
		result = y * twom100;
	}
}

/* This scale factor will be changed to equalise the runtime of the
   benchmarks. */
#define SCALE_FACTOR (REPEAT_FACTOR >> 0)

/* This benchmark does not support verification */

void check()
{
	//printf("%f",result);

	// printf("resultado , total_errors: %f %d\n", result, total_errors);
}

void runMain(){
	init();
	test();
	//return result;
}	

int main(){
	runMain();
	return 0 ;
}
