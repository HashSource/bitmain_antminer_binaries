
void PEM_proc_type(char *buf,int type)

{
  size_t sVar1;
  char *pcVar2;
  
  sVar1 = strlen(buf);
  if (type == 10) {
    pcVar2 = "ENCRYPTED";
  }
  else if (type == 0x1e) {
    pcVar2 = "MIC-CLEAR";
  }
  else if (type == 0x14) {
    pcVar2 = "MIC-ONLY";
  }
  else {
    pcVar2 = "BAD-TYPE";
  }
  BIO_snprintf(buf + sVar1,0x400 - sVar1,"Proc-Type: 4,%s\n",pcVar2);
  return;
}

