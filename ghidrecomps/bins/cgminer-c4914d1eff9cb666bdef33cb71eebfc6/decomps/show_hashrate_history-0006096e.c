
/* WARNING: Unknown calling convention */

void show_hashrate_history(void)

{
  FILE *pFVar1;
  int extraout_r1;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile_3;
  FILE *pFile;
  uint32_t raw;
  uint32_t i;
  
  if (3 < log_level) {
    pFVar1 = fopen(hash_log,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fwrite("Unit:THash\n",1,0xb,pFVar1);
    }
    fclose(pFVar1);
  }
  for (i = 0; i < 0x41; i = i + 1) {
    if (3 < log_level) {
      pFVar1 = fopen(hash_log,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"hash[%02d]:%9.0f   ",i,*(undefined4 *)(thashrate_array + i),
                *(undefined4 *)(thashrate_array + i),
                *(undefined4 *)((int)thashrate_array + i * 8 + 4));
      }
      fclose(pFVar1);
    }
    __aeabi_uidivmod(i + 1,5);
    if ((extraout_r1 == 0) && (3 < log_level)) {
      pFVar1 = fopen(hash_log,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fputc(10,pFVar1);
      }
      fclose(pFVar1);
    }
  }
  if (3 < log_level) {
    pFVar1 = fopen(hash_log,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fputc(10,pFVar1);
    }
    fclose(pFVar1);
  }
  return;
}

