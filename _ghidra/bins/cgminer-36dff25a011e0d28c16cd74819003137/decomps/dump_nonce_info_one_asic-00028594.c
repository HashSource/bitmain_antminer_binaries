
void dump_nonce_info_one_asic(uint32_t chain,uint32_t asic_id)

{
  FILE *pFVar1;
  uint32_t asic_id_local;
  uint32_t chain_local;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile_3;
  FILE *pFile;
  char *hash_log;
  int core_id;
  
  if (3 < log_level) {
    pFVar1 = fopen("/var/log/hash_rate","a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"\n asic nonce number for chain[%d] asic[%d]...\n",chain,asic_id);
    }
    fclose(pFVar1);
  }
  for (core_id = 0; core_id < 0x2a0; core_id = core_id + 1) {
    if (3 < log_level) {
      pFVar1 = fopen("/var/log/hash_rate","a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"core[%03d]=%-8d",core_id,
                calc_nonce_info.chain_asic_core_nonce_num[chain][asic_id][core_id]);
      }
      fclose(pFVar1);
    }
    if (((core_id + 1) % 10 == 0) && (3 < log_level)) {
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
      fputc(10,pFVar1);
    }
    fclose(pFVar1);
  }
  return;
}

