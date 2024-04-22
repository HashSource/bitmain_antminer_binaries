
int ASN1_UTCTIME_set_string(ASN1_UTCTIME *s,char *str)

{
  int iVar1;
  size_t local_20;
  undefined4 local_1c;
  char *local_18;
  
  local_1c = 0x17;
  local_20 = strlen(str);
  local_18 = str;
  iVar1 = asn1_utctime_to_tm_part_0(0,&local_20);
  if (iVar1 != 0) {
    if (s == (ASN1_UTCTIME *)0x0) {
      return 1;
    }
    iVar1 = ASN1_STRING_set(s,str,local_20);
    if (iVar1 != 0) {
      s->type = 0x17;
      return 1;
    }
  }
  return 0;
}

