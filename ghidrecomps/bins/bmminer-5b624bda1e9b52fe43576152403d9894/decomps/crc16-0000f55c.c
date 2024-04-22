
ushort crc16(uchar *buffer,int len)

{
  byte *pbVar1;
  uint uVar3;
  byte *pbVar2;
  
  if (len < 1) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0;
    pbVar2 = buffer;
    do {
      pbVar1 = pbVar2 + 1;
      uVar3 = (uint)*(ushort *)(DAT_0000f58c + ((uint)*pbVar2 ^ uVar3 >> 8) * 4) ^
              (uVar3 & 0xff) << 8;
      pbVar2 = pbVar1;
    } while (pbVar1 != buffer + len);
  }
  return (ushort)uVar3;
}

