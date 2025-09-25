
/* WARNING: Unknown calling convention */

_Bool is_power_status_with_64bits(void)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = _g_power_state.power_version - 0xc1;
  uVar3 = uVar2;
  if (1 < uVar2) {
    uVar3 = 0;
  }
  uVar1 = (undefined1)uVar3;
  if (uVar2 < 2) {
    uVar1 = 1;
  }
  return (_Bool)uVar1;
}

