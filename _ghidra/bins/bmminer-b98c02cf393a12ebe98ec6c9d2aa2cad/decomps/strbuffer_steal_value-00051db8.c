
undefined4 strbuffer_steal_value(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}

