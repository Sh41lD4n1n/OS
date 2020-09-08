#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int    n=0;
    if (argc>0){n=atoi(argv[1]);}
	
    pid_t p;
    p=fork();
        if (p>0){
            printf("Hello from parent [%d - %d] \n",getpid(),n);
	}
        else{
            if (p==0)
                printf("Hello from child [%d - %d] \n",getpid(),n);
            else
                printf("ID of perent process is less then 0 \n");
	}
	return EXIT_SUCCESS;
    return 0;
}
/*result
 The processes aren't sorted by number of iteration as the executed simultaniusly with interuptions
Hello from parent [2699 - 0] 
Hello from child [2700 - 0] 
Hello from parent [2701 - 1] 
Hello from child [2702 - 1] 
Hello from parent [2703 - 2] 
Hello from child [2704 - 2] 
Hello from parent [2705 - 3] 
Hello from child [2706 - 3] 
Hello from parent [2707 - 4] 
Hello from parent [2709 - 5] 
Hello from child [2708 - 4] 
Hello from parent [2711 - 6] 
Hello from child [2710 - 5] 
Hello from parent [2713 - 7] 
Hello from child [2712 - 6] 
Hello from parent [2715 - 8] 
Hello from child [2714 - 7] 
Hello from parent [2717 - 9] 
Hello from child [2716 - 8] 
Hello from parent [2719 - 10] 
Hello from child [2718 - 9] 
Hello from child [2720 - 10] 
*/