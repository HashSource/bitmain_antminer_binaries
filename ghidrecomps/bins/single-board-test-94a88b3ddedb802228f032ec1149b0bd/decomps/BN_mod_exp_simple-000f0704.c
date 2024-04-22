
int BN_mod_exp_simple(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  bool bVar1;
  BIGNUM *r_00;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  BIGNUM **ppBVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int local_b8;
  int local_b4;
  BIGNUM *local_a8 [33];
  
  if (p->flags << 0x1d < 0) {
    ERR_put_error(3,0x7e,0x42,DAT_000f0928,0x514);
    return -1;
  }
  local_b8 = BN_num_bits(p);
  if (local_b8 == 0) {
    iVar3 = BN_set_word(r,1);
    return iVar3;
  }
  BN_CTX_start(ctx);
  r_00 = BN_CTX_get(ctx);
  pBVar2 = BN_CTX_get(ctx);
  local_a8[0] = pBVar2;
  if (((r_00 != (BIGNUM *)0x0) && (pBVar2 != (BIGNUM *)0x0)) &&
     (iVar3 = BN_nnmod(pBVar2,a,m,ctx), iVar3 != 0)) {
    if (pBVar2->top == 0) {
      iVar3 = 1;
      BN_set_word(r,0);
      goto LAB_000f0754;
    }
    if (local_b8 < 0x2a0) {
      if (0xef < local_b8) {
        local_b4 = 5;
        goto LAB_000f07a2;
      }
      if (0x4f < local_b8) {
        local_b4 = 4;
        goto LAB_000f07a2;
      }
      if (0x17 < local_b8) {
        local_b4 = 3;
        goto LAB_000f07a2;
      }
      local_b4 = 1;
    }
    else {
      local_b4 = 6;
LAB_000f07a2:
      iVar3 = BN_mod_mul(r_00,pBVar2,pBVar2,m,ctx);
      if (iVar3 == 0) goto LAB_000f0752;
      iVar3 = 1;
      iVar9 = 1 << (local_b4 - 1U & 0xff);
      if (1 < iVar9) {
        ppBVar5 = local_a8;
        do {
          iVar3 = iVar3 + 1;
          pBVar2 = BN_CTX_get(ctx);
          ppBVar5[1] = pBVar2;
          if ((pBVar2 == (BIGNUM *)0x0) ||
             (iVar4 = BN_mod_mul(pBVar2,*ppBVar5,r_00,m,ctx), iVar4 == 0)) goto LAB_000f0752;
          ppBVar5 = ppBVar5 + 1;
        } while (iVar3 != iVar9);
      }
    }
    iVar3 = BN_set_word(r,1);
    if (iVar3 != 0) {
      local_b8 = local_b8 + -1;
      bVar1 = true;
      while( true ) {
        while (iVar3 = BN_is_bit_set(p,local_b8), iVar3 == 0) {
          if ((!bVar1) && (iVar3 = BN_mod_mul(r,r,r,m,ctx), iVar3 == 0)) goto LAB_000f0752;
          if (local_b8 == 0) goto LAB_000f08f2;
          local_b8 = local_b8 + -1;
        }
        if (local_b4 == 1) {
          uVar6 = 0;
          uVar7 = 1;
        }
        else {
          uVar7 = 1;
          if (local_b8 + -1 < 0) {
            uVar6 = 0;
          }
          else {
            uVar8 = 1;
            uVar6 = 0;
            iVar3 = local_b8 + -1;
            iVar9 = local_b8 + -2;
            do {
              iVar3 = BN_is_bit_set(p,iVar3);
              if (iVar3 != 0) {
                uVar7 = uVar7 << (uVar8 - uVar6 & 0xff) | 1;
                uVar6 = uVar8;
              }
              uVar8 = uVar8 + 1;
              iVar4 = iVar9 + -1;
            } while ((iVar9 != local_b8 - local_b4) && (iVar3 = iVar9, iVar9 = iVar4, iVar4 != -2));
          }
        }
        if (!bVar1) {
          iVar3 = 0;
          do {
            iVar3 = iVar3 + 1;
            iVar9 = BN_mod_mul(r,r,r,m,ctx);
            if (iVar9 == 0) goto LAB_000f0752;
          } while (iVar3 <= (int)uVar6);
        }
        iVar3 = BN_mod_mul(r,r,local_a8[(int)uVar7 >> 1],m,ctx);
        if (iVar3 == 0) goto LAB_000f0752;
        local_b8 = local_b8 + ~uVar6;
        if (local_b8 < 0) break;
        bVar1 = false;
      }
LAB_000f08f2:
      iVar3 = 1;
      goto LAB_000f0754;
    }
  }
LAB_000f0752:
  iVar3 = 0;
LAB_000f0754:
  BN_CTX_end(ctx);
  return iVar3;
}

