//
//  main.c
//  BenchMark_Functions
//
//  Created by Bill Forsyth on 3/10/17.
//  Copyright © 2017 Bill Forsyth. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <inttypes.h>

#define matrix_size 500
#define string_size 256

void integer_math_benchmark();
void add_matrix(int [matrix_size][matrix_size], int [matrix_size][matrix_size], int [matrix_size][matrix_size]);
void subtract_matrix(int [matrix_size][matrix_size], int [matrix_size][matrix_size], int [matrix_size][matrix_size]);
void multiply_matrix(int [matrix_size][matrix_size], int [matrix_size][matrix_size], int [matrix_size][matrix_size]);
void divide_matrix(int [matrix_size][matrix_size], int [matrix_size][matrix_size], int [matrix_size][matrix_size]);
void fill_matrix(int [matrix_size][matrix_size], int);
void print_matrix(int [matrix_size][matrix_size]);
void run_length_encoding_benchmark();
void run_length_encode(char [string_size]);
void prime_number_benchmark(int);
int is_prime(int);


int main(int argc, const char * argv[]) {
    
    integer_math_benchmark();
    run_length_encoding_benchmark();
    prime_number_benchmark(1000);
    return 0;
}

void integer_math_benchmark(){
    
    int a[matrix_size][matrix_size];
    int b[matrix_size][matrix_size];
    int c[matrix_size][matrix_size];
    struct timeval t1, t2;
    double elapsedTime;

    /*
    int a[2][2] = {{1, 2},
                   {3, 4}};
    int b[2][2] = {{1, 2},
                   {3, 4}};
    int c[2][2];
    */

    fill_matrix(a, 1);
    fill_matrix(b, 2);
//    print_matrix(a);
//    print_matrix(b);

    printf("Add_Matrix: ");
    // start timer
    gettimeofday(&t1, NULL);
    add_matrix(a, b, c);
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("elapsed %fus\n", elapsedTime);
    
    printf("Subtract_Matrix: ");
    // start timer
    gettimeofday(&t1, NULL);
    subtract_matrix(a, b, c);
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("elapsed %fus\n", elapsedTime);
    
    printf("Multiply_Matrix: ");
    // start timer
    gettimeofday(&t1, NULL);
    multiply_matrix(a, b, c);
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("elapsed %fus\n", elapsedTime);
    
    printf("Divide_Matrix: ");
    // start timer
    gettimeofday(&t1, NULL);
    divide_matrix(a, b, c);
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("elapsed %fus\n", elapsedTime);
}

void add_matrix(int a[matrix_size][matrix_size], int b[matrix_size][matrix_size], int c[matrix_size][matrix_size]){
    int i = 0, j = 0;
    for(i = 0; i<matrix_size; i++){
        for(j = 0; j < matrix_size; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtract_matrix(int a[matrix_size][matrix_size], int b[matrix_size][matrix_size], int c[matrix_size][matrix_size]){
    int i = 0, j = 0;
    for(i = 0; i<matrix_size; i++){
        for(j = 0; j < matrix_size; j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiply_matrix(int a[matrix_size][matrix_size], int b[matrix_size][matrix_size], int c[matrix_size][matrix_size]){
    int i = 0, j = 0;
    for(i = 0; i<matrix_size; i++){
        for(j = 0; j < matrix_size; j++){
            c[i][j] = a[i][j] * b[i][j];
        }
    }
}

void divide_matrix(int a[matrix_size][matrix_size], int b[matrix_size][matrix_size], int c[matrix_size][matrix_size]){
    int i = 0, j = 0;
    for(i = 0; i<matrix_size; i++){
        for(j = 0; j < matrix_size; j++){
            c[i][j] = a[i][j] / b[i][j];
        }
    }
}

void fill_matrix(int x[matrix_size][matrix_size], int matrix){
    FILE* file;
    int i = 0, j = 0;

    if(matrix == 1){
        //open DataA.txt
        file = fopen ("MatrixA.txt", "r");
    }else{
        //open DataB.txt
        file = fopen ("MatrixB.txt", "r");
    }
    for(i = 0; i<matrix_size; i++){
        for(j = 0; j < matrix_size; j++){
            fscanf (file, "%d", &x[i][j]);
        }
    }
    fclose (file);
}

void print_matrix(int x[matrix_size][matrix_size]){
    int i = 0, j= 0;
    for(i = 0; i<matrix_size; i++){
        for(j = 0; j < matrix_size; j++){
            printf("[%i][%i] = %i\n", i, j, x[i][j]);
        }
    }
}

void run_length_encoding_benchmark(){
    FILE* file;
    char line[string_size];
//    char line[20] = {'1','1','1','2','2','2','2','0','0','0','1','1','1','2','2','2','2','0','0','0'};

    file = fopen ("Strings.txt", "r");
    
    struct timeval t1, t2;
    double elapsedTime;

    printf("Run_Time_Encode: ");
    // start timer
    gettimeofday(&t1, NULL);
    while(fscanf(file, "%s", line) != EOF){
        run_length_encode(line);
    }
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("elapsed %fus\n", elapsedTime);
 }

void run_length_encode(char x[string_size]){
    char result[string_size*2];
    int i = 0, j= 0, char_count = 0, result_position = 0;
    char temp, count_string[3];
    
    temp = x[0];
    result[0] = temp;
    char_count++;
    result_position++;
    
    for(i = 1; i<string_size; i++){
        if(x[i] == temp){
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

void prime_number_benchmark(int limit){
    struct timeval t1, t2;
    int prime_count = 0;
    double elapsedTime;
    
    printf("Prime numbers to %d: ", limit);
    // start timer
    gettimeofday(&t1, NULL);
    int i = 0;
    for(i = 0; i<limit; i++){
        if(is_prime(i)){
            prime_count++;
        }else{
            //do nothing
        }
    }
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("found %d in %fus\n",prime_count, elapsedTime);
}

int is_prime(int n){
    int p;
    for(p = 2; p < n; p++){
        if(n % p ==0 && p != n)
            return 0;
    }
    return 1;
}
















