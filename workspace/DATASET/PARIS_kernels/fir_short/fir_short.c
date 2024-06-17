// #include <stdio.h>

/* BEEBS fir benchmark

   MDH WCET BENCHMARK SUITE.
   Copyright (C) 2014 Embecosm Limited and University of Bristol

   Contributor Pierre Langlois <pierre.langlois@embecosm.com>

   This file is part of the Bristol/Embecosm Embedded Benchmark Suite.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program. If not, see <http://www.gnu.org/licenses/>. */

//#include "support.h"

/* This scale factor will be changed to equalise the runtime of the
   benchmarks. */
//#define SCALE_FACTOR    (REPEAT_FACTOR >> 0)

#define LOOPS 1

/*--------------------------------------------------
 *---- INPUT DATA FOR TESTING
 *--------------------------------------------------*/
const long fir_int[36]={
0xfffffffe, 0x1, 0x4, 0x3, 0xfffffffe, 0xfffffffc, 0x2, 0x7, 0x0,
0xfffffff7, 0xfffffffc, 0xc, 0xb, 0xfffffff2, 0xffffffe6, 0xf, 0x59, 0x7f,
0x59, 0xf, 0xffffffe6, 0xfffffff2, 0xb, 0xc, 0xfffffffc, 0xfffffff7, 0x0,
0x7, 0x2, 0xfffffffc, 0xfffffffe, 0x3, 0x4, 0x1, 0xfffffffe, 0};

const long in_data[128]={
0x0, 0x0, 0x0, 0x0, 0x7f, 0x79, 0x72, 0x79, 0xd, 0xd,
0x0, 0x3, 0x5, 0x2, 0x3, 0x7f, 0x7f, 0x2, 0x7e, 0x0,
0x1, 0x7e, 0x1, 0x1, 0x7f, 0x0, 0x7f, 0x0, 0x2, 0x1,
0x1, 0x3, 0x1, 0x7f, 0x1, 0x0, 0x1, 0x1, 0x7d, 0x7b,
0x73, 0x6a, 0x77, 0x10, 0xe, 0x1, 0x5, 0x5, 0x5, 0x5,
0x7d, 0x0, 0x2, 0x7d, 0x0, 0x0, 0x7e, 0x1, 0x7e, 0x7f,
0x3, 0x7c, 0x7e, 0x6, 0x0, 0x7e, 0x3, 0x2, 0x7f, 0x7e,
0x7f, 0x2, 0x1, 0x7f, 0x1, 0x1, 0x0, 0x3, 0x0, 0x7f,
0x2, 0x0, 0x7f, 0x3, 0x1, 0x0, 0x0, 0x7d, 0x0, 0x3,
0x0, 0x7e, 0x7f, 0x2, 0x1, 0x7e, 0x0, 0x3, 0x7f, 0x7d,
0x1, 0x1, 0x1, 0x7f, 0x0, 0x5, 0x0, 0x7f, 0x2, 0x7e,
0x7f, 0x2, 0x1, 0x0, 0x7e, 0x0, 0x5, 0x0, 0x7f, 0x0,
0x7e, 0x1, 0x0, 0x7d, 0x1, 0x3, 0x7f, 0x0};

