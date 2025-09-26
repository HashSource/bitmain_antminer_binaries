
ASN1_STRING * rsa_ctx_to_pss_string(EVP_PKEY_CTX *param_1)

{
  EVP_PKEY *pkey;
  int iVar1;
  RSA_PSS_PARAMS *a;
  ASN1_STRING *pAVar2;
  int iVar3;
  uint uVar4;
  EVP_MD *local_24;
  undefined4 local_20;
  int local_1c [2];
  
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  iVar1 = EVP_PKEY_CTX_ctrl(param_1,-1,0xf8,0xd,0,&local_24);
  if (((iVar1 < 1) || (iVar1 = RSA_pkey_ctx_ctrl(param_1,0x3f8,0x1008,0,&local_20), iVar1 < 1)) ||
     (iVar1 = RSA_pkey_ctx_ctrl(param_1,0x18,0x1007,0,local_1c), iVar1 == 0)) {
    return (ASN1_STRING *)0x0;
  }
  if (local_1c[0] == -1) {
    local_1c[0] = EVP_MD_size(local_24);
  }
  else if (local_1c[0] + 3U < 2) {
    iVar1 = EVP_PKEY_size(pkey);
    iVar3 = EVP_MD_size(local_24);
    local_1c[0] = (iVar1 - iVar3) + -2;
    uVar4 = EVP_PKEY_bits(pkey);
    if ((uVar4 & 7) == 1) {
      local_1c[0] = local_1c[0] + -1;
    }
    if (local_1c[0] < 0) {
      return (ASN1_STRING *)0x0;
    }
  }
  a = (RSA_PSS_PARAMS *)rsa_pss_params_create(local_24,local_20,local_1c[0]);
  if (a == (RSA_PSS_PARAMS *)0x0) {
    pAVar2 = (ASN1_STRING *)0x0;
  }
  else {
    pAVar2 = ASN1_item_pack(a,(ASN1_ITEM *)RSA_PSS_PARAMS_it,(ASN1_OCTET_STRING **)0x0);
    RSA_PSS_PARAMS_free(a);
  }
  return pAVar2;
}

