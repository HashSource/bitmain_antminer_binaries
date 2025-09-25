
EVP_PKEY * EVP_PKEY_new_CMAC_key(ENGINE *param_1,void *param_2,size_t param_3,EVP_CIPHER *param_4)

{
  EVP_PKEY *pkey;
  CMAC_CTX *ctx;
  EVP_PKEY_ASN1_METHOD *pEVar1;
  code *pcVar2;
  int iVar3;
  ENGINE **pe;
  ENGINE *local_2c [2];
  
  pkey = EVP_PKEY_new();
  ctx = CMAC_CTX_new();
  if (ctx == (CMAC_CTX *)0x0 || pkey == (EVP_PKEY *)0x0) goto LAB_0012e1b2;
  pe = (ENGINE **)0x0;
  if (param_1 == (ENGINE *)0x0) {
    pe = local_2c;
  }
  local_2c[0] = param_1;
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
  if ((pkey->save_type != 0x37e) || (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0)) {
    ENGINE_finish(pkey->engine);
    pkey->engine = (ENGINE *)0x0;
    ENGINE_finish((ENGINE *)(pkey->pkey).rsa);
    (pkey->pkey).ptr = (char *)0x0;
    pEVar1 = EVP_PKEY_asn1_find(pe,0x37e);
    if (pEVar1 == (EVP_PKEY_ASN1_METHOD *)0x0) {
      ERR_put_error(6,0x9e,0x9c,"crypto/evp/p_lib.c",0xd2);
      goto LAB_0012e1b2;
    }
    iVar3 = *(int *)pEVar1;
    pkey->ameth = pEVar1;
    pkey->save_type = 0x37e;
    pkey->type = iVar3;
    if (((pe == (ENGINE **)0x0) && (local_2c[0] != (ENGINE *)0x0)) &&
       (iVar3 = ENGINE_init(local_2c[0]), iVar3 == 0)) {
      ERR_put_error(6,0x9e,0x86,"crypto/evp/p_lib.c",0xdb);
      goto LAB_0012e1b2;
    }
    pkey->engine = local_2c[0];
  }
  iVar3 = CMAC_Init(ctx,param_2,param_3,param_4,param_1);
  if (iVar3 != 0) {
    pkey->save_parameters = (int)ctx;
    return pkey;
  }
  ERR_put_error(6,0xc1,0xb4,"crypto/evp/p_lib.c",0x151);
LAB_0012e1b2:
  EVP_PKEY_free(pkey);
  CMAC_CTX_free(ctx);
  return (EVP_PKEY *)0x0;
}

