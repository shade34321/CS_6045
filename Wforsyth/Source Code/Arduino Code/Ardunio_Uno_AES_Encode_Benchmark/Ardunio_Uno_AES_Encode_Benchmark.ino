#include <AESLib.h>

#define max_lines 500

void configCrypt()
{
  
}
void setup() {
randomSeed(analogRead(0));
  uint8_t key[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  uint8_t iv[] = {(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255)};
  char data[] = "0123456789012345384729834723895798327598798759837423987589759759723957329857290472907109375923753094730948093490750947230970925723907530975slkflkfenl;kgngjkrhfkrhfjkshfkehfekfhekjfhhrslkedkfhkgeklejilfjlrifjelfewkfhehekgjkghukghuhfughreughrkhrkheukgrhkuuhgkehrhgihfihfoihfoihgeoifhiohewoighweioewrhewioheoi09237329075"; //16 chars == 16 bytes
  int len= (sizeof(data)/sizeof(char));
  int origlen=len;
  int padding = 16-(len%16);
  char paddedData[len];
  unsigned long starttime, elapsed;
  int i = 0, j = 0;
  Serial.begin(9600);
  Serial.println("Benchmark,AES_Encode_Decode,Processor,Ardunio_Mega_2560");
  Serial.println("Line Size(bytes),Encode Time(miliseconds),Decode Time(miliseconds)");

  for(j = 1; j<=max_lines; j++){
    Serial.print(len*j);
    Serial.print(",");
    if(padding>0)
    {
      len+=padding;
    }
    for(int i=0; i<len; i++)
    {
      if(i<origlen)
      {
        paddedData[i]=data[i];
      }
      else
      {
        paddedData[i]='F';
      }
    }
  
    starttime=millis();
    for(i = 1; i<=j; i++)
    {
      aes128_cbc_enc(key, iv, paddedData, len);    
    }
    elapsed=millis() - starttime;
    Serial.print(elapsed);
    Serial.print(",");
  
    starttime=millis();
    for(i = 1; i<=j; i++)
    {
      aes128_cbc_dec(key,iv, paddedData, len);    
    }
    elapsed=millis() - starttime;
    Serial.println(elapsed);
    len= (sizeof(data)/sizeof(char));
    origlen=len;
    padding = 16-(len%16);
  }
  Serial.println("END");
}

void loop() {
  // put your main code here, to run repeatedly:

}
