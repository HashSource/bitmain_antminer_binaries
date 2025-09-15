
EVP_MD_CTX * md_new(int param_1)

{
  EVP_MD_CTX *pEVar1;
  
  pEVar1 = EVP_MD_CTX_create();
  if (pEVar1 != (EVP_MD_CTX *)0x0) {
    *(EVP_MD_CTX **)(param_1 + 0x20) = pEVar1;
    pEVar1 = (EVP_MD_CTX *)0x1;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return pEVar1;
}

