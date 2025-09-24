
/* WARNING: Unknown calling convention */

int32_t bitmain_power_get_calibration_date(void)

{
  int32_t iVar1;
  _Bool is_calibrated;
  
  iVar1 = bitmain_power_is_calibrated(&is_calibrated);
  if ((iVar1 != 0) || (iVar1 = _g_power_state.eeprom.c_date, is_calibrated == false)) {
    iVar1 = -1;
  }
  return iVar1;
}

