
int BN_div(BIGNUM *dv,BIGNUM *rem,BIGNUM *m,BIGNUM *d,BN_CTX *ctx)

{
  longlong lVar1;
  longlong lVar2;
  BIGNUM *pBVar3;
  BIGNUM *r;
  BIGNUM *r_00;
  int iVar4;
  BIGNUM *pBVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  int iVar9;
  ulong *puVar10;
  ulong *puVar11;
  uint uVar12;
  uint w;
  int iVar13;
  uint uVar14;
  bool bVar15;
  int local_a4;
  int local_a0;
  int local_8c;
  ulong *local_78;
  uint local_74;
  BIGNUM local_3c;
  
  if (((0 < m->top) && (m->d[m->top + -1] == 0)) ||
     ((iVar7 = d->top, 0 < iVar7 && (d->d[iVar7 + -1] == 0)))) {
    ERR_put_error(3,0x6b,0x6b,DAT_000ef4dc,0xcf);
    return 0;
  }
  if ((m->flags << 0x1d < 0) || ((d->flags & 4U) != 0)) {
    if (iVar7 == 0) goto LAB_000ef272;
    local_a4 = 1;
  }
  else {
    if (iVar7 == 0) {
LAB_000ef272:
      ERR_put_error(3,0x6b,0x67,DAT_000ef4dc,0xe5);
      return 0;
    }
    iVar7 = BN_ucmp(m,d);
    if (iVar7 < 0) {
      if ((rem != (BIGNUM *)0x0) && (pBVar3 = BN_copy(rem,m), pBVar3 == (BIGNUM *)0x0)) {
        return 0;
      }
      if (dv == (BIGNUM *)0x0) {
        return 1;
      }
      BN_set_word(dv,0);
      return 1;
    }
    local_a4 = 0;
  }
  BN_CTX_start(ctx);
  pBVar3 = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  r_00 = BN_CTX_get(ctx);
  if (dv == (BIGNUM *)0x0) {
    dv = BN_CTX_get(ctx);
  }
  if ((r_00 == (BIGNUM *)0x0 || dv == (BIGNUM *)0x0) ||
     (pBVar3 == (BIGNUM *)0x0 || r == (BIGNUM *)0x0)) goto LAB_000ef212;
  iVar7 = BN_num_bits(d);
  iVar4 = BN_lshift(r_00,d,0x20 - iVar7 % 0x20);
  if (iVar4 == 0) goto LAB_000ef212;
  iVar4 = 0x40 - iVar7 % 0x20;
  r_00->neg = 0;
  iVar7 = BN_lshift(r,m,iVar4);
  if (iVar7 == 0) goto LAB_000ef212;
  r->neg = 0;
  if (local_a4 == 0) {
    local_a0 = r->top;
    local_3c.d = r->d;
  }
  else {
    iVar13 = r->top;
    iVar7 = r_00->top + 1;
    if (iVar7 < iVar13) {
      if (r->dmax <= iVar13) {
        pBVar5 = bn_expand2(r,iVar13 + 1);
        if (pBVar5 == (BIGNUM *)0x0) goto LAB_000ef212;
        iVar13 = r->top;
      }
      local_3c.d = r->d;
      local_3c.d[iVar13] = 0;
      local_a0 = r->top + 1;
      r->top = local_a0;
    }
    else {
      if (iVar7 < r->dmax) {
LAB_000ef586:
        local_3c.d = r->d;
        puVar10 = local_3c.d + iVar13 + -1;
        do {
          puVar10 = puVar10 + 1;
          *puVar10 = 0;
          iVar13 = iVar13 + 1;
          local_a0 = r_00->top;
        } while (iVar13 <= local_a0 + 1);
      }
      else {
        pBVar5 = bn_expand2(r,r_00->top + 2);
        if (pBVar5 == (BIGNUM *)0x0) goto LAB_000ef212;
        local_a0 = r_00->top;
        iVar13 = r->top;
        if (iVar13 <= local_a0 + 1) goto LAB_000ef586;
        local_3c.d = r->d;
      }
      local_a0 = local_a0 + 2;
      r->top = local_a0;
    }
  }
  iVar7 = r_00->top;
  local_3c.neg = 0;
  bVar15 = iVar7 == 1;
  if (bVar15) {
    local_74 = 0;
  }
  iVar13 = local_a0 - iVar7;
  local_3c.d = local_3c.d + iVar13;
  local_3c.dmax = r->dmax - iVar13;
  uVar8 = iVar7 - 1;
  uVar12 = r_00->d[uVar8];
  if (!bVar15) {
    uVar8 = r_00->d[iVar7 + -2];
  }
  if (!bVar15) {
    local_74 = uVar8;
  }
  puVar10 = r->d;
  dv->neg = m->neg ^ d->neg;
  local_3c.top = iVar7;
  if ((iVar13 < dv->dmax) || (pBVar5 = bn_expand2(dv,iVar13 + 1), pBVar5 != (BIGNUM *)0x0)) {
    iVar9 = pBVar3->dmax;
    puVar11 = dv->d;
    dv->top = iVar13 - local_a4;
    if ((iVar7 < iVar9) || (pBVar5 = bn_expand2(pBVar3,iVar7 + 1), pBVar5 != (BIGNUM *)0x0)) {
      iVar13 = iVar13 + -1;
      local_78 = puVar11 + iVar13;
      if (local_a4 == 0) {
        iVar9 = BN_ucmp(&local_3c,r_00);
        if (iVar9 < 0) {
          iVar9 = dv->top + -1;
          dv->top = iVar9;
        }
        else {
          bn_sub_words(local_3c.d,local_3c.d,r_00->d,iVar7);
          puVar11[iVar13] = 1;
          iVar9 = dv->top;
        }
      }
      else {
        iVar9 = dv->top;
      }
      if (iVar9 == 0) {
        dv->neg = 0;
      }
      else {
        local_78 = local_78 + -1;
      }
      if (0 < iVar13) {
        local_8c = 0;
        puVar10 = puVar10 + local_a0 + -1;
        do {
          uVar8 = puVar10[-1];
          if (*puVar10 == uVar12) {
            w = 0xffffffff;
          }
          else {
            w = __aeabi_uldivmod(uVar8,*puVar10,uVar12,0);
            lVar1 = (ulonglong)w * (ulonglong)local_74;
            uVar6 = (uint)((ulonglong)lVar1 >> 0x20);
            uVar14 = uVar8 - uVar12 * w;
            bVar15 = uVar6 <= uVar14;
            if (uVar14 == uVar6) {
              bVar15 = (uint)lVar1 <= puVar10[-2];
            }
            if ((!bVar15) && (w = w - 1, CARRY4(uVar14,uVar12) == false)) {
              do {
                uVar14 = uVar14 + uVar12;
                lVar2 = lVar1 - (ulonglong)local_74;
                uVar6 = (uint)((ulonglong)lVar2 >> 0x20);
                lVar1 = lVar1 - (ulonglong)local_74;
                bVar15 = uVar6 <= uVar14;
                if (uVar14 == uVar6) {
                  bVar15 = (uint)lVar2 <= puVar10[-2];
                }
              } while ((!bVar15) && (w = w - 1, CARRY4(uVar14,uVar12) == false));
            }
          }
          uVar8 = bn_mul_words(pBVar3->d,r_00->d,iVar7,w);
          local_3c.d = local_3c.d + -1;
          pBVar3->d[iVar7] = uVar8;
          uVar8 = bn_sub_words(local_3c.d,local_3c.d,pBVar3->d,iVar7 + 1);
          if (uVar8 != 0) {
            w = w - 1;
            uVar8 = bn_add_words(local_3c.d,local_3c.d,r_00->d,iVar7);
            if (uVar8 != 0) {
              *puVar10 = *puVar10 + 1;
            }
          }
          local_8c = local_8c + 1;
          *local_78 = w;
          puVar10 = puVar10 + -1;
          local_78 = local_78 + -1;
        } while (iVar13 != local_8c);
      }
      iVar7 = r->top;
      if (0 < iVar7) {
        puVar10 = r->d + iVar7 + -1;
        do {
          if (*puVar10 != 0) break;
          iVar7 = iVar7 + -1;
          puVar10 = puVar10 + -1;
        } while (iVar7 != 0);
        r->top = iVar7;
      }
      if (rem != (BIGNUM *)0x0) {
        iVar7 = m->neg;
        BN_rshift(rem,r,iVar4);
        if (rem->top != 0) {
          rem->neg = iVar7;
        }
      }
      if ((local_a4 != 0) && (iVar7 = dv->top, 0 < iVar7)) {
        puVar10 = dv->d + iVar7 + -1;
        do {
          if (*puVar10 != 0) break;
          iVar7 = iVar7 + -1;
          puVar10 = puVar10 + -1;
        } while (iVar7 != 0);
        dv->top = iVar7;
      }
      BN_CTX_end(ctx);
      return 1;
    }
  }
LAB_000ef212:
  BN_CTX_end(ctx);
  return 0;
}

