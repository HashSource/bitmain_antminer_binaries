
void _eeprom_dump_raw(uint8_t *buf,int len)

{
  FILE *pFVar1;
  uint uVar2;
  int len_local;
  uint8_t *buf_local;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int i;
  
  for (i = 0; i < len; i = i + 1) {
    if (((i & 0xfU) == 0) && (3 < log_level)) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"0x%04X ",i);
      }
      fclose(pFVar1);
    }
    uVar2 = i & 0xf;
    if (i < 1) {
      uVar2 = -(-i & 0xfU);
    }
    if ((uVar2 == 8) && (3 < log_level)) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fwrite(&DAT_000abb28,1,2,pFVar1);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%02X ",(uint)buf[i]);
      }
      fclose(pFVar1);
    }
    uVar2 = i & 0xf;
    if (i < 1) {
      uVar2 = -(-i & 0xfU);
    }
    if ((uVar2 == 0xf) && (3 < log_level)) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fputc(10,pFVar1);
      }
      fclose(pFVar1);
    }
  }
  return;
}

