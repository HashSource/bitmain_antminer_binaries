
uint crc16(byte *param_1,int param_2)

{
  byte *pbVar1;
  uint uVar3;
  byte *pbVar2;
  
  if (0 < param_2) {
    uVar3 = 0;
    pbVar2 = param_1;
    do {
      pbVar1 = pbVar2 + 1;
      uVar3 = (uint)*(ushort *)(&crc16_table + ((uint)*pbVar2 ^ uVar3 >> 8) * 4) ^
              (uVar3 & 0xff) << 8;
      pbVar2 = pbVar1;
    } while (pbVar1 != param_1 + param_2);
    return uVar3;
  }
  return 0;
}

