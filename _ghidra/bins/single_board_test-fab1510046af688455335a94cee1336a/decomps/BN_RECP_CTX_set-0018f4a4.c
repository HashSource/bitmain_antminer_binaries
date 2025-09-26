
int BN_RECP_CTX_set(BN_RECP_CTX *recp,BIGNUM *rdiv,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  int iVar2;
  
  pBVar1 = BN_copy(&recp->N,rdiv);
  if (pBVar1 != (BIGNUM *)0x0) {
    BN_set_word(&recp->Nr,0);
    iVar2 = BN_num_bits(rdiv);
    recp->num_bits = iVar2;
    pBVar1 = (BIGNUM *)0x1;
    recp->shift = 0;
  }
  return (int)pBVar1;
}

