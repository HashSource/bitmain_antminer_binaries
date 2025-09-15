
/* WARNING: Unknown calling convention */

_Bool scanfreq_is_all_finished(void)

{
  int chain;
  
  chain = 0;
  while( true ) {
    if (0xf < chain) {
      return true;
    }
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.scan_finished[chain] != true)) break;
    chain = chain + 1;
  }
  return false;
}

