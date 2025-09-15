
/* WARNING: Unknown calling convention */

uint16_t CRC16(uchar *p_data,uint16_t w_len)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  uint uVar5;
  
  sVar4 = w_len - 1;
  if (w_len == 0) {
    uVar1 = 0xffff;
  }
  else {
    uVar2 = 0xff;
    uVar5 = 0xff;
    do {
      sVar4 = sVar4 + -1;
      uVar3 = *p_data ^ uVar2;
      uVar2 = uVar5 ^ ""[uVar3];
      uVar5 = (uint)""[uVar3];
      p_data = p_data + 1;
    } while (sVar4 != -1);
    uVar1 = (ushort)uVar2 | (ushort)""[uVar3] << 8;
  }
  return uVar1;
}

