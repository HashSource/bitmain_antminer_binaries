
/* WARNING: Unknown calling convention */

_Bool sock_blocks(void)

{
  int *piVar1;
  _Bool _Var2;
  
  piVar1 = __errno_location();
  if ((*piVar1 == 0xb) || (piVar1 = __errno_location(), *piVar1 == 0xb)) {
    _Var2 = true;
  }
  else {
    _Var2 = false;
  }
  return _Var2;
}

