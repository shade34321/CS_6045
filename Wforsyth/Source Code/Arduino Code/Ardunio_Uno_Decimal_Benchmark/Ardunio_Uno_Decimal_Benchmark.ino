#include <avr/pgmspace.h>
#define matrix_size 5 //the length AND width of the integer maxtrixes for integer_math_benchmark()
#define max_iterations 5000
//const dataType variableName[] PROGMEM = {};   // use this form


 void setup() {
  int i = 0;
  Serial.begin(9600);
  for(i = 975; i<=max_iterations; i+=100)
  {
      integer_math_benchmark(i);
  }
  
  Serial.flush();
}

void loop() {
  // put your main code here, to run repeatedly:

}

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
    
    unsigned long starttime;
    unsigned long elapsed;
    
    Serial.println("Benchmark,Decimal_Addition,Processor,Ardunio_Uno");
    // start timer
    starttime=millis();
    add_matrix(a, b, c, iterations);
    // stop timer
    elapsed=(millis() - starttime);
    Serial.println("# of additions,time(miliseconds)");
    Serial.print((matrix_size*matrix_size)+iterations);
    Serial.print(",");
    Serial.println(elapsed);
    Serial.println("END");
    
    Serial.println("Benchmark,Integer_Subtraction,Processor,Ardunio_Uno");
     // start timer
    starttime=millis();
    subtract_matrix(a, b, c, iterations);
    // stop timer
    elapsed=(millis() - starttime);
    Serial.println("# of subtractions,time(miliseconds)");
    Serial.print((matrix_size*matrix_size)+iterations);
    Serial.print(",");
    Serial.println(elapsed);
    Serial.println("END");
    
    Serial.println("Benchmark,Integer_Multiplication,Processor,Ardunio_Uno");
     // start timer
    starttime=millis();
    multiply_matrix(a, b, c, iterations);
    // stop timer
    elapsed=(millis() - starttime);
    Serial.println("# of multiplications,time(miliseconds)");
    Serial.print((matrix_size*matrix_size)+iterations);
    Serial.print(",");
    Serial.println(elapsed);
    Serial.println("END");
    
    Serial.println("Benchmark,Integer_Division,Processor,Ardunio_Uno");
     // start timer
    starttime=millis();
    divide_matrix(a, b, c, iterations);
    // stop timer
    elapsed=(millis() - starttime);
    Serial.println("# of divisions,time(miliseconds)");
    Serial.print((matrix_size*matrix_size)+iterations);
    Serial.print(",");
    Serial.println(elapsed);
    Serial.println("END");
}

