
int EVP_PKEY_keygen(EVP_PKEY_CTX *ctx,EVP_PKEY **ppkey)

{
  int iVar1;
  EVP_PKEY *pEVar2;
  code *pcVar3;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (*(int *)ctx == 0)) ||
     (pcVar3 = *(code **)(*(int *)ctx + 0x20), pcVar3 == (code *)0x0)) {
    ERR_put_error(6,0x92,0x96,"crypto/evp/pmeth_gn.c",0x5c);
    return -2;
  }
  if (*(int *)(ctx + 0x10) != 4) {
    ERR_put_error(6,0x92,0x97,"crypto/evp/pmeth_gn.c",0x60);
    return -1;
  }
  if (ppkey == (EVP_PKEY **)0x0) {
LAB_00132eb4:
    iVar1 = -1;
  }
  else {
    pEVar2 = *ppkey;
    if (pEVar2 == (EVP_PKEY *)0x0) {
      pEVar2 = EVP_PKEY_new();
      *ppkey = pEVar2;
      if (pEVar2 == (EVP_PKEY *)0x0) goto LAB_00132eb4;
      pcVar3 = *(code **)(*(int *)ctx + 0x20);
    }
    iVar1 = (*pcVar3)(ctx,pEVar2);
    if (iVar1 < 1) {
      EVP_PKEY_free(*ppkey);
      *ppkey = (EVP_PKEY *)0x0;
      return iVar1;
    }
  }
  return iVar1;
}

