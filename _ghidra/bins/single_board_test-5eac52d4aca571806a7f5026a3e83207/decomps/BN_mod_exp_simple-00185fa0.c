
int BN_mod_exp_simple(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *r_00;
  BIGNUM *pBVar2;
  int iVar3;
  BIGNUM *a_00;
  uint uVar4;
  BIGNUM **ppBVar5;
  int iVar6;
  int iVar7;
  int local_b8;
  int local_b4;
  int local_b0;
  BIGNUM *local_a8 [33];
  
  iVar1 = BN_get_flags(p,4);
  if (((iVar1 != 0) || (iVar1 = BN_get_flags(a,4), iVar1 != 0)) ||
     (iVar1 = BN_get_flags(m,4), iVar1 != 0)) {
    ERR_put_error(3,0x7e,0x42,"crypto/bn/bn_exp.c",0x513);
    return 0;
  }
  local_b8 = BN_num_bits(p);
  if (local_b8 == 0) {
    iVar1 = BN_abs_is_word(m,1);
    if (iVar1 != 0) {
      BN_set_word(r,0);
      return 1;
    }
    iVar1 = BN_set_word(r,1);
    return iVar1;
  }
  BN_CTX_start(ctx);
  r_00 = BN_CTX_get(ctx);
  pBVar2 = BN_CTX_get(ctx);
  local_a8[0] = pBVar2;
  if ((pBVar2 != (BIGNUM *)0x0) && (iVar1 = BN_nnmod(pBVar2,a,m,ctx), iVar1 != 0)) {
    iVar1 = BN_is_zero(pBVar2);
    if (iVar1 != 0) {
      BN_set_word(r,0);
      iVar1 = 1;
      goto LAB_00186020;
    }
    if (local_b8 < 0x2a0) {
      if (0xef < local_b8) {
        local_b4 = 0x10;
        local_b0 = 5;
        goto LAB_00186154;
      }
      if (0x4f < local_b8) {
        local_b4 = 8;
        local_b0 = 4;
        goto LAB_00186154;
      }
      if (0x17 < local_b8) {
        local_b4 = 4;
        local_b0 = 3;
        goto LAB_00186154;
      }
      local_b0 = 1;
    }
    else {
      local_b4 = 0x20;
      local_b0 = 6;
LAB_00186154:
      iVar1 = BN_mod_mul(r_00,pBVar2,pBVar2,m,ctx);
      if (iVar1 == 0) goto LAB_0018601e;
      ppBVar5 = local_a8;
      iVar1 = 1;
      do {
        iVar1 = iVar1 + 1;
        pBVar2 = BN_CTX_get(ctx);
        ppBVar5[1] = pBVar2;
        if (pBVar2 == (BIGNUM *)0x0) goto LAB_0018601e;
        a_00 = *ppBVar5;
        ppBVar5 = ppBVar5 + 1;
        iVar3 = BN_mod_mul(pBVar2,a_00,r_00,m,ctx);
        if (iVar3 == 0) goto LAB_0018601e;
      } while (iVar1 < local_b4);
    }
    iVar1 = BN_set_word(r,1);
    if (iVar1 != 0) {
      local_b8 = local_b8 + -1;
      local_b4 = 1;
      while( true ) {
        while (iVar1 = BN_is_bit_set(p,local_b8), iVar1 == 0) {
          if ((local_b4 == 0) && (iVar1 = BN_mod_mul(r,r,r,m,ctx), iVar1 == 0)) goto LAB_0018601e;
          if (local_b8 == 0) goto LAB_001861dc;
          local_b8 = local_b8 + -1;
        }
        if (local_b0 == 1) {
          iVar1 = 0;
          uVar4 = 1;
        }
        else {
          iVar1 = 0;
          uVar4 = 1;
          if (-1 < local_b8 + -1) {
            iVar7 = 1;
            uVar4 = 1;
            iVar3 = local_b8 + -1;
            do {
              iVar6 = iVar3 + -1;
              iVar3 = BN_is_bit_set(p,iVar3);
              if (iVar3 != 0) {
                uVar4 = uVar4 << (iVar7 - iVar1 & 0xffU) | 1;
                iVar1 = iVar7;
              }
              iVar7 = iVar7 + 1;
            } while ((iVar7 != local_b0) && (iVar3 = iVar6, iVar6 != -1));
          }
        }
        if (local_b4 == 0) {
          do {
            local_b4 = local_b4 + 1;
            iVar3 = BN_mod_mul(r,r,r,m,ctx);
            if (iVar3 == 0) goto LAB_0018601e;
          } while (local_b4 <= iVar1);
        }
        iVar3 = BN_mod_mul(r,r,local_a8[(int)uVar4 >> 1],m,ctx);
        if (iVar3 == 0) goto LAB_0018601e;
        local_b8 = local_b8 - (iVar1 + 1);
        if (local_b8 < 0) break;
        local_b4 = 0;
      }
LAB_001861dc:
      iVar1 = 1;
      goto LAB_00186020;
    }
  }
LAB_0018601e:
  iVar1 = 0;
LAB_00186020:
  BN_CTX_end(ctx);
  return iVar1;
}

