
/* WARNING: Unknown calling convention */

int32_t bitmain_set_voltage_by_n(uint8_t n)

{
  int32_t iVar1;
  char tmp42 [2048];
  
  if ((_g_power_state.power_open == 0) && (iVar1 = bitmain_power_open(), iVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_set_voltage_by_n");
    _applog(0,tmp42,false);
  }
  else {
    iVar1 = _bitmain_set_DA_conversion_N(_g_power_state.power_fd,n);
  }
  return iVar1;
}

