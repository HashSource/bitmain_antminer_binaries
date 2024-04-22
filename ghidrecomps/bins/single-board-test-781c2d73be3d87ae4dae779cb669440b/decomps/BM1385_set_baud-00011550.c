
/* WARNING: Unknown calling convention */

void BM1385_set_baud(uchar which_chain,uchar chip_addr,uchar baud,_Bool mode)

{
  uchar uVar1;
  undefined uVar2;
  uchar buf [4];
  
  if (mode) {
    uVar2 = 0x86;
  }
  else {
    uVar2 = 6;
  }
  buf = (uchar  [4])(CONCAT21(CONCAT11(baud,chip_addr),uVar2) & 0x1fffff);
  uVar1 = CRC5(buf,'\x1b');
  buf[3] = uVar1;
  uart_send(which_chain,buf,4);
  return;
}

