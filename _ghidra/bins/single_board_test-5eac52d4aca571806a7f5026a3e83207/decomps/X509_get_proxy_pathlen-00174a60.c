
int X509_get_proxy_pathlen(X509 *param_1)

{
  int iVar1;
  
  iVar1 = X509_check_purpose(param_1,-1,-1);
  if ((iVar1 == 1) && (param_1[1].references << 0x15 < 0)) {
    return param_1[1].valid;
  }
  return -1;
}

