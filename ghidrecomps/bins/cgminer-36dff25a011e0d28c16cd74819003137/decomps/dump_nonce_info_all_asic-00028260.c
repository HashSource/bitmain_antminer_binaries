
/* WARNING: Unknown calling convention */

void dump_nonce_info_all_asic(void)

{
  FILE *pFVar1;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_1;
  FILE *pFile;
  char *hash_log;
  uint32_t total_nonce_num;
  uint32_t nounc_num;
  int core_id;
  int chip_id;
  int chain_id;
  
  if (3 < log_level) {
    pFVar1 = fopen("/var/log/hash_rate","a+");
    if (pFVar1 != (FILE *)0x0) {
      fwrite("\n dump asic nonce number...\n",1,0x1c,pFVar1);
    }
    fclose(pFVar1);
  }
  for (chain_id = 0; chain_id < 0x10; chain_id = chain_id + 1) {
    if (dev->chain_exist[chain_id] == 1) {
      if (3 < log_level) {
        pFVar1 = fopen("/var/log/hash_rate","a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"Chain[%d]:\n",chain_id);
        }
        fclose(pFVar1);
      }
      total_nonce_num = 0;
      for (chip_id = 0; chip_id < 0x30; chip_id = chip_id + 1) {
        nounc_num = 0;
        for (core_id = 0; core_id < 0x2a0; core_id = core_id + 1) {
          nounc_num = nounc_num +
                      calc_nonce_info.chain_asic_core_nonce_num[chain_id][chip_id][core_id];
        }
        if (3 < log_level) {
          pFVar1 = fopen("/var/log/hash_rate","a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"ic[%02d]=%-10d",chip_id,nounc_num);
          }
          fclose(pFVar1);
        }
        total_nonce_num = total_nonce_num + nounc_num;
        if (((chip_id + 1U & 3) == 0) && (3 < log_level)) {
          pFVar1 = fopen("/var/log/hash_rate","a+");
          if (pFVar1 != (FILE *)0x0) {
            fputc(10,pFVar1);
          }
          fclose(pFVar1);
        }
      }
      if (3 < log_level) {
        pFVar1 = fopen("/var/log/hash_rate","a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"Chain[%d] total nonce number = %d\n",chain_id,total_nonce_num);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen("/var/log/hash_rate","a+");
        if (pFVar1 != (FILE *)0x0) {
          fputc(10,pFVar1);
        }
        fclose(pFVar1);
      }
    }
  }
  return;
}

