
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int X509_TRUST_get_count(void)

{
  int iVar1;
  
  if (trtable != (_STACK *)0x0) {
    iVar1 = sk_num(trtable);
    return iVar1 + 8;
  }
  return 8;
}

