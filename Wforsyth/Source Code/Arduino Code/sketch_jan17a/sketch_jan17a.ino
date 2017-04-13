#include <aes.h>
#include <aes128_dec.h>
#include <aes128_enc.h>
#include <aes192_dec.h>
#include <aes192_enc.h>
#include <aes256_dec.h>
#include <aes256_enc.h>
#include <AESLib.h>
#include <aes_dec.h>
#include <aes_enc.h>
#include <aes_invsbox.h>
#include <aes_keyschedule.h>
#include <aes_sbox.h>
#include <aes_types.h>
#include <bcal-basic.h>
#include <bcal-cbc.h>
#include <bcal-cmac.h>
#include <bcal-ofb.h>
#include <bcal_aes128.h>
#include <bcal_aes192.h>
#include <bcal_aes256.h>
#include <blockcipher_descriptor.h>
#include <gf256mul.h>
#include <keysize_descriptor.h>
#include <memxor.h>

#include <AESLib.h>
void configCrypt()
{
  
}
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
randomSeed(analogRead(0));
uint8_t key[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
uint8_t iv[] = {(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255),(uint8_t)random(255)};
char data[] = "0123456789012345384729834723895798327598798759837423987589759759723957329857290472907109375923753094730948093490750947230970925723907530975slkflkfenl;kgngjkrhfkrhfjkshfkehfekfhekjfhhrslkedkfhkgeklejilfjlrifjelfewkfhehekgjkghukghuhfughreughrkhrkheukgrhkuuhgkehrhgihfihfoihfoihgeoifhiohewoighweioewrhewioheoi09237329075"; //16 chars == 16 bytes
//Serial.println(data);
int len= (sizeof(data)/sizeof(char));
int origlen=len;
//Serial.println(len);
int padding = 16-(len%16);
if(padding>0)
{
  len+=padding;
}
//Serial.println(len);
char paddedData[len];
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
//Serial.println(paddedData);
unsigned long starttime=millis();
aes128_cbc_enc(key, iv, paddedData, len);
Serial.print("encrypted:");
//Serial.println(paddedData);
unsigned long elapsed;
elapsed=millis() - starttime;
String Str1="Operation time: ";
Str1+=(int)elapsed;
Serial.println(Str1);
starttime=millis();
aes128_cbc_dec(key,iv, paddedData, len);
Serial.print("decrypted:");
//Serial.println(paddedData);
elapsed=millis() - starttime;
String Str2="Operation time: ";
Str2+=(int)elapsed;
Serial.println(Str2);
}

void loop() {
  // put your main code here, to run repeatedly:

}
