
/* WARNING: Unknown calling convention */

_Bool is_domain_unbalance(void)

{
  uint uVar1;
  uint32_t uVar2;
  FILE *pFVar3;
  uint uVar4;
  bool bVar5;
  undefined8 uVar6;
  uint32_t domain_nonce [48];
  FILE *pFile;
  uint64_t nonce_unbalance_threshold;
  uint64_t domain_nonce_avg;
  FILE *pFile_1;
  uint32_t core_domain_number;
  uint32_t domain_nonce_check_threshold;
  uint64_t chain_nonce_total;
  uint32_t core_domain;
  uint32_t chain;
  
  domain_nonce_check_threshold = 5000;
  core_domain_number = 0x30;
  chain = 0;
  do {
    if (0xf < chain) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: No Domain unbalance happened.\n","driver-btm-soc.c",0xd89,
                  "is_domain_unbalance");
        }
        fclose(pFVar3);
      }
      return false;
    }
    if (dev->chain_exist[chain] != 0) {
      chain_nonce_total._0_4_ = 0;
      chain_nonce_total._4_4_ = 0;
      for (core_domain = 0; core_domain < core_domain_number; core_domain = core_domain + 1) {
        uVar2 = get_domain_nounce_number(chain,core_domain);
        domain_nonce[core_domain] = uVar2;
        bVar5 = CARRY4((uint)chain_nonce_total,domain_nonce[core_domain]);
        chain_nonce_total._0_4_ = (uint)chain_nonce_total + domain_nonce[core_domain];
        chain_nonce_total._4_4_ = chain_nonce_total._4_4_ + (uint)bVar5;
      }
      uVar6 = __aeabi_uldivmod((uint)chain_nonce_total,chain_nonce_total._4_4_,core_domain_number,0)
      ;
      uVar4 = (uint)((ulonglong)uVar6 >> 0x20);
      uVar1 = (uint)((byte)((ulonglong)uVar6 >> 0x20) & 1) << 0x1f | (uint)uVar6 >> 1;
      if (uVar4 != 0 || domain_nonce_check_threshold <= (uint)uVar6) {
        for (core_domain = 0; core_domain < core_domain_number; core_domain = core_domain + 1) {
          bVar5 = uVar4 >> 1 != 0;
          if ((bVar5 || domain_nonce[core_domain] <= uVar1) &&
              (bVar5 || uVar1 != domain_nonce[core_domain])) {
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFVar3 = fopen(log_file,"a+");
              if (pFVar3 != (FILE *)0x0) {
                fprintf(pFVar3,"%s:%d:%s: Domain unbalance happened!\n","driver-btm-soc.c",0xd83,
                        "is_domain_unbalance");
              }
              fclose(pFVar3);
            }
            return true;
          }
        }
      }
    }
    chain = chain + 1;
  } while( true );
}

