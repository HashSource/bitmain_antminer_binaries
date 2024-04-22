
/* WARNING: Unknown calling convention */

void set_BM1385_freq(uchar which_chain,uchar chip_addr,uint freq,_Bool mode)

{
  byte bVar1;
  uint16_t reg_data_pll2;
  uchar buf [4];
  uint reg_data_pll;
  uint reg_data_vil;
  uint cmd_buf [3];
  
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  reg_data_pll = 0;
  reg_data_vil = 0;
  reg_data_pll2 = 0;
  printf("\n--- %s\n",DAT_000112bc);
  get_BM1385_plldata(freq,&reg_data_pll,&reg_data_pll2,&reg_data_vil);
  buf[1] = (uchar)(reg_data_pll >> 0x10);
  buf[0] = '\a';
  buf[2] = (uchar)(reg_data_pll >> 8);
  buf[3] = (uchar)reg_data_pll;
  bVar1 = CRC5(buf,'\x1b');
  buf[3] = buf[3] | bVar1;
  uart_send(which_chain,buf,4);
  usleep(3000);
  if (mode) {
    buf[0] = 0x82;
  }
  else {
    buf[0] = '\x02';
  }
  cmd_buf[0] = 0;
  buf[2] = (char)(reg_data_pll2 >> 8);
  buf[1] = chip_addr;
  buf[3] = (char)reg_data_pll2;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  bVar1 = CRC5(buf,'\x1b');
  buf[3] = buf[3] | bVar1;
  uart_send(which_chain,buf,4);
  usleep(5000);
  return;
}

