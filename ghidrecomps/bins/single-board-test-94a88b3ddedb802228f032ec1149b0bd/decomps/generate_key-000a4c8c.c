
BIGNUM * generate_key(int param_1)

{
  bool bVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BN_CTX *ctx;
  BN_MONT_CTX *pBVar4;
  BIGNUM *pBVar5;
  int iVar6;
  BIGNUM *rnd;
  BIGNUM *pBVar7;
  BIGNUM local_34;
  
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
LAB_000a4dd0:
    rnd = (BIGNUM *)0x0;
    pBVar7 = (BIGNUM *)0x0;
LAB_000a4cea:
    ERR_put_error(5,0x67,3,DAT_000a4df4,0xc6);
    if (pBVar7 == (BIGNUM *)0x0) goto LAB_000a4d08;
    pBVar3 = (BIGNUM *)0x0;
    pBVar5 = pBVar7;
    pBVar2 = *(BIGNUM **)(param_1 + 0x14);
  }
  else {
    rnd = *(BIGNUM **)(param_1 + 0x18);
    if (rnd == (BIGNUM *)0x0) {
      rnd = BN_new();
      if (rnd == (BIGNUM *)0x0) goto LAB_000a4dd0;
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    pBVar7 = *(BIGNUM **)(param_1 + 0x14);
    if ((pBVar7 == (BIGNUM *)0x0) && (pBVar7 = BN_new(), pBVar7 == (BIGNUM *)0x0))
    goto LAB_000a4cea;
    if ((*(uint *)(param_1 + 0x1c) & 1) == 0) {
      pBVar4 = (BN_MONT_CTX *)0x0;
    }
    else {
      pBVar4 = BN_MONT_CTX_set_locked
                         ((BN_MONT_CTX **)(param_1 + 0x20),0x1a,*(BIGNUM **)(param_1 + 8),ctx);
      if (pBVar4 == (BN_MONT_CTX *)0x0) goto LAB_000a4cea;
    }
    if (bVar1) {
      pBVar5 = *(BIGNUM **)(param_1 + 0x24);
      if (pBVar5 == (BIGNUM *)0x0) {
        iVar6 = *(int *)(param_1 + 0x10);
        if (iVar6 == 0) {
          iVar6 = BN_num_bits(*(BIGNUM **)(param_1 + 8));
          iVar6 = iVar6 + -1;
        }
        iVar6 = BN_rand(rnd,iVar6,0,0);
        if (iVar6 != 0) goto LAB_000a4d38;
      }
      else {
        while (iVar6 = BN_rand_range(rnd,pBVar5), iVar6 != 0) {
          if ((rnd->top != 0) && (((rnd->top != 1 || (*rnd->d != 1)) || (rnd->neg != 0))))
          goto LAB_000a4d38;
          pBVar5 = *(BIGNUM **)(param_1 + 0x24);
        }
      }
      goto LAB_000a4cea;
    }
LAB_000a4d38:
    pBVar5 = rnd;
    if (-1 < *(int *)(param_1 + 0x1c) << 0x1e) {
      BN_init(&local_34);
      local_34.top = rnd->top;
      local_34.d = rnd->d;
      local_34.flags = local_34.flags & 1U | rnd->flags & 0xfffffffeU | 6;
      local_34.neg = rnd->neg;
      local_34.dmax = rnd->dmax;
      pBVar5 = &local_34;
    }
    iVar6 = (**(code **)(*(int *)(param_1 + 0x44) + 0xc))
                      (param_1,pBVar7,*(undefined4 *)(param_1 + 0xc),pBVar5,
                       *(undefined4 *)(param_1 + 8),ctx,pBVar4);
    if (iVar6 == 0) goto LAB_000a4cea;
    *(BIGNUM **)(param_1 + 0x14) = pBVar7;
    *(BIGNUM **)(param_1 + 0x18) = rnd;
    pBVar3 = (BIGNUM *)0x1;
    pBVar5 = pBVar7;
    pBVar2 = pBVar7;
  }
  pBVar7 = pBVar3;
  if (pBVar2 == (BIGNUM *)0x0) {
    BN_free(pBVar5);
  }
LAB_000a4d08:
  if ((rnd != (BIGNUM *)0x0) && (*(int *)(param_1 + 0x18) == 0)) {
    BN_free(rnd);
  }
  BN_CTX_free(ctx);
  return pBVar7;
}

