
/* WARNING: Unknown calling convention */

uint16_t CRC16(uint8_t *p_data,uint16_t w_len)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  
  if (w_len != 0) {
    uVar3 = 0xff;
    pbVar2 = p_data + -1;
    uVar4 = 0xff;
    do {
      pbVar2 = pbVar2 + 1;
      uVar1 = *pbVar2 ^ uVar3;
      uVar3 = ""[uVar1] ^ uVar4;
      uVar4 = (uint)""[uVar1];
    } while (pbVar2 != p_data + (ushort)(w_len - 1));
    return (ushort)uVar3 | (ushort)""[uVar1] << 8;
  }
  return 0xffff;
}

