
undefined4 utf8_encode(uint param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  
  if ((int)param_1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    bVar1 = (byte)param_1;
    if ((int)param_1 < 0x80) {
      *param_2 = bVar1;
      *param_3 = 1;
    }
    else if ((int)param_1 < 0x800) {
      *param_2 = (char)((int)(param_1 & 0x7c0) >> 6) - 0x40;
      param_2[1] = (bVar1 & 0x3f) + 0x80;
      *param_3 = 2;
    }
    else if ((int)param_1 < 0x10000) {
      *param_2 = (char)((int)(param_1 & 0xf000) >> 0xc) - 0x20;
      param_2[1] = (char)((int)(param_1 & 0xfc0) >> 6) + 0x80;
      param_2[2] = (bVar1 & 0x3f) + 0x80;
      *param_3 = 3;
    }
    else {
      if (0x10ffff < (int)param_1) {
        return 0xffffffff;
      }
      *param_2 = (char)((int)(param_1 & 0x1c0000) >> 0x12) - 0x10;
      param_2[1] = (char)((int)(param_1 & 0x3f000) >> 0xc) + 0x80;
      param_2[2] = (char)((int)(param_1 & 0xfc0) >> 6) + 0x80;
      param_2[3] = (bVar1 & 0x3f) + 0x80;
      *param_3 = 4;
    }
    uVar2 = 0;
  }
  return uVar2;
}

