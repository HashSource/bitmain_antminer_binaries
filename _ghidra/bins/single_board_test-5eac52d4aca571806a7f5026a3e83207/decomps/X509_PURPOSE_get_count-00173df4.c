
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int X509_PURPOSE_get_count(void)

{
  int iVar1;
  
  if (xptable != 0) {
    iVar1 = OPENSSL_sk_num();
    return iVar1 + 9;
  }
  return 9;
}

