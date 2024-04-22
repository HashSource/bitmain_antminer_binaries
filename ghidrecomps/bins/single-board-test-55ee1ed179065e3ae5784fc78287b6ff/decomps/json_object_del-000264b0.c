
undefined4 json_object_del(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 0)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = hashtable_del(param_1 + 2,param_2);
  }
  return uVar1;
}

