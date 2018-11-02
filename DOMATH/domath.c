// your code here
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include<sys/wait.h> 
#include <stdlib.h>
int main(int argc, char *argv[]) 
{ 
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    // make two process which run same 
    // program after this instruction 

    int x = fork(); 
    if(x == 0){
	printf("child1: %d+%d = %d\n",a, b, a+b);
	_exit(-1);
    }
    else{
	wait(0);
	//printf("done\n");
    }
    
    int x1 = fork(); 
    if(x1 == 0){
	printf("child2: %d-%d = %d\n",a, b, a-b);
	_exit(-1);
    }
    else{
	wait(0);
	//printf("done\n");
    }
    int x2 = fork(); 
    if(x2 == 0){
	printf("child3: %d*%d = %d\n",a, b, a*b);
	_exit(-1);
    }
    else{
	wait(0);
	//printf("done\n");
    }
    int x3 = fork(); 
    if(x3 == 0){
	printf("child4: %d/%d = %d\n",a, b, a/b);
	_exit(-1);
    }
    else{
	wait(0);
	printf("parent: done\n");
    }
    
    return 0; 
}
