
int X509_VERIFY_PARAM_get_count(void)

{
  int iVar1;
  
  if (*DAT_000c64d8 != (_STACK *)0x0) {
    iVar1 = sk_num(*DAT_000c64d8);
    return iVar1 + 5;
  }
  return 5;
}

