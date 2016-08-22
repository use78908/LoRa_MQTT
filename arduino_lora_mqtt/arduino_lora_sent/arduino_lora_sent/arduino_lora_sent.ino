#include <TLM926P01A.h>
#include <SoftwareSerial.h>

char *data = "987654321";
int error = 0;

void setup()
{
  tlm_init();
}

void loop()
{
  error = tlm_sent_data( data , 9) ;
  testprint( error );
  delay(1000);
}
