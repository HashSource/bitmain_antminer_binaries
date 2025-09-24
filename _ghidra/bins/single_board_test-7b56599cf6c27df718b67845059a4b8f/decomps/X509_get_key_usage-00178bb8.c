
char * X509_get_key_usage(X509 *param_1)

{
  int iVar1;
  
  iVar1 = X509_check_purpose(param_1,-1,-1);
  if (iVar1 != 1) {
    return (char *)0x0;
  }
  if (-1 < param_1[1].references << 0x1e) {
    return (char *)0xffffffff;
  }
  return param_1[1].name;
}

