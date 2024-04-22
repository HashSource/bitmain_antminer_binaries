
/* WARNING: Unknown calling convention */

void saveTestID(int testID)

{
  FILE *__s;
  FILE *fd;
  char testnumStr [32];
  
  __s = fopen(DAT_000339ac,DAT_000339a8);
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
    testnumStr[11] = '\0';
    testnumStr[12] = '\0';
    testnumStr[13] = '\0';
    testnumStr[14] = '\0';
    testnumStr[15] = '\0';
    testnumStr[16] = '\0';
    testnumStr[17] = '\0';
    testnumStr[18] = '\0';
    testnumStr[19] = '\0';
    testnumStr[20] = '\0';
    testnumStr[21] = '\0';
    testnumStr[22] = '\0';
    testnumStr[23] = '\0';
    testnumStr[24] = '\0';
    testnumStr[25] = '\0';
    testnumStr[26] = '\0';
    testnumStr[27] = '\0';
    testnumStr[28] = '\0';
    testnumStr[29] = '\0';
    testnumStr[30] = '\0';
    testnumStr[31] = '\0';
    sprintf(testnumStr,DAT_000339b0,testID);
    fwrite(testnumStr,1,0x20,__s);
    fclose(__s);
  }
  return;
}

