
/* WARNING: Unknown calling convention */

void dump_nonce_info_all_core(void)

{
  int j;
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      for (j = 0; j < 0x30; j = j + 1) {
        dump_nonce_info_one_asic(i,j);
      }
    }
  }
  return;
}

