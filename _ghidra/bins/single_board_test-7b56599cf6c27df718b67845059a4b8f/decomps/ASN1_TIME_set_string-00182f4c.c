
int ASN1_TIME_set_string(ASN1_TIME *s,char *str)

{
  int iVar1;
  
  iVar1 = ASN1_UTCTIME_set_string(s,str);
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = ASN1_GENERALIZEDTIME_set_string(s,str);
  return iVar1;
}

