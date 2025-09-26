
uint16_t ASIC_CRC16(uint8_t *pdata,uint32_t length)

{
  byte *pbVar1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar2;
  
  if (length != 0) {
    uVar3 = 0xff;
    uVar5 = 0xff;
    pbVar2 = pdata;
    do {
      pbVar1 = pbVar2 + 1;
      uVar4 = uVar3 ^ *pbVar2;
      uVar3 = uVar5 ^ ""[uVar4];
      uVar5 = (uint)""[uVar4];
      pbVar2 = pbVar1;
    } while (pbVar1 != pdata + length);
    return (ushort)uVar3 | (ushort)""[uVar4] << 8;
  }
  return 0xffff;
}

