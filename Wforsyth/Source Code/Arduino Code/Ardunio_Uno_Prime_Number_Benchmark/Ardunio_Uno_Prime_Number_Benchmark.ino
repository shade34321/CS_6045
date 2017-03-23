void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Benchmark,Prime_Number,Processor,Ardunio_Uno");
  Serial.println("limit,# found,time(miliseconds)");
  unsigned long starttime;
  unsigned long elapsed;
  for(int i = 10; i<=1000; i+=10){
    // start timer
    starttime=millis();
    int found = prime_number_benchmark(i);
    // stop timer
    elapsed=(millis() - starttime);
    Serial.print(i);
    Serial.print(",");
    Serial.print(found);
    Serial.print(",");
    Serial.println(elapsed);
  }
  Serial.println("END");
  Serial.flush();
}

void loop() {
  // put your main code here, to run repeatedly:

}

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
