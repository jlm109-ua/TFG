#include <stdlib.h>
#include <stdio.h>

#define SCALE_FACTOR (REPEAT_FACTOR >> 0)
#define N 100
#define SGLIB_SAFE_NUMERIC_COMPARATOR(x, y) (((x) > (y) ? 1 : ((x) < (y) ? -1 : 0)))
#define SGLIB_NUMERIC_COMPARATOR(x, y) SGLIB_SAFE_NUMERIC_COMPARATOR(x, y)
#define SGLIB_ARRAY_ELEMENTS_EXCHANGER(type, a, i, j) \
	{                                                 \
		type _sgl_aee_tmp_;                           \
		_sgl_aee_tmp_ = (a)[(i)];                     \
		(a)[(i)] = (a)[(j)];                          \
		(a)[(j)] = _sgl_aee_tmp_;                     \
	}

int initVals[N] = {14, 66, 12, 41, 86, 69, 19, 77, 68, 38, 26, 42, 37, 23, 17, 29, 55, 13,
				   90, 92, 76, 99, 10, 54, 57, 83, 40, 44, 75, 33, 24, 28, 80, 18, 78, 32, 93, 89, 52, 11,
				   21, 96, 50, 15, 48, 63, 87, 20, 8, 85, 43, 16, 94, 88, 53, 84, 74, 91, 67, 36, 95, 61,
				   64, 5, 30, 82, 72, 46, 59, 9, 7, 3, 39, 31, 4, 73, 70, 60, 58, 81, 56, 51, 45, 1, 6, 49,
				   27, 47, 34, 35, 62, 97, 2, 79, 98, 25, 22, 65, 71, 0};

int expected[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
				   10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
				   20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
				   30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
				   40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
				   50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
				   60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
				   70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
				   80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
				   90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
int a[N];
int total_errors;

void init()
{
	total_errors = 0;
	for (int Index = 0; Index < N; Index++)
		a[Index] = initVals[Index];
}
void test() {
	int max=N;
  int   _i_, _j_, _p_, _stacki_, _start_, _end_;\
  /* can sort up to 2^64 elements */\
  int   _startStack_[64]; \
  int   _endStack_[64];\
  _startStack_[0] = 0;\
  _endStack_[0] = (max);\
  _stacki_ = 1;\
  while (_stacki_ > 0) {\
    _stacki_ --;\
    _start_ = _startStack_[_stacki_];\
    _end_ = _endStack_[_stacki_];\
    while (_end_ - _start_ > 2) {\
      _p_ = _start_;\
      _i_ = _start_ + 1;\
      _j_ = _end_ - 1;\
      while (_i_<_j_) {\
        for(; _i_<=_j_ && SGLIB_NUMERIC_COMPARATOR(((a)[_i_]),((a)[_p_]))<=0; _i_++) ;\
        if (_i_ > _j_) {\
          /* all remaining elements lesseq than pivot */\
          SGLIB_ARRAY_ELEMENTS_EXCHANGER(int, a, _j_, _p_);\
          _i_ = _j_;\
        } else {\
          for(; _i_<=_j_ && SGLIB_NUMERIC_COMPARATOR(((a)[_j_]),((a)[_p_]))>=0; _j_--) ;\
          if (_i_ > _j_) {\
            /* all remaining elements greater than pivot */\
            SGLIB_ARRAY_ELEMENTS_EXCHANGER(int, a, _j_, _p_);\
            _i_ = _j_;\
          } else if (_i_ < _j_) {\
            SGLIB_ARRAY_ELEMENTS_EXCHANGER(int, a, _i_, _j_);\
            if (_i_+2 < _j_) {_i_++; _j_--;}\
            else if (_i_+1 < _j_) _i_++;\
          }\
        }\
      }\
      /* O.K. i==j and pivot is on a[i] == a[j] */\
      /* handle recursive calls without recursion */\
      if (_i_-_start_ > 1 && _end_-_j_ > 1) {\
        /* two recursive calls, use array-stack */\
        if (_i_-_start_ < _end_-_j_-1) {\
          _startStack_[_stacki_] = _j_+1;\
          _endStack_[_stacki_] = _end_;\
          _stacki_ ++;\
          _end_ = _i_;\
        } else {\
          _startStack_[_stacki_] = _start_;\
          _endStack_[_stacki_] = _i_;\
          _stacki_ ++;\
          _start_ = _j_+1;\
        }\
      } else {\
        if (_i_-_start_ > 1) {\
          _end_ = _i_;\
        } else {\
          _start_ = _j_+1;\
        }\
      }\
    }\
    if (_end_ - _start_ == 2) {\
      if (SGLIB_NUMERIC_COMPARATOR(((a)[_start_]),((a)[_end_-1])) > 0) {\
        SGLIB_ARRAY_ELEMENTS_EXCHANGER(int, a, _start_, _end_-1);\
      }\
    }\
  }\
}

void golden(){
	for (int i=0; i<N; i++) {
		//printf("%i",a[i]);
	//printf ("data[%d]: %d \n", i, result_data[i]);
      if (a[i] != expected[i])
         total_errors+=1;
  }
}

void runMain()
{
  init();
  test();
  golden();
}

int main()
{
  runMain();
  return 0;
}