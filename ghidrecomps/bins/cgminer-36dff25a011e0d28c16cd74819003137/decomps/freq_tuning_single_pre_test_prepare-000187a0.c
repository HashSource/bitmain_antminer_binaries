
/* WARNING: Unknown calling convention */

void freq_tuning_single_pre_test_prepare(void)

{
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      set_reset_hashboard(chain,1);
      sleep(3);
      set_reset_hashboard(chain,0);
      sleep(3);
    }
  }
  set_iic_power_to_highest_voltage();
  set_baud(0x1c200,1);
  cgsleep_ms(10);
  balance_domain_voltage();
  init_uart_baud();
  cgsleep_ms(10);
  software_set_address();
  cgsleep_ms(10);
  set_asic_ticket_mask(ticket_mask);
  cgsleep_ms(10);
  set_pll(init_freq);
  set_timeout((int)init_freq,0x5a);
  open_core_bm1391(true,All_Chain);
  return;
}

