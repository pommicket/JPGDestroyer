#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOO_SMALL_ERROR 1

int main()
{
	char* filename;
	int file_name_size;
	
	FILE* fp;
	int file_size;
	int i;

	int pos;
	int amount;
	
	char* fileContents;

	srand(time(NULL));
	
	filename = malloc(1024);
	printf("File to destroy (it will be overwritten): ");
	
	fgets(filename, 1024, stdin);
	filename = strtok(filename, "\n");
	
	file_name_size = strlen(filename);
	
	fp = fopen(filename, "rb");

	fseek(fp, 0L, SEEK_END);
	file_size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	
	if (file_size < 2100)
	{
		fprintf(stderr, "Error: File too small: %s.", filename);
		return TOO_SMALL_ERROR;
	}

	fileContents = malloc(file_size);
	fread(fileContents, 1, file_size, fp);
	fclose(fp);

	pos = file_size/4 + (int)(file_size/4 * ((double)rand()/RAND_MAX));

	printf("Destruction amount (~50 is recommended): ");
	scanf("%d", &amount);
	
	for (i = pos; i < pos+amount; i++)
	{
		fileContents[i] = '0';
	}

	fp = fopen(filename, "wb");
	fwrite(fileContents, 1, file_size, fp);

	fclose(fp);
	printf("Done! Your image might be corrupt.\n");

	
	return 0;
	
}
