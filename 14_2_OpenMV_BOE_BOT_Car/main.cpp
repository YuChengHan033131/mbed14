#include"mbed.h"

Serial pc(USBTX,USBRX); //tx,rx
Serial uart(D1,D0); //tx,rx
Serial xbee(D12, D11);
DigitalIn sw3(SW3);
int main(){
   uart.baud(9600);
   pc.printf("start");
   while(1){
      if(uart.readable()){
            char recv = uart.getc();
            pc.putc(recv);
      }else if(sw3==0){
         sprintf(s,"send");
         uart.puts(s);
         wait(1);
      }
   }
}