
undefined4 __json_array_string(int *param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if ((((*param_1 == 1) && (uVar1 = json_array_size(), param_2 <= uVar1)) &&
      (piVar2 = (int *)json_array_get(param_1,param_2), piVar2 != (int *)0x0)) && (*piVar2 == 2)) {
    uVar3 = json_string_value();
    return uVar3;
  }
  return 0;
}

