
int BN_MONT_CTX_set(BN_MONT_CTX *mont,BIGNUM *mod,BN_CTX *ctx)

{
  BIGNUM *ret;
  BIGNUM *pBVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  BIGNUM *a;
  ulong local_3c;
  undefined4 local_38;
  BIGNUM local_34;
  
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  if (ret != (BIGNUM *)0x0) {
    a = &mont->RR;
    pBVar1 = BN_copy(&mont->N,mod);
    if (pBVar1 != (BIGNUM *)0x0) {
      (mont->N).neg = 0;
      BN_init(&local_34);
      local_34.d = &local_3c;
      local_34.dmax = 2;
      local_34.neg = 0;
      iVar2 = BN_num_bits(mod);
      uVar3 = iVar2 + 0x1fU;
      if ((int)(iVar2 + 0x1fU) < 0) {
        uVar3 = iVar2 + 0x3e;
      }
      mont->ri = uVar3 & 0xffffffe0;
      BN_set_word(a,0);
      iVar2 = BN_set_bit(a,0x20);
      if (iVar2 != 0) {
        local_3c = *mod->d;
        local_38 = 0;
        local_34.top = local_3c;
        if (local_3c != 0) {
          local_34.top = 1;
        }
        pBVar1 = BN_mod_inverse(ret,a,&local_34,ctx);
        if ((pBVar1 != (BIGNUM *)0x0) && (iVar2 = BN_lshift(ret,ret,0x20), iVar2 != 0)) {
          if (ret->top == 0) {
            iVar2 = BN_set_word(ret,0xffffffff);
          }
          else {
            iVar2 = BN_sub_word(ret,1);
          }
          if ((iVar2 != 0) && (iVar2 = BN_div(ret,(BIGNUM *)0x0,ret,&local_34,ctx), iVar2 != 0)) {
            if (ret->top < 1) {
              uVar4 = 0;
            }
            else {
              uVar4 = *ret->d;
            }
            mont->n0[1] = 0;
            mont->n0[0] = uVar4;
            BN_set_word(a,0);
            iVar2 = BN_set_bit(a,mont->ri << 1);
            if (iVar2 != 0) {
              iVar2 = BN_div((BIGNUM *)0x0,a,a,&mont->N,ctx);
              if (iVar2 != 0) {
                iVar2 = 1;
              }
              goto LAB_000f4a8e;
            }
          }
        }
      }
    }
  }
  iVar2 = 0;
LAB_000f4a8e:
  BN_CTX_end(ctx);
  return iVar2;
}

