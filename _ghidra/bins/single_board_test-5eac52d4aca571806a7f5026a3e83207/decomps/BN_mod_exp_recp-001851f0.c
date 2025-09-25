
int BN_mod_exp_recp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *a_00;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  BIGNUM **ppBVar8;
  int iVar9;
  int local_e8;
  int local_e4;
  BN_RECP_CTX BStack_dc;
  BIGNUM *local_a8 [33];
  
  iVar1 = BN_get_flags(p,4);
  if (((iVar1 != 0) || (iVar1 = BN_get_flags(a,4), iVar1 != 0)) ||
     (iVar1 = BN_get_flags(m,4), iVar1 != 0)) {
    ERR_put_error(3,0x7d,0x42,"crypto/bn/bn_exp.c",0xaf);
    return 0;
  }
  iVar1 = BN_num_bits(p);
  if (iVar1 == 0) {
    iVar1 = BN_abs_is_word(m,1);
    if (iVar1 == 0) {
      iVar1 = BN_set_word(r,1);
      return iVar1;
    }
    BN_set_word(r,0);
    return 1;
  }
  BN_RECP_CTX_init(&BStack_dc);
  BN_CTX_start(ctx);
  a_00 = BN_CTX_get(ctx);
  pBVar2 = BN_CTX_get(ctx);
  local_a8[0] = pBVar2;
  if (pBVar2 != (BIGNUM *)0x0) {
    if (m->neg == 0) {
      iVar4 = BN_RECP_CTX_set(&BStack_dc,m,ctx);
    }
    else {
      pBVar3 = BN_copy(a_00,m);
      if (pBVar3 == (BIGNUM *)0x0) goto LAB_00185296;
      a_00->neg = 0;
      iVar4 = BN_RECP_CTX_set(&BStack_dc,a_00,ctx);
    }
    if ((0 < iVar4) && (iVar4 = BN_nnmod(pBVar2,a,m,ctx), iVar4 != 0)) {
      iVar4 = BN_is_zero(pBVar2);
      if (iVar4 != 0) {
        BN_set_word(r,0);
        iVar1 = 1;
        goto LAB_00185298;
      }
      if (iVar1 < 0x2a0) {
        if (0xef < iVar1) {
          iVar4 = 0x10;
          local_e4 = 5;
          goto LAB_001853c0;
        }
        if (0x4f < iVar1) {
          iVar4 = 8;
          local_e4 = 4;
          goto LAB_001853c0;
        }
        if (0x17 < iVar1) {
          iVar4 = 4;
          local_e4 = 3;
          goto LAB_001853c0;
        }
        local_e4 = 1;
      }
      else {
        iVar4 = 0x20;
        local_e4 = 6;
LAB_001853c0:
        iVar5 = BN_mod_mul_reciprocal(a_00,pBVar2,pBVar2,&BStack_dc,ctx);
        if (iVar5 == 0) goto LAB_00185296;
        iVar5 = 1;
        ppBVar8 = local_a8;
        do {
          iVar5 = iVar5 + 1;
          pBVar2 = BN_CTX_get(ctx);
          ppBVar8[1] = pBVar2;
          if (pBVar2 == (BIGNUM *)0x0) goto LAB_00185296;
          iVar6 = BN_mod_mul_reciprocal(pBVar2,*ppBVar8,a_00,&BStack_dc,ctx);
          if (iVar6 == 0) goto LAB_00185296;
          ppBVar8 = ppBVar8 + 1;
        } while (iVar5 < iVar4);
      }
      iVar4 = BN_set_word(r,1);
      if (iVar4 != 0) {
        iVar1 = iVar1 + -1;
        local_e8 = 1;
        while( true ) {
          while (iVar4 = BN_is_bit_set(p,iVar1), iVar4 == 0) {
            if ((local_e8 == 0) && (iVar4 = BN_mod_mul_reciprocal(r,r,r,&BStack_dc,ctx), iVar4 == 0)
               ) goto LAB_00185296;
            if (iVar1 == 0) goto LAB_0018543a;
            iVar1 = iVar1 + -1;
          }
          if (local_e4 == 1) {
            iVar4 = 0;
            uVar7 = 1;
          }
          else {
            uVar7 = 1;
            iVar4 = 0;
            if (-1 < iVar1 + -1) {
              iVar6 = 1;
              iVar5 = iVar1 + -1;
              do {
                iVar9 = iVar5 + -1;
                iVar5 = BN_is_bit_set(p,iVar5);
                if (iVar5 != 0) {
                  uVar7 = uVar7 << (iVar6 - iVar4 & 0xffU) | 1;
                  iVar4 = iVar6;
                }
                iVar6 = iVar6 + 1;
              } while ((iVar6 != local_e4) && (iVar5 = iVar9, iVar9 != -1));
            }
          }
          if (local_e8 == 0) {
            do {
              local_e8 = local_e8 + 1;
              iVar5 = BN_mod_mul_reciprocal(r,r,r,&BStack_dc,ctx);
              if (iVar5 == 0) goto LAB_00185296;
            } while (local_e8 <= iVar4);
          }
          iVar5 = BN_mod_mul_reciprocal(r,r,local_a8[(int)uVar7 >> 1],&BStack_dc,ctx);
          if (iVar5 == 0) goto LAB_00185296;
          iVar1 = iVar1 - (iVar4 + 1);
          if (iVar1 < 0) break;
          local_e8 = 0;
        }
LAB_0018543a:
        iVar1 = 1;
        goto LAB_00185298;
      }
    }
  }
LAB_00185296:
  iVar1 = 0;
LAB_00185298:
  BN_CTX_end(ctx);
  BN_RECP_CTX_free(&BStack_dc);
  return iVar1;
}

