
/* WARNING: Unknown calling convention */

void scan_freq_reset_scan_mark(void)

{
  low_rate_error = 0;
  low_rate_error_now = false;
  first_time_init = true;
  memset(freq_adjust_record,0,0x180);
  cgsleep_ms(10);
  memset(calc_ability,0,0x50);
  memset(calc_ability_per_chain,0,0x500);
  memset(calc_ability_per_chain_recode,0,0x40);
  cgsleep_ms(10);
  memset(&scanfreq_calc_nonce_info,0,0xc3f44);
  cgsleep_ms(10);
  low_rate_error = 0;
  return;
}

