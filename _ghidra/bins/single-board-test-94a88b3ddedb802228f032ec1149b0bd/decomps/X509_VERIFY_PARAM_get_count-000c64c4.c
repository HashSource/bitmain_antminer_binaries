
int X509_VERIFY_PARAM_get_count(void)

{
  int iVar1;
  
  if (param_table != (_STACK *)0x0) {
    iVar1 = sk_num(param_table);
    return iVar1 + 5;
  }
  return 5;
}

