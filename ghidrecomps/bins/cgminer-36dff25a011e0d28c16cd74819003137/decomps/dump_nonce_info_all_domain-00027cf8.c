
/* WARNING: Unknown calling convention */

void dump_nonce_info_all_domain(void)

{
  FILE *pFVar1;
  uint32_t uVar2;
  int iVar3;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_4;
  FILE *pFile_1;
  FILE *pFile;
  char *hash_log;
  uint32_t nonce_num;
  uint32_t total_big_domain_nonce_num;
  int domain_id;
  int chain_id;
  
  if (3 < log_level) {
    pFVar1 = fopen("/var/log/hash_rate","a+");
    if (pFVar1 != (FILE *)0x0) {
      fwrite("\n dump domain nonce number...\n",1,0x1e,pFVar1);
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
      for (domain_id = 0; domain_id < 0x30; domain_id = domain_id + 1) {
        uVar2 = get_domain_nounce_number(chain_id,domain_id);
        if (3 < log_level) {
          pFVar1 = fopen("/var/log/hash_rate","a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"D[%02d]:%-10d ",domain_id,uVar2);
          }
          fclose(pFVar1);
        }
        total_big_domain_nonce_num = total_big_domain_nonce_num + uVar2;
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

