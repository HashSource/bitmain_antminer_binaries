
undefined4 crl_inf_cb(int param_1,int *param_2)

{
  void *pvVar1;
  
  if (((*param_2 != 0) && (pvVar1 = *(void **)(*param_2 + 0x14), pvVar1 != (void *)0x0)) &&
     (param_1 == 5)) {
    sk_set_cmp_func(pvVar1,DAT_00107cfc);
  }
  return 1;
}

