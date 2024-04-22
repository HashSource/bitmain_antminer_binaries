
int dump_string(char *str,size_t len,json_dump_callback_t dump,void *data,size_t flags)

{
  char *pcVar1;
  int iVar2;
  void *data_local;
  json_dump_callback_t dump_local;
  size_t len_local;
  char *str_local;
  char seq [13];
  int32_t codepoint;
  int32_t last;
  int32_t first;
  char *lim;
  int length;
  char *text;
  char *end;
  char *pos;
  
  iVar2 = (*dump)("\"",1,data);
  if (iVar2 != 0) {
    return -1;
  }
  lim = str + len;
  pcVar1 = str;
LAB_000938bc:
  pos = pcVar1;
  end = pos;
  if (pos < lim) goto LAB_00093820;
  goto LAB_000938dc;
LAB_00093820:
  end = utf8_iterate(pos,(int)lim - (int)pos,&codepoint);
  if (end == (char *)0x0) {
    return -1;
  }
  if (((((codepoint != 0x5c) && (codepoint != 0x22)) && (0x1f < codepoint)) &&
      (((flags & 0x400) == 0 || (codepoint != 0x2f)))) &&
     ((pcVar1 = end, (flags & 0x40) == 0 || (pcVar1 = end, codepoint < 0x80)))) goto LAB_000938bc;
LAB_000938dc:
  if ((pos != str) && (iVar2 = (*dump)(str,(int)pos - (int)str,data), iVar2 != 0)) {
    return -1;
  }
  if (end == pos) {
    iVar2 = (*dump)("\"",1,data);
    return iVar2;
  }
  length = 2;
  if (codepoint == 0xc) {
    text = "\\f";
    goto LAB_00093acc;
  }
  if (codepoint < 0xd) {
    if (codepoint == 9) {
      text = "\\t";
      goto LAB_00093acc;
    }
    if (codepoint == 10) {
      text = "\\n";
      goto LAB_00093acc;
    }
    if (codepoint == 8) {
      text = "\\b";
      goto LAB_00093acc;
    }
  }
  else {
    if (codepoint == 0x22) {
      text = "\\\"";
      goto LAB_00093acc;
    }
    if (codepoint < 0x23) {
      if (codepoint == 0xd) {
        text = "\\r";
        goto LAB_00093acc;
      }
    }
    else {
      if (codepoint == 0x2f) {
        text = "\\/";
        goto LAB_00093acc;
      }
      if (codepoint == 0x5c) {
        text = "\\\\";
        goto LAB_00093acc;
      }
    }
  }
  if (codepoint < 0x10000) {
    snprintf(seq,0xd,"\\u%04X",codepoint);
    length = 6;
  }
  else {
    codepoint = codepoint - 0x10000;
    first = codepoint >> 10 & 0x3ffU | 0xd800;
    last = codepoint & 0x3ffU | 0xdc00;
    snprintf(seq,0xd,"\\u%04X\\u%04X",first,last);
    length = 0xc;
  }
  text = seq;
LAB_00093acc:
  iVar2 = (*dump)(text,length,data);
  if (iVar2 != 0) {
    return -1;
  }
  pos = end;
  pcVar1 = pos;
  str = end;
  goto LAB_000938bc;
}

