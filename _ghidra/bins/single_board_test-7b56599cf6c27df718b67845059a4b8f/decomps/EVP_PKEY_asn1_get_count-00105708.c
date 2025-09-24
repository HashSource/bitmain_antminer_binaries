
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int EVP_PKEY_asn1_get_count(void)

{
  int iVar1;
  
  if (app_methods != 0) {
    iVar1 = OPENSSL_sk_num();
    return iVar1 + 0x14;
  }
  return 0x14;
}

