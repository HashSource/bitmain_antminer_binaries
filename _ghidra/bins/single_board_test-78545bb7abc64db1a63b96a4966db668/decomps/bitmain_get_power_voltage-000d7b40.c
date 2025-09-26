
/* WARNING: Unknown calling convention */

int32_t bitmain_get_power_voltage(void)

{
  int32_t iVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = _g_power_state.power_version & 0xfffffff7;
  bVar3 = 0x61 < uVar2;
  if (uVar2 != 0x62) {
    bVar3 = 1 < _g_power_state.power_version - 100;
  }
  if (bVar3 && (uVar2 != 0x62 && _g_power_state.power_version - 100 != 2)) {
    return 0;
  }
  iVar1 = _get_power_dc_voltage_v2();
  return iVar1;
}

