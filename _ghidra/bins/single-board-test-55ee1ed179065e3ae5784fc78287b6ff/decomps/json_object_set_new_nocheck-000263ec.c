
undefined4 json_object_set_new_nocheck(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  if (param_3 != (int *)0x0) {
    if ((((param_2 != 0) && (param_1 != (int *)0x0)) && (*param_1 == 0)) && (param_1 != param_3)) {
      iVar1 = param_1[7];
      param_1[7] = iVar1 + 1;
      iVar1 = hashtable_set(param_1 + 2,param_2,iVar1,param_3);
      if (iVar1 == 0) {
        return 0;
      }
      json_decref(param_3);
      return 0xffffffff;
    }
    json_decref(param_3);
  }
  return 0xffffffff;
}

