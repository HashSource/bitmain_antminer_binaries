
/* WARNING: Unknown calling convention */

int32_t eeprom_open(uint32_t which_chain)

{
  uint32_t uVar1;
  uint32_t extraout_r2;
  uint32_t uVar2;
  bitmain_eeprom_t *extraout_r3;
  bitmain_eeprom_t *pbVar3;
  iic_init_param_t param;
  
  if (which_chain < 0x10) {
    uVar1 = _g_eeprom_state[which_chain].eeprom_fd;
    if ((uVar1 == 0) || (_g_eeprom_state[which_chain].chain_has_opened == 0)) {
      param.i2c_path = (char *)0x0;
      param.slave_low = (uint8_t)which_chain;
      param.master_addr = 0;
      param.slave_high = '\n';
      param.chain_id = which_chain;
      uVar1 = iic_init(&param);
      pbVar3 = extraout_r3;
      uVar2 = extraout_r2;
      if (-1 < (int)uVar1) {
        pbVar3 = _g_eeprom_state + which_chain;
        uVar2 = 1;
        _g_eeprom_state[which_chain].eeprom_fd = uVar1;
      }
      if (-1 < (int)uVar1) {
        pbVar3->chain_has_opened = uVar2;
      }
    }
  }
  else {
    uVar1 = eeprom_open(which_chain);
  }
  return uVar1;
}

