
int BN_mod_exp_mont(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *m_ctx)

{
  bool bVar1;
  uint *puVar2;
  BIGNUM *pBVar3;
  BIGNUM *a_00;
  BIGNUM *pBVar4;
  int iVar5;
  int iVar6;
  ulong *puVar7;
  ulong *puVar8;
  ulong *puVar9;
  int iVar10;
  BIGNUM **ppBVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  ulong *puVar16;
  BN_MONT_CTX *local_c0;
  int local_bc;
  int local_b8;
  BIGNUM *local_a8 [33];
  
  if ((p->flags & 4U) != 0) {
    iVar5 = BN_mod_exp_mont_consttime(r,a,p,m,ctx,m_ctx);
    return iVar5;
  }
  if ((m->top < 1) || (-1 < (int)(*m->d << 0x1f))) {
    ERR_put_error(3,0x6d,0x66,DAT_000f0234,0x1a6);
    return 0;
  }
  local_bc = BN_num_bits(p);
  if (local_bc == 0) {
    iVar5 = BN_set_word(r,1);
    return iVar5;
  }
  BN_CTX_start(ctx);
  pBVar3 = BN_CTX_get(ctx);
  a_00 = BN_CTX_get(ctx);
  pBVar4 = BN_CTX_get(ctx);
  local_a8[0] = pBVar4;
  if ((pBVar3 == (BIGNUM *)0x0 || a_00 == (BIGNUM *)0x0) || (pBVar4 == (BIGNUM *)0x0)) {
LAB_000f0088:
    iVar5 = 0;
    goto LAB_000f008a;
  }
  if (m_ctx == (BN_MONT_CTX *)0x0) {
    local_c0 = BN_MONT_CTX_new();
    if (local_c0 == (BN_MONT_CTX *)0x0) goto LAB_000f0088;
    iVar5 = BN_MONT_CTX_set(local_c0,m,ctx);
    if (iVar5 != 0) goto LAB_000f0016;
    iVar5 = 0;
  }
  else {
    local_c0 = m_ctx;
LAB_000f0016:
    if (((a->neg == 0) && (iVar5 = BN_ucmp(a,m), iVar5 < 0)) ||
       (iVar5 = BN_nnmod(pBVar4,a,m,ctx), a = pBVar4, iVar5 != 0)) {
      pBVar4 = local_a8[0];
      if (a->top == 0) {
        iVar5 = 1;
        BN_set_word(r,0);
      }
      else {
        iVar5 = BN_mod_mul_montgomery(local_a8[0],a,&local_c0->RR,local_c0,ctx);
        if (iVar5 == 0) goto LAB_000f0084;
        if (local_bc < 0x2a0) {
          if (0xef < local_bc) {
            local_b8 = 5;
            goto LAB_000f00d0;
          }
          if (0x4f < local_bc) {
            local_b8 = 4;
            goto LAB_000f00d0;
          }
          if (0x17 < local_bc) {
            local_b8 = 3;
            goto LAB_000f00d0;
          }
          local_b8 = 1;
        }
        else {
          local_b8 = 6;
LAB_000f00d0:
          iVar5 = BN_mod_mul_montgomery(pBVar3,pBVar4,pBVar4,local_c0,ctx);
          if (iVar5 == 0) goto LAB_000f0084;
          iVar5 = 1 << (local_b8 - 1U & 0xff);
          if (1 < iVar5) {
            iVar12 = 1;
            ppBVar11 = local_a8;
            do {
              iVar12 = iVar12 + 1;
              pBVar4 = BN_CTX_get(ctx);
              ppBVar11[1] = pBVar4;
              if ((pBVar4 == (BIGNUM *)0x0) ||
                 (iVar6 = BN_mod_mul_montgomery(pBVar4,*ppBVar11,pBVar3,local_c0,ctx), iVar6 == 0))
              goto LAB_000f0084;
              ppBVar11 = ppBVar11 + 1;
            } while (iVar12 != iVar5);
          }
        }
        iVar5 = m->top;
        puVar16 = m->d;
        if ((int)puVar16[iVar5 + -1] < 0) {
          if (a_00->dmax < iVar5) {
            pBVar3 = bn_expand2(a_00,iVar5);
            if (pBVar3 == (BIGNUM *)0x0) goto LAB_000f0084;
            puVar16 = m->d;
          }
          puVar7 = a_00->d;
          *puVar7 = -*puVar16;
          if (iVar5 < 2) {
            a_00->top = iVar5;
            if (iVar5 < 1) goto LAB_000f016c;
          }
          else {
            if (iVar5 < 10) {
              iVar6 = 1;
              iVar12 = 2;
            }
            else {
              puVar9 = puVar16 + 0x18;
              puVar8 = puVar7;
              iVar10 = 1;
              do {
                iVar6 = iVar10 + 8;
                iVar12 = iVar10 + 9;
                HintPreloadData(puVar9);
                puVar8[1] = ~puVar9[-0x17];
                puVar8[2] = ~puVar9[-0x16];
                puVar8[3] = ~puVar9[-0x15];
                puVar8[4] = ~puVar9[-0x14];
                puVar8[5] = ~puVar9[-0x13];
                puVar8[6] = ~puVar9[-0x12];
                puVar8[7] = ~puVar9[-0x11];
                puVar2 = puVar9 + -0x10;
                puVar9 = puVar9 + 8;
                puVar8 = puVar8 + 8;
                *puVar8 = ~*puVar2;
                iVar10 = iVar6;
              } while (iVar12 < iVar5 + -7);
            }
            iVar10 = 0;
            do {
              *(uint *)((int)puVar7 + iVar10 + iVar6 * 4) =
                   ~*(uint *)((int)puVar16 + iVar10 + iVar6 * 4);
              iVar10 = iVar10 + 4;
              bVar1 = iVar12 < iVar5;
              iVar12 = iVar12 + 1;
            } while (bVar1);
            a_00->top = iVar5;
          }
          puVar16 = puVar7 + iVar5 + -1;
          do {
            if (*puVar16 != 0) break;
            iVar5 = iVar5 + -1;
            puVar16 = puVar16 + -1;
          } while (iVar5 != 0);
          a_00->top = iVar5;
        }
        else {
          pBVar3 = BN_value_one();
          iVar5 = BN_mod_mul_montgomery(a_00,pBVar3,&local_c0->RR,local_c0,ctx);
          if (iVar5 == 0) goto LAB_000f0084;
        }
LAB_000f016c:
        local_bc = local_bc + -1;
        bVar1 = true;
        while( true ) {
          while (iVar5 = BN_is_bit_set(p,local_bc), iVar5 == 0) {
            if ((!bVar1) && (iVar5 = BN_mod_mul_montgomery(a_00,a_00,a_00,local_c0,ctx), iVar5 == 0)
               ) goto LAB_000f0084;
            if (local_bc == 0) goto LAB_000f026a;
            local_bc = local_bc + -1;
          }
          if (local_b8 == 1) {
            uVar13 = 0;
            uVar15 = 1;
          }
          else {
            uVar15 = 1;
            if (local_bc + -1 < 0) {
              uVar13 = 0;
            }
            else {
              uVar14 = 1;
              uVar13 = 0;
              iVar5 = local_bc + -1;
              iVar12 = local_bc + -2;
              do {
                iVar5 = BN_is_bit_set(p,iVar5);
                if (iVar5 != 0) {
                  uVar15 = uVar15 << (uVar14 - uVar13 & 0xff) | 1;
                  uVar13 = uVar14;
                }
                uVar14 = uVar14 + 1;
                iVar6 = iVar12 + -1;
              } while ((iVar12 != local_bc - local_b8) &&
                      (iVar5 = iVar12, iVar12 = iVar6, iVar6 != -2));
            }
          }
          if (!bVar1) {
            iVar5 = 0;
            do {
              iVar5 = iVar5 + 1;
              iVar12 = BN_mod_mul_montgomery(a_00,a_00,a_00,local_c0,ctx);
              if (iVar12 == 0) goto LAB_000f0084;
            } while (iVar5 <= (int)uVar13);
          }
          iVar5 = BN_mod_mul_montgomery(a_00,a_00,local_a8[(int)uVar15 >> 1],local_c0,ctx);
          if (iVar5 == 0) goto LAB_000f0084;
          local_bc = local_bc + ~uVar13;
          if (local_bc < 0) break;
          bVar1 = false;
        }
LAB_000f026a:
        iVar5 = BN_from_montgomery(r,a_00,local_c0,ctx);
        if (iVar5 != 0) {
          iVar5 = 1;
        }
      }
    }
    else {
LAB_000f0084:
      iVar5 = 0;
    }
    if (m_ctx != (BN_MONT_CTX *)0x0) goto LAB_000f008a;
  }
  BN_MONT_CTX_free(local_c0);
LAB_000f008a:
  BN_CTX_end(ctx);
  return iVar5;
}

