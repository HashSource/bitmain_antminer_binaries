
undefined4 crl_inf_cb(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (((*param_2 != 0) && (iVar1 = *(int *)(*param_2 + 0x18), iVar1 != 0)) && (param_1 == 5)) {
    OPENSSL_sk_set_cmp_func(iVar1,0x16cc75,param_3,iVar1,param_4);
    return 1;
  }
  return 1;
}

