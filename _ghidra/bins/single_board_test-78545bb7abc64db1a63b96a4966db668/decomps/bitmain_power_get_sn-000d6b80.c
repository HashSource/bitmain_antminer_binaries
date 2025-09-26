
/* WARNING: Unknown calling convention */

char * bitmain_power_get_sn(void)

{
  int32_t iVar1;
  char *pcVar2;
  _Bool is_calibrated;
  
  iVar1 = bitmain_power_is_calibrated(&is_calibrated);
  if (iVar1 == 0) {
    pcVar2 = "NOSNGOT0000000000";
    if (is_calibrated != false) {
      pcVar2 = _g_power_state.eeprom.sn;
    }
    return ((eeprom_data_t *)pcVar2)->sn;
  }
  return "NOSNGOT0000000000";
}

