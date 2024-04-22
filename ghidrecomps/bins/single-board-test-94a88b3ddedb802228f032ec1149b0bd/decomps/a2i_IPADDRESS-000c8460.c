
ASN1_OCTET_STRING * a2i_IPADDRESS(char *ipasc)

{
  char *pcVar1;
  int iVar2;
  ASN1_OCTET_STRING *str;
  uint local_40 [2];
  int local_38 [2];
  int local_30 [2];
  int local_28 [2];
  undefined local_20;
  undefined local_1f;
  undefined local_1e;
  undefined local_1d;
  
  pcVar1 = strchr(ipasc,0x3a);
  if (pcVar1 == (char *)0x0) {
    iVar2 = __isoc99_sscanf(ipasc,DAT_000c84f4,local_40,local_38,local_30,local_28);
    if (iVar2 != 4) {
      return (ASN1_OCTET_STRING *)0x0;
    }
    if (0xff < local_40[0]) {
      return (ASN1_OCTET_STRING *)0x0;
    }
    if (local_38[0] < 0) {
      return (ASN1_OCTET_STRING *)0x0;
    }
    if (0xff < local_38[0]) {
      return (ASN1_OCTET_STRING *)0x0;
    }
    if (local_30[0] < 0) {
      return (ASN1_OCTET_STRING *)0x0;
    }
    if (0xff < local_30[0]) {
      return (ASN1_OCTET_STRING *)0x0;
    }
    if (local_28[0] < 0) {
      return (ASN1_OCTET_STRING *)0x0;
    }
    if (0xff < local_28[0]) {
      return (ASN1_OCTET_STRING *)0x0;
    }
    local_20 = (undefined)local_40[0];
    local_1f = (undefined)local_38[0];
    local_1e = (undefined)local_30[0];
    local_1d = (undefined)local_28[0];
    iVar2 = 4;
  }
  else {
    iVar2 = ipv6_from_asc(&local_20,ipasc);
    if (iVar2 == 0) {
      return (ASN1_OCTET_STRING *)0x0;
    }
    iVar2 = 0x10;
  }
  str = ASN1_OCTET_STRING_new();
  if (str == (ASN1_OCTET_STRING *)0x0) {
    return (ASN1_OCTET_STRING *)0x0;
  }
  iVar2 = ASN1_OCTET_STRING_set(str,&local_20,iVar2);
  if (iVar2 == 0) {
    ASN1_OCTET_STRING_free(str);
    return (ASN1_OCTET_STRING *)0x0;
  }
  return str;
}

