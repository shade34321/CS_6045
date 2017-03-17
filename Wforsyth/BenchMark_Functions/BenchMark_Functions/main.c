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

#define matrix_size 10 //the length AND width of the integer maxtrixes for integer_math_benchmark()
#define line_size 512  //the length of the line for run_length_encode()
#define prime_limit 1000 //The limit for prime_number_benchmark()

void integer_math_benchmark();
void add_matrix(int [matrix_size][matrix_size], int [matrix_size][matrix_size], int [matrix_size][matrix_size]);
void subtract_matrix(int [matrix_size][matrix_size], int [matrix_size][matrix_size], int [matrix_size][matrix_size]);
void multiply_matrix(int [matrix_size][matrix_size], int [matrix_size][matrix_size], int [matrix_size][matrix_size]);
void divide_matrix(int [matrix_size][matrix_size], int [matrix_size][matrix_size], int [matrix_size][matrix_size]);
void fill_matrix(int [matrix_size][matrix_size], int);
void print_matrix(int [matrix_size][matrix_size]);
void run_length_encoding_benchmark();
void run_length_encode(char [line_size]);
void prime_number_benchmark(int);
int is_prime(int);


int main(int argc, const char * argv[]) {
    
    integer_math_benchmark();
    run_length_encoding_benchmark();
    prime_number_benchmark(prime_limit);
    return 0;
}

