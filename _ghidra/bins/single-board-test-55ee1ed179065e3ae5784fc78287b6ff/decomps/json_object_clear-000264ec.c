
undefined4 json_object_clear(int *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 0)) {
    uVar1 = 0xffffffff;
  }
  else {
    hashtable_clear(param_1 + 2);
    param_1[7] = 0;
    uVar1 = 0;
  }
  return uVar1;
}

