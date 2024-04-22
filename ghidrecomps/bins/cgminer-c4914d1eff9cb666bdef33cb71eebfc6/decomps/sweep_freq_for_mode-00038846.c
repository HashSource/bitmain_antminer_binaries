
int sweep_freq_for_mode(working_mode_e working_mode)

{
  byte bVar1;
  _Bool _Var2;
  FILE *__stream;
  int iVar3;
  working_mode_e working_mode_local;
  FILE *pFile;
  int chain_num;
  int ret;
  int chain_count;
  
  asic_sweep_stat_start();
  bVar1 = dev->chain_num;
  chain_count = 0;
  while( true ) {
    if ((int)(uint)bVar1 <= chain_count) {
      check_chain();
      sweep_fix_ideal_rate();
      sweep_freq_save_result(working_mode);
      _Var2 = eeprom_save();
      if (_Var2) {
        iVar3 = asic_sweep_stat_end();
        if (iVar3 == 0) {
          freq_scan_set_state();
          iVar3 = 0;
        }
      }
      else {
        iVar3 = -1;
      }
      return iVar3;
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: sweep for %d chain\n","freq_scan.c",0xe3c,"sweep_freq_for_mode",
                chain_count);
      }
      fclose(__stream);
    }
    sweep_set_current_chain(chain_count);
    iVar3 = sweep_freq_get_chip_max_freq(working_mode);
    if (iVar3 != 0) break;
    sweep_freq_balance_domain_freq();
    sweep_freq_decrease_freq(working_mode);
    iVar3 = sweep_freq_get_ideal_hashrate(working_mode);
    if (iVar3 != 0) {
      return iVar3;
    }
    scan_freq_stop_hash_board();
    chain_count = chain_count + 1;
  }
  return iVar3;
}

