
/* WARNING: Unknown calling convention */

_Bool is_domain_unbalance(void)

{
  uint32_t uVar1;
  FILE *pFVar2;
  uint uVar3;
  bool bVar4;
  undefined8 uVar5;
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
  
  chain = 0;
  do {
    if (0xf < chain) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: No Domain unbalance happened.\n","driver-btm-soc.c",0xd89,
                  "is_domain_unbalance");
        }
        fclose(pFVar2);
      }
      return false;
    }
    if (dev->chain_exist[chain] != 0) {
      chain_nonce_total._0_4_ = 0;
      chain_nonce_total._4_4_ = 0;
      for (core_domain = 0; core_domain < 0x30; core_domain = core_domain + 1) {
        uVar1 = get_domain_nounce_number(chain,core_domain);
        domain_nonce[core_domain] = uVar1;
        bVar4 = CARRY4((uint)chain_nonce_total,domain_nonce[core_domain]);
        chain_nonce_total._0_4_ = (uint)chain_nonce_total + domain_nonce[core_domain];
        chain_nonce_total._4_4_ = chain_nonce_total._4_4_ + (uint)bVar4;
      }
      uVar5 = __aeabi_uldivmod((uint)chain_nonce_total,chain_nonce_total._4_4_,0x30,0);
      uVar3 = (uint)((ulonglong)uVar5 >> 0x20);
      if (uVar3 != 0 || 4999 < (uint)uVar5) {
        for (core_domain = 0; core_domain < 0x30; core_domain = core_domain + 1) {
          if (uVar3 >> 1 != 0 ||
              domain_nonce[core_domain] <
              ((uint)((byte)((ulonglong)uVar5 >> 0x20) & 1) << 0x1f | (uint)uVar5 >> 1)) {
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFVar2 = fopen(log_file,"a+");
              if (pFVar2 != (FILE *)0x0) {
                fprintf(pFVar2,"%s:%d:%s: Domain unbalance happened!\n","driver-btm-soc.c",0xd83,
                        "is_domain_unbalance");
              }
              fclose(pFVar2);
            }
            return true;
          }
        }
      }
    }
    chain = chain + 1;
  } while( true );
}

