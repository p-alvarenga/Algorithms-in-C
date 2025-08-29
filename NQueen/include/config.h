#ifndef CONFIG__H__
#define CONFIG__H__

#define N 41
#define NMAX N - 1

#define QUEEN_CHAR 'Q'
#define EMPTY_CHAR '.'

#if N > 15
	#if N % 2 != 0
		#define OPT_MV N/2 - 1
	#else 
		#define OPT_MV N/2 - 1
	#endif
#else 
	#define OPT_MV 1
#endif

#endif
