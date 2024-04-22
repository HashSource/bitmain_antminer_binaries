
void hexdump(uchar *p,uint len)

{
  byte bVar1;
  uint uVar2;
  undefined auStack_98 [80];
  uint len_local;
  uchar *p_local;
  int pos;
  uchar v;
  uchar_0_ *line;
  undefined4 local_30;
  uint wordlen;
  uint addr;
  uint i;
  
  wordlen = 4;
  local_30 = 0x4f;
  line = auStack_98;
  len_local = len;
  p_local = p;
  for (addr = 0; addr < len_local; addr = addr + 0x10) {
    for (i = 0; i < 0x50; i = i + 1) {
      if (((wordlen + 0x1a) * 2 - i == 0) || (wordlen * 2 + 0x45 == i)) {
        line[i] = 0x7c;
      }
      else if ((wordlen + 0x23) * 2 - i == 0) {
        line[i] = 0;
      }
      else {
        line[i] = 0x20;
      }
    }
    for (i = 0; i <= wordlen * 2 && wordlen * 2 - i != 0; i = i + 1) {
      uVar2 = addr >> (((wordlen * 2 - i) + 0x3fffffff) * 4 & 0xff);
      v = (uchar)uVar2;
      line[i] = nibble[uVar2 & 0xf];
    }
    for (i = 0; (i < 0x10 && (pos = (i >> 3) + wordlen * 2 + 3, addr + i < len_local)); i = i + 1) {
      v = p_local[i + addr];
      line[i * 3 + pos] = nibble[v >> 4];
      line[pos + i * 3 + 1] = nibble[v & 0xf];
      if ((v < 0x20) || (bVar1 = v, 0x7e < v)) {
        bVar1 = 0x2e;
      }
      line[i + wordlen * 2 + 0x35] = bVar1;
    }
    fprintf(stderr,"%s\n",line);
  }
  return;
}

