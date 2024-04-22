
undefined4 json_object_iter_next(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((param_1 == (int *)0x0) || (*param_1 != 0)) || (param_2 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = hashtable_iter_next(param_1 + 2,param_2);
  }
  return uVar1;
}

