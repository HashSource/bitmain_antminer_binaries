
undefined4 json_object_iter_set_new(int *param_1,int param_2,int param_3)

{
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    if (param_3 != 0 && param_2 != 0) {
      hashtable_iter_set(param_2,param_3);
      return 0;
    }
    return 0xffffffff;
  }
  return 0xffffffff;
}

