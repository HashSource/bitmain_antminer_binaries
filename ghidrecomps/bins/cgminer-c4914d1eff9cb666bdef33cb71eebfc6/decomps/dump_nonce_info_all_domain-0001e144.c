
/* WARNING: Unknown calling convention */

void dump_nonce_info_all_domain(void)

{
  FILE *pFVar1;
  uint32_t uVar2;
  int iVar3;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_1;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile;
  char *hash_log;
  uint32_t nonce_num;
  uint32_t total_big_domain_nonce_num;
  int inbalance_domain_num_all_chain;
  int inbalance_domain_num_single_chain;
  int domain_id;
  int chain_id;
  
  inbalance_domain_num_all_chain = 0;
  if (3 < log_level) {
    print_crt_time_to_file("/var/log/hash_rate",3);
    pFVar1 = fopen("/var/log/hash_rate","a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: \n dump domain nonce number...\n","driver-btm-soc.c",0x937,
              "dump_nonce_info_all_domain");
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
      total_big_domain_nonce_num = 0;
      inbalance_domain_num_single_chain = 0;
      for (domain_id = 0; domain_id < 0x18; domain_id = domain_id + 1) {
        uVar2 = get_domain_nounce_number(chain_id,domain_id);
        if (3 < log_level) {
          pFVar1 = fopen("/var/log/hash_rate","a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"D[%02d]:%-10d ",domain_id,uVar2);
          }
          fclose(pFVar1);
        }
        total_big_domain_nonce_num = uVar2 + total_big_domain_nonce_num;
        if ((domain_id + 1U & 3) == 0) {
          if (3 < log_level) {
            pFVar1 = fopen("/var/log/hash_rate","a+");
            if (pFVar1 != (FILE *)0x0) {
              iVar3 = domain_id + 3;
              if (-1 < domain_id) {
                iVar3 = domain_id;
              }
              fprintf(pFVar1,"D_BIG[%02d]:%-10d\n",iVar3 >> 2,total_big_domain_nonce_num);
            }
            fclose(pFVar1);
          }
          total_big_domain_nonce_num = 0;
        }
        if (uVar2 == dump_nonce_info_all_domain::nonce_at_domain[chain_id][domain_id]) {
          inbalance_domain_num_single_chain = inbalance_domain_num_single_chain + 1;
          inbalance_domain_num_all_chain = inbalance_domain_num_all_chain + 1;
        }
        dump_nonce_info_all_domain::nonce_at_domain[chain_id][domain_id] = uVar2;
      }
      if (3 < log_level) {
        pFVar1 = fopen("/var/log/hash_rate","a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"chain [%d] inbalance domain number: %d\n",chain_id,
                  inbalance_domain_num_single_chain);
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
      imbalance_domain_count_chain[chain_id] = inbalance_domain_num_single_chain;
    }
  }
  if (3 < log_level) {
    pFVar1 = fopen("/var/log/hash_rate","a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"inbalance domain number of all chain: %d\n",inbalance_domain_num_all_chain);
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
  imbalance_domain_count_total = inbalance_domain_num_all_chain;
  return;
}

