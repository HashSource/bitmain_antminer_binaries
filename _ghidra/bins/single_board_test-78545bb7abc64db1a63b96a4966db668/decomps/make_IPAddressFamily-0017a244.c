
IPAddressFamily * make_IPAddressFamily(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  IPAddressFamily *pIVar2;
  ASN1_STRING *str;
  IPAddressChoice *pIVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  size_t __n;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  
  local_23 = (undefined1)param_2;
  local_24 = (undefined1)((uint)param_2 >> 8);
  if (param_3 == (undefined4 *)0x0) {
    __n = 2;
    iVar6 = 2;
  }
  else {
    __n = 3;
    iVar6 = 3;
    local_22 = (undefined1)*param_3;
  }
  iVar4 = 0;
  while( true ) {
    iVar1 = OPENSSL_sk_num(param_1);
    iVar5 = iVar4 + 1;
    if (iVar1 <= iVar4) break;
    pIVar2 = (IPAddressFamily *)OPENSSL_sk_value(param_1,iVar4);
    iVar4 = iVar5;
    if ((iVar6 == pIVar2->addressFamily->length) &&
       (iVar1 = memcmp(pIVar2->addressFamily->data,&local_24,__n), iVar1 == 0)) {
      return pIVar2;
    }
  }
  pIVar2 = IPAddressFamily_new();
  if (pIVar2 != (IPAddressFamily *)0x0) {
    if (pIVar2->ipAddressChoice == (IPAddressChoice *)0x0) {
      pIVar3 = IPAddressChoice_new();
      pIVar2->ipAddressChoice = pIVar3;
      if (pIVar3 == (IPAddressChoice *)0x0) goto LAB_0017a2c8;
    }
    str = pIVar2->addressFamily;
    if (str == (ASN1_OCTET_STRING *)0x0) {
      str = ASN1_OCTET_STRING_new();
      pIVar2->addressFamily = str;
      if (str == (ASN1_OCTET_STRING *)0x0) goto LAB_0017a2c8;
    }
    iVar6 = ASN1_OCTET_STRING_set(str,&local_24,iVar6);
    if ((iVar6 != 0) && (iVar6 = OPENSSL_sk_push(param_1,pIVar2), iVar6 != 0)) {
      return pIVar2;
    }
  }
LAB_0017a2c8:
  IPAddressFamily_free(pIVar2);
  return (IPAddressFamily *)0x0;
}

