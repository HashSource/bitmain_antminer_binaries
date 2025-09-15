
void opt_set_intval(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = opt_set_longval(param_1,&local_c);
  if (iVar1 != 0) {
    return;
  }
  *param_2 = local_c;
  return;
}

