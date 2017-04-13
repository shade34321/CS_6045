#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <inttypes.h>

int is_prime(int n){
    int p;
    for(p = 2; p < n; p++){
        if(n % p ==0 && p != n)
            return 0;
    }
    return 1;
}

int prime_number_benchmark(int limit){
    int prime_count = 0;    
    int i = 0;
    for(i = 0; i<limit; i++){
        if(is_prime(i)){
            prime_count++;
        }else{
            //do nothing
        }
    }

    return prime_count;
}

int main() {
  printf("Benchmark,Prime_Number,Processor,Raspberry_Pi_B+\n");
  printf("limit,# found,time(miliseconds)\n");
  struct timeval t1, t2;
  double elapsedTime;
  for(int i = 10; i<=5000; i+=10){
    // start timer
    gettimeofday(&t1, NULL);
    int found = prime_number_benchmark(i);
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("%d,%d,%f\n",i, found, elapsedTime);
  }
  printf("END\n");
  return 0;
}
