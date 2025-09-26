
int ASN1_GENERALIZEDTIME_set_string(ASN1_GENERALIZEDTIME *s,char *str)

{
  int iVar1;
  ASN1_GENERALIZEDTIME local_20;
  
  local_20.type = 0x18;
  local_20.length = strlen(str);
  local_20.flags = 0;
  local_20.data = (uchar *)str;
  iVar1 = ASN1_GENERALIZEDTIME_check(&local_20);
  if (((iVar1 != 0) && (iVar1 = 1, s != (ASN1_GENERALIZEDTIME *)0x0)) &&
     (iVar1 = ASN1_STRING_copy(s,&local_20), iVar1 != 0)) {
    iVar1 = 1;
  }
  return iVar1;
}

