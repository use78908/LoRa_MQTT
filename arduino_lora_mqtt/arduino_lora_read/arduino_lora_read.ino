#include <TLM926P01A.h>
#include <SoftwareSerial.h>

int read_data_len = 0;
char *local_buf;
int rssi ;

void setup()
{
  tlm_init();
  //Serial.println("fsdfs");
}

void loop()
{
  read_data_len = tlm_receive_data( &local_buf, &rssi );
  if (read_data_len) {
    /* print receive data len */
    testprint(read_data_len);
    /* print receive data */
    for ( int i=0 ; i<read_data_len-1 ; i++ ) {
      print_char( local_buf[i] );
      Serial.print(local_buf[i]);
    }
    /* print receive rssi */
    testprint(rssi);

    read_data_len = 0;
    rssi =0;
  }
}
