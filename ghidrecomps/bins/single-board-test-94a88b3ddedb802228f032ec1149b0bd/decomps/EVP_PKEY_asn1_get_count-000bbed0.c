
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int EVP_PKEY_asn1_get_count(void)

{
  int iVar1;
  
  if (app_methods != (_STACK *)0x0) {
    iVar1 = sk_num(app_methods);
    return iVar1 + 0xc;
  }
  return 0xc;
}

