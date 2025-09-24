
/* WARNING: Unknown calling convention */

int32_t bitmain_set_watchdog(uint8_t ctrl)

{
  int32_t iVar1;
  bool bVar2;
  char tmp42 [2048];
  
  if ((_g_power_state.power_open == 0) && (iVar1 = bitmain_power_open(), iVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_set_watchdog");
    _applog(0,tmp42,false);
  }
  else {
    bVar2 = 0x61 < _g_power_state.power_version;
    if (_g_power_state.power_version != 0x62) {
      bVar2 = 1 < _g_power_state.power_version - 100;
    }
    if (bVar2 && (_g_power_state.power_version != 0x62 && _g_power_state.power_version - 100 != 2))
    {
      if (ctrl == '\x01') {
        iVar1 = _bitmain_set_watchdog(_g_power_state.power_fd,'\x01');
      }
      else {
        iVar1 = _bitmain_set_watchdog(_g_power_state.power_fd,'\0');
      }
    }
    else {
      if (ctrl != '\x01') {
        iVar1 = _bitmain_set_watchdog_v2(_g_power_state.power_fd,'\0');
        if (-1 < iVar1) {
          return iVar1;
        }
        goto LAB_000cd08e;
      }
      iVar1 = _bitmain_set_watchdog_v2(_g_power_state.power_fd,'\x01');
    }
    if (iVar1 < 0) {
LAB_000cd08e:
      builtin_strncpy(tmp42,"can nont set power watchdog\n",0x1c);
      tmp42[0x1c] = '\0';
      _applog(0,tmp42,false);
      return iVar1;
    }
  }
  return iVar1;
}

