
int BN_mod_exp_mont(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *m_ctx)

{
  bool bVar1;
  int iVar2;
  BIGNUM *pBVar3;
  BIGNUM *a_00;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  uint uVar6;
  BIGNUM **ppBVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  BN_MONT_CTX *local_c0;
  int local_bc;
  int local_b4;
  int local_b0;
  BIGNUM *local_a8 [33];
  
  iVar2 = BN_get_flags(p,4);
  if (((iVar2 != 0) || (iVar2 = BN_get_flags(a,4), iVar2 != 0)) ||
     (iVar2 = BN_get_flags(m,4), iVar2 != 0)) {
    iVar2 = BN_mod_exp_mont_consttime(r,a,p,m,ctx,m_ctx);
    return iVar2;
  }
  iVar2 = BN_is_odd(m);
  if (iVar2 == 0) {
    ERR_put_error(3,0x6d,0x66,"crypto/bn/bn_exp.c",0x13f);
    return 0;
  }
  local_bc = BN_num_bits(p);
  if (local_bc == 0) {
    iVar2 = BN_abs_is_word(m,1);
    if (iVar2 != 0) {
      BN_set_word(r,0);
      return 1;
    }
    iVar2 = BN_set_word(r,1);
    return iVar2;
  }
  BN_CTX_start(ctx);
  pBVar3 = BN_CTX_get(ctx);
  a_00 = BN_CTX_get(ctx);
  pBVar4 = BN_CTX_get(ctx);
  local_a8[0] = pBVar4;
  if (pBVar4 == (BIGNUM *)0x0) {
    iVar2 = 0;
    local_c0 = (BN_MONT_CTX *)0x0;
LAB_001938e0:
    if (m_ctx != (BN_MONT_CTX *)0x0) goto LAB_001938e6;
  }
  else {
    if (m_ctx != (BN_MONT_CTX *)0x0) {
      local_c0 = m_ctx;
LAB_001937d2:
      if ((((a->neg != 0) || (iVar2 = BN_ucmp(a,m), -1 < iVar2)) &&
          (iVar2 = BN_nnmod(pBVar4,a,m,ctx), a = pBVar4, iVar2 == 0)) ||
         (iVar2 = bn_to_mont_fixed_top(pBVar4,a,local_c0,ctx), iVar2 == 0)) goto LAB_001938e0;
      if (local_bc < 0x2a0) {
        if (0xef < local_bc) {
          local_b4 = 0x10;
          local_b0 = 5;
          goto LAB_00193942;
        }
        if (0x4f < local_bc) {
          local_b4 = 8;
          local_b0 = 4;
          goto LAB_00193942;
        }
        if (0x17 < local_bc) {
          local_b4 = 4;
          local_b0 = 3;
          goto LAB_00193942;
        }
        local_b0 = 1;
      }
      else {
        local_b4 = 0x20;
        local_b0 = 6;
LAB_00193942:
        iVar2 = bn_mul_mont_fixed_top(pBVar3,pBVar4,pBVar4,local_c0,ctx);
        if (iVar2 == 0) goto LAB_001938e0;
        ppBVar7 = local_a8;
        iVar9 = 1;
        do {
          iVar9 = iVar9 + 1;
          pBVar4 = BN_CTX_get(ctx);
          ppBVar7[1] = pBVar4;
          if (pBVar4 == (BIGNUM *)0x0) {
            iVar2 = 0;
            goto LAB_001938e0;
          }
          pBVar5 = *ppBVar7;
          ppBVar7 = ppBVar7 + 1;
          iVar2 = bn_mul_mont_fixed_top(pBVar4,pBVar5,pBVar3,local_c0,ctx);
          if (iVar2 == 0) goto LAB_001938e0;
        } while (iVar9 < local_b4);
      }
      pBVar3 = BN_value_one();
      iVar2 = bn_to_mont_fixed_top(a_00,pBVar3,local_c0,ctx);
      if (iVar2 != 0) {
        local_bc = local_bc + -1;
        bVar1 = true;
        while( true ) {
          while (iVar2 = BN_is_bit_set(p,local_bc), iVar2 == 0) {
            if ((!bVar1) && (iVar2 = bn_mul_mont_fixed_top(a_00,a_00,a_00,local_c0,ctx), iVar2 == 0)
               ) {
              iVar2 = 0;
              goto LAB_001938e0;
            }
            if (local_bc == 0) goto LAB_00193a1e;
            local_bc = local_bc + -1;
          }
          if (local_b0 == 1) {
            iVar9 = 0;
            uVar6 = 1;
          }
          else {
            iVar9 = 0;
            uVar6 = 1;
            if (-1 < local_bc + -1) {
              iVar8 = 1;
              iVar2 = local_bc + -1;
              do {
                iVar10 = iVar2 + -1;
                iVar2 = BN_is_bit_set(p,iVar2);
                if (iVar2 != 0) {
                  uVar6 = uVar6 << (iVar8 - iVar9 & 0xffU) | 1;
                  iVar9 = iVar8;
                }
                iVar8 = iVar8 + 1;
              } while ((iVar8 != local_b0) && (iVar2 = iVar10, iVar10 != -1));
            }
          }
          if (!bVar1) {
            iVar8 = 0;
            do {
              iVar8 = iVar8 + 1;
              iVar2 = bn_mul_mont_fixed_top(a_00,a_00,a_00,local_c0,ctx);
              if (iVar2 == 0) goto LAB_001938e0;
            } while (iVar8 <= iVar9);
          }
          iVar2 = bn_mul_mont_fixed_top(a_00,a_00,local_a8[(int)uVar6 >> 1],local_c0,ctx);
          if (iVar2 == 0) goto LAB_001938e0;
          local_bc = local_bc - (iVar9 + 1);
          if (local_bc < 0) break;
          bVar1 = false;
        }
LAB_00193a1e:
        iVar2 = BN_from_montgomery(r,a_00,local_c0,ctx);
        if (iVar2 != 0) {
          iVar2 = 1;
        }
      }
      goto LAB_001938e0;
    }
    local_c0 = BN_MONT_CTX_new();
    if ((local_c0 != (BN_MONT_CTX *)0x0) && (iVar2 = BN_MONT_CTX_set(local_c0,m,ctx), iVar2 != 0))
    goto LAB_001937d2;
    iVar2 = 0;
  }
  BN_MONT_CTX_free(local_c0);
LAB_001938e6:
  BN_CTX_end(ctx);
  return iVar2;
}

