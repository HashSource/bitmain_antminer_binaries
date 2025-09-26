
/* WARNING: Unknown calling convention */

int32_t bitmain_power_is_calibrated(_Bool *is_calibrated)

{
  int32_t iVar1;
  char tmp42 [2048];
  
  if ((_g_power_state.power_open == 0) && (iVar1 = bitmain_power_open(), iVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_power_is_calibrated");
    _applog(0,tmp42,false);
  }
  else if (is_calibrated == (_Bool *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    *is_calibrated = _g_power_state.power_Calibrated;
  }
  return iVar1;
}

