#ifndef CONFIG__H__
#define CONFIG__H__

#define N 9 
#define N_MAX N - 1

#define QUEEN_CHAR 'Q'
#define EMPTY_CHAR '.'

#if N > 15
	#define OPT_MV N/2 - 1 
#else
	#define OPT_MV 1
#endif

#endif
