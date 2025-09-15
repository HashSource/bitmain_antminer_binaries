
int sk_set_cmp_func(void *param_1,void *param_2)

{
  void *pvVar1;
  undefined4 in_r2;
  
  pvVar1 = *(void **)((int)param_1 + 0x10);
  *(void **)((int)param_1 + 0x10) = param_2;
  if (pvVar1 != param_2) {
    in_r2 = 0;
  }
  if (pvVar1 != param_2) {
    *(undefined4 *)((int)param_1 + 8) = in_r2;
  }
  return (int)pvVar1;
}

