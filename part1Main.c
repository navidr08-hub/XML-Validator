#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);

int main(int argc, char * argv[])
{
	int ch; int identity[10];
	int valid = 1, check = 0;
  	while ((ch = getchar()) != EOF) {
    		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      			continue;
    		if(ch == '<'){
			int next = getchar(); int count = 0;
			if (isalpha(next)){
					check++;
					push(next);
			}
			else{
				while((next != '>') && (next != EOF)){// reading identity
					if (next != '/'){
						identity[count++] = next;
					}
					next = getchar();
				}
				int previous = pop();
				if (previous != -1){
					if(previous != identity[--count]){
						valid = 0;
					} else {check--;}
				}
				else {valid = 0;}
			}
		}

		if(valid == 0){break;}
    	}
	if((valid == 1) && (check == 0)){fprintf(stdout, "Valid\n");}
	else{fprintf(stdout, "Not valid\n");}

  	exit(0);
}
