#include <AESLib.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <inttypes.h>

#define max_lines 500

void configCrypt()
{

}
int main() {
	randomSeed(analogRead(0));
	uint8_t key[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	uint8_t iv[] = { (uint8_t)random(255), (uint8_t)random(255), (uint8_t)random(255), (uint8_t)random(255), (uint8_t)random(255), (uint8_t)random(255), (uint8_t)random(255), (uint8_t)random(255), (uint8_t)random(255), (uint8_t)random(255), (uint8_t)random(255), (uint8_t)random(255), (uint8_t)random(255), (uint8_t)random(255), (uint8_t)random(255), (uint8_t)random(255) };
	char data[] = "0123456789012345384729834723895798327598798759837423987589759759723957329857290472907109375923753094730948093490750947230970925723907530975slkflkfenl;kgngjkrhfkrhfjkshfkehfekfhekjfhhrslkedkfhkgeklejilfjlrifjelfewkfhehekgjkghukghuhfughreughrkhrkheukgrhkuuhgkehrhgihfihfoihfoihgeoifhiohewoighweioewrhewioheoi09237329075"; //16 chars == 16 bytes
	int len = (sizeof(data) / sizeof(char));
	int origlen = len;
	int padding = 16 - (len % 16);
	char paddedData[len];
	struct timeval t1, t2;
	double elapsedTime;	
	int i = 0, j = 0;
	printf("Benchmark,AES_Encode_Decode,Processor,Ardunio_Uno\n");
	printf("Line Size(bytes),Encode Time(miliseconds),Decode Time(miliseconds)\n");

	for (j = 1; j <= max_lines; j++){
		printf("%d,",len*j);
		if (padding>0)
		{
			len += padding;
		}
		for (int i = 0; i<len; i++)
		{
			if (i<origlen)
			{
				paddedData[i] = data[i];
			}
			else
			{
				paddedData[i] = 'F';
			}
		}

		// start timer
		gettimeofday(&t1, NULL);

		for (i = 1; i <= j; i++)
		{
			aes128_cbc_enc(key, iv, paddedData, len);
		}
		
		// stop timer
		gettimeofday(&t2, NULL);
		// compute and print the elapsed time in millisec
		elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
		elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms

		printf("%d,",elapsed);

		starttime = millis();
		for (i = 1; i <= j; i++)
		{
			aes128_cbc_dec(key, iv, paddedData, len);
		}
		elapsed = millis() - starttime;
		printf("%d\n",elapsed);
		len = (sizeof(data) / sizeof(char));
		origlen = len;
		padding = 16 - (len % 16);
	}
	printf("END\n");
	return 0;
}