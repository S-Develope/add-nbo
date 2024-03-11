#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

uint32_t my_ntohs(uint32_t n){
	return ((n&0xFF000000)>>24|(n&0x00FF0000)>>8);
}

int main(int argc, char* argv[]){
	FILE* fp1 = fopen(argv[1],"rb");
	FILE* fp2 = fopen(argv[2],"rb");
	uint8_t buffer_1000[4] = {0x00,0x00,0x00,0x00};
	uint8_t buffer_500[4] = {0x00, 0x00, 0x00, 0x00};
	int ch1,ch2,count=0;
	for(int i=0;i<4;i++){
		ch1=fgetc(fp1);
		ch2=fgetc(fp2);
		if(ch1!=0)buffer_1000[count]=ch1;
		if(ch2!=0)buffer_500[count]=ch2;
		count++;
	}
	uint32_t* p1 = reinterpret_cast<uint32_t*>(buffer_1000);
	uint32_t* p2 = reinterpret_cast<uint32_t*>(buffer_500);
	uint32_t n1 = my_ntohs(*p1);
	uint32_t n2 = my_ntohs(*p2);
	printf("1000(0x%x) + 500(0x%x) = 1500(0x%x)\n",n1,n2,n1+n2);
	return 0;
}
