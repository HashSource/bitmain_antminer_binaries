
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int X509_TRUST_get_count(void)

{
  int iVar1;
  
  if (*DAT_000c50c0 != (_STACK *)0x0) {
    iVar1 = sk_num(*DAT_000c50c0);
    return iVar1 + 8;
  }
  return 8;
}

