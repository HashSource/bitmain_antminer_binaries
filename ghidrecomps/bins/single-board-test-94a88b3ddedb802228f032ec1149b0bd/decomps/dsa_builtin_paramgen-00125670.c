
/* WARNING: Type propagation algorithm not settling */

undefined4
dsa_builtin_paramgen
          (int param_1,uint param_2,uint param_3,EVP_MD *param_4,void *param_5,size_t param_6,
          void *param_7,int *param_8,int *param_9,BN_GENCB *param_10)

{
  bool bVar1;
  bool bVar2;
  uint *puVar3;
  BN_CTX *ctx;
  BIGNUM *pBVar4;
  BIGNUM *r;
  BIGNUM *pBVar5;
  BIGNUM *ret;
  BIGNUM *a;
  BIGNUM *rem;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *pBVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  char cVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  undefined4 uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint *puVar19;
  int iVar20;
  uint __n;
  uint uVar21;
  uint *puVar22;
  uint uVar23;
  bool bVar24;
  int local_114;
  EVP_MD *local_104;
  BN_MONT_CTX *local_fc;
  int local_c8;
  uchar auStack_a8 [31];
  byte bStack_89;
  uint local_88 [7];
  char acStack_6a [2];
  uint local_68 [8];
  uint local_48 [9];
  
  __n = param_3 >> 3;
  if (((__n & 0xfffffff7) != 0x14) && (__n != 0x20)) {
    return 0;
  }
  local_104 = param_4;
  if (param_4 == (EVP_MD *)0x0) {
    local_104 = EVP_sha1();
  }
  if (param_2 < 0x200) {
    uVar16 = 0x200;
  }
  else {
    uVar16 = param_2 + 0x3f & 0xffffffc0;
  }
  if ((param_6 == 0 || param_6 <= __n) && (param_6 != 0 && __n != param_6)) {
    ctx = BN_CTX_new();
    if (__n <= param_6) {
      param_6 = __n;
    }
  }
  else {
    if (__n <= param_6) {
      param_6 = __n;
    }
    if (param_5 != (void *)0x0) {
      memcpy(auStack_a8,param_5,param_6);
    }
    ctx = BN_CTX_new();
  }
  if ((ctx == (BN_CTX *)0x0) || (local_fc = BN_MONT_CTX_new(), local_fc == (BN_MONT_CTX *)0x0)) {
    local_fc = (BN_MONT_CTX *)0x0;
  }
  else {
    uVar16 = uVar16 - 1;
    BN_CTX_start(ctx);
    pBVar4 = BN_CTX_get(ctx);
    r = BN_CTX_get(ctx);
    pBVar5 = BN_CTX_get(ctx);
    ret = BN_CTX_get(ctx);
    a = BN_CTX_get(ctx);
    rem = BN_CTX_get(ctx);
    r_00 = BN_CTX_get(ctx);
    r_01 = BN_CTX_get(ctx);
    pBVar6 = BN_value_one();
    iVar7 = BN_lshift(r_01,pBVar6,uVar16);
    if (iVar7 != 0) {
      uVar21 = param_3 >> 5;
      bVar24 = uVar21 == 0;
      bVar2 = 2 < __n;
      bVar1 = __n != 3;
      uVar17 = uVar21 << 2;
      uVar18 = uVar17;
      if ((bVar24 || bVar2) && (!bVar24 && bVar1)) {
        uVar18 = 0;
      }
      if (!bVar24 && !bVar2 || (bVar24 || !bVar1)) {
        uVar18 = 1;
      }
      uVar8 = uVar17;
      if (!bVar24 && !bVar2 || (bVar24 || !bVar1)) {
        uVar8 = 0;
      }
      iVar7 = 0;
      while( true ) {
        iVar9 = BN_GENCB_call(param_10,0,iVar7);
        if (iVar9 == 0) break;
        if (param_6 == 0) {
          iVar9 = RAND_pseudo_bytes(auStack_a8,__n);
          if (iVar9 < 0) break;
          local_c8 = 1;
        }
        else {
          local_c8 = 0;
        }
        memcpy(acStack_6a + 2,auStack_a8,__n);
        memcpy(local_48,auStack_a8,__n);
        if ((-1 < (int)(__n - 1)) &&
           (cVar11 = acStack_6a[__n + 1], acStack_6a[__n + 1] = cVar11 + '\x01',
           (char)(cVar11 + '\x01') == '\0')) {
          pcVar14 = acStack_6a + __n;
          do {
            if (pcVar14 == acStack_6a + 1) break;
            cVar11 = *pcVar14;
            *pcVar14 = cVar11 + '\x01';
            pcVar14 = pcVar14 + -1;
          } while ((char)(cVar11 + '\x01') == '\0');
        }
        iVar9 = EVP_Digest(auStack_a8,__n,(uchar *)local_88,(uint *)0x0,local_104,(ENGINE *)0x0);
        if ((iVar9 == 0) ||
           (iVar9 = EVP_Digest(acStack_6a + 2,__n,(uchar *)local_48,(uint *)0x0,local_104,
                               (ENGINE *)0x0), iVar9 == 0)) break;
        if (__n != 0) {
          uVar13 = uVar8;
          if (uVar18 == 0) {
            if (uVar21 < 9) {
              uVar12 = 0;
              puVar19 = local_88;
              puVar22 = local_48;
            }
            else {
              puVar22 = local_48;
              uVar12 = 0;
              puVar3 = (uint *)(acStack_6a + 2);
              do {
                puVar19 = puVar3;
                puVar22 = puVar22 + 8;
                uVar23 = uVar12 + 9;
                uVar12 = uVar12 + 8;
                HintPreloadData(puVar19 + 0xc);
                puVar19[-8] = puVar22[-8] ^ puVar19[-8];
                puVar19[-7] = puVar22[-7] ^ puVar19[-7];
                puVar19[-6] = puVar22[-6] ^ puVar19[-6];
                puVar19[-5] = puVar22[-5] ^ puVar19[-5];
                puVar19[-4] = puVar22[-4] ^ puVar19[-4];
                puVar19[-3] = puVar22[-3] ^ puVar19[-3];
                puVar19[-2] = puVar19[-2] ^ puVar22[-2];
                puVar19[-1] = puVar19[-1] ^ puVar22[-1];
                puVar3 = puVar19 + 8;
              } while (uVar23 < uVar21 - 7);
            }
            iVar9 = 0;
            do {
              uVar12 = uVar12 + 1;
              *(uint *)((int)puVar19 + iVar9) =
                   *(uint *)((int)puVar19 + iVar9) ^ *(uint *)((int)puVar22 + iVar9);
              iVar9 = iVar9 + 4;
            } while (uVar12 < uVar21);
            if (__n == uVar17) goto LAB_0012594a;
          }
          do {
            *(byte *)((int)local_88 + uVar13) =
                 *(byte *)((int)local_48 + uVar13) ^ *(byte *)((int)local_88 + uVar13);
            uVar13 = uVar13 + 1;
          } while ((int)uVar13 < (int)__n);
        }
LAB_0012594a:
        local_88[0]._0_1_ = (byte)local_88[0] | 0x80;
        *(byte *)((int)local_88 + (__n - 1)) = *(byte *)((int)local_88 + (__n - 1)) | 1;
        pBVar6 = BN_bin2bn((uchar *)local_88,__n,ret);
        if (pBVar6 == (BIGNUM *)0x0) break;
        iVar9 = BN_is_prime_fasttest_ex(ret,0x32,ctx,local_c8,param_10);
        if (iVar9 < 1) {
          if (iVar9 != 0) break;
        }
        else {
          iVar9 = BN_GENCB_call(param_10,2,0);
          if ((iVar9 == 0) || (iVar9 = BN_GENCB_call(param_10,3,0), iVar9 == 0)) break;
          local_114 = 0;
          while( true ) {
            iVar9 = 0;
            iVar20 = 0;
            BN_set_word(pBVar5,0);
            do {
              if (-1 < (int)(__n - 1)) {
                cVar11 = acStack_6a[__n + 1] + '\x01';
                acStack_6a[__n + 1] = cVar11;
                for (pcVar14 = acStack_6a + __n; (cVar11 == '\0' && (pcVar14 != acStack_6a + 1));
                    pcVar14 = pcVar14 + -1) {
                  cVar11 = *pcVar14 + '\x01';
                  *pcVar14 = cVar11;
                }
              }
              iVar10 = EVP_Digest(acStack_6a + 2,__n,(uchar *)local_88,(uint *)0x0,local_104,
                                  (ENGINE *)0x0);
              if ((((iVar10 == 0) ||
                   (pBVar6 = BN_bin2bn((uchar *)local_88,__n,pBVar4), pBVar6 == (BIGNUM *)0x0)) ||
                  (iVar10 = BN_lshift(pBVar4,pBVar4,iVar9), iVar10 == 0)) ||
                 (iVar10 = BN_add(pBVar5,pBVar5,pBVar4), iVar10 == 0)) goto LAB_001259a2;
              iVar20 = iVar20 + 1;
              iVar9 = iVar9 + (param_3 & 0xfffffff8);
            } while (iVar20 <= (int)(uVar16 / 0xa0));
            iVar9 = BN_mask_bits(pBVar5,uVar16);
            if (((iVar9 == 0) || (pBVar6 = BN_copy(a,pBVar5), pBVar6 == (BIGNUM *)0x0)) ||
               ((iVar9 = BN_add(a,a,r_01), iVar9 == 0 ||
                ((iVar9 = BN_lshift1(pBVar4,ret), iVar9 == 0 ||
                 (iVar9 = BN_div((BIGNUM *)0x0,rem,a,pBVar4,ctx), iVar9 == 0))))))
            goto LAB_001259a2;
            pBVar6 = BN_value_one();
            iVar9 = BN_sub(pBVar4,rem,pBVar6);
            if ((iVar9 == 0) || (iVar9 = BN_sub(r_00,a,pBVar4), iVar9 == 0)) goto LAB_001259a2;
            iVar9 = BN_cmp(r_00,r_01);
            if (-1 < iVar9) {
              iVar9 = BN_is_prime_fasttest_ex(r_00,0x32,ctx,1,param_10);
              if (0 < iVar9) {
                iVar7 = BN_GENCB_call(param_10,2,1);
                if (iVar7 == 0) goto LAB_001259a2;
                pBVar5 = BN_value_one();
                iVar7 = BN_sub(r_01,r_00,pBVar5);
                if ((((iVar7 == 0) ||
                     (iVar7 = BN_div(pBVar4,(BIGNUM *)0x0,r_01,ret,ctx), iVar7 == 0)) ||
                    (iVar7 = BN_set_word(r_01,2), iVar7 == 0)) ||
                   (iVar7 = BN_MONT_CTX_set(local_fc,r_00,ctx), iVar7 == 0)) goto LAB_001259a2;
                iVar7 = 2;
                goto LAB_00125bb2;
              }
              if (iVar9 != 0) goto LAB_001259a2;
            }
            local_114 = local_114 + 1;
            if (local_114 == 0x1000) break;
            iVar9 = BN_GENCB_call(param_10,0,local_114);
            if (iVar9 == 0) goto LAB_001259a2;
          }
        }
        param_6 = 0;
        iVar7 = iVar7 + 1;
      }
    }
  }
LAB_001259a2:
  if (ctx == (BN_CTX *)0x0) {
    uVar15 = 0;
  }
  else {
LAB_001259b8:
    uVar15 = 0;
LAB_001259ba:
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
  }
  if (local_fc != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(local_fc);
  }
  return uVar15;
LAB_00125bb2:
  iVar9 = BN_mod_exp_mont(r,r_01,pBVar4,r_00,ctx,local_fc);
  if (iVar9 == 0) goto LAB_001259a2;
  if (((r->top != 1) || (*r->d != 1)) || (r->neg != 0)) {
    iVar9 = BN_GENCB_call(param_10,3,1);
    if (iVar9 != 0) {
      if (*(BIGNUM **)(param_1 + 0xc) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0xc));
      }
      if (*(BIGNUM **)(param_1 + 0x10) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0x10));
      }
      if (*(BIGNUM **)(param_1 + 0x14) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0x14));
      }
      pBVar4 = BN_dup(r_00);
      *(BIGNUM **)(param_1 + 0xc) = pBVar4;
      pBVar4 = BN_dup(ret);
      *(BIGNUM **)(param_1 + 0x10) = pBVar4;
      pBVar4 = BN_dup(r);
      *(BIGNUM **)(param_1 + 0x14) = pBVar4;
      if (((*(int *)(param_1 + 0xc) == 0) || (*(int *)(param_1 + 0x10) == 0)) ||
         (pBVar4 == (BIGNUM *)0x0)) goto LAB_001259b8;
      if (param_8 != (int *)0x0) {
        *param_8 = local_114;
      }
      if (param_9 != (int *)0x0) {
        *param_9 = iVar7;
      }
      uVar15 = 1;
      if (param_7 != (void *)0x0) {
        uVar15 = 1;
        memcpy(param_7,auStack_a8,__n);
      }
      goto LAB_001259ba;
    }
    goto LAB_001259a2;
  }
  pBVar5 = BN_value_one();
  iVar9 = BN_add(r_01,r_01,pBVar5);
  if (iVar9 == 0) goto LAB_001259a2;
  iVar7 = iVar7 + 1;
  goto LAB_00125bb2;
}

