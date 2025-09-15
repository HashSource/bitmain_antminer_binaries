
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int X509_PURPOSE_get_count(void)

{
  int iVar1;
  
  if (xptable != (_STACK *)0x0) {
    iVar1 = sk_num(xptable);
    return iVar1 + 9;
  }
  return 9;
}

