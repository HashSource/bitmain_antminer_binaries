
int ASN1_STRING_print_ex(BIO *out,ASN1_STRING *str,ulong flags)

{
  int iVar1;
  
  iVar1 = do_print_ex_constprop_2(out,flags,str);
  return iVar1;
}

