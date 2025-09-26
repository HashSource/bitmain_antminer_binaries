
stack_st_void * X509_get_extended_key_usage(X509 *param_1)

{
  int iVar1;
  
  iVar1 = X509_check_purpose(param_1,-1,-1);
  if (iVar1 != 1) {
    return (stack_st_void *)0x0;
  }
  if (-1 < param_1[1].references << 0x1d) {
    return (stack_st_void *)0xffffffff;
  }
  return param_1[1].ex_data.sk;
}