const long out_data[128]={
0xfffffffff286bca4, 0x6bca1aec, 0x53896e78, 0xffffffffbad5c86c, 0x649a7fe5, 0xffffffff91840b50, 0xffffffff823ee117, 
0x5c84f111, 0x3c2eb592, 0x31674c60, 0x4c59d31e, 0x452a37b5, 0x4e25b9e8, 0x37b0f451, 
0x2f9b65a8, 0xfffffffff5389743, 0x785d6b4f, 0xffffffffd5c84f5b, 0x324d3ff2, 0x36cb0107, 0xffffffffdb2c03c5, 
0x58ed2338, 0x41926a26, 0x2c0397f4, 0xffffffffc0397d12, 0x48c205ab, 0xffffffffe50d7986, 0xffffffffcf7ea73a, 
0xffffffff96e7bf5b, 0xffffffff9fe34186, 0x4a8dec31, 0xffffffffe7bf5397, 0xffffffffd0649aae, 0xffffffff9601cc22, 0x2dcf7ecc, 
0xffffffffdb2c0397, 0x52a37b06, 0x3081590a, 0x2785d708, 0x6cb00ee2, 0xe5f3752, 0x50d794a5, 
0xffffffffcdb2c088, 0x397cdb5b, 0xffffffffb823ee1b, 0xe5f36c9, 0xffffffff99999994, 0xffffffffd79435e9, 0x2dcf7ebc, 
0xffffffff999999bd, 0xffffffffc0397d08, 0x5e50d7c5, 0xffffffffb48c2085, 0xbad5cae, 0xffffffff9d316772, 0xffffffffc2eb574c, 
0xffffffffd3fc6869, 0x213c2efe, 0xffffffff9e175b11, 0x649a7fec, 0xffffffffea712e2a, 0xffffffffbf5389bd, 0x23ee0942, 
0xffffffffd5c84f4d, 0x63b48c52, 0xffffffff9435e528, 0xffffffff999999b0, 0xffffffffd4e25bd6, 0x59d316de, 0xffffffffb00e5fb2, 
0xffffffffb823ee62, 0xffffffffd3fc6861, 0x41926a22, 0x3ee08fe8, 0xffffffffb00e5f61, 0x2785d6b6, 0x49a7f8c5, 
0xffffffffd0649a87, 0xffffffffad5c8515, 0x41926a2f, 0xffffffffd9601cee, 0xffffffffd14a8e1f, 0xffffffffad5c8523, 0x3ee08fd6, 
0x601cbe71, 0x46102b24, 0x24d3fc8c, 0x3fc68358, 0x601cbe8f, 0xffffffffee08fb90, 0xffffffffb658074e, 
0xffffffffaf286c15, 0xffffffffd0649ae0, 0x7f8d0695, 0x40ac76b3, 0xffffffff9269fe42, 0x42785d8c, 0x62ce98fd, 
0x5d6ae485, 0x230815db, 0xffffffffd0649aa5, 0xffffffffd5c84f17, 0xffffffffb00e5f4f, 0xffffffffaf286bfc, 0xffffffffd3fc6865, 
0xffffffffd0649a95, 0xffffffff91840acc, 0xffffffffac7691ad, 0x649a7ff1, 0xfffffffff36cb085, 0xffffffffaf286c17, 0x1da46118, 
0xffffffffd31674d0, 0xffffffffd4e25bc5, 0xffffffffcf7ea748, 0x3dfa9c6e, 0x3896e7cb, 0xffffffffcf7ea728, 0x601cbea6, 
0x5c84f108, 0x5c84f0fb, 0x59d3169b, 0x3fc68341, 0x5b9efd75, 0xffffffffeb57216f, 0x75ab90d4, 0xffffffffc4b73e28, 0xffffffffc59d3185};

int total_errors = 0;

// To match size of input
#define OUTSIZE 128
long output[OUTSIZE];
long data[128];

/*--------------------------------------------------
 *--- Prototypes
 *--------------------------------------------------*/


void fir_filter_int(const long* in,long* out,long in_len,
                    const long* coef,long coef_len,
                    long scale);

/**************************************************************************
fir_filter_int - Filters int data array based on passed int coefficients.

The length of the input and output arrays are equal
and are allocated by the calller.
The length of the coefficient array is passed.
An integer scale factor (passed) is used to divide the accumulation result.

void fir_filter_int(int *in,int *out,int in_len,
                                  int *coef,int coef_len,int scale)

    in          integer pointer to input array
    out         integer pointer to output array
    in_len      length of input and output arrays
    coef        integer pointer to coefficient array
    coef_len    length of coeffient array
    scale       scale factor to divide after accumulation

No return value.

*************************************************************************/

void fir_filter_int(const long* in,long* out,long in_len,
                    const long* coef,long coef_len,
                    long scale)
{
  long i,j,coef_len2,acc_length;
  long acc;
  const long *in_ptr, *data_ptr, *coef_start, *coef_ptr, *in_end;

  /* set up for coefficients */
  coef_start = coef;
  coef_len2 = (coef_len + 1) >> 1;

  /* set up input data pointers */
  in_end = in + in_len - 1;
  in_ptr = in + coef_len2 - 1;

  /* initial value of accumulation length for startup */
  acc_length = coef_len2;

  for(i = 0 ; i < in_len ; i++) {

    /* set up pointer for accumulation */
    data_ptr = in_ptr;
    coef_ptr = coef_start;

    /* do accumulation and write result with scale factor */

    acc = (long)(*coef_ptr++) * (*data_ptr--);
    for(j = 1 ; j < acc_length ; j++)
      acc += (long)(*coef_ptr++) * (*data_ptr--);
    *out++ = (int)(acc/scale);

    /* check for end case */

    if(in_ptr == in_end) {
      acc_length--;       /* one shorter each time */
      coef_start++;       /* next coefficient each time */
    }

    /* if not at end, then check for startup, add to input pointer */

    else {
      if(acc_length < coef_len) acc_length++;
      in_ptr++;
    }
  }
}

void check ()
{

  for (int i=0; i<128; i++) {
    //printf("%ld", output[i]);
  };

}


void init(void) {
	total_errors = 0;
	for (int i=0; i<128; i++){
		data[i] = in_data[i];
	}
}


void test (void) {
  fir_filter_int(data,output,128,fir_int,35,285);
}



void runMain(){
	init();
	test();
	//return (int) &output;
}	

int main(){
  runMain();
  return 0;
}