
void EVP_PKEY_free(EVP_PKEY *pkey)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  
  if (pkey == (EVP_PKEY *)0x0) {
    return;
  }
  piVar2 = &pkey->references;
  do {
    ExclusiveAccess(piVar2);
    iVar3 = *piVar2;
    bVar1 = (bool)hasExclusiveAccess(piVar2);
  } while (!bVar1);
  *piVar2 = iVar3 + -1;
  if (iVar3 == 1) {
    DataMemoryBarrier(0x1b);
  }
  else if (0 < iVar3 + -1) {
    return;
  }
  if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (pcVar4 = *(code **)(pkey->ameth + 0x58), pcVar4 != (code *)0x0)) {
    (*pcVar4)();
    pkey->save_parameters = 0;
  }
  ENGINE_finish(pkey->engine);
  pkey->engine = (ENGINE *)0x0;
  ENGINE_finish((ENGINE *)(pkey->pkey).rsa);
  iVar3 = pkey[1].save_type;
  (pkey->pkey).ptr = (char *)0x0;
  CRYPTO_THREAD_lock_free(iVar3);
  OPENSSL_sk_pop_free(pkey[1].type,0x16cc01);
  CRYPTO_free(pkey);
  return;
}

