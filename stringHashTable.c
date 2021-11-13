#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TAG 20
#define HASH_TABLE_SIZE 1057
//typedef struct Entry Entry, *EntryPtr;
typedef struct Entry {
  char * string;
  int count;
}Entry;
Entry * hash_table[HASH_TABLE_SIZE];

int i;

unsigned int hash(char * tag){ //Hash Function
	int length = strnlen(tag, MAX_TAG);
	unsigned int hash_value = 0;
	for (i = 0; i < length; i++){
		hash_value += tag[i];
		hash_value = (hash_value * tag[i]) % HASH_TABLE_SIZE;	
	}
	return hash_value;	
}

void intialize_table(){ //Setting all table entries to NULL
	for(i = 0; i < HASH_TABLE_SIZE; i++){
		hash_table[i] = NULL;
	}
}

void print_table(){
	fprintf(stdout, "Start\n");
	for(i = 0; i < HASH_TABLE_SIZE; i++){
		if (hash_table[i] != NULL){
			fprintf(stdout, "\t%i\t%s\n", i, hash_table[i]->string);		}
	}
	fprintf(stdout, "End\n");
}
void add(char * tag){
	Entry element= {.string = tag, .count = 0};
	while(true){
		if (tag != NULL){
			int index = hash(tag);
			if (hash_table[index] == NULL){
				*hash_table[index] = element;
				fprintf(stdout, "Fresh\n");
				break;
			} else {
				if(hash_table[index]->string == tag){
					hash_table[index]->count++;
					fprintf(stdout, "Multiple\n");
					break;
				} else {
					index++;
					index %= HASH_TABLE_SIZE;
					fprintf(stdout, "Occupied, trying again\n");
				}
			}
		} else {fprintf(stdout, "Tag is null\n"); break;}
	}
}

Entry getEntry(char * tag){
	int index = hash(tag), limit = 0;
	Entry e = {.string = ((char *)0), .count = 0};
	while(true){
		if(hash_table[index]->string == tag){
			fprintf(stdout, "Found!");
			return * hash_table[index];
		} else {
			fprintf(stdout, "Not found, trying again");
			index++;
			index %= HASH_TABLE_SIZE;
			limit++;
		}
		if (limit >= HASH_TABLE_SIZE){break;}
	}
	return e;
}
