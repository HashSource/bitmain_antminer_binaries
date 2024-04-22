
undefined4 json_object_set_new_nocheck(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  if (param_3 == (int *)0x0) {
    return 0xffffffff;
  }
  if (((param_1 != (int *)0x0 && param_2 != 0) && (*param_1 == 0 && param_3 != param_1)) &&
     (iVar1 = hashtable_set(param_1 + 2), iVar1 == 0)) {
    return 0;
  }
  if ((param_3[1] != -1) && (iVar1 = param_3[1] + -1, param_3[1] = iVar1, iVar1 == 0)) {
    json_delete(param_3);
  }
  return 0xffffffff;
}

