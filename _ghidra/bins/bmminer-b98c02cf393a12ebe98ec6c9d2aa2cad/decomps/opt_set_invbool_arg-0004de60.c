
void opt_set_invbool_arg(undefined4 param_1,byte *param_2)

{
  int iVar1;
  
  iVar1 = opt_set_bool_arg();
  if (iVar1 != 0) {
    return;
  }
  *param_2 = *param_2 ^ 1;
  return;
}

