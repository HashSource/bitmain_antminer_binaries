
undefined4 pkey_poly1305_ctrl(EVP_PKEY_CTX *param_1,int param_2,int param_3,void *param_4)

{
  ASN1_STRING *str;
  EVP_PKEY *pEVar1;
  undefined4 uVar2;
  int iVar3;
  int local_1c;
  
  str = (ASN1_STRING *)EVP_PKEY_CTX_get_data(param_1);
  if (param_2 == 1) {
    uVar2 = 1;
  }
  else {
    if ((param_2 < 1) || (1 < param_2 - 6U)) {
      return 0xfffffffe;
    }
    iVar3 = param_3;
    if (param_2 != 6) {
      pEVar1 = EVP_PKEY_CTX_get0_pkey(param_1);
      param_4 = (void *)EVP_PKEY_get0_poly1305(pEVar1,&local_1c);
      iVar3 = local_1c;
    }
    local_1c = iVar3;
    if (((param_4 == (void *)0x0) || (local_1c != 0x20)) ||
       (iVar3 = ASN1_OCTET_STRING_set(str,param_4,0x20), iVar3 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = ASN1_STRING_get0_data(str);
      Poly1305_Init(str + 1,uVar2);
      uVar2 = 1;
    }
  }
  return uVar2;
}

