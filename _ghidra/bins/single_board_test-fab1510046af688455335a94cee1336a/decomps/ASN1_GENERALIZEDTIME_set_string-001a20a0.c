
int ASN1_GENERALIZEDTIME_set_string(ASN1_GENERALIZEDTIME *s,char *str)

{
  int iVar1;
  size_t local_20 [2];
  char *local_18;
  
  local_20[1] = 0x18;
  local_20[0] = strlen(str);
  local_18 = str;
  iVar1 = asn1_generalizedtime_to_tm(0,local_20);
  if (iVar1 != 0) {
    if (s == (ASN1_GENERALIZEDTIME *)0x0) {
      return 1;
    }
    iVar1 = ASN1_STRING_set(s,str,local_20[0]);
    if (iVar1 != 0) {
      s->type = 0x18;
      return 1;
    }
  }
  return 0;
}

