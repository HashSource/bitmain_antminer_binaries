
int UTF8_getc(uchar *str,int len,ulong *val)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  
  if (len < 1) {
    return 0;
  }
  uVar2 = (uint)*str;
  if ((*str & 0x80) == 0) {
    uVar3 = uVar2 & 0x7f;
    iVar1 = 1;
  }
  else if ((uVar2 & 0xe0) == 0xc0) {
    if (len == 1) {
      return -1;
    }
    if ((str[1] & 0xc0) != 0x80) {
      return -3;
    }
    uVar3 = str[1] & 0x3f | (uVar2 & 0x1f) << 6;
    if (uVar3 < 0x80) {
      return -4;
    }
    iVar1 = 2;
  }
  else if ((uVar2 & 0xf0) == 0xe0) {
    if (len < 3) {
      return -1;
    }
    if ((str[1] & 0xc0) != 0x80) {
      return -3;
    }
    if ((str[2] & 0xc0) != 0x80) {
      return -3;
    }
    uVar3 = (uVar2 & 0xf) << 0xc | (str[1] & 0x3f) << 6 | str[2] & 0x3f;
    if (uVar3 < 0x800) {
      return -4;
    }
    iVar1 = 3;
  }
  else if ((uVar2 & 0xf8) == 0xf0) {
    if (len < 4) {
      return -1;
    }
    if ((str[1] & 0xc0) != 0x80) {
      return -3;
    }
    if ((str[2] & 0xc0) != 0x80) {
      return -3;
    }
    if ((str[3] & 0xc0) != 0x80) {
      return -3;
    }
    uVar3 = str[3] & 0x3f | (uVar2 & 7) << 0x12 | (str[1] & 0x3f) << 0xc | (str[2] & 0x3f) << 6;
    if (uVar3 < 0x10000) {
      return -4;
    }
    iVar1 = 4;
  }
  else if ((uVar2 & 0xfc) == 0xf8) {
    if (len < 5) {
      return -1;
    }
    if ((str[1] & 0xc0) != 0x80) {
      return -3;
    }
    if ((str[2] & 0xc0) != 0x80) {
      return -3;
    }
    if ((str[3] & 0xc0) != 0x80) {
      return -3;
    }
    if ((str[4] & 0xc0) != 0x80) {
      return -3;
    }
    uVar3 = (str[1] & 0x3f) << 0x12 | (uVar2 & 3) << 0x18 | str[4] & 0x3f | (str[2] & 0x3f) << 0xc |
            (str[3] & 0x3f) << 6;
    if (uVar3 < 0x200000) {
      return -4;
    }
    iVar1 = 5;
  }
  else {
    if ((uVar2 & 0xfe) != 0xfc) {
      return -2;
    }
    if (len < 6) {
      return -1;
    }
    if (((((str[1] & 0xc0) != 0x80) || ((str[2] & 0xc0) != 0x80)) || ((str[3] & 0xc0) != 0x80)) ||
       (((str[4] & 0xc0) != 0x80 || ((str[5] & 0xc0) != 0x80)))) {
      return -3;
    }
    uVar3 = str[5] & 0x3f | (uint)(str[1] & 0x3f) << 0x18 | (uVar2 & 1) << 0x1e |
            (str[2] & 0x3f) << 0x12 | (str[3] & 0x3f) << 0xc | (str[4] & 0x3f) << 6;
    if (uVar3 < 0x4000000) {
      return -4;
    }
    iVar1 = 6;
  }
  *val = uVar3;
  return iVar1;
}

