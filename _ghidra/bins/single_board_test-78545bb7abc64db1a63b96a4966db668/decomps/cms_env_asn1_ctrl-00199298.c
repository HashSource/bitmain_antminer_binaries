
undefined4 cms_env_asn1_ctrl(int *param_1,undefined4 param_2)

{
  EVP_PKEY *pEVar1;
  int iVar2;
  code *pcVar3;
  
  if (*param_1 == 0) {
    pEVar1 = *(EVP_PKEY **)(param_1[1] + 0x14);
  }
  else {
    if (*param_1 != 1) {
      return 0;
    }
    if (*(EVP_PKEY_CTX **)(param_1[1] + 0x14) == (EVP_PKEY_CTX *)0x0) {
      return 0;
    }
    pEVar1 = EVP_PKEY_CTX_get0_pkey(*(EVP_PKEY_CTX **)(param_1[1] + 0x14));
    if (pEVar1 == (EVP_PKEY *)0x0) {
      return 0;
    }
  }
  if ((pEVar1->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (pcVar3 = *(code **)(pEVar1->ameth + 0x5c), pcVar3 != (code *)0x0)) {
    iVar2 = (*pcVar3)(pEVar1,7,param_2,param_1);
    if (iVar2 == -2) {
      ERR_put_error(0x2e,0xab,0x7d,"crypto/cms/cms_env.c",0x47);
      return 0;
    }
    if (iVar2 < 1) {
      ERR_put_error(0x2e,0xab,0x6f,"crypto/cms/cms_env.c",0x4b);
      return 0;
    }
  }
  return 1;
}

