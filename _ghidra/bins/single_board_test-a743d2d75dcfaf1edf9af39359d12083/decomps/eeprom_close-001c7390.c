
/* WARNING: Unknown calling convention */

void eeprom_close(uint32_t which_chain)

{
  char tmp42 [2048];
  
  if (which_chain < 0x10) {
    if ((_g_eeprom_state[which_chain].eeprom_fd != 0) ||
       (_g_eeprom_state[which_chain].chain_has_opened != 0)) {
      iic_uninit(_g_eeprom_state[which_chain].eeprom_fd);
      _g_eeprom_state[which_chain].chain_has_opened = 0;
      _g_eeprom_state[which_chain].eeprom_fd = 0;
    }
    return;
  }
  snprintf(tmp42,0x800,"%s: Bad eeprom param, input chain is %d\n","eeprom_close",which_chain);
  _applog(0,tmp42,false);
  return;
}

