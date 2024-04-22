
/* WARNING: Unknown calling convention */

void BM1385_set_gateblk(uchar which_chain,uchar chip_addr,_Bool mode)

{
  byte bVar1;
  undefined uVar2;
  uchar gateblk [4];
  
  if (mode) {
    uVar2 = 0x86;
  }
  else {
    uVar2 = 6;
  }
  gateblk = (uchar  [4])(CONCAT31((int3)(((Conf.baud & 0xff) << 0x10) >> 8),uVar2) | 0x800000);
  bVar1 = CRC5(gateblk,'\x1b');
  gateblk[3] = gateblk[3] | bVar1 & 0x1f;
  uart_send(which_chain,gateblk,4);
  usleep(10000);
  return;
}

