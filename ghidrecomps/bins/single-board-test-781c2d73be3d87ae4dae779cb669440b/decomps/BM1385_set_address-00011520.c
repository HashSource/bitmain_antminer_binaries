
/* WARNING: Unknown calling convention */

void BM1385_set_address(uchar which_chain,uchar address)

{
  uchar uVar1;
  uchar buf [4];
  
  buf[2] = '\0';
  buf[3] = '\0';
  buf[1] = address;
  buf[0] = '\x01';
  uVar1 = CRC5(buf,'\x1b');
  buf[3] = uVar1;
  uart_send(which_chain,buf,4);
  return;
}

