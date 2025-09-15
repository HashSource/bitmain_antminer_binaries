
EC_GROUP * EC_GROUP_new_curve_GFp(BIGNUM *p,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  EC_METHOD *pEVar1;
  EC_GROUP *pEVar2;
  int iVar3;
  ulong uVar4;
  
  pEVar1 = EC_GFp_nist_method();
  pEVar2 = EC_GROUP_new(pEVar1);
  if (pEVar2 != (EC_GROUP *)0x0) {
    iVar3 = EC_GROUP_set_curve_GFp(pEVar2,p,a,b,ctx);
    if (iVar3 != 0) {
      return pEVar2;
    }
    uVar4 = ERR_peek_last_error();
    if ((uVar4 >> 0x18 != 0x10) || (1 < (uVar4 & 0xfff) - 0x87)) {
      EC_GROUP_clear_free(pEVar2);
      return (EC_GROUP *)0x0;
    }
    ERR_clear_error();
    EC_GROUP_clear_free(pEVar2);
    pEVar1 = EC_GFp_mont_method();
    pEVar2 = EC_GROUP_new(pEVar1);
    if (pEVar2 != (EC_GROUP *)0x0) {
      iVar3 = EC_GROUP_set_curve_GFp(pEVar2,p,a,b,ctx);
      if (iVar3 != 0) {
        return pEVar2;
      }
      EC_GROUP_clear_free(pEVar2);
      return (EC_GROUP *)0x0;
    }
  }
  return (EC_GROUP *)0x0;
}

