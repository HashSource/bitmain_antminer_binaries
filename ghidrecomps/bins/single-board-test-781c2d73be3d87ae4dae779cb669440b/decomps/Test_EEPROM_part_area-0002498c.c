
/* WARNING: Unknown calling convention */

uchar Test_EEPROM_part_area(void)

{
  byte *pbVar1;
  uint uVar2;
  uchar uVar3;
  int iVar4;
  byte *pbVar5;
  byte bStack_21;
  uchar buf1 [8];
  
  pbVar5 = &bStack_21;
  iVar4 = 0;
  buf1[0] = '\0';
  buf1[1] = '\0';
  buf1[2] = '\0';
  buf1[3] = '\0';
  buf1[4] = '\0';
  buf1[5] = '\0';
  buf1[6] = '\0';
  buf1[7] = '\0';
  pbVar1 = pbVar5;
  do {
    pbVar1 = pbVar1 + 1;
    *pbVar1 = (byte)iVar4;
    iVar4 = iVar4 + 1;
  } while (iVar4 != 8);
  puts("\n");
  AT24C02_write_bytes('\0',buf1,'\0',gChain,8);
  pbVar1 = pbVar5;
  do {
    pbVar1 = pbVar1 + 1;
    *pbVar1 = 0;
  } while (pbVar1 != buf1 + 7);
  uVar3 = '\0';
  puts("\n");
  AT24C02_read_bytes('\0',buf1,'\0',gChain,8);
  uVar2 = 0;
  pbVar1 = pbVar5;
  do {
    pbVar1 = pbVar1 + 1;
    if (*pbVar1 != uVar2) {
      uVar3 = '\x01';
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 8);
  do {
    pbVar5 = pbVar5 + 1;
    *pbVar5 = 0xff;
  } while (pbVar5 != buf1 + 7);
  puts("\n");
  AT24C02_write_bytes('\0',buf1,'\0',gChain,8);
  return uVar3;
}

