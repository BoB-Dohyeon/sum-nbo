#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include <netinet/in.h>

void file_handle(FILE* fp, uint32_t *buf, uint32_t &sum, int argc, char* argv[]){
	for(uint8_t i = 1; i < argc; i++){
		fp = fopen(argv[i], "ro");
		if(fp == NULL){
			printf("open error\n");
			exit(0);
		}

		uint32_t read = fread(&buf[i - 1], 4, 4, fp);
		if(read <= 0){
			printf("read error\n");
			exit(0);
		}
		fclose(fp);
		buf[i-1] = htonl(buf[i-1]);
		sum += buf[i-1];
	}
}

void print_result(uint32_t* buf, uint32_t sum){
	printf("%d(0x%08x) + %d(0x%08x) + %d(0x%08x) = %d(0x%08x)", buf[0], buf[0], buf[1], buf[1], buf[2], buf[2], sum, sum);
}

int main(int argc, char* argv[]){
	if(argc < 3){
		printf("parameter is not 3 file\n");
		return 0;
	}
	FILE* fp;
	uint32_t buf[3];
	uint32_t sum = 0;
	file_handle(fp, buf, sum, argc, argv);
	print_result(buf, sum);
}
