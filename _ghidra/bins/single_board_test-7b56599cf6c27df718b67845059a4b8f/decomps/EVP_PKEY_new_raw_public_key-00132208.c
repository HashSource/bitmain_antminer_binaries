
EVP_PKEY *
EVP_PKEY_new_raw_public_key(int param_1,ENGINE *param_2,undefined4 param_3,undefined4 param_4)

{
  EVP_PKEY *pkey;
  EVP_PKEY_ASN1_METHOD *pEVar1;
  code *pcVar2;
  int iVar3;
  ENGINE **pe;
  ENGINE *local_24 [2];
  
  pkey = EVP_PKEY_new();
  if (pkey != (EVP_PKEY *)0x0) {
    if (param_2 == (ENGINE *)0x0) {
      pe = local_24;
    }
    else {
      pe = (ENGINE **)0x0;
    }
    local_24[0] = param_2;
    if (pkey->save_parameters != 0) {
      if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
         (pcVar2 = *(code **)(pkey->ameth + 0x58), pcVar2 != (code *)0x0)) {
        (*pcVar2)(pkey);
        pkey->save_parameters = 0;
      }
      ENGINE_finish(pkey->engine);
      pkey->engine = (ENGINE *)0x0;
      ENGINE_finish((ENGINE *)(pkey->pkey).rsa);
      (pkey->pkey).ptr = (char *)0x0;
    }
    if ((param_1 != pkey->save_type) ||
       (pEVar1 = pkey->ameth, pEVar1 == (EVP_PKEY_ASN1_METHOD *)0x0)) {
      ENGINE_finish(pkey->engine);
      pkey->engine = (ENGINE *)0x0;
      ENGINE_finish((ENGINE *)(pkey->pkey).rsa);
      (pkey->pkey).ptr = (char *)0x0;
      pEVar1 = EVP_PKEY_asn1_find(pe,param_1);
      if (pEVar1 == (EVP_PKEY_ASN1_METHOD *)0x0) {
        ERR_put_error(6,0x9e,0x9c,"crypto/evp/p_lib.c",0xd2);
        goto LAB_001322d4;
      }
      iVar3 = *(int *)pEVar1;
      pkey->ameth = pEVar1;
      pkey->type = iVar3;
      pkey->save_type = param_1;
      if ((pe == (ENGINE **)0x0) && (local_24[0] != (ENGINE *)0x0)) {
        iVar3 = ENGINE_init(local_24[0]);
        if (iVar3 == 0) {
          ERR_put_error(6,0x9e,0x86,"crypto/evp/p_lib.c",0xdb);
          goto LAB_001322d4;
        }
        pEVar1 = pkey->ameth;
      }
      pkey->engine = local_24[0];
    }
    if (*(code **)(pEVar1 + 0x84) == (code *)0x0) {
      ERR_put_error(6,0xc0,0x96,"crypto/evp/p_lib.c",0x110);
    }
    else {
      iVar3 = (**(code **)(pEVar1 + 0x84))(pkey,param_3,param_4);
      if (iVar3 != 0) {
        return pkey;
      }
      ERR_put_error(6,0xc0,0xb4,"crypto/evp/p_lib.c",0x115);
    }
  }
LAB_001322d4:
  EVP_PKEY_free(pkey);
  return (EVP_PKEY *)0x0;
}

