
undefined4 json_object_iter(int *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    uVar1 = hashtable_iter(param_1 + 2);
    return uVar1;
  }
  return 0;
}

