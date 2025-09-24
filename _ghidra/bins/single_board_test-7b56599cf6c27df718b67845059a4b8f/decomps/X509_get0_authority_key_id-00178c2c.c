
undefined4 * X509_get0_authority_key_id(X509 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = X509_check_purpose(param_1,-1,-1);
  if (iVar1 == 1) {
    puVar2 = (undefined4 *)param_1[1].ex_pcpathlen;
    if (puVar2 != (undefined4 *)0x0) {
      return (undefined4 *)*puVar2;
    }
  }
  else {
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}

