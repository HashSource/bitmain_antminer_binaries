
int EC_POINTs_mul(EC_GROUP *group,EC_POINT *r,BIGNUM *n,size_t num,EC_POINT **p,BIGNUM **m,
                 BN_CTX *ctx)

{
  EC_POINT *pEVar1;
  int iVar2;
  int iVar3;
  BN_CTX *c;
  EC_POINT **ppEVar4;
  size_t sVar5;
  
  iVar2 = *(int *)r;
  if ((iVar2 == *(int *)group) &&
     ((iVar3 = *(int *)(group + 0x10), iVar3 == 0 ||
      (*(int *)(r + 4) == 0 || iVar3 == *(int *)(r + 4))))) {
    if (n == (BIGNUM *)0x0 && num == 0) {
      iVar2 = EC_POINT_set_to_infinity(group,r);
      return iVar2;
    }
    sVar5 = 0;
    if (num == 0) {
LAB_0011f0be:
      c = (BN_CTX *)0x0;
      if (ctx == (BN_CTX *)0x0) {
        c = (BN_CTX *)BN_CTX_secure_new();
        if (c == (BN_CTX *)0x0) {
          ERR_put_error(0x10,0x122,0x44,"crypto/ec/ec_lib.c",0x403);
          return 0;
        }
        iVar2 = *(int *)group;
        ctx = c;
      }
      if (*(code **)(iVar2 + 0x7c) == (code *)0x0) {
        iVar2 = ec_wNAF_mul(group,r,n,num,p,m,ctx);
      }
      else {
        iVar2 = (**(code **)(iVar2 + 0x7c))();
      }
      BN_CTX_free(c);
      return iVar2;
    }
    pEVar1 = *p;
    if (iVar2 == *(int *)pEVar1) {
      ppEVar4 = p;
      if (iVar3 == 0) {
        sVar5 = 0;
        do {
          sVar5 = sVar5 + 1;
          if (num == sVar5) goto LAB_0011f0be;
          ppEVar4 = ppEVar4 + 1;
        } while (*(int *)*ppEVar4 == iVar2);
      }
      else {
        do {
          if (iVar3 != *(int *)(pEVar1 + 4) && *(int *)(pEVar1 + 4) != 0) break;
          sVar5 = sVar5 + 1;
          if (num == sVar5) goto LAB_0011f0be;
          pEVar1 = ppEVar4[1];
          ppEVar4 = ppEVar4 + 1;
        } while (iVar2 == *(int *)pEVar1);
      }
    }
    iVar2 = 0x3fd;
  }
  else {
    iVar2 = 0x3f4;
  }
  ERR_put_error(0x10,0x122,0x65,"crypto/ec/ec_lib.c",iVar2);
  return 0;
}

