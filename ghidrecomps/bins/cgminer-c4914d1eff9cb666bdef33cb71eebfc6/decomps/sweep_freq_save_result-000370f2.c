
/* WARNING: Variable defined which should be unmapped: working_mode-local */

void sweep_freq_save_result(working_mode_e working_mode)

{
  _Bool _Var1;
  uint8_t chain_00;
  uint uStack_20;
  working_mode_e working_mode_local;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      chain_00 = (uint8_t)chain;
      if (working_mode == MODE1) {
        _Var1 = eeprom_set_freq_mode1(chain_00,(uint32_t *)(scanfreq_info.final_chip_freq + chain));
        if (!_Var1) {
          stop_scan(3,chain_00);
        }
        get_working_voltage_by_chain(chain_00);
        _Var1 = eeprom_set_voltage_mode1(chain_00,(double)(ulonglong)uStack_20);
        if (!_Var1) {
          stop_scan(3,chain_00);
        }
        _Var1 = eeprom_set_hashrate_mode1(chain_00,scanfreq_info.ideal_hashrate[chain]);
        if (!_Var1) {
          stop_scan(3,chain_00);
        }
      }
      else {
        _Var1 = eeprom_set_freq_mode2(chain_00,(uint32_t *)(scanfreq_info.final_chip_freq + chain));
        if (!_Var1) {
          stop_scan(3,chain_00);
        }
        get_working_voltage_by_chain(chain_00);
        _Var1 = eeprom_set_voltage_mode2(chain_00,(double)CONCAT44(working_mode,uStack_20));
        if (!_Var1) {
          stop_scan(3,chain_00);
        }
        _Var1 = eeprom_set_hashrate_mode2(chain_00,scanfreq_info.ideal_hashrate[chain]);
        if (!_Var1) {
          stop_scan(3,chain_00);
        }
      }
    }
  }
  return;
}

