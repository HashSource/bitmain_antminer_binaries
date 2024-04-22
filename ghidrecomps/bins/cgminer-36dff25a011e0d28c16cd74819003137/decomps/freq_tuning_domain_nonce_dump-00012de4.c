
void freq_tuning_domain_nonce_dump(int chain)

{
  FILE *pFVar1;
  int chain_local;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile;
  int domain_total;
  int core_domain;
  int domain;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"chain %d domain_nonce_num:\n",chain);
    }
    fclose(pFVar1);
  }
  for (domain = 0; domain < 0xc; domain = domain + 1) {
    domain_total = 0;
    for (core_domain = 0; core_domain < 4; core_domain = core_domain + 1) {
      domain_total = domain_total + (uint)domain_nonce_num[chain][domain][core_domain];
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"D[%02d]:%04d ",domain * 4 + core_domain,
                  (uint)domain_nonce_num[chain][domain][core_domain]);
        }
        fclose(pFVar1);
      }
    }
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1," D_BIG[%02d]:%05d\n",domain,domain_total);
      }
      fclose(pFVar1);
    }
  }
  return;
}

