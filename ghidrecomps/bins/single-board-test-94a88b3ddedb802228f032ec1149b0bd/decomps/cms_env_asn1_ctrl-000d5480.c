
undefined4 cms_env_asn1_ctrl(int *param_1,undefined4 param_2)

{
  EVP_PKEY *pEVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  if (*param_1 == 0) {
    pEVar1 = *(EVP_PKEY **)(param_1[1] + 0x14);
LAB_000d548e:
    if ((pEVar1->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (pcVar4 = *(code **)(pEVar1->ameth + 0x58), pcVar4 != (code *)0x0)) {
      iVar2 = (*pcVar4)(pEVar1,7,param_2,param_1);
      if (iVar2 == -2) {
        ERR_put_error(0x2e,0xab,0x7d,DAT_000d54f0,0x7b);
        return 0;
      }
      if (iVar2 < 1) {
        ERR_put_error(0x2e,0xab,0x6f,DAT_000d54f0,0x7f);
        goto LAB_000d54b0;
      }
    }
    uVar3 = 1;
  }
  else {
    if (((*param_1 == 1) && (*(EVP_PKEY_CTX **)(param_1[1] + 0x14) != (EVP_PKEY_CTX *)0x0)) &&
       (pEVar1 = EVP_PKEY_CTX_get0_pkey(*(EVP_PKEY_CTX **)(param_1[1] + 0x14)),
       pEVar1 != (EVP_PKEY *)0x0)) goto LAB_000d548e;
LAB_000d54b0:
    uVar3 = 0;
  }
  return uVar3;
}

