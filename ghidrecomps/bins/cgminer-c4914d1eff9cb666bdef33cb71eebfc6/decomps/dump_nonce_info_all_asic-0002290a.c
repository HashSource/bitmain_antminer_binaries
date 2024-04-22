
/* WARNING: Unknown calling convention */

void dump_nonce_info_all_asic(void)

{
  FILE *pFVar1;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_1;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile;
  char *hash_log;
  uint32_t total_nonce_num;
  int inbalance_asic_num_all_chain;
  int inbalance_asic_num_single_chain;
  uint32_t nounc_num;
  int core_id;
  int chip_id;
  int chain_id;
  
  inbalance_asic_num_all_chain = 0;
  if (3 < log_level) {
    pFVar1 = fopen("/var/log/hash_rate","a+");
    if (pFVar1 != (FILE *)0x0) {
      fwrite("\n dump asic nonce number...\n",1,0x1c,pFVar1);
    }
    fclose(pFVar1);
  }
  for (chain_id = 0; chain_id < 0x10; chain_id = chain_id + 1) {
    if (dev->chain_exist[chain_id] == 1) {
      inbalance_asic_num_single_chain = 0;
      if (3 < log_level) {
        pFVar1 = fopen("/var/log/hash_rate","a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"Chain[%d]:\n",chain_id);
        }
        fclose(pFVar1);
      }
      total_nonce_num = 0;
      for (chip_id = 0; chip_id < 0x3c; chip_id = chip_id + 1) {
        nounc_num = 0;
        for (core_id = 0; core_id < 0xd0; core_id = core_id + 1) {
          nounc_num = nounc_num +
                      calc_nonce_info.chain_asic_core_nonce_num[chain_id][chip_id][core_id];
        }
        if (3 < log_level) {
          pFVar1 = fopen("/var/log/hash_rate","a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"ic[%03d]=%-10d",chip_id,nounc_num);
          }
          fclose(pFVar1);
        }
        if (nounc_num == dump_nonce_info_all_asic::nonce_at_asic[chain_id][chip_id]) {
          inbalance_asic_num_single_chain = inbalance_asic_num_single_chain + 1;
          inbalance_asic_num_all_chain = inbalance_asic_num_all_chain + 1;
        }
        dump_nonce_info_all_asic::nonce_at_asic[chain_id][chip_id] = nounc_num;
        total_nonce_num = nounc_num + total_nonce_num;
        if (((chip_id + 1) % 10 == 0) && (3 < log_level)) {
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
          fprintf(pFVar1,"Chain[%d] inbalance asic number: %d\n",chain_id,
                  inbalance_asic_num_single_chain);
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
  if (3 < log_level) {
    pFVar1 = fopen("/var/log/hash_rate","a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"inbalance asic number of all chain: %d\n",inbalance_asic_num_all_chain);
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
  return;
}

