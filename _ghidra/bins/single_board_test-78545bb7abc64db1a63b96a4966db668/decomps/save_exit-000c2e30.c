
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void save_exit(void)

{
  bitmain_power_off();
  clear_all_thread();
  usleep(100000);
  bitmain_power_off();
  usleep(100000);
  chain_reset_low(gChain);
                    /* WARNING: Subroutine does not return */
  exit(0);
}

