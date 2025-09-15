
/* WARNING: Unknown calling convention */

int scanfreq_get_next_freq(void)

{
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.scan_finished[chain] == false)) {
      scanfreq_get_next_freq_chain(chain);
    }
  }
  return chain;
}

