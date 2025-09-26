
uint LZ4_NbCommonBytes(reg_t val)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  reg_t val_local;
  
  uVar5 = LZ4_isLittleEndian();
  if (uVar5 != 0) {
    bVar2 = (byte)val;
    bVar3 = (byte)(val >> 8);
    bVar4 = (byte)(val >> 0x10);
    bVar1 = (byte)(val >> 0x18);
    val = (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                          bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                       bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
          (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1 |
                          bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                       bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
          (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1 |
                          bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                       bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
          (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1 |
                          bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                       bVar1 >> 6 & 1) << 1 | bVar1 >> 7);
  }
  return (uint)LZCOUNT(val) >> 3;
}