void integer_math_benchmark(){
    
//    int a[matrix_size][matrix_size];
//    int b[matrix_size][matrix_size];
//    int c[matrix_size][matrix_size];
    
    int a[10][10] = {
        {10750, 32185, 20007, 45611, 42716, 63119, 20551, 2148, 28041, 30839},
        {7772, 21397, 49886, 47742, 13420, 40857, 47798, 28235, 26000, 49557},
        {39602, 22794, 26276, 38458, 58983, 9743, 11001, 9352, 4711, 30876},
        {9784, 20529, 45865, 3186, 31884, 21098, 15706, 41921, 23778, 50833},
        {13723, 61779, 46156, 28209, 48336, 23186, 36870, 35609, 57736, 33877},
        {65518, 64501, 48700, 4312, 6940, 2913, 56573, 54290, 2168, 61464},
        {34581, 56253, 43755, 5891, 34190, 58783, 8071, 65291, 31599, 58097},
        {21391, 61594, 32954, 29174, 49242, 12609, 64565, 36967, 23536, 33873},
        {32835, 26600, 22625, 26442, 27266, 64418, 33926, 53361, 684, 6850},
        {17341, 54250, 13644, 40189, 1067, 65219, 35081, 43426, 56893, 32370},
    };
    
    int b[10][10] = {
        {58424, 22099, 18281, 53572, 16069, 16941, 19678, 6143, 7919, 16349},
        {10377, 62560, 14610, 33528, 41805, 628, 31202, 43037, 36219, 31066},
        {46267, 57586, 19629, 35749, 36045, 60479, 54825, 14561, 14696, 35808},
        {38369, 51075, 7920, 36673, 12902, 54411, 49518, 45503, 2968, 21751},
        {55729, 9895, 60584, 13527, 62529, 24891, 41840, 58189, 26993, 18111},
        {53479, 40686, 21421, 35069, 36583, 28419, 57906, 20201, 29837, 49172},
        {36553, 31214, 52276, 41677, 25467, 29638, 54072, 52085, 10711, 25080},
        {33549, 23486, 44177, 7338, 46782, 34751, 57241, 64310, 11311, 5033},
        {53494, 63393, 32565, 18012, 1728, 14758, 16072, 7912, 21865, 64399},
        {12824, 35134, 61804, 54506, 4543, 39064, 31454, 11444, 5371, 36072},
    };
    
    int c[10][10];
    
    struct timeval t1, t2;
    double elapsedTime;

    //fill_matrix(a, 1);
    //fill_matrix(b, 2);

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
//    FILE* file; //For file IO
    int i;

    char line[50][512] = {
        "11000111000100110100000100000111101111110110011101011100111001001001110000110110100011100110010101111100100001110000100101001111111111001011001011100010010000001011000011111110111001111101011000111101001010010011110011111011010111011100011010111011011000001110011010101011111010010000001100101010001110111100011111100010001001111010011011101000011000100101110011011011001101100111110111100111011000101101111001010101110010101110000101100001001100001011000111010101111000111101001000001010001010101111100000011110",
        "00110010110111110010100111010010110101101010100110000001100111001101000001010100111010110101001010000110111101101111100110010110110100101010011000110001111110001011000101011111110100101000000000011010001010011010010001111111101101010100100011000100111010001011101101001001001011011001111000001010111110100011000001010110111110011001000111101110001010010001100001001100011100101000101100011000010111011101101000001110001001001010111100010010011111000011100110000100110000111110000011000100001111100000110000100001",
        "00111000100100011011110111001110001000011100100100011010000010110010000001110011101011000001111101010000001001010010100101011011010001110010001010000110000111110110101100100001001001000000111000001110001101100100000100010110101001011011000011011001000000011001111111000101111001000110010101011001010100010100001010110011001101110000001100101100110101011000100010000000000011110100000101101010110100111100010011001000100000110101100000011111001010010010110011100111000101101110011010110001010111110001111001010000",
        "11111100101000101001111111111111111110011101100001110010110101000010110010011100101001010100110100111101011101010011100011000000110001011101001011111101101010111110111010011001101111011010110001101000111101000010001110100011100100000000001011001011101101110110100010111111010001101101110111110100010010110111110010000111100010001110110010101001110111110111011100110110010111011010011011111000101000000100100001110011000101100011111110111000000100010111100011011000110010111010110100111011010001010000110001111010",
        "01001010100011000011111011001110101101111110001001110101000101010010000011100101010100010100111111100111011000101011101000101100000110111100110010011111111011000101111001111111110110110000101010001110011000010110100101101000010101011010010000011110100010101100101011001001100010010000001111111101111100001001100000010110000010000000010111001111001111000010100100000010001111101100100111011011000001100100101010100101001011101110100111100011111100111100110000111100110101100111101011110010011011010111011010000010",
        "01101100010001010111011101111000110000011111001011111100000010101011000000111010011110011110111110000010100011110111100001010110011111100011000100001111110100010100110000101011011011011111101010101101111001110100101111100010110011110111100000101111000101001010101000111110100010011001010010101011111110110001101011101101010011010110010010101011111011111001010000010001100110011100111101011010111100111101101100001100000011110010010000001100011101011110100000101101001011001001000111101111100100111100010110101110",
        "01011101101001001100101101011000110101111011010100101000001100101110001001101000000001100010111111001101000010101001010001000100101010000001100110111000011100000010100110001111010000000101110100111000001100101011101010000101110011101010111010001001011000100011100000100101001011110110001011011111101010100000110110001000000111001010010100101010101010101111011110101101011000011101001000001001001001011000100001100100000100101000100100110001101001100100000000010101100011100011001011100100001100010101010001010110",
        "10011011110101100110100011000110100111111001001100010100110101010011001100011000001101011100010101001111010111100010001101001101100110010000110100010010011010100100100011100001101110110111000100100101010110110001001101001111010100010010110001101100001100010111100111110110111001100111110110010111010000001111010110101100010000101010011100100000001000100100011100010110010010110000111010011101110100100111010111011010110000010110101010110000010010001110111101000101001101010111000101100011010100010010010110111110",
        "11101010110000101001001110010011101101001001111111000111111101101110100110000111011001001011111111000000011001001100101011101011101110010001111010101101011111110000000100101110101101010110100011000010110001101001101010010001000101100111011101000100000010100000011010001100010000001001101100101111011001110111010101100100110100011000011011100001010001001011111010110101011010010100011000011000010111111110010010100110011011001001010010101001111100101001110110101110100100111110100101110100100100000101111110111000",
        "01111101000110111100111110011101000100010011010110110111111010001110001011110010010011010100011001001110110000001010101101001100100011101100010100101001110010111101111000110100101100000101000101001100110001010100011011000110100011111011010001001010100000011000000110011101110000000010000101001101000100111000001100110101100111001001000101101110001001110100110111111100101000101101110101111101110110000100110110110110101001110100110010100111110111000100001100111001001001101011000010101000000101000101001100101001",
        "11000000010001000110000111001110111100011000000100110011000011011000001000101111100001101111101111101010100000111010111100101010101111011111000101001010110111011010000100010100100110010010001101100001101000100010001111001000001101111101111100010110111110100110011100011100000100011000100110100111101100111110100110110101101000101101001101000001100100101010000110110100010011000101011100100110000001010000011100000100001111111011101010100101111110000000000100111010100001101001100100111001110000010111111110000110",
        "10110101010110110000001011010111110011110001111110000000101010001000001101010110111001011101001110111001000110100000001011100010100100101100000011100110010010111111001111111100001101010101111010110100001011111000001010010101000010110110011111101110110011101110010001010111111100111100010010001011010010100100000011111001100001111111010100111001111011000100011100010000000001000100101010111101111001101101011001011000000101011111100010110000000111110010011011100100010010111000101000001001010110010010100001000101",
        "11000110101001000000011111011111010101110101010101001011110011111111011010110000101101010010111110010100010111101101000010000111100100110101011001000100100110000100111000110100000111011001001010101011001001110001100111111000010110000011100011011110011101111001010011010100010110101001011001101101110000010100000010100111001101010100011101011001001000101011011100011010010000100111000000011011010011001101111001010011011011110001001000101010111110100101111111001101101110001010000101100110000010111111010101110100",
        "10011001010001001010011100101001111011001001100001001110100100011101101011011000010100110010010000011110111101101010011001001001100101110001011010001001110010111111101010101010101001000101101110000100111111100111100001110101000010100010011011010000000111111011110010110101000001011000011010000101101101111100001010110101110101100100011001110111111011100001011100110111101011110110100010100100110011011000001100100001100000101000011010010100111111011001100011101011101101011100111101111111101110110111001011010111",
        "11110111111101000011010000001011010001111010110010101010001110110010000011011000010000111111001100100101111000010001010100110000100111101110011101100101110101110011100011001010010101111010110000011110100001111001110100010011001001111000001100110100101111001010110111111100001000111100110100010010110100001011011101010010000001110111000010100011101001111001011111100011101011100000101010101111110011000001010010110101110001110001010011011100111110100000111010101001110011101011101010000111011101011100000111001001",
        "00111110101011101101110000111011001110001111110110010000101111111011000010101000101000100101101101111001101011001111100000000011001010001101111000110100001100100010010011101110111111101000100101111101010110111100011100000111011110100000111111111010010101111011100110111000110101110001001100110010110001000001001100000000111001100101101111111010000110000010011011000011010001010111110100001010110010001110111100001010111101100100011001111111111001110001100010011111101010101000000001110010001000010100001110011110",
        "11000110110010011001010111101001101100101001111001001011011001000011111100011111011111001001101011000101100010011110011011100110000001010100100011010100100110110110001000000010001101111001001100110001001100110011101101010011010101110000010011110001110011001011010101010111001011100001001011101010000110100100010010101100000001100010010011001101101001111001000011101010010000110010010010111010100011000000110101110010011100100010110000111111011110100101001000001010101101110101111101100101111011110101101111100101",
        "11011001011010011101111000010111101000000010010000001100101011011111111100110111000111101010101101111001111010110100100001011101010000011110110111000011101010000001011010000100000000101110110110001010110011100111100011110011101011001110101001001010110111010001010010101111000110011100001001100110001011111110000011101100101000000000111001000100010011100100101011001001011010000100100000111011111111110101001010000000100110011010101011111010110010110100101110111001010011011011111101010100001001111110110111000101",
        "11001100100001111110010110001001011011111001001000010000101001111100011010000010111010000101100111111000101111000001001000001001001001100100001111111011111110011001101110010110110011100100000010111001101000011101110101110101100101111000001101011000111011111110010001011100100001001101101001010010000101100000111110011110110001000111000010110010000111100010101010001101110001101000010000000111101000101010001010001100010000110000101011110100000100010001100111101010000010100010110111001110011000010011011111100101",
        "10011100100000011001100011000010000000000101001101110000100101010101010010010101110001011111101111001000110000000000000001110100000011010010111000001010101100001010010001001000110001011100000111011101101110111011111110111010110110111101010000001101010110001001011010011010000001100101110100101011010110011110111110000001011011110100101011000111101001101111110010110011000001110001101101100011110010000111111100111100010010001001110011001010111110111110101111011010111000111101100110100110010011110001010101011001",
        "00011010000010110000110011100000011011000100001111011100100001111110111111001001011000000001110111110000001001100110100011111100000100000001000001100111110110111111011100101010010100100011110001011100010111111100110011100010000111101110111100110000101001011101111011011001001010110101110000100010001100001010100010111111000011011111111100000111101011110010000110101111100001000000001001111111111000011101100011010000001100100011010101010101000110011100011110100011000011001100010011000000110100010110010110100100",
        "10100111001001001010100001000100101010011001111100101011001000111111000000100110100100100001100011100100110001101000001000100111110101110110000110011001111010001001100001110111000100101111101001100011010101000000010010100110110100000100111101111101101000100101010000100001000101011111101001110100101011000101100111100100100111011011010110100001111011101011011010010010010010101111110001111111011010101101000010101101100110000101100010100010001000110000010010001100111000010001000010110101110111001111011101111110",
        "01011110110100010011001010000011111001100000100100001010011001100011100111111000011101011101100010101010000100100101111010011001101010111011001001100100010111001010110001010100001110110010111110010101011100011101010001110011100100001110001000011011111010010000001000010100010111000011011101010011000011011011010110101001101111000110110110011111110010100001101101110100000100011011001110101110011110100011011001010010001001111110011110110011011001110100001101010100011011101100111010110100110011010110011100000100",
        "00111001110010100010101000101011000011101101001011111011010001010100010000010111010000110000100110100010110101100010010110010010100001100101011110011111001111111111010111010110000101111110100010001101001010101111000111100011001101011010011100111000111011100011101001111100000000110001101101001000111010110001101101101010000100010110000011100000100111101000001110001110100111010011100111010101111000110101010100100110100010000101101100100101000101100110011111001011101100011111000000111000001100111110000111101110",
        "00101000100010101001110001000101010110011111111001011011010101111101000010000101110100101010001001001001000110010110001000100101110111110000010010110000000011010101101011000010001111001010110110011011001100110100011110011011011101011001011001010110011110000001000101011100000001110001011010111010011110001110100110110000011000011110010111110111110110101000111100111011111000001001100011110011011111010100001101110111101100001110110100011001110000010010011101100010000110111011011100100010101100101010011001000100",
        "01000011000000111110101001000110110101011100011100010100100100011011101001001000011000000001010110110000111100011000011111001101001111110001101100110111110100011100110110110000110011010010111100000011010110010010000010101111001011100100010110100011110110011010000010001111100100110111101011100010011100111111110000000011111011010110000000000010011110001000101010110110011010110101100100100010001000001110001010100110011011001100000100110010111001110110001000000000111010001100011101010011011001101000011010011001",
        "01100011100111000001101000101001100100100011110000111010001111011111000101111010101101110000000010101010111011111000110100011111111011101111111101100101001001101010001101111100001101011000011010011001001101100111111000001011101000011110011100010001000100001011001001110001110100111001110110001000010110100000001011101110101101010010111000010000110011101000101000000100011001110110100001110001001100100111100101111000000000000000101110011111001011011011100000100000110101111101101001011010001101101001011000001001",
        "00010011000000011001010100101111110011110011110111011001000100011101110111010010001001110010001101001000111001010001110101001011010011000100110110000001000001111010000010000111101110110011101010000110001101100001110001011011100001111011111001111100011001100010010111100111110011011011011000001000000011100100000010111101011100001011011001011110010010000001101111111001111111000010010000111100100001010110100100111011011011011110100001110001000101101011110110001001101011100100010100001110000111010011010110111001",
        "10110111010100001111111101011001100000100100101001110000110011010101001000000001001001011110001110111000110100011001010000011111011001010101011110010110011010001001101111110011000000110101011001100001100001010101011000001110010110000101010110111100010010011101011010101101011011101001010010110110001000001110111101001100001010000110001110100111111111100101100010110011101000110010110000110011010001100010010000000110111111111110011101001011101011100101100010110111010100011011011100110000010001100110000101011011",
        "00000100011101010111000101111000010100001101001100011011100011001011100001011010111010110010011000000110111010000111111100010000000101110110011001100000001010110000110111111110100001110000010001001011001000111011001111010001001000010100111000101101000100011110011010110100101111100110010001111001110110010010001000011000010000011100010110000100111001001000001011011100000000011011010001011100100000101011010000101011000010100100000001110101001010100000110111011101111000111000100010111010011100111111111110000111",
        "11101000000110111000100100001010100010000111001010000110101010011101101101111111010111110000010001101111110001110011110111001101101000000111001111101111100001000101101110110100100011110011110010101001001111000110111001100110010001100100100100010101010101100010000011101110101010011001010011010101011001011110100111111010110111100111110001011101100101000001011101000111100110011101101000000001011111000011111000101000010000100000000111011000001011001110011001011101010111111011110110100111101101111001100010010010",
        "00110111111101110101110110100101001100011011000111100101100100011001000110010101000101000010110001111011101001010011111011111000011111101001101010000111110011010000011101010011111000001000001001100001011010110101000001000101000100110011101110101001101101101101101001010000011000101000100011110011111111111010111111000111110011000111110001111101110110010110111010111100110110101110011110010100100000110011100100000110110011010000011101010101111100100000100011000010010111110100011011011110000011010000111011110001",
        "10110100011000000001010101011111010011111001101111100100100011011101111111001000110111110101100100000010011000110100111111101111001010000010100010100011000100100111101101010001010111101001000111100111101000101011110001100001110100011000010011100011101100000011100101110010000001101001010001011101101110100101111011001010001000110001101111000000100010101101111100001000011001110000101100101100101100010000000000110011110001011101101111111110001000000010001100101010100110011111100010001010011001001100101000010111",
        "11001011001000001100010111011110011110010111010100010111101101000001101110111011010110110001001010101100001010110101001010001011010111000110001011100110011100001011000110101110111000000100001001101011101100111100101010011010101001010010101100010110011100010110110111101110110000100100111111011111110111000000111110010000011011000001100010001001011100100100011100111001100000100100110110011010011111101110110100111111100100010010000110110010101000111010110010000010010101000011100000000010001011010011110001011111",
        "00010101111100100001101110100101101011011011010100111111111100111100001111000100100101111101011110010001100101000100110101100111110011101101000100011100100010001000100111100110111011100111001110101100100010001111011001000101111000101001100010001010001101111000110101000100111111001001000111101001011111000011111101100111011100001101110000110111110111010100011000010100111011110000001011100100100110100001100101100010111111100110100001110110110011110101111010000111011100101100011110000001011110111000000111100000",
        "11011101001100001100010011111111101110010111000111110000011110011011010111110100000010111110111100010101011111011001110101010111101011110100010100001110011110100101011101000101000110011001110000111111100011000000100111010010000000010100100101110001100100100111110011111101100110100011000100010111001110001110001101011011010111000101101000111010011001100101000010010000010100010100001000011100001100010111000001000010100000000010000101011101101100111000001000111010111000010011110001011101010100011101000110101001",
        "10110110000111110100010001011100011110000000110111111010000011000000111100011010011001011110001001111010010101000101010110111011110000110101011100010000110001001100110101111101111000010110101000111101001010001011111010111101010101001101000001000100001101010010001011100111110110010110010111111001110001101101111100001111000110011100000011001011001000100011011100010010011101001011010010000011001101011000000111011011010101000100110110001001010001000001110110100010011000000010010001101100110111000111011110110101",
        "10011101010001000111011001010111100100001010000111100011001101101001101010011000001001010011100111111111001010001111101100110000101000011010000010111001100100100101111011010010110011001011100110101010110010001011000001101000101110101111011000011011000101110100111100010001111011000010010011101101001110001111011010010010011100100110011110011010100011110010111100010001000110101001110000001010001010010011011101001011100010000101100010011000000100101001001011100101001011000000110110110001010110001100100110010001",
        "00010011100011100111101001000000011001011111001111011000011001000011001101111001011101111000001001110011010100000101111111000011101111011110000000000110011000101111101000101001101100100001000010010010001101000011101011011101001001001000101011101110110011100001001111110111111100000111001000010100000111001111111001001100000010001100011001110111011111111110110100110000010000010000011011001010011100001100011100100001101101100010110110101001100101110111100010011011100000101010010011111110001010110110010001001001",
        "11000000110101010101011110111110010001011010100110110011111011011000000110111101000111011110011001110011101101101000000000010001110011010010101011101001010101111100111100010110100000001011101011000011011010111001101101111111111011101000101110010111110001100111010010000010111101101011001111000000001011100011100011110010010110110110010010101001011111101001000011011100000000010001001011101110111101010011101001111000011111001111100010100000111101111011111001110000100001001111000100001100111100010001000000111001",
        "10111001111010000000011010111101011110111000100100011111110000000010010110011000010010101010110000010010111010010100111011010001110100010101010001011010110111001111001111101110101010100011011110110000011101000001010011000111111101001101100010111110000011011011001110111001100011001011110110000010011011011001000010000110101000111111010111110011000001111100111011101001100110100001000100010110011101001101101001111111110010010111010100010110101001010111001000110110000110110001111111001111000100001000001111101001",
        "01001111110101101111110011001101111111000000111100100011110101110110001111100100010000110110010010011100100100111110101011100000011110011110000011110001010011000000100101111011001011110110111101000010111011111110010000011011100111011101001110100000000011110000000001100000101000101010000010000001000001010101101111000111101101011000011101010110100100010100101011001111010000000001110111011100101100010110101110000110101010011010011001001100110111101000100001001111010111111010000010001001010010010101111011110110",
        "11111001110001010100001110011001010111011000010010011011111001001101010100010011000001101011100001001100000100000011000111011010001010111101011100101010011100110110011101100001100011110001101100110100011001110000010011001110111100111000001001111001000011001011010100010111001001000010010000111011011011110011011101101101000110111010011100010110010011110001010010111100101110111110100010010101100010001100001100100001110100010101101100001010000100100101000010111000100111101101100111111010010101111001010111010110",
        "00011101100000001100101100011011010000101100010111110001001111101011100111111011110011101111011111101001000111111101011110000101000100010011011111110101100100110001000011111110001111001111011100000110010101011101101001001100101101110000010110111000000110010011001101010100100111000000011100001100101010011001001010011100001001010010000001011100011100100010111101101111011001110000110110011010100001111000010011001010111100101001111001011110111111100000011000100001010010000000000010011010100101100111110011001110",
        "10010000000011011101110001100010101011111010110101011111100101101001110010010110010000000011000011101000100101101101100001111010110011110010100001110000101001011100111101000000011101101100010111001010111010111101000101010111000101010101000010011001010001011111111101010111001100000100001110100100011100111110001101111011011001000011001100000110010000000000101101001011000001000001000111110010110001011010001110100101011101011111110111011101101010000010110011100111101101100101101001100011100111010010011001101000",
        "10111011100010111101101001101101101000011110000001100110111010001101110101010100001000011011001110011101101011100000110100101001011001001101101001001010110100111101111011001101110001000111101000000000000101000011011001110011111100100100111011110100101011000111001100110101101000100110100110010010101111011100001001011111011101101010111111000111110001100100100111010100000111101001111001100100101010100000010001001010011110100001001001110000000001101101101011101001001000001001100011010111100011010100101011001111",
        "01000100100010010111010010000110000010111011010001101001110001111111110010011100111101111011000110101011011100011011110110101010111100011110011101101101111110111011111100110001010100101001001011010110011001000001110011111110110000011010001100011101010110101001001001001111001001011001110101001111011111101000001000011001000111010110111111000111111111111110000010011000001110100000010110100110010111000001110001100100100111010000101010111010110110111011010110010011010011000111000011000000110011111000101000101011",
        "10101010101011100110010000011000000011010111001010100100000000110101001111010001100110100001011010010010011111010011110000000011001000111111100100000111101001011010011000101001101111110100101001101001111001011011001000101000001000110011001110001110001000101110111000001101001110111101000111110011110110001010100100100001100001111010010010111000111110101111100111111001111100101110111010011001011010101000101110000111101011011010000110001000000010001010011001101110011111001011000110111100010001100111110111000100",
        "11001100111010100100011001100001111100010000000110110011011100001100100100010101011001000010101001100111010010111001111101000000110010001101010101011000111010111100011101110010101110001110010110100001010010101000101111011100000001100000101100111001010011010011111110111001111000011011101011100010000101000100010101011000000100000001111000111010010001101111011011010000001001011011011110001111111100000100111100010010110100011011010011010101100010100011011101000010001001001000011001001000110110101010011101101100",
        "01101100110001011011001110010000010000000101101000011101111100011100010011101100011100001100011111001000010011000000111011101100101110001100011101011101011000000111001110000011101000110011000110110111111110010101110000011011001000100101100000101000110110000100101000001011000001010100110011011101010100011011100100001010010110010011110000011000011111010000100010101000001110110010101100010101000010010100100001110000100110100111101001101111100101111111111000101011100110001100011010001000101111000100111000011100",
    };
//    file = fopen ("Strings.txt", "r"); //For file IO
    
    struct timeval t1, t2;
    double elapsedTime;

    printf("Run_Time_Encode: ");
    // start timer
    gettimeofday(&t1, NULL);
    
    for(i = 0; i<sizeof(line)/sizeof(line[0]); i++){
        run_length_encode(line[i]);
    }
//For file IO
//    while(fscanf(file, "%s", line) != EOF){
//        run_length_encode(line);
//    }

    
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("elapsed %fus\n", elapsedTime);
 }

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
















