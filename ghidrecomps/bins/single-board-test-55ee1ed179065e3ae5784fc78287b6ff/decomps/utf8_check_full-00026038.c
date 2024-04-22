
undefined4 utf8_check_full(byte *param_1,int param_2,uint *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint local_10;
  int local_c;
  
  bVar1 = *param_1;
  if (param_2 == 2) {
    local_10 = bVar1 & 0x1f;
  }
  else if (param_2 == 3) {
    local_10 = bVar1 & 0xf;
  }
  else {
    if (param_2 != 4) {
      return 0;
    }
    local_10 = bVar1 & 7;
  }
  local_c = 1;
  while( true ) {
    if (param_2 <= local_c) {
      if ((int)local_10 < 0x110000) {
        if (((int)local_10 < 0xd800) || (0xdfff < (int)local_10)) {
          if ((((param_2 == 2) && ((int)local_10 < 0x80)) ||
              ((param_2 == 3 && ((int)local_10 < 0x800)))) ||
             ((param_2 == 4 && ((int)local_10 < 0x10000)))) {
            uVar2 = 0;
          }
          else {
            if (param_3 != (uint *)0x0) {
              *param_3 = local_10;
            }
            uVar2 = 1;
          }
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
      }
      return uVar2;
    }
    bVar1 = param_1[local_c];
    if ((-1 < (char)bVar1) || (0xbf < bVar1)) break;
    local_10 = local_10 * 0x40 + (bVar1 & 0x3f);
    local_c = local_c + 1;
  }
  return 0;
}

