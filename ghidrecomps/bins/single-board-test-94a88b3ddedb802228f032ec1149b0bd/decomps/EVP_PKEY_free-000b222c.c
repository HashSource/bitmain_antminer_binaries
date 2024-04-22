
void EVP_PKEY_free(EVP_PKEY *pkey)

{
  int iVar1;
  code *pcVar2;
  
  if (pkey != (EVP_PKEY *)0x0) {
    iVar1 = CRYPTO_add_lock(&pkey->references,-1,10,DAT_000b2284,0x17f);
    if (iVar1 < 1) {
      if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
         (pcVar2 = *(code **)(pkey->ameth + 0x54), pcVar2 != (code *)0x0)) {
        (*pcVar2)(pkey);
        (pkey->pkey).ptr = (char *)0x0;
      }
      if (pkey->engine != (ENGINE *)0x0) {
        ENGINE_finish(pkey->engine);
        pkey->engine = (ENGINE *)0x0;
      }
      if (&pkey->attributes->stack != (_STACK *)0x0) {
        sk_pop_free(&pkey->attributes->stack,DAT_000b2288);
      }
      CRYPTO_free(pkey);
      return;
    }
  }
  return;
}

