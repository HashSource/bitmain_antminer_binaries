
/* WARNING: Unknown calling convention */

_Bool is_hashboard_dead(void)

{
  undefined uVar1;
  int iVar2;
  
  iVar2 = fatal_error_counter;
  if (fatal_error_counter == 0xdead) {
    iVar2 = 1;
  }
  uVar1 = (undefined)iVar2;
  if (fatal_error_counter != 0xdead) {
    uVar1 = 0;
  }
  return (_Bool)uVar1;
}

