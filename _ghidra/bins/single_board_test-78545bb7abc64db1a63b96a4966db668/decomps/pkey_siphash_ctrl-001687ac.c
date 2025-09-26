
undefined4 pkey_siphash_ctrl(EVP_PKEY_CTX *param_1,int param_2,int param_3,void *param_4)

{
  ASN1_STRING *str;
  undefined4 uVar1;
  EVP_PKEY *pEVar2;
  int iVar3;
  int local_1c;
  
  str = (ASN1_STRING *)EVP_PKEY_CTX_get_data(param_1);
  switch(param_2) {
  case 1:
    return 1;
  default:
    return 0xfffffffe;
  case 6:
  case 7:
    iVar3 = param_3;
    if (param_2 != 6) {
      pEVar2 = EVP_PKEY_CTX_get0_pkey(param_1);
      param_4 = (void *)EVP_PKEY_get0_siphash(pEVar2,&local_1c);
      iVar3 = local_1c;
    }
    local_1c = iVar3;
    if (((param_4 == (void *)0x0) || (local_1c != 0x10)) ||
       (iVar3 = ASN1_OCTET_STRING_set(str,param_4,0x10), iVar3 == 0)) {
      return 0;
    }
    uVar1 = ASN1_STRING_get0_data(str);
    uVar1 = SipHash_Init(str + 1,uVar1,0);
    break;
  case 0xe:
    uVar1 = SipHash_set_hash_size(str + 1,param_3);
  }
  return uVar1;
}

