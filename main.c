#include <stdio.h>                                                                                  
#include <unistd.h>

#define THREAD_INTERVAL 500

static int condition = 1;

static void user_thread_1()
{
	static int __s = 0;
	switch (__s) {
	case 0:
		for ( ; ; ) {
			/* do something */
			printf("Run %s\n", __FUNCTION__);
		
			__s = __LINE__; usleep(THREAD_INTERVAL); return; case __LINE__:;
		}
	}
	__s = 0;
}

static void user_thread_2() 
{
	static int __s = 0;
	switch (__s) {
	case 0:
		for ( ; ; ) {
			if (condition) {
				/* do something conditional */
				printf("Run %s - (1)\n", __FUNCTION__);
				__s = __LINE__; usleep(THREAD_INTERVAL); return; case __LINE__: ;
			}
		/* do something */
		printf("Run %s - (2)\n", __FUNCTION__);
		condition = !condition;
		__s = __LINE__; usleep(THREAD_INTERVAL); return; case __LINE__: ;
		}
	}
	__s = 0;
}

int main() 
{
        for ( ; ; ) {
                user_thread_1();
                user_thread_2();
        }
        return 0;
}
