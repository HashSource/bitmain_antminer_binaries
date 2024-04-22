
int BN_mod_exp_recp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  bool bVar1;
  BIGNUM *a_00;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  BIGNUM *pBVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  BIGNUM **ppBVar10;
  int local_ec;
  int local_e8;
  BN_RECP_CTX BStack_dc;
  BIGNUM *local_a8 [33];
  
  if ((p->flags & 4U) != 0) {
    ERR_put_error(3,0x7d,0x42,DAT_000ef9ec,0x11e);
    return -1;
  }
  local_ec = BN_num_bits(p);
  if (local_ec == 0) {
    iVar3 = BN_set_word(r,1);
    return iVar3;
  }
  BN_CTX_start(ctx);
  a_00 = BN_CTX_get(ctx);
  pBVar2 = BN_CTX_get(ctx);
  local_a8[0] = pBVar2;
  if ((a_00 != (BIGNUM *)0x0) && (pBVar2 != (BIGNUM *)0x0)) {
    BN_RECP_CTX_init(&BStack_dc);
    if (m->neg == 0) {
      iVar3 = BN_RECP_CTX_set(&BStack_dc,m,ctx);
    }
    else {
      pBVar5 = BN_copy(a_00,m);
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_000ef928;
      a_00->neg = 0;
      iVar3 = BN_RECP_CTX_set(&BStack_dc,a_00,ctx);
    }
    if ((0 < iVar3) && (iVar3 = BN_nnmod(pBVar2,a,m,ctx), iVar3 != 0)) {
      if (pBVar2->top == 0) {
        iVar3 = 1;
        BN_set_word(r,0);
        goto LAB_000ef92a;
      }
      if (local_ec < 0x2a0) {
        if (0xef < local_ec) {
          local_e8 = 5;
          goto LAB_000ef81a;
        }
        if (0x4f < local_ec) {
          local_e8 = 4;
          goto LAB_000ef81a;
        }
        if (0x17 < local_ec) {
          local_e8 = 3;
          goto LAB_000ef81a;
        }
        local_e8 = 1;
      }
      else {
        local_e8 = 6;
LAB_000ef81a:
        iVar3 = BN_mod_mul_reciprocal(a_00,pBVar2,pBVar2,&BStack_dc,ctx);
        if (iVar3 == 0) goto LAB_000ef928;
        iVar3 = 1;
        iVar9 = 1 << (local_e8 - 1U & 0xff);
        if (1 < iVar9) {
          ppBVar10 = local_a8;
          do {
            iVar3 = iVar3 + 1;
            pBVar2 = BN_CTX_get(ctx);
            ppBVar10[1] = pBVar2;
            if ((pBVar2 == (BIGNUM *)0x0) ||
               (iVar4 = BN_mod_mul_reciprocal(pBVar2,*ppBVar10,a_00,&BStack_dc,ctx), iVar4 == 0))
            goto LAB_000ef928;
            ppBVar10 = ppBVar10 + 1;
          } while (iVar3 != iVar9);
        }
      }
      iVar3 = BN_set_word(r,1);
      if (iVar3 != 0) {
        local_ec = local_ec + -1;
        bVar1 = true;
        while( true ) {
          while (iVar3 = BN_is_bit_set(p,local_ec), iVar3 == 0) {
            if ((!bVar1) && (iVar3 = BN_mod_mul_reciprocal(r,r,r,&BStack_dc,ctx), iVar3 == 0))
            goto LAB_000ef928;
            if (local_ec == 0) goto LAB_000ef9b8;
            local_ec = local_ec + -1;
          }
          if (local_e8 == 1) {
            uVar7 = 0;
            uVar8 = 1;
          }
          else {
            uVar8 = 1;
            if (local_ec + -1 < 0) {
              uVar7 = 0;
            }
            else {
              uVar7 = 0;
              uVar6 = 1;
              iVar3 = local_ec + -1;
              iVar9 = local_ec + -2;
              do {
                iVar3 = BN_is_bit_set(p,iVar3);
                if (iVar3 != 0) {
                  uVar8 = uVar8 << (uVar6 - uVar7 & 0xff) | 1;
                  uVar7 = uVar6;
                }
                uVar6 = uVar6 + 1;
                iVar4 = iVar9 + -1;
              } while ((iVar9 != local_ec - local_e8) && (iVar3 = iVar9, iVar9 = iVar4, iVar4 != -2)
                      );
            }
          }
          if (!bVar1) {
            iVar3 = 0;
            do {
              iVar3 = iVar3 + 1;
              iVar9 = BN_mod_mul_reciprocal(r,r,r,&BStack_dc,ctx);
              if (iVar9 == 0) goto LAB_000ef928;
            } while (iVar3 <= (int)uVar7);
          }
          iVar3 = BN_mod_mul_reciprocal(r,r,local_a8[(int)uVar8 >> 1],&BStack_dc,ctx);
          if (iVar3 == 0) goto LAB_000ef928;
          local_ec = local_ec + ~uVar7;
          if (local_ec < 0) break;
          bVar1 = false;
        }
LAB_000ef9b8:
        iVar3 = 1;
        goto LAB_000ef92a;
      }
    }
  }
LAB_000ef928:
  iVar3 = 0;
LAB_000ef92a:
  BN_CTX_end(ctx);
  BN_RECP_CTX_free(&BStack_dc);
  return iVar3;
}

