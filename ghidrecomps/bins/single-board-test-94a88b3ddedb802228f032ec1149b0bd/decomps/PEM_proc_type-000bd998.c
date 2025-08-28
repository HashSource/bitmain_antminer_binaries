
void PEM_proc_type(char *buf,int type)

{
  char *src;
  
  if (type == 10) {
    src = "ENCRYPTED";
  }
  else if (type == 0x1e) {
    src = "MIC-CLEAR";
  }
  else {
    src = "BAD-TYPE";
    if (type == 0x14) {
      src = "MIC-ONLY";
    }
  }
  BUF_strlcat(buf,"Proc-Type: 4,",0x400);
  BUF_strlcat(buf,src,0x400);
  BUF_strlcat(buf,"\n",0x400);
  return;
}

