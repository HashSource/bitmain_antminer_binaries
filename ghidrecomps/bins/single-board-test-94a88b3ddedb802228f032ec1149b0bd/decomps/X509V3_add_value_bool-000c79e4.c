
int X509V3_add_value_bool(char *name,int asn1_bool,stack_st_CONF_VALUE **extlist)

{
  int iVar1;
  
  if (asn1_bool == 0) {
    iVar1 = X509V3_add_value(name,DAT_000c79f4,extlist);
    return iVar1;
  }
  iVar1 = X509V3_add_value(name,DAT_000c79f8,extlist);
  return iVar1;
}

