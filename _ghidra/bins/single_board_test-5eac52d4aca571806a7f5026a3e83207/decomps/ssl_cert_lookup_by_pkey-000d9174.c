
undefined1 * ssl_cert_lookup_by_pkey(EVP_PKEY *param_1,int *param_2)

{
  int iVar1;
  int local_c;
  
  iVar1 = EVP_PKEY_id(param_1);
  if ((iVar1 != 0) && (iVar1 = ssl_cert_lookup_by_nid(iVar1,&local_c), iVar1 != 0)) {
    if (param_2 != (int *)0x0) {
      *param_2 = local_c;
    }
    return ssl_cert_info + local_c * 8;
  }
  return (undefined1 *)0x0;
}

