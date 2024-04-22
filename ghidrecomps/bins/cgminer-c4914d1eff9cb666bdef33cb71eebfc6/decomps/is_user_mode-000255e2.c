
/* WARNING: Unknown calling convention */

_Bool is_user_mode(void)

{
  undefined uVar1;
  int iVar2;
  
  iVar2 = freq_mode;
  if (freq_mode == 1) {
    iVar2 = 1;
  }
  uVar1 = (undefined)iVar2;
  if (freq_mode != 1) {
    uVar1 = 0;
  }
  return (_Bool)uVar1;
}

