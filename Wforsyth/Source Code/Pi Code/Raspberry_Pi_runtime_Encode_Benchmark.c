#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <inttypes.h>

#define line_size 512  //the length of the line for run_length_encode()
#define max_encodes 500

void run_length_encode(char x[line_size]){
    char result[line_size*2];
    int i = 0, j= 0, char_count = 0, result_position = 0;
    char temp, count_string[3];
    
    temp = x[0];
    result[0] = temp;
    char_count++;
    result_position++;
    
    for(i = 1; i<line_size; i++){
        if(x[i] == temp && char_count < 9){
            char_count++;
        }else{
            sprintf(count_string, "%d", char_count);
            
            for(j = 0; *(count_string+j); j++){
                result[result_position] = count_string[j];
                result_position++;
            }

            char_count = 0;
            temp  = x[i];
            result[result_position] = temp;
            result_position++;
            char_count++;

        }
    }
    sprintf(count_string, "%d", char_count);
    
    for(j = 0; *(count_string+j); j++){
        result[result_position] = count_string[j];
        result_position++;
    }
    result[result_position] = '\0';
//    printf("%s\n", result);
}

void run_length_encoding_benchmark(int number_of_lines){
    int i;
    char line[1][513] = {
		"10001010100101010001101100111001010011011000110000111110010010001011100100101110010000111010011111110110110011101100110101101100011001000010110000000101101010101100110110101110100100101010011000000100100101101101111101001010000010110100001011111000001101101000010111000111000100111110010101101111001011001011000000010000000100000110100110001100000001111111101101000110011001011100111001110111000000101110110010110100011110011110001110000000001100010101010111110000011001110000111110110011100100100001001001101011"};
    for(i = 0; i<number_of_lines; i++){
        run_length_encode(line[i % sizeof(line)/sizeof(line[0])]);
    }
 }
 
 int main() {
  printf("Benchmark,Run_Time_Encode,Processor,Raspberry_Pi_B+\n");
  printf("String length(bytes),# of lines,time(miliseconds)\n");
  struct timeval t1, t2;
  double elapsedTime;
  int i = 1;
  for(i = 1; i<=max_encodes; i++){
    // start timer
    gettimeofday(&t1, NULL);
    run_length_encoding_benchmark(i);
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("%d,%d,%f\n",line_size, i, elapsedTime);
  }
  printf("END\n");
  return 0;
}
