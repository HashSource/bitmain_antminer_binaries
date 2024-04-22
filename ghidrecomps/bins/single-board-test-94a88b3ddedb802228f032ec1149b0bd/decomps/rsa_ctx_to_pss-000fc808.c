
ASN1_STRING * rsa_ctx_to_pss(EVP_PKEY_CTX *param_1)

{
  EVP_PKEY *pkey;
  int iVar1;
  RSA_PSS_PARAMS *a;
  ASN1_INTEGER *a_00;
  X509_ALGOR *alg;
  ASN1_STRING *pAVar2;
  int iVar3;
  EVP_MD *local_20;
  undefined4 local_1c;
  ASN1_STRING *local_18;
  int local_14;
  
  local_18 = (ASN1_STRING *)0x0;
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  iVar1 = EVP_PKEY_CTX_ctrl(param_1,-1,0xf8,0xd,0,&local_20);
  if (((iVar1 < 1) || (iVar1 = EVP_PKEY_CTX_ctrl(param_1,6,0x3f8,0x1008,0,&local_1c), iVar1 < 1)) ||
     (iVar1 = EVP_PKEY_CTX_ctrl(param_1,6,0x18,0x1007,0,&local_14), iVar1 == 0)) goto LAB_000fc88e;
  if (local_14 == -1) {
    local_14 = EVP_MD_size(local_20);
  }
  else if (local_14 == -2) {
    iVar1 = EVP_PKEY_size(pkey);
    iVar3 = EVP_MD_size(local_20);
    local_14 = (iVar1 - iVar3) + -2;
    iVar1 = EVP_PKEY_bits(pkey);
    if ((iVar1 - 1U & 7) == 0) {
      local_14 = local_14 + -1;
    }
  }
  a = RSA_PSS_PARAMS_new();
  if (a == (RSA_PSS_PARAMS *)0x0) goto LAB_000fc88e;
  if (local_14 == 0x14) {
LAB_000fc89c:
    iVar1 = EVP_MD_type(local_20);
    if (iVar1 != 0x40) {
      alg = X509_ALGOR_new();
      a->hashAlgorithm = alg;
      if (alg == (X509_ALGOR *)0x0) goto LAB_000fc888;
      X509_ALGOR_set_md(alg,local_20);
    }
    iVar1 = rsa_md_to_mgf1(&a->maskGenAlgorithm,local_1c);
    if (iVar1 != 0) {
      pAVar2 = ASN1_item_pack(a,DAT_000fc914,&local_18);
      RSA_PSS_PARAMS_free(a);
      if (pAVar2 != (ASN1_STRING *)0x0) {
        return local_18;
      }
      goto LAB_000fc88e;
    }
  }
  else {
    a_00 = ASN1_INTEGER_new();
    a->saltLength = a_00;
    if ((a_00 != (ASN1_INTEGER *)0x0) && (iVar1 = ASN1_INTEGER_set(a_00,local_14), iVar1 != 0))
    goto LAB_000fc89c;
  }
LAB_000fc888:
  RSA_PSS_PARAMS_free(a);
LAB_000fc88e:
  if (local_18 != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(local_18);
    local_18 = (ASN1_STRING *)0x0;
  }
  return local_18;
}

