
/* WARNING: Unknown calling convention */

void btm_check_open_again(void)

{
  int k;
  int j;
  int i;
  
  btm_check_open_again::time = btm_check_open_again::time + 1;
  if (first_time == 1) {
    if (btm_check_open_again::time < 0x12) {
      return;
    }
    first_time = 0;
  }
  if (2 < btm_check_open_again::time) {
    btm_check_open_again::time = 0;
    for (k = 0; k < 0x10; k = k + 1) {
      if (dev->chain_exist[k] == 1) {
        for (i = 0; i < 0x6c; i = i + 1) {
          for (j = 0; j < 0xd0; j = j + 1) {
            if (asic_core_nonce_num_chain[k][i][j] == 0) {
              btm_reopen_core_again(i,j,k);
            }
          }
        }
      }
    }
  }
  return;
}

