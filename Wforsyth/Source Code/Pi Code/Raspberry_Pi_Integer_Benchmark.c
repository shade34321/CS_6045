#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <inttypes.h>

#define matrix_size 10 //the length AND width of the integer maxtrixes for integer_math_benchmark()
#define max_iterations 10000

void add_matrix(int a[matrix_size][matrix_size], int b[matrix_size][matrix_size], int c[matrix_size][matrix_size], int iterations){
    int i = 0, j = 0, k = 0;
    for(k = 0; k<iterations; k++){
      for(i = 0; i<matrix_size; i++){
        for(j = 0; j < matrix_size; j++){
          c[i][j] = a[i][j] + b[i][j];
        }
      }
   }
}

void subtract_matrix(int a[matrix_size][matrix_size], int b[matrix_size][matrix_size], int c[matrix_size][matrix_size], int iterations){
    int i = 0, j = 0, k = 0;
    for(k = 0; k<iterations; k++){
      for(i = 0; i<matrix_size; i++){
        for(j = 0; j < matrix_size; j++){
          c[i][j] = a[i][j] - b[i][j];
        }
      }
   }
}

void multiply_matrix(int a[matrix_size][matrix_size], int b[matrix_size][matrix_size], int c[matrix_size][matrix_size], int iterations){
    int i = 0, j = 0, k = 0;
    for(k = 0; k<iterations; k++){
      for(i = 0; i<matrix_size; i++){
        for(j = 0; j < matrix_size; j++){
          c[i][j] = a[i][j] * b[i][j];
        }
      }
   }
}

void divide_matrix(int a[matrix_size][matrix_size], int b[matrix_size][matrix_size], int c[matrix_size][matrix_size], int iterations){
    int i = 0, j = 0, k = 0;
    for(k = 0; k<iterations; k++){
      for(i = 0; i<matrix_size; i++){
        for(j = 0; j < matrix_size; j++){
          c[i][j] = a[i][j] / b[i][j];
        }
      }
   }
}

void integer_math_benchmark(int iterations){
    
int a[10][10] = {
{49611, 48882, 55017, 63991, 50383, 8180, 50063, 6248, 49916, 21836},
{5231, 9213, 48348, 26683, 41339, 27836, 54972, 8712, 44745, 5173},
{54509, 13580, 29402, 32800, 58863, 27373, 32022, 30562, 53276, 4002},
{61602, 3129, 52701, 13901, 55087, 61915, 22612, 34146, 20376, 42039},
{58628, 10802, 20212, 61645, 48177, 64983, 35529, 60041, 12661, 10781},
{23728, 27033, 24362, 38012, 42940, 52813, 21696, 60109, 470, 15596},
{2855, 30449, 54342, 24048, 55333, 16620, 24004, 7052, 4642, 21869},
{30456, 9261, 36250, 52278, 27568, 26006, 39231, 26931, 13997, 12748},
{15525, 39023, 61434, 13714, 34270, 52752, 54042, 62677, 2969, 20301},
{29294, 42465, 6446, 51305, 45510, 10638, 22682, 62680, 23151, 8485},
};

int b[10][10] = {
{4443, 18647, 28107, 6905, 13367, 23839, 24739, 31576, 30917, 2189},
{31551, 10558, 6054, 21858, 29067, 9087, 20716, 26935, 3144, 11592},
{9115, 14406, 27480, 6679, 17096, 20133, 24508, 1602, 5729, 14972},
{11566, 7125, 6938, 9310, 24704, 26026, 30939, 27940, 23774, 7836},
{13757, 2445, 7025, 32078, 16049, 25445, 27315, 2673, 29817, 850},
{28809, 23697, 21144, 1333, 7237, 13835, 6599, 3474, 22255, 12028},
{27968, 1284, 20724, 15193, 8457, 16216, 17157, 30987, 23654, 24842},
{7638, 24433, 16536, 13390, 25048, 20775, 29083, 10092, 32118, 24543},
{150, 31066, 26656, 98, 24793, 29823, 3498, 10431, 19200, 9065},
{2016, 13689, 2398, 15112, 23515, 13333, 12502, 4763, 1609, 24883},
};

int c[10][10];
    
    struct timeval t1, t2;
    double elapsedTime;
        
    printf("Benchmark,Integer_Addition,Processor,Raspberry_Pi_B+\n");
    // start timer
    gettimeofday(&t1, NULL);
    add_matrix(a, b, c, iterations);
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("# of additions,time(miliseconds)\n");
    printf("%d,%f\n",(matrix_size*matrix_size)+iterations, elapsedTime);
    printf("END\n");
    
    printf("Benchmark,Integer_Subtraction,Processor,Raspberry_Pi_B+\n");
     // start timer
    gettimeofday(&t1, NULL);
    subtract_matrix(a, b, c, iterations);
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("# of subtractions,time(miliseconds)\n");
    printf("%d,%f\n",(matrix_size*matrix_size)+iterations, elapsedTime);
    printf("END\n");
    
    printf("Benchmark,Integer_Multiplication,Processor,Raspberry_Pi_B+\n");
     // start timer
    gettimeofday(&t1, NULL);
    multiply_matrix(a, b, c, iterations);
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("# of multiplications,time(miliseconds)\n");
    printf("%d,%f\n",(matrix_size*matrix_size)+iterations, elapsedTime);
    printf("END\n");
    
    printf("Benchmark,Integer_Division,Processor,Raspberry_Pi_B+\n");
     // start timer
    gettimeofday(&t1, NULL);
    divide_matrix(a, b, c, iterations);
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("# of divisions,time(miliseconds)\n");
    printf("%d,%f\n",(matrix_size*matrix_size)+iterations, elapsedTime);
    printf("END\n");
}

int main() {
  int i = 0;
  for(i = 900; i<=max_iterations; i+=100)
  {
      integer_math_benchmark(i);
  }
  return 0;
}
