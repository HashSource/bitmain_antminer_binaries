
int BN_MONT_CTX_set(BN_MONT_CTX *mont,BIGNUM *mod,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *a;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  uint uVar4;
  ulong uVar5;
  int iVar6;
  BIGNUM *a_00;
  ulong local_3c;
  undefined4 local_38;
  BIGNUM local_34;
  
  iVar1 = BN_is_zero(mod);
  if (iVar1 != 0) {
    return 0;
  }
  BN_CTX_start(ctx);
  a = BN_CTX_get(ctx);
  if (a != (BIGNUM *)0x0) {
    a_00 = &mont->N;
    pBVar2 = BN_copy(a_00,mod);
    if (pBVar2 != (BIGNUM *)0x0) {
      iVar1 = BN_get_flags(mod,4);
      if (iVar1 != 0) {
        BN_set_flags(a_00,4);
      }
      (mont->N).neg = 0;
      bn_init(&local_34);
      local_34.d = &local_3c;
      local_34.neg = 0;
      local_34.dmax = 2;
      iVar1 = BN_get_flags(mod,4);
      if (iVar1 != 0) {
        BN_set_flags(&local_34,4);
      }
      pBVar2 = &mont->RR;
      iVar1 = BN_num_bits(mod);
      uVar4 = iVar1 + 0x7e;
      if (-1 < (int)(iVar1 + 0x3fU)) {
        uVar4 = iVar1 + 0x3fU;
      }
      mont->ri = uVar4 & 0xffffffc0;
      BN_set_word(pBVar2,0);
      iVar1 = BN_set_bit(pBVar2,0x40);
      if (iVar1 != 0) {
        local_3c = *mod->d;
        local_38 = 0;
        local_34.top = local_3c;
        if (local_3c != 0) {
          local_34.top = 1;
        }
        iVar1 = BN_is_one(&local_34);
        if (iVar1 == 0) {
          pBVar3 = BN_mod_inverse(a,pBVar2,&local_34,ctx);
          if (pBVar3 == (BIGNUM *)0x0) goto LAB_0010d238;
        }
        else {
          BN_set_word(a,0);
        }
        iVar1 = BN_lshift(a,a,0x40);
        if (iVar1 != 0) {
          iVar1 = BN_is_zero(a);
          if (iVar1 == 0) {
            iVar1 = BN_sub_word(a,1);
          }
          else {
            iVar1 = BN_set_word(a,0xffffffff);
          }
          if ((iVar1 != 0) && (iVar1 = BN_div(a,(BIGNUM *)0x0,a,&local_34,ctx), iVar1 != 0)) {
            if (a->top < 1) {
              uVar5 = 0;
            }
            else {
              uVar5 = *a->d;
            }
            mont->n0[1] = 0;
            mont->n0[0] = uVar5;
            BN_set_word(pBVar2,0);
            iVar1 = BN_set_bit(pBVar2,mont->ri << 1);
            if ((iVar1 != 0) && (iVar1 = BN_div((BIGNUM *)0x0,pBVar2,pBVar2,a_00,ctx), iVar1 != 0))
            {
              iVar1 = (mont->RR).top;
              iVar6 = (mont->N).top;
              if (iVar1 < iVar6) {
                memset((mont->RR).d + iVar1,0,(iVar6 - iVar1) * 4);
              }
              (mont->RR).top = iVar6;
              iVar1 = 1;
              goto LAB_0010d23a;
            }
          }
        }
      }
    }
  }
LAB_0010d238:
  iVar1 = 0;
LAB_0010d23a:
  BN_CTX_end(ctx);
  return iVar1;
}

