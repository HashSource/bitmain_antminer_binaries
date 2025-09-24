
/* WARNING: Unknown calling convention */

int32_t power_need_open(void)

{
  uint32_t uVar1;
  uint32_t uVar2;
  char tmp42 [2048];
  
  _g_power_state.power_open = 0;
  uVar1 = bitmain_power_open();
  uVar2 = _g_power_state.power_version;
  if ((int)uVar1 < 0) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "power_need_open");
    _applog(0,tmp42,false);
    uVar2 = uVar1;
  }
  return uVar2;
}

