
/* WARNING: Unknown calling convention */

_Bool is_power_protocal_v2(void)

{
  undefined1 uVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  
  uVar2 = _g_power_state.power_version - 100;
  bVar5 = 0x61 < (_g_power_state.power_version & 0xfffffff7);
  bVar3 = (_g_power_state.power_version & 0xfffffff7) == 0x62;
  if (!bVar3) {
    bVar5 = 1 < uVar2;
  }
  bVar4 = uVar2 == 2;
  if (!bVar5 || (bVar3 || bVar4)) {
    uVar2 = 1;
  }
  uVar1 = (undefined1)uVar2;
  if (bVar5 && (!bVar3 && !bVar4)) {
    uVar1 = 0;
  }
  return (_Bool)uVar1;
}

