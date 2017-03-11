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

void integer_math_benchmark();
void add_matrix(int [matrix_size][matrix_size], int [matrix_size][matrix_size], int [matrix_size][matrix_size]);
void subtract_matrix(int [matrix_size][matrix_size], int [matrix_size][matrix_size], int [matrix_size][matrix_size]);
void multiply_matrix(int [matrix_size][matrix_size], int [matrix_size][matrix_size], int [matrix_size][matrix_size]);
void divide_matrix(int [matrix_size][matrix_size], int [matrix_size][matrix_size], int [matrix_size][matrix_size]);
void fill_matrix(int [matrix_size][matrix_size], int);
void print_matrix(int [matrix_size][matrix_size]);

int main(int argc, const char * argv[]) {
    
    //integer_math_benchmark();
    
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
        file = fopen ("DataA.txt", "r");
    }else{
        //open DataB.txt
        file = fopen ("DataB.txt", "r");
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
    }}
