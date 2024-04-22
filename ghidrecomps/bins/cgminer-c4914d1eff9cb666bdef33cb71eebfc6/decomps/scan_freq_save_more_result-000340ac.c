
void scan_freq_save_more_result(working_mode_e working_mode)

{
  uint8_t chain_00;
  _Bool _Var1;
  FILE *pFVar2;
  double in_stack_ffffffc8;
  working_mode_e working_mode_local;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      chain_00 = (uint8_t)chain;
      if (working_mode == MODE1) {
        _Var1 = eeprom_set_hashrate_mode1
                          (chain_00,(uint)(0.0 < calc_ability_per_chain[scanfreq_best_times][chain])
                                    * (int)calc_ability_per_chain[scanfreq_best_times][chain]);
        if (!_Var1) {
          stop_scan(3,chain_00);
        }
      }
      else {
        _Var1 = eeprom_set_hashrate_mode2
                          (chain_00,(uint)(0.0 < calc_ability_per_chain[scanfreq_best_times][chain])
                                    * (int)calc_ability_per_chain[scanfreq_best_times][chain]);
        if (!_Var1) {
          stop_scan(3,chain_00);
        }
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"chain[%d]\n",chain);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"vol num = %d\n",(uint)(byte)inbalance_info[chain].len);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          in_stack_ffffffc8 =
               (double)(ulonglong)
                       CONCAT14(inbalance_info[chain].vol3,(uint)(byte)inbalance_info[chain].vol2);
          fprintf(pFVar2,"inbalance vol = %d,%d,%d,%d\n",(uint)(byte)inbalance_info[chain].vol0,
                  (uint)(byte)inbalance_info[chain].vol1);
        }
        fclose(pFVar2);
      }
      if ((working_mode == MODE1) &&
         (_Var1 = eeprom_set_inbalance_info
                            (chain_00,(uint8_t *)(inbalance_info + chain),
                             (uint)(byte)inbalance_info[chain].len), !_Var1)) {
        stop_scan(3,chain_00);
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          in_stack_ffffffc8 = get_working_voltage_by_chain(chain_00);
          fprintf(pFVar2,"chain[%d] working vol = %.2f\n",chain);
        }
        fclose(pFVar2);
      }
      if (working_mode == MODE1) {
        get_working_voltage_by_chain(chain_00);
        _Var1 = eeprom_set_voltage_mode1(chain_00,in_stack_ffffffc8);
        if (!_Var1) {
          stop_scan(3,chain_00);
        }
      }
      else {
        get_working_voltage_by_chain(chain_00);
        _Var1 = eeprom_set_voltage_mode2(chain_00,in_stack_ffffffc8);
        if (!_Var1) {
          stop_scan(3,chain_00);
        }
      }
    }
  }
  return;
}

