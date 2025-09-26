
undefined4 siphash_set_priv_key(int param_1,void *param_2,int param_3)

{
  ASN1_OCTET_STRING *str;
  int iVar1;
  undefined4 uVar2;
  
  if ((param_3 == 0x10 && *(int *)(param_1 + 0x18) == 0) &&
     (str = ASN1_OCTET_STRING_new(), str != (ASN1_OCTET_STRING *)0x0)) {
    iVar1 = ASN1_OCTET_STRING_set(str,param_2,0x10);
    if (iVar1 == 0) {
      ASN1_OCTET_STRING_free(str);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
      *(ASN1_OCTET_STRING **)(param_1 + 0x18) = str;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

