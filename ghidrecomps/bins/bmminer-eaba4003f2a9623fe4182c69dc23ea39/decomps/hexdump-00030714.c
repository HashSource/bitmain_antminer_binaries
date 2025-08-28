
void hexdump(uchar *p,uint len)

{
  byte bVar1;
  int iVar2;
  uint len_local;
  uchar *p_local;
  char tmp42 [2048];
  uchar line [80];
  int pos;
  uchar v;
  uint wordlen;
  uint addr;
  uint i;
  
  for (addr = 0; addr < len; addr = addr + 0x10) {
    for (i = 0; i < 0x50; i = i + 1) {
      if ((i == 0x3c) || (i == 0x4d)) {
        line[i] = '|';
      }
      else if (i == 0x4e) {
        line[0x4e] = '\0';
      }
      else {
        line[i] = ' ';
      }
    }
    for (i = 0; i < 8; i = i + 1) {
      line[i] = nibble[addr >> ((0x40000007 - i) * 4 & 0xff) & 0xf];
    }
    for (i = 0; (i < 0x10 && (iVar2 = (i >> 3) + 0xb, addr + i < len)); i = i + 1) {
      bVar1 = p[addr + i];
      line[i * 3 + iVar2] = nibble[bVar1 >> 4];
      line[i * 3 + iVar2 + 1] = nibble[bVar1 & 0xf];
      if ((bVar1 < 0x20) || (0x7e < bVar1)) {
        bVar1 = 0x2e;
      }
      line[i + 0x3d] = bVar1;
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s",line);
      _applog(7,tmp42,false);
    }
  }
  return;
}

