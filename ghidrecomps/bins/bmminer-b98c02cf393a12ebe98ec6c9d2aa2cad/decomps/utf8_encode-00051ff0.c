
undefined4 utf8_encode(int param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  
  if (-1 < param_1) {
    bVar1 = (byte)param_1;
    if (param_1 < 0x80) {
      *param_2 = bVar1;
      *param_3 = 1;
      return 0;
    }
    if (param_1 < 0x800) {
      param_2[1] = (bVar1 & 0x3f) + 0x80;
      *param_2 = (byte)((uint)(param_1 << 0x15) >> 0x1b) - 0x40;
      *param_3 = 2;
      return 0;
    }
    if (param_1 < 0x10000) {
      *param_2 = ((byte)((uint)param_1 >> 8) >> 4) - 0x20;
      param_2[1] = (byte)((uint)(param_1 << 0x14) >> 0x1a) + 0x80;
      param_2[2] = (bVar1 & 0x3f) + 0x80;
      *param_3 = 3;
      return 0;
    }
    if (param_1 < 0x110000) {
      *param_2 = (byte)((uint)(param_1 << 0xb) >> 0x1d) - 0x10;
      param_2[1] = (byte)((uint)(param_1 << 0xe) >> 0x1a) + 0x80;
      param_2[2] = (byte)((uint)(param_1 << 0x14) >> 0x1a) + 0x80;
      param_2[3] = (bVar1 & 0x3f) + 0x80;
      *param_3 = 4;
      return 0;
    }
  }
  return 0xffffffff;
}

