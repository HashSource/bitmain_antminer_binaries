
undefined4 json_object_clear(int *param_1)

{
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  if (*param_1 == 0) {
    hashtable_clear(param_1 + 2);
    return 0;
  }
  return 0xffffffff;
}

