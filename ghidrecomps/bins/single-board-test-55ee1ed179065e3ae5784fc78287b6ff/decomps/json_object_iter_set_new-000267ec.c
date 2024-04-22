
undefined4 json_object_iter_set_new(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((((param_1 == (int *)0x0) || (*param_1 != 0)) || (param_2 == 0)) || (param_3 == 0)) {
    uVar1 = 0xffffffff;
  }
  else {
    hashtable_iter_set(param_2,param_3);
    uVar1 = 0;
  }
  return uVar1;
}

