
int EVP_PKEY_set_type_str(EVP_PKEY *pkey,char *str,int len)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  int iVar2;
  code *pcVar3;
  ENGINE *local_1c [2];
  
  local_1c[0] = (ENGINE *)0x0;
  if (pkey != (EVP_PKEY *)0x0) {
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
    if ((pkey->save_type == 0) && (pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0)) {
      return 1;
    }
    ENGINE_finish(pkey->engine);
    pkey->engine = (ENGINE *)0x0;
    ENGINE_finish((ENGINE *)(pkey->pkey).rsa);
    (pkey->pkey).ptr = (char *)0x0;
  }
  if (str == (char *)0x0) {
    pEVar1 = EVP_PKEY_asn1_find(local_1c,0);
  }
  else {
    pEVar1 = EVP_PKEY_asn1_find_str(local_1c,str,len);
  }
  if (pkey == (EVP_PKEY *)0x0) {
    ENGINE_finish(local_1c[0]);
    if (pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0) {
      return 1;
    }
  }
  else if (pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0) {
    iVar2 = *(int *)pEVar1;
    pkey->ameth = pEVar1;
    pkey->type = iVar2;
    pkey->engine = local_1c[0];
    pkey->save_type = 0;
    return 1;
  }
  ERR_put_error(6,0x9e,0x9c,"crypto/evp/p_lib.c",0xd2);
  return 0;
}

