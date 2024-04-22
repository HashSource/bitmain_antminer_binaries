
/* WARNING: Unknown calling convention */

void clear_test_ID(void)

{
  FILE *__s;
  char testnumStr [32];
  FILE *fd;
  
  __s = fopen("/tmp/testID","wb");
  if (__s != (FILE *)0x0) {
    memset(testnumStr,0,0x20);
    sprintf(testnumStr,"%d",0);
    fwrite(testnumStr,1,0x20,__s);
    fclose(__s);
  }
  return;
}

