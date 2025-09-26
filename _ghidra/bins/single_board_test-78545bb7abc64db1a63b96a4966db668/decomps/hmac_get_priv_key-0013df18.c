
undefined4 hmac_get_priv_key(int param_1,void *param_2,size_t *param_3)

{
  uint uVar1;
  size_t sVar2;
  void *__src;
  undefined4 uVar3;
  ASN1_STRING *x;
  uint uVar4;
  
  x = *(ASN1_STRING **)(param_1 + 0x18);
  if (param_2 == (void *)0x0) {
    sVar2 = ASN1_STRING_length(x);
    uVar3 = 1;
    *param_3 = sVar2;
  }
  else {
    if ((x != (ASN1_STRING *)0x0) &&
       (uVar4 = *param_3, uVar1 = ASN1_STRING_length(x), uVar1 <= uVar4)) {
      sVar2 = ASN1_STRING_length(x);
      *param_3 = sVar2;
      __src = (void *)ASN1_STRING_get0_data(x);
      memcpy(param_2,__src,*param_3);
      return 1;
    }
    uVar3 = 0;
  }
  return uVar3;
}

