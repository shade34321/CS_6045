#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <inttypes.h>

#define matrix_size 5 //the length AND width of the integer maxtrixes for integer_math_benchmark()
#define max_iterations 10000


void add_matrix(double a[matrix_size][matrix_size], double b[matrix_size][matrix_size], double c[matrix_size][matrix_size], int iterations){
    int i = 0, j = 0, k = 0;
    for(k = 0; k<iterations; k++){
      for(i = 0; i<matrix_size; i++){
        for(j = 0; j < matrix_size; j++){
          c[i][j] = a[i][j] + b[i][j];
        }
      }
   }
}

void subtract_matrix(double a[matrix_size][matrix_size], double b[matrix_size][matrix_size], double c[matrix_size][matrix_size], int iterations){
    int i = 0, j = 0, k = 0;
    for(k = 0; k<iterations; k++){
      for(i = 0; i<matrix_size; i++){
        for(j = 0; j < matrix_size; j++){
          c[i][j] = a[i][j] - b[i][j];
        }
      }
   }
}

void multiply_matrix(double a[matrix_size][matrix_size], double b[matrix_size][matrix_size], double c[matrix_size][matrix_size], int iterations){
    int i = 0, j = 0, k = 0;
    for(k = 0; k<iterations; k++){
      for(i = 0; i<matrix_size; i++){
        for(j = 0; j < matrix_size; j++){
          c[i][j] = a[i][j] * b[i][j];
        }
      }
   }
}

void divide_matrix(double a[matrix_size][matrix_size], double b[matrix_size][matrix_size], double c[matrix_size][matrix_size], int iterations){
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
    
double a[5][5] = {
{14489, 9304.5, 13067, 12057, 8584.5},
{11844, 12292, 15594.5, 8841, 4527.5},
{6758.5, 6597.5, 14787.5, 15203, 4511},
{4581.5, 5664, 6906.5, 16051.5, 13703.5},
{3850.5, 7153, 6055.5, 5981, 12211.5},
};

double b[5][5] = {
{3012, 771.5, 1110, 1458.5, 5046},
{5957, 15498.5, 3795, 7775.5, 73},
{1955, 7653.5, 8205.5, 7265, 8864.5},
{10447, 5569, 914, 12885, 8524.5},
{1962.5, 4446, 9290.5, 3618, 14789},
};

double c[5][5];

    struct timeval t1, t2;
    double elapsedTime;
    
    printf("Benchmark,Decimal_Addition,Processor,Raspberry_Pi_B+\n");
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
    
    printf("Benchmark,Decimal_Subtraction,Processor,Raspberry_Pi_B+\n");
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
    
    printf("Benchmark,Decimal_Multiplication,Processor,Raspberry_Pi_B+\n");
     // start timer
    gettimeofday(&t1, NULL);
    multiply_matrix(a, b, c, iterations);
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("# of multiplications,time(miliseconds)\n");
    printf("%d,%f\n",(matrix_size*matrix_size)+iterations,elapsedTime);
    printf("END\n");
    
    printf("Benchmark,Decimal_Division,Processor,Raspberry_Pi_B+\n");
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
  for(i = 975; i<=max_iterations; i+=100)
  {
      integer_math_benchmark(i);
  }
  return 0;
}
