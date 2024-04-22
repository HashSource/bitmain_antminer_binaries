
/* WARNING: Unknown calling convention */

void freq_tuning_get_domain_nonce_statistics(void)

{
  int iVar1;
  int core_domain;
  int domain;
  int core;
  int asic;
  int chain;
  
  memset(domain_nonce_num,0,0x600);
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      for (asic = 0; asic < 0x30; asic = asic + 1) {
        iVar1 = asic + 3;
        if (-1 < asic) {
          iVar1 = asic;
        }
        for (core = 0; core < 0x2a0; core = core + 1) {
          domain_nonce_num[chain][iVar1 >> 2][core / 0x54] =
               domain_nonce_num[chain][iVar1 >> 2][core / 0x54] +
               (short)asic_core_nonce_num[chain][asic][core];
        }
      }
    }
  }
  return;
}

