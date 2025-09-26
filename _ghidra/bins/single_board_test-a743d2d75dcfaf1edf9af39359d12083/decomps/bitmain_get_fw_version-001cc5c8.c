
/* WARNING: Unknown calling convention */

uint32_t bitmain_get_fw_version(void)

{
  uint32_t uVar1;
  char tmp42 [2048];
  
  if ((_g_power_state.power_open == 0) && (uVar1 = bitmain_power_open(), (int)uVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_get_fw_version");
    _applog(0,tmp42,false);
  }
  else {
    uVar1 = _bitmain_get_power_fw_version(_g_power_state.power_fd);
  }
  return uVar1;
}

