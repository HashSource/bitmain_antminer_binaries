
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int X509_TRUST_get_count(void)

{
  int iVar1;
  
  if (trtable != 0) {
    iVar1 = OPENSSL_sk_num();
    return iVar1 + 8;
  }
  return 8;
}

