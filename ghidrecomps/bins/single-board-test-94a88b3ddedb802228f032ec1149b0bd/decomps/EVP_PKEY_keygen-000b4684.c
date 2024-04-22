
int EVP_PKEY_keygen(EVP_PKEY_CTX *ctx,EVP_PKEY **ppkey)

{
  int iVar1;
  EVP_PKEY *pEVar2;
  code *pcVar3;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (*(int *)ctx == 0)) ||
     (pcVar3 = *(code **)(*(int *)ctx + 0x20), pcVar3 == (code *)0x0)) {
    ERR_put_error(6,0x92,0x96,DAT_000b4704,0x88);
    iVar1 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 4) {
    if (ppkey == (EVP_PKEY **)0x0) {
      iVar1 = -1;
    }
    else {
      pEVar2 = *ppkey;
      if (pEVar2 == (EVP_PKEY *)0x0) {
        pEVar2 = EVP_PKEY_new();
        *ppkey = pEVar2;
        pcVar3 = *(code **)(*(int *)ctx + 0x20);
      }
      iVar1 = (*pcVar3)(ctx,pEVar2);
      if (iVar1 < 1) {
        EVP_PKEY_free(*ppkey);
        *ppkey = (EVP_PKEY *)0x0;
      }
    }
  }
  else {
    ERR_put_error(6,0x92,0x97,DAT_000b4704,0x8c);
    iVar1 = -1;
  }
  return iVar1;
}

