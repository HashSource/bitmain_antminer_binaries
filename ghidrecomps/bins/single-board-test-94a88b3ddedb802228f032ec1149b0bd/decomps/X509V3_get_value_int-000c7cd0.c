
int X509V3_get_value_int(CONF_VALUE *value,ASN1_INTEGER **aint)

{
  ASN1_INTEGER *pAVar1;
  
  pAVar1 = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,value->value);
  if (pAVar1 == (ASN1_INTEGER *)0x0) {
    ERR_add_error_data(6,DAT_000c7d0c,value->section,DAT_000c7d10,value->name,DAT_000c7d08,
                       value->value);
  }
  else {
    *aint = pAVar1;
  }
  return (uint)(pAVar1 != (ASN1_INTEGER *)0x0);
}

