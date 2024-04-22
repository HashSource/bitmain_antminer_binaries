
int boardsweep_start(working_mode_e working_mode)

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
  
  bVar1 = dev->chain_num;
  chain_count = 0;
  while( true ) {
    if ((int)(uint)bVar1 <= chain_count) {
      check_chain();
      boardsweep_get_ideal_hashrate(working_mode);
      sweep_freq_save_result(working_mode);
      _Var2 = eeprom_save();
      if (_Var2) {
        freq_scan_set_state();
        iVar3 = 0;
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
        fprintf(__stream,"%s:%d:%s: sweep for %d chain\n","freq_scan.c",0x1041,"boardsweep_start",
                chain_count);
      }
      fclose(__stream);
    }
    sweep_set_current_chain(chain_count);
    iVar3 = boardsweep_get_chip_max_freq(working_mode);
    if (iVar3 != 0) break;
    scan_freq_stop_hash_board();
    chain_count = chain_count + 1;
  }
  return iVar3;
}

