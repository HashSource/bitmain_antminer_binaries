
/* WARNING: Unknown calling convention */

int check_asicnum(int asic_num,uchar nonce)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  
  switch(asic_num) {
  case 1:
    break;
  case 2:
    if ((int)((uint)nonce << 0x18) < 0) {
      return 2;
    }
    break;
  default:
    return 0;
  case 4:
    bVar2 = nonce & 0xc0;
    if (bVar2 == 0x80) {
      return 3;
    }
    if (bVar2 == 0xc0) {
      return 4;
    }
    if (bVar2 == 0x40) {
      iVar1 = 2;
    }
    else {
      iVar1 = 1;
    }
    return iVar1;
  case 8:
    bVar2 = nonce & 0xe0;
    if (bVar2 == 0x80) {
      return 5;
    }
    if (bVar2 < 0x81) {
      if (bVar2 == 0x40) {
        return 3;
      }
      if (bVar2 == 0x60) {
        return 4;
      }
      if (bVar2 == 0x20) {
        return 2;
      }
    }
    else {
      if (bVar2 == 0xc0) {
        return 7;
      }
      if (bVar2 == 0xe0) {
        return 8;
      }
      if (bVar2 == 0xa0) {
        return 6;
      }
    }
    break;
  case 0x10:
    bVar2 = nonce & 0xf0;
    if (bVar2 == 0x80) {
      return 9;
    }
    if (bVar2 < 0x81) {
      if (bVar2 == 0x40) {
        return 5;
      }
      if (bVar2 < 0x41) {
        if (bVar2 == 0x20) {
          return 3;
        }
        if (bVar2 == 0x30) {
          return 4;
        }
        if (bVar2 == 0x10) {
          return 2;
        }
      }
      else {
        if (bVar2 == 0x60) {
          return 7;
        }
        if (bVar2 == 0x70) {
          return 8;
        }
        if (bVar2 == 0x50) {
          return 6;
        }
      }
    }
    else {
      if (bVar2 == 0xc0) {
        return 0xd;
      }
      if (bVar2 < 0xc1) {
        if (bVar2 == 0xa0) {
          return 0xb;
        }
        if (bVar2 == 0xb0) {
          return 0xc;
        }
        if (bVar2 == 0x90) {
          return 10;
        }
      }
      else {
        if (bVar2 == 0xe0) {
          return 0xf;
        }
        if (bVar2 == 0xf0) {
          return 0x10;
        }
        if (bVar2 == 0xd0) {
          return 0xe;
        }
      }
    }
    break;
  case 0x20:
    uVar3 = (uint)(byte)((nonce & 0xf8) - 8);
    if (uVar3 < 0xf1) {
      return (int)*(char *)(DAT_000153d0 + uVar3 + 0x7c8);
    }
    break;
  case 0x40:
    uVar3 = (uint)(byte)((nonce & 0xfc) - 4);
    if (uVar3 < 0xf9) {
      return (int)*(char *)(DAT_000153d0 + uVar3 + 0x8bc);
    }
  }
  return 1;
}

