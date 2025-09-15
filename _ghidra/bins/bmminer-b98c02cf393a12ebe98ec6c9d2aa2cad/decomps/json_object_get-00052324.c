
undefined4 json_object_get(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != (int *)0x0 && param_2 != 0) && (*param_1 == 0)) {
    uVar1 = hashtable_get(param_1 + 2);
    return uVar1;
  }
  return 0;
}

