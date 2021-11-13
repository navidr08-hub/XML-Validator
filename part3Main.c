#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

extern char * pop();
extern void push(char *);
extern void add(char *tag);
extern void print_table();

void append(char * s, char c){
	int length = strlen(s);
	s[length] = c;
	s[length + 1] = '\0';
}

int main(int argc, char * argv[])
{
	int ch, i;
	int valid = 1, check = 0;
	fprintf(stdout, "ok1\n");
  	while ((ch = getchar()) != EOF) {
		fprintf(stdout, "ok2\n");
    		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/')){
			fprintf(stdout, "ok3 %c\n", (char)ch);
      			continue;
		}
    		else if(ch == '<'){
			fprintf(stdout, "ok4\n");
			int next = getchar();
			if (isalpha(next)){
					fprintf(stdout, "ok5\n");
					char open[50] = "";
					fprintf(stdout, "ok6\t%s\n", open);
					check++;
					while((next != EOF) && (isalpha(next))){
						append(open, (char)next);
						next = getchar();
					}
					fprintf(stdout, "%s\n", open);
					push(open);
			}
			else if(next == '/'){
				char close[15] = "";
				next = getchar();
				while ((next != EOF) && (next != '>')){
					append(close, (char)next);
					next = getchar();
				} 
				fprintf(stdout, "%s\n", close);
				char * tmp = pop();
				fprintf(stdout, "%s\n", tmp);
				if (tmp != ((char *)0)){
					bool fine = true; int count = 0;
					fprintf(stdout, "%s\n", tmp);
					for(i = 0; close[i] != '\0'; i++){
						fprintf(stdout, "%d", ++count);
						fprintf(stdout, "%c\t%c\n", tmp[i], close[i]);
						if(close[i] != tmp[i]){
							fine = false;
						}
					}
					if(!fine){
						valid = 0;
					} else {check--;}
				} else {
					valid = 0;
					fprintf(stdout, "empty");
				}
			}
		}
    	}
	if((valid == 1) && (check == 0)){fprintf(stdout, "Valid\n");}
	else{fprintf(stdout, "Not valid\n");}

  	exit(0);
}
