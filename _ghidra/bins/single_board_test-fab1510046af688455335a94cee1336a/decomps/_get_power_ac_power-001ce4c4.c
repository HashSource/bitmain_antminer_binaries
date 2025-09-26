
/* WARNING: Unknown calling convention */

float _get_power_ac_power(void)

{
  uint uVar1;
  bool bVar2;
  float fVar3;
  
  uVar1 = _g_power_state.power_version & 0xfffffff7;
  bVar2 = 0x61 < uVar1;
  if (uVar1 != 0x62) {
    bVar2 = 1 < _g_power_state.power_version - 100;
  }
  if (bVar2 && (uVar1 != 0x62 && _g_power_state.power_version - 100 != 2)) {
    return 0.0;
  }
  fVar3 = _get_power_ac_power();
  return fVar3;
}

