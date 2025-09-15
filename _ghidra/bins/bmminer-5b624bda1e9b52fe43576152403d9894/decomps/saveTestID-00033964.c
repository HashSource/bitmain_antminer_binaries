
/* WARNING: Unknown calling convention */

void saveTestID(int testID)

{
  FILE *__s;
  char testnumStr [32];
  
  __s = fopen("/etc/config/testID","wb");
  if (__s != (FILE *)0x0) {
    testnumStr[0] = '\0';
    testnumStr[1] = '\0';
    testnumStr[2] = '\0';
    testnumStr[3] = '\0';
    testnumStr[4] = '\0';
    testnumStr[5] = '\0';
    testnumStr[6] = '\0';
    testnumStr[7] = '\0';
    testnumStr[8] = '\0';
    testnumStr[9] = '\0';
    testnumStr[10] = '\0';
    testnumStr[0xb] = '\0';
    testnumStr[0xc] = '\0';
    testnumStr[0xd] = '\0';
    testnumStr[0xe] = '\0';
    testnumStr[0xf] = '\0';
    testnumStr[0x10] = '\0';
    testnumStr[0x11] = '\0';
    testnumStr[0x12] = '\0';
    testnumStr[0x13] = '\0';
    testnumStr[0x14] = '\0';
    testnumStr[0x15] = '\0';
    testnumStr[0x16] = '\0';
    testnumStr[0x17] = '\0';
    testnumStr[0x18] = '\0';
    testnumStr[0x19] = '\0';
    testnumStr[0x1a] = '\0';
    testnumStr[0x1b] = '\0';
    testnumStr[0x1c] = '\0';
    testnumStr[0x1d] = '\0';
    testnumStr[0x1e] = '\0';
    testnumStr[0x1f] = '\0';
    sprintf(testnumStr,"%d",testID);
    fwrite(testnumStr,1,0x20,__s);
    fclose(__s);
  }
  return;
}

