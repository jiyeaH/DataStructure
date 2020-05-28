#include <stdio.h>
#include <string.h>
#define BUCKET_SIZE (10)

const char* sample[] = {
	"i","j","k","test","test1","test2","sample1","sample2","data","age","length","width","sum","average","max","min","temp"
};
int hashCode(const char* str);

int main() {
	int hashTable[BUCKET_SIZE];
	for (int i = 0; i < BUCKET_SIZE; i++) hashTable[i] = 0;
	for (int i = 0; i < (sizeof(sample) / sizeof(sample[0])); i++) {
		const char* source = sample[i];
		int hashAddress = hashCode(source);
		hashTable[hashAddress]++;
		printf("%s --> %d\n", source, hashAddress);
	}
	for (int i = 0; i < BUCKET_SIZE; i++) printf("%d ; %d\n", i, hashTable[i]);
	return 0;
}

int hashCode(const char* str) {
	int hash = 0;
	for (int i = 0; i < strlen(str); i++) {
		hash = (hash * 10) + (int)(str[i] - '0');
	}
	return (hash%BUCKET_SIZE);
}