
/* WARNING: Unknown calling convention */

uint16_t CRC16(uchar *p_data,uint16_t w_len)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  
  sVar5 = w_len - 1;
  if (w_len == 0) {
    uVar2 = 0xffff;
  }
  else {
    uVar3 = 0xff;
    uVar6 = 0xff;
    do {
      sVar5 = sVar5 + -1;
      iVar4 = (*p_data ^ uVar3) + DAT_0002b87c;
      uVar3 = uVar6 ^ *(byte *)(iVar4 + 0x7b8);
      bVar1 = *(byte *)(iVar4 + 0x8b8);
      uVar6 = (uint)bVar1;
      p_data = p_data + 1;
    } while (sVar5 != -1);
    uVar2 = (ushort)uVar3 | (ushort)bVar1 << 8;
  }
  return uVar2;
}

