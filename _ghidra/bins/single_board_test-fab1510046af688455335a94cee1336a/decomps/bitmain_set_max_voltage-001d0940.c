
/* WARNING: Unknown calling convention */

int32_t bitmain_set_max_voltage(void)

{
  int32_t iVar1;
  uint uVar2;
  bool bVar3;
  double dVar4;
  char tmp42 [2048];
  
  uVar2 = _g_power_state.power_version & 0xfffffff7;
  bVar3 = 0x61 < uVar2;
  if (uVar2 != 0x62) {
    bVar3 = 1 < _g_power_state.power_version - 100;
  }
  if (bVar3 && (uVar2 != 0x62 && _g_power_state.power_version - 100 != 2)) {
    if ((_g_power_state.power_open == 0) && (iVar1 = bitmain_power_open(), iVar1 < 0)) {
      snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
               "bitmain_set_max_voltage");
      _applog(0,tmp42,false);
    }
    else {
      iVar1 = _bitmain_set_DA_conversion_N(_g_power_state.power_fd,'\0');
      dVar4 = bitmain_V_diff_of_N(0);
      diff_V = (float)dVar4;
    }
    return iVar1;
  }
  return -0x7ffffcff;
}

