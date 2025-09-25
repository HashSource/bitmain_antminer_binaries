
int BN_mod_exp_mont_consttime
              (BIGNUM *rr,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *in_mont)

{
  ulong **ppuVar1;
  undefined1 *puVar2;
  BN_MONT_CTX *pBVar3;
  int iVar4;
  BIGNUM *pBVar5;
  int extraout_r1;
  uint uVar6;
  void *pvVar7;
  BIGNUM *pBVar8;
  ulong *puVar9;
  ulong *puVar10;
  uint uVar11;
  BIGNUM *pBVar12;
  uint uVar13;
  void *__s;
  BIGNUM *pBVar14;
  int iVar15;
  BIGNUM *pBVar16;
  undefined1 *puVar17;
  BIGNUM *pBVar18;
  uint uVar19;
  undefined4 *puVar20;
  undefined1 auStack_78 [4];
  BIGNUM *local_74;
  BIGNUM *local_70;
  ulong **local_6c;
  undefined1 *local_68;
  BIGNUM *local_64;
  BIGNUM *local_60;
  void *local_5c;
  size_t local_58;
  BN_MONT_CTX *local_54;
  BIGNUM local_50;
  ulong *local_3c;
  BIGNUM *local_38;
  BIGNUM *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  puVar20 = (undefined4 *)&stack0xffffff80;
  iVar4 = BN_is_odd(m);
  if (iVar4 == 0) {
    ERR_put_error(3,0x7c,0x66,"crypto/bn/bn_exp.c",0x267);
    return 0;
  }
  pBVar12 = (BIGNUM *)(p->top * 0x40);
  if (pBVar12 == (BIGNUM *)0x0) {
    iVar4 = BN_abs_is_word(m,1);
    if (iVar4 != 0) {
      BN_set_word(rr,0);
      return 1;
    }
    iVar4 = BN_set_word(rr,1);
    return iVar4;
  }
  pBVar18 = (BIGNUM *)m->top;
  BN_CTX_start(ctx);
  if (in_mont == (BN_MONT_CTX *)0x0) {
    local_54 = BN_MONT_CTX_new();
    if ((local_54 != (BN_MONT_CTX *)0x0) && (iVar4 = BN_MONT_CTX_set(local_54,m,ctx), iVar4 != 0))
    goto LAB_001854ae;
  }
  else {
    local_54 = in_mont;
LAB_001854ae:
    if (((a->neg == 0) && (iVar4 = BN_ucmp(a,m), local_60 = a, iVar4 < 0)) ||
       ((local_60 = BN_CTX_get(ctx), local_60 != (BIGNUM *)0x0 &&
        (iVar4 = BN_nnmod(local_60,a,m,ctx), iVar4 != 0)))) {
      if ((int)pBVar12 < 0x3aa) {
        if ((int)pBVar12 < 0x133) {
          if ((int)pBVar12 < 0x5a) {
            if ((int)pBVar12 < 0x17) {
              pBVar14 = (BIGNUM *)0x2;
              local_68 = (undefined1 *)0x1;
            }
            else {
              local_68 = (undefined1 *)0x3;
              pBVar14 = (BIGNUM *)0x8;
            }
          }
          else {
            local_68 = &DAT_00000004;
            pBVar14 = (BIGNUM *)0x10;
          }
        }
        else {
          local_68 = &DAT_00000005;
          pBVar14 = (BIGNUM *)0x20;
        }
      }
      else {
        pBVar14 = (BIGNUM *)0x40;
        local_68 = &DAT_00000006;
      }
      pBVar5 = (BIGNUM *)((int)pBVar18 * 2);
      if ((int)pBVar5 < (int)pBVar14) {
        pBVar5 = pBVar14;
      }
      local_58 = (int)((int)&pBVar5->d + (int)pBVar14 * (int)pBVar18) * 4;
      local_64 = pBVar14;
      if ((int)local_58 < 0xc00) {
        puVar20 = (undefined4 *)(&stack0xffffff80 + -(local_58 + 0x48));
        local_5c = (void *)0x0;
        __s = (void *)(((uint)(auStack_78 + -(local_58 + 0x48)) & 0xffffffc0) + 0x40);
        memset(__s,0,local_58);
      }
      else {
        local_5c = CRYPTO_malloc(local_58 + 0x40,"crypto/bn/bn_exp.c",0x2d4);
        if (local_5c == (void *)0x0) goto LAB_00185522;
        __s = (void *)(((uint)local_5c & 0xffffffc0) + 0x40);
        memset(__s,0,local_58);
      }
      iVar15 = 0;
      local_50.d = (ulong *)((int)local_64 * (int)pBVar18 * 4 + (int)__s);
      local_2c = 2;
      local_50.flags = 2;
      local_64 = &local_50;
      local_38 = (BIGNUM *)0x0;
      local_3c = local_50.d + (int)pBVar18;
      local_50.top = 0;
      local_30 = 0;
      local_50.neg = 0;
      local_50.dmax = (int)pBVar18;
      local_34 = pBVar18;
      pBVar5 = BN_value_one();
      iVar4 = bn_to_mont_fixed_top(local_64,pBVar5,local_54,ctx);
      if (iVar4 == 0) {
LAB_00185612:
        iVar4 = 0;
      }
      else {
        local_6c = &local_3c;
        iVar4 = bn_to_mont_fixed_top(local_6c,local_60,local_54,ctx);
        pBVar5 = local_64;
        ppuVar1 = local_6c;
        if (iVar4 == 0) goto LAB_00185612;
        pBVar16 = (BIGNUM *)local_50.top;
        if ((int)pBVar18 <= local_50.top) {
          pBVar16 = pBVar18;
        }
        if (0 < (int)pBVar16) {
          puVar10 = local_50.d;
          do {
            puVar9 = puVar10 + 1;
            *(ulong *)((int)__s + iVar15 * 4) = *puVar10;
            iVar15 = (int)&pBVar14->d + iVar15;
            puVar10 = puVar9;
          } while (puVar9 != local_50.d + (int)pBVar16);
        }
        pBVar16 = local_38;
        if ((int)pBVar18 <= (int)local_38) {
          pBVar16 = pBVar18;
        }
        if (0 < (int)pBVar16) {
          pvVar7 = __s;
          puVar10 = local_3c;
          do {
            puVar9 = puVar10 + 1;
            *(ulong *)((int)pvVar7 + 4) = *puVar10;
            pvVar7 = (void *)((int)pvVar7 + (int)pBVar14 * 4);
            puVar10 = puVar9;
          } while (puVar9 != local_3c + (int)pBVar16);
        }
        if (local_68 != (undefined1 *)0x1) {
          *puVar20 = ctx;
          iVar4 = bn_mul_mont_fixed_top(pBVar5,ppuVar1,ppuVar1,local_54);
          pBVar3 = local_54;
          pBVar5 = local_64;
          ppuVar1 = local_6c;
          if (iVar4 == 0) goto LAB_00185612;
          pBVar16 = (BIGNUM *)local_50.top;
          if ((int)pBVar18 <= local_50.top) {
            pBVar16 = pBVar18;
          }
          if (0 < (int)pBVar16) {
            pvVar7 = __s;
            puVar10 = local_50.d;
            do {
              puVar9 = puVar10 + 1;
              *(ulong *)((int)pvVar7 + 8) = *puVar10;
              pvVar7 = (void *)((int)pvVar7 + (int)pBVar14 * 4);
              puVar10 = puVar9;
            } while (puVar9 != local_50.d + (int)pBVar16);
          }
          if ((BIGNUM *)0x3 < pBVar14) {
            pBVar16 = (BIGNUM *)0x3;
            local_74 = p;
            local_70 = rr;
            local_60 = pBVar12;
            do {
              *puVar20 = ctx;
              iVar4 = bn_mul_mont_fixed_top(pBVar5,ppuVar1,pBVar5,pBVar3);
              if (iVar4 == 0) goto LAB_00185612;
              pBVar12 = (BIGNUM *)local_50.top;
              if ((int)pBVar18 <= local_50.top) {
                pBVar12 = pBVar18;
              }
              if (0 < (int)pBVar12) {
                pBVar8 = pBVar16;
                puVar10 = local_50.d;
                do {
                  puVar9 = puVar10 + 1;
                  *(ulong *)((int)__s + (int)pBVar8 * 4) = *puVar10;
                  pBVar8 = (BIGNUM *)((int)&pBVar14->d + (int)&pBVar8->d);
                  puVar10 = puVar9;
                } while (local_50.d + (int)pBVar12 != puVar9);
              }
              pBVar16 = (BIGNUM *)((int)&pBVar16->d + 1);
              pBVar12 = local_60;
              p = local_74;
              rr = local_70;
            } while (pBVar16 != pBVar14);
          }
        }
        __aeabi_idivmod((undefined1 *)((int)&pBVar12[-1].flags + 3),local_68);
        pBVar5 = local_64;
        pBVar16 = (BIGNUM *)(extraout_r1 + 1);
        uVar13 = (int)pBVar12 - (int)pBVar16;
        uVar11 = (uint)pBVar16 & 0xff;
        uVar19 = uVar13 + 0x3f & (int)uVar13 >> 0x20;
        if ((uVar11 != 0 || pBVar12 < pBVar16) &&
            (uVar11 == 0 || (1 << uVar11 - 1 & 0x80000000U) == 0)) {
          uVar19 = uVar13;
        }
        iVar4 = (int)uVar19 >> 6;
        if ((iVar4 < 0) || (p->top <= iVar4)) {
          uVar19 = 0;
        }
        else {
          uVar6 = uVar13 & 0x3f;
          if ((int)uVar13 < 1) {
            uVar6 = -(-uVar13 & 0x3f);
          }
          uVar19 = p->d[iVar4];
          if ((uVar6 != 0) && (uVar19 = uVar19 >> (uVar6 & 0xff), iVar4 + 1 < p->top)) {
            uVar19 = p->d[iVar4 + 1] << (0x40 - uVar6 & 0xff) | uVar19;
          }
          uVar19 = uVar19 & (1 << uVar11) - 1U;
        }
        *puVar20 = local_68;
        iVar4 = MOD_EXP_CTIME_COPY_FROM_PREBUF(pBVar5,pBVar18,__s,uVar19);
        pBVar3 = local_54;
        pBVar12 = local_64;
        puVar2 = local_68;
        if (iVar4 == 0) goto LAB_00185612;
        if (0 < (int)uVar13) {
          uVar13 = uVar13 - (int)local_68;
          local_70 = rr;
          local_68 = (undefined1 *)((int)&pBVar14[-1].flags + 3);
          local_60 = pBVar18;
          do {
            puVar17 = (undefined1 *)0x0;
            do {
              puVar17 = puVar17 + 1;
              *puVar20 = ctx;
              iVar4 = bn_mul_mont_fixed_top(pBVar12,pBVar12,pBVar12,pBVar3);
              ppuVar1 = local_6c;
              if (iVar4 == 0) goto LAB_00185612;
            } while (puVar2 != puVar17);
            uVar11 = uVar13 + 0x3f & (int)uVar13 >> 0x20;
            if (puVar2 < puVar17) {
              uVar11 = uVar13;
            }
            iVar4 = (int)uVar11 >> 6;
            if (iVar4 < p->top) {
              uVar19 = uVar13 & 0x3f;
              if ((int)uVar13 < 1) {
                uVar19 = -(-uVar13 & 0x3f);
              }
              uVar11 = p->d[iVar4];
              if ((uVar19 != 0) && (uVar11 = uVar11 >> (uVar19 & 0xff), iVar4 + 1 < p->top)) {
                uVar11 = uVar11 | p->d[iVar4 + 1] << (0x40 - uVar19 & 0xff);
              }
              uVar11 = (uint)local_68 & uVar11;
            }
            else {
              uVar11 = 0;
            }
            *puVar20 = puVar2;
            iVar4 = MOD_EXP_CTIME_COPY_FROM_PREBUF(ppuVar1,local_60,__s,uVar11);
            if (iVar4 == 0) goto LAB_00185612;
            *puVar20 = ctx;
            iVar4 = bn_mul_mont_fixed_top(pBVar12,pBVar12,ppuVar1,pBVar3);
            if (iVar4 == 0) goto LAB_00185612;
            uVar13 = uVar13 - (int)puVar2;
            rr = local_70;
          } while (0 < (int)(puVar2 + uVar13));
        }
        iVar4 = BN_from_montgomery(rr,local_64,local_54,ctx);
        if (iVar4 != 0) {
          iVar4 = 1;
        }
      }
      if (in_mont == (BN_MONT_CTX *)0x0) {
        BN_MONT_CTX_free(local_54);
      }
      OPENSSL_cleanse(__s,local_58);
      CRYPTO_free(local_5c);
      goto LAB_00185528;
    }
LAB_00185522:
    iVar4 = 0;
    if (in_mont != (BN_MONT_CTX *)0x0) goto LAB_00185528;
  }
  iVar4 = 0;
  BN_MONT_CTX_free(local_54);
LAB_00185528:
  BN_CTX_end(ctx);
  return iVar4;
}

