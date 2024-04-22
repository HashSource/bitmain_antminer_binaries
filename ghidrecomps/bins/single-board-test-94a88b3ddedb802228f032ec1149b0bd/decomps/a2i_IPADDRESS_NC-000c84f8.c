
ASN1_OCTET_STRING * a2i_IPADDRESS_NC(char *ipasc)

{
  char *pcVar1;
  char *__s;
  char *pcVar2;
  int iVar3;
  int iVar4;
  ASN1_OCTET_STRING *str;
  bool bVar5;
  bool bVar6;
  undefined *puVar7;
  uint local_60 [2];
  int local_58 [2];
  int local_50 [2];
  int local_48 [2];
  undefined local_40 [32];
  
  pcVar1 = strchr(ipasc,0x2f);
  if ((pcVar1 != (char *)0x0) && (__s = BUF_strdup(ipasc), __s != (char *)0x0)) {
    bVar5 = false;
    __s[(int)pcVar1 - (int)ipasc] = '\0';
    pcVar2 = strchr(__s,0x3a);
    if (pcVar2 == (char *)0x0) {
      iVar3 = __isoc99_sscanf(__s,DAT_000c865c,local_60,local_58,local_50,local_48);
      if (((((iVar3 != 4) || (0xff < local_60[0])) || (local_58[0] < 0)) ||
          ((0xff < local_58[0] || (local_50[0] < 0)))) ||
         ((0xff < local_50[0] || ((local_48[0] < 0 || (0xff < local_48[0])))))) goto LAB_000c8582;
      iVar3 = 4;
      bVar6 = false;
      bVar5 = true;
      local_40[0] = (undefined)local_60[0];
      local_40[1] = (undefined)local_58[0];
      local_40[2] = (undefined)local_50[0];
      local_40[3] = (undefined)local_48[0];
    }
    else {
      iVar3 = ipv6_from_asc(local_40,__s);
      if (iVar3 == 0) {
LAB_000c8582:
        CRYPTO_free(__s);
        return (ASN1_OCTET_STRING *)0x0;
      }
      bVar6 = true;
      iVar3 = 0x10;
    }
    pcVar2 = __s + ((int)pcVar1 - (int)ipasc) + 1;
    puVar7 = local_40 + iVar3;
    pcVar1 = strchr(pcVar2,0x3a);
    if (pcVar1 == (char *)0x0) {
      iVar4 = __isoc99_sscanf(pcVar2,DAT_000c865c,local_60,local_58,local_50,local_48);
      if ((((iVar4 == 4) && (local_60[0] < 0x100)) && (-1 < local_58[0])) &&
         (((local_58[0] < 0x100 && (-1 < local_50[0])) &&
          ((local_50[0] < 0x100 && ((-1 < local_48[0] && (local_48[0] < 0x100)))))))) {
        *puVar7 = (char)local_60[0];
        local_40[iVar3 + 1] = (char)local_58[0];
        local_40[iVar3 + 2] = (char)local_50[0];
        local_40[iVar3 + 3] = (char)local_48[0];
        iVar4 = 4;
      }
      else {
        bVar6 = true;
        iVar4 = 0;
      }
    }
    else {
      iVar4 = ipv6_from_asc(puVar7,pcVar2);
      if (iVar4 == 0) {
        CRYPTO_free(__s);
        return (ASN1_OCTET_STRING *)0x0;
      }
      iVar4 = 0x10;
      bVar6 = bVar5;
    }
    CRYPTO_free(__s);
    if ((!bVar6) && (str = ASN1_OCTET_STRING_new(), str != (ASN1_OCTET_STRING *)0x0)) {
      iVar3 = ASN1_OCTET_STRING_set(str,local_40,iVar3 + iVar4);
      if (iVar3 == 0) {
        ASN1_OCTET_STRING_free(str);
        return (ASN1_OCTET_STRING *)0x0;
      }
      return str;
    }
  }
  return (ASN1_OCTET_STRING *)0x0;
}

