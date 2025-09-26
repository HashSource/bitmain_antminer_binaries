
int X509_VERIFY_PARAM_add0_policy(X509_VERIFY_PARAM *param,ASN1_OBJECT *policy)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = param[1].name;
  if (pcVar1 == (char *)0x0) {
    pcVar1 = (char *)OPENSSL_sk_new_null();
    param[1].name = pcVar1;
    if (pcVar1 == (char *)0x0) {
      return 0;
    }
  }
  iVar2 = OPENSSL_sk_push(pcVar1,policy);
  if (iVar2 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}

