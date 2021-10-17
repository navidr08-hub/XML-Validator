#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);

int main(int argc, char * argv[])
{
	int ch; int identity1[26]; int identity2[26]; int i; int size = 0; int multi[26];
	int valid = 1, done, check = 0;
  	while ((ch = getchar()) != EOF) {
    		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      			continue;
    		if(ch == '<'){
			int next = getchar(); 
			int count = 0, done = 0;
			if (isalpha(next)){
				check++;
				for (i = 0; i < size; i++){
					if (next == identity2[i]){
						multi[i]++;
						done = 1;
					}
				}
				if (done == 0){
					identity2[size++] = next;
				}
				push(next);
				next = getchar();
			}
			else{
				while((next != '>') && (next != EOF)){// reading identity1
					if (next != '/'){
						identity1[count++] = next;
					}
					next = getchar();
				}
				int previous = pop();
				if (previous != -1){
					if(previous != identity1[--count]){
						valid = 0;
					} else {check--;}
				}
				else {valid = 0;}
			}
		}

		if(valid == 0){break;}
    	}
	if((valid == 1) && (check == 0)){
		fprintf(stdout, "Valid\n");
		for(i = 0; i < size; i++){
			fprintf(stdout, "%c %d\n", identity2[i], multi[i]+1);
		}
	}
	else{fprintf(stdout, "Not valid\n");}

  	exit(0);
}
