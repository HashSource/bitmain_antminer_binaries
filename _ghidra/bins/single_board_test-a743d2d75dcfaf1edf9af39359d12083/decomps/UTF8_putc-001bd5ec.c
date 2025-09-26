
int UTF8_putc(uchar *str,int len,ulong value)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = (byte)value;
  if (str == (uchar *)0x0) {
    if (value < 0x80) {
      return 1;
    }
    if (value < 0x800) {
      return 2;
    }
    len = 6;
  }
  else {
    if (len < 1) {
      return -1;
    }
    if (value < 0x80) {
      *str = bVar1;
      return 1;
    }
    if (value < 0x800) {
      if (len == 1) {
        return -1;
      }
      str[1] = bVar1 & 0x3f | 0x80;
      *str = (byte)(value >> 6) | 0xc0;
      return 2;
    }
  }
  if (value < 0x10000) {
    if (2 < len) {
      if (str != (uchar *)0x0) {
        *str = (byte)(value >> 0xc) | 0xe0;
        str[1] = (byte)((value << 0x14) >> 0x1a) | 0x80;
        str[2] = bVar1 & 0x3f | 0x80;
        return 3;
      }
      return 3;
    }
  }
  else if (value < 0x200000) {
    if (3 < len) {
      if (str != (uchar *)0x0) {
        str[1] = (byte)((value << 0xe) >> 0x1a) | 0x80;
        *str = (byte)(value >> 0x12) | 0xf0;
        str[2] = (byte)((value << 0x14) >> 0x1a) | 0x80;
        str[3] = bVar1 & 0x3f | 0x80;
        return 4;
      }
      return 4;
    }
  }
  else {
    bVar2 = (byte)(value >> 0x10);
    if (value < 0x4000000) {
      if (4 < len) {
        if (str != (uchar *)0x0) {
          str[1] = bVar2 >> 2 | 0x80;
          *str = (byte)(value >> 0x18) | 0xf8;
          str[2] = (byte)((value << 0xe) >> 0x1a) | 0x80;
          str[3] = (byte)((value << 0x14) >> 0x1a) | 0x80;
          str[4] = bVar1 & 0x3f | 0x80;
          return 5;
        }
        return 5;
      }
    }
    else if (5 < len) {
      if (str != (uchar *)0x0) {
        *str = (byte)((value << 1) >> 0x1f) | 0xfc;
        str[1] = (byte)((value << 2) >> 0x1a) | 0x80;
        str[2] = bVar2 >> 2 | 0x80;
        str[3] = (byte)((value << 0xe) >> 0x1a) | 0x80;
        str[4] = (byte)((value << 0x14) >> 0x1a) | 0x80;
        str[5] = bVar1 & 0x3f | 0x80;
        return 6;
      }
      return 6;
    }
  }
  return -1;
}

