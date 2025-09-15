
/* WARNING: Unknown calling convention */

int get_hw_errors(void)

{
  _Bool _Var1;
  int iVar2;
  
  _Var1 = aging_is_bad_machine();
  iVar2 = hw_errors;
  if (_Var1) {
    iVar2 = 1000000;
  }
  return iVar2;
}

