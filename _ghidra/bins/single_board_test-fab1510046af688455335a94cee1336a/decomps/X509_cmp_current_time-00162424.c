
int X509_cmp_current_time(ASN1_TIME *s)

{
  int iVar1;
  
  iVar1 = X509_cmp_time(s,(time_t *)0x0);
  return iVar1;
}

