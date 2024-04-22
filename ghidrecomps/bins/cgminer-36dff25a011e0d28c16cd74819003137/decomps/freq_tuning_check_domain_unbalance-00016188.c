
/* WARNING: Unknown calling convention */

_Bool freq_tuning_check_domain_unbalance(void)

{
  uint uVar1;
  FILE *pFVar2;
  FILE *pFile_1;
  uint32_t nonce_unbalance_threshold;
  uint32_t domain_nonce_avg;
  FILE *pFile;
  _Bool is_unbalance_happened;
  uint32_t chain_nonce_total;
  int core_domain;
  int domain;
  int chain;
  
  is_unbalance_happened = false;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: Check domain unbalance.\n","freq_tuning.c",0x439,
              "freq_tuning_check_domain_unbalance");
    }
    fclose(pFVar2);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      chain_nonce_total = 0;
      for (domain = 0; domain < 0xc; domain = domain + 1) {
        for (core_domain = 0; core_domain < 4; core_domain = core_domain + 1) {
          chain_nonce_total = chain_nonce_total + domain_nonce_num[chain][domain][core_domain];
        }
      }
      uVar1 = chain_nonce_total / 0x30 >> 1;
      for (domain = 0; domain < 0xc; domain = domain + 1) {
        for (core_domain = 0; core_domain < 4; core_domain = core_domain + 1) {
          if (domain_nonce_num[chain][domain][core_domain] <= uVar1) {
            is_unbalance_happened = true;
            g_chain_unbalance[chain] = '\x01';
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFVar2 = fopen(log_file,"a+");
              if (pFVar2 != (FILE *)0x0) {
                fprintf(pFVar2,
                        "%s:%d:%s: chain[%d] domain[%d] core_domain[%d] unbalance: domain_nonce_num(%d) <= unbalance_threshold(%u)\n"
                        ,"freq_tuning.c",0x457,"freq_tuning_check_domain_unbalance",chain,domain,
                        core_domain,(uint)domain_nonce_num[chain][domain][core_domain],uVar1);
              }
              fclose(pFVar2);
            }
          }
        }
      }
    }
  }
  return is_unbalance_happened;
}

