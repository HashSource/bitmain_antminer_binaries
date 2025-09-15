
void saveTestID(int testID)

{
  FILE *__s;
  int testID_local;
  char testnumStr [32];
  FILE *fd;
  
  __s = fopen("/tmp/testID","wb");
  if (__s != (FILE *)0x0) {
    memset(testnumStr,0,0x20);
    sprintf(testnumStr,"%d",testID);
    fwrite(testnumStr,1,0x20,__s);
    fclose(__s);
  }
  return;
}

