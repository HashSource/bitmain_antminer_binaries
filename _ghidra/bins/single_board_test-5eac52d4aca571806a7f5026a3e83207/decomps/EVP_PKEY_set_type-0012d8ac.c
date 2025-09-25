
int EVP_PKEY_set_type(EVP_PKEY *pkey,int type)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  int iVar2;
  code *pcVar3;
  ENGINE *local_14;
  
  local_14 = (ENGINE *)0x0;
  if (pkey == (EVP_PKEY *)0x0) {
    pEVar1 = EVP_PKEY_asn1_find(&local_14,type);
    ENGINE_finish(local_14);
    if (pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0) {
      return 1;
    }
  }
  else {
    if (pkey->save_parameters != 0) {
      if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
         (pcVar3 = *(code **)(pkey->ameth + 0x58), pcVar3 != (code *)0x0)) {
        (*pcVar3)();
        pkey->save_parameters = 0;
      }
      ENGINE_finish(pkey->engine);
      pkey->engine = (ENGINE *)0x0;
      ENGINE_finish((ENGINE *)(pkey->pkey).rsa);
      (pkey->pkey).ptr = (char *)0x0;
    }
    if ((type == pkey->save_type) && (pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0)) {
      return 1;
    }
    ENGINE_finish(pkey->engine);
    pkey->engine = (ENGINE *)0x0;
    ENGINE_finish((ENGINE *)(pkey->pkey).rsa);
    (pkey->pkey).ptr = (char *)0x0;
    pEVar1 = EVP_PKEY_asn1_find(&local_14,type);
    if (pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0) {
      iVar2 = *(int *)pEVar1;
      pkey->ameth = pEVar1;
      pkey->type = iVar2;
      pkey->save_type = type;
      pkey->engine = local_14;
      return 1;
    }
  }
  ERR_put_error(6,0x9e,0x9c,"crypto/evp/p_lib.c",0xd2);
  return 0;
}

