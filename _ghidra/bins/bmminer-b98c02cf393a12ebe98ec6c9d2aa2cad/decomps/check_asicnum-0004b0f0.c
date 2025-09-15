
int check_asicnum(undefined4 param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  switch(param_1) {
  case 1:
    break;
  case 2:
    if ((param_2 & 0x80) == 0x80) {
      iVar1 = 2;
    }
    else {
      iVar1 = 1;
    }
    return iVar1;
  default:
    return 0;
  case 4:
    param_2 = param_2 & 0xc0;
    if (param_2 == 0x80) {
      return 3;
    }
    if (param_2 == 0xc0) {
      return 4;
    }
    if (param_2 == 0x40) {
      iVar1 = 2;
    }
    else {
      iVar1 = 1;
    }
    return iVar1;
  case 8:
    param_2 = param_2 & 0xe0;
    if (param_2 == 0x80) {
      return 5;
    }
    if (param_2 < 0x81) {
      if (param_2 == 0x40) {
        return 3;
      }
      if (param_2 == 0x60) {
        return 4;
      }
      if (param_2 == 0x20) {
        return 2;
      }
    }
    else {
      if (param_2 == 0xc0) {
        return 7;
      }
      if (param_2 == 0xe0) {
        return 8;
      }
      if (param_2 == 0xa0) {
        return 6;
      }
    }
    break;
  case 0x10:
    param_2 = param_2 & 0xf0;
    if (param_2 == 0x80) {
      return 9;
    }
    if (param_2 < 0x81) {
      if (param_2 == 0x40) {
        return 5;
      }
      if (param_2 < 0x41) {
        if (param_2 == 0x20) {
          return 3;
        }
        if (param_2 == 0x30) {
          return 4;
        }
        if (param_2 == 0x10) {
          return 2;
        }
      }
      else {
        if (param_2 == 0x60) {
          return 7;
        }
        if (param_2 == 0x70) {
          return 8;
        }
        if (param_2 == 0x50) {
          return 6;
        }
      }
    }
    else {
      if (param_2 == 0xc0) {
        return 0xd;
      }
      if (param_2 < 0xc1) {
        if (param_2 == 0xa0) {
          return 0xb;
        }
        if (param_2 == 0xb0) {
          return 0xc;
        }
        if (param_2 == 0x90) {
          return 10;
        }
      }
      else {
        if (param_2 == 0xe0) {
          return 0xf;
        }
        if (param_2 == 0xf0) {
          return 0x10;
        }
        if (param_2 == 0xd0) {
          return 0xe;
        }
      }
    }
    break;
  case 0x20:
    uVar2 = (param_2 & 0xfffffff8) - 8 & 0xff;
    if (uVar2 < 0xf1) {
      return (int)(char)CSWTCH_368[uVar2];
    }
    break;
  case 0x40:
    uVar2 = (param_2 & 0xfffffffc) - 4 & 0xff;
    if (uVar2 < 0xf9) {
      return (int)(char)CSWTCH_369[uVar2];
    }
  }
  return 1;
}

