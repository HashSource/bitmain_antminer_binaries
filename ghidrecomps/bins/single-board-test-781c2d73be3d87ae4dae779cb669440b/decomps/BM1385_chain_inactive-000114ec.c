
/* WARNING: Unknown calling convention */

void BM1385_chain_inactive(uchar which_chain)

{
  uchar uVar1;
  uchar buf [4];
  
  buf[0] = 0x85;
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  uVar1 = CRC5(buf,'\x1b');
  buf[3] = uVar1;
  uart_send(which_chain,buf,4);
  usleep(5000);
  return;
}

