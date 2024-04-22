
int X509V3_add_value_bool_nf(char *name,int asn1_bool,stack_st_CONF_VALUE **extlist)

{
  int iVar1;
  
  if (asn1_bool == 0) {
    return 1;
  }
  iVar1 = X509V3_add_value(name,DAT_000c7a08,extlist);
  return iVar1;
}

