
char * ASN1_tag2str(int tag)

{
  char *pcVar1;
  
  if ((tag & 0xfffffff7U) == 0x102) {
    tag = tag & 0xfffffeff;
  }
  if ((uint)tag < 0x1f) {
    pcVar1 = *(char **)(&tag2str_9369 + tag * 4);
  }
  else {
    pcVar1 = "(unknown)";
  }
  return pcVar1;
}

