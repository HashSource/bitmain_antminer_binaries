
void PEM_proc_type(char *buf,int type)

{
  char *src;
  
  src = DAT_000bd9f0;
  if (((type != 10) && (src = DAT_000bd9f4, type != 0x1e)) && (src = DAT_000bd9e0, type == 0x14)) {
    src = DAT_000bd9e4;
  }
  BUF_strlcat(buf,DAT_000bd9e8,0x400);
  BUF_strlcat(buf,src,0x400);
  BUF_strlcat(buf,DAT_000bd9ec,0x400);
  return;
}

