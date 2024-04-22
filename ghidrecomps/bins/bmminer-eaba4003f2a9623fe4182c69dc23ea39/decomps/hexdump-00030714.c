
void hexdump(uchar *p,uint len)

{
  uint len_local;
  uchar *p_local;
  char tmp42 [2048];
  uchar line [80];
  int pos;
  uchar v;
  uint wordlen;
  uint addr;
  uint i;
  
  wordlen = 4;
  for (addr = 0; addr < len; addr = addr + 0x10) {
    for (i = 0; i < 0x50; i = i + 1) {
      if (((wordlen + 0x1a) * 2 - i == 0) || (wordlen * 2 + 0x45 == i)) {
        line[i] = '|';
      }
      else if ((wordlen + 0x23) * 2 - i == 0) {
        line[i] = '\0';
      }
      else {
        line[i] = ' ';
      }
    }
    for (i = 0; i <= wordlen * 2 && wordlen * 2 - i != 0; i = i + 1) {
      line[i] = nibble[addr >> (((wordlen * 2 - i) + 0x3fffffff) * 4 & 0xff) & 0xf];
    }
    for (i = 0; (i < 0x10 && (pos = wordlen * 2 + (i >> 3) + 3, addr + i < len)); i = i + 1) {
      v = p[addr + i];
      line[i * 3 + pos] = nibble[v >> 4];
      line[i * 3 + pos + 1] = nibble[v & 0xf];
      if ((v < 0x20) || (0x7e < v)) {
        v = '.';
      }
      line[wordlen * 2 + i + 0x35] = v;
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s",line);
      _applog(7,tmp42,false);
    }
  }
  return;
}

