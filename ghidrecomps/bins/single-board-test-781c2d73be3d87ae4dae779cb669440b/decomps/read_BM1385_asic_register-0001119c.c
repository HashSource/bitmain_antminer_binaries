
/* WARNING: Unknown calling convention */

void read_BM1385_asic_register(uchar which_chain,uchar chip_addr,uchar reg_addr,_Bool mode)

{
  uint3 uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  uchar buf [4];
  
  uVar1 = CONCAT12('\0',CONCAT11(reg_addr,chip_addr));
  buf[1] = (char)uVar1;
  buf[2] = (char)(uVar1 >> 8);
  buf[3] = (char)(uVar1 >> 0x10);
  buf[0] = '\x04';
  if (mode) {
    buf[1] = (char)uVar1;
    buf[2] = (char)(uVar1 >> 8);
    buf[3] = (char)(uVar1 >> 0x10);
    buf[0] = 0x84;
  }
  bVar4 = CRC5(buf,'\x1b');
  uVar2 = (uint)buf >> 0x10;
  uVar3 = (uint)buf >> 8;
  uVar5 = (uint)buf & 0xff;
  buf[3] = bVar4;
  printf("%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",DAT_000111f8,uVar5,uVar3 & 0xff,
         uVar2 & 0xff,(uint)bVar4);
  uart_send(which_chain,buf,4);
  return;
}

