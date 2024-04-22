
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int EVP_PKEY_asn1_get_count(void)

{
  int iVar1;
  
  if (*DAT_000bbee4 != (_STACK *)0x0) {
    iVar1 = sk_num(*DAT_000bbee4);
    return iVar1 + 0xc;
  }
  return 0xc;
}

