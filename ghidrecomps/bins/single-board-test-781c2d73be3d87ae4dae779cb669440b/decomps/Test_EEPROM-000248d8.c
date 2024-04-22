
/* WARNING: Unknown calling convention */

uchar Test_EEPROM(void)

{
  byte *pbVar1;
  uchar *puVar2;
  uchar *puVar3;
  uint uVar4;
  byte *pbVar5;
  uchar uVar6;
  byte bStack_121;
  uchar buf1 [256];
  uchar auStack_20 [4];
  
  memset(buf1,0,0x100);
  puVar2 = buf1;
  do {
    puVar3 = puVar2 + 1;
    *puVar2 = (char)puVar2 - (char)buf1;
    puVar2 = puVar3;
  } while (puVar3 != auStack_20);
  pbVar5 = &bStack_121;
  AT24C02_write_bytes('\0',buf1,gI2c,gChain,0x100);
  pbVar1 = pbVar5;
  do {
    pbVar1 = pbVar1 + 1;
    *pbVar1 = 0;
  } while (pbVar1 != buf1 + 0xff);
  uVar6 = '\0';
  AT24C02_read_bytes('\0',buf1,gI2c,gChain,0x100);
  uVar4 = 0;
  pbVar1 = pbVar5;
  do {
    pbVar1 = pbVar1 + 1;
    if (*pbVar1 != uVar4) {
      uVar6 = '\x01';
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 0x100);
  do {
    pbVar5 = pbVar5 + 1;
    *pbVar5 = 0xff;
  } while (pbVar5 != buf1 + 0xff);
  AT24C02_write_bytes('\0',buf1,gI2c,gChain,0x100);
  return uVar6;
}

