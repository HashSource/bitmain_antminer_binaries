
char * SSLeay_version(int type)

{
  char *pcVar1;
  
  if (type == 0) {
    return DAT_0008ae24;
  }
  if (type == 3) {
    return DAT_0008ae28;
  }
  if (type == 2) {
    return DAT_0008ae2c;
  }
  if (type != 4) {
    pcVar1 = DAT_0008ae1c;
    if (type == 5) {
      pcVar1 = DAT_0008ae20;
    }
    return pcVar1;
  }
  return DAT_0008ae30;
}

