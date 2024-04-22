
/* WARNING: Unknown calling convention */

int freq_scan_get_sale_hash_rate(void)

{
  int hash_rate_ideal;
  int chain;
  
  hash_rate_ideal = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      hash_rate_ideal = scanfreq_info.ideal_hashrate[chain] + hash_rate_ideal;
    }
  }
  return ((hash_rate_ideal + -100) / 500) * 500;
}

