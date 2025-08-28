
/* WARNING: Type propagation algorithm not settling */

undefined4
dsa_builtin_paramgen
          (int param_1,uint param_2,uint param_3,EVP_MD *param_4,void *param_5,uint param_6,
          void *param_7,int *param_8,int *param_9,BN_GENCB *param_10)

{
  uint *puVar1;
  BN_CTX *ctx;
  BIGNUM *pBVar2;
  BIGNUM *r;
  BIGNUM *pBVar3;
  BIGNUM *ret;
  BIGNUM *a;
  BIGNUM *rem;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *pBVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  undefined4 uVar13;
  uint uVar14;
  uint *puVar15;
  int iVar16;
  uint __n;
  uint *puVar17;
  uint uVar18;
  int local_114;
  EVP_MD *local_104;
  BN_MONT_CTX *local_fc;
  int local_c8;
  uchar auStack_a8 [31];
  byte bStack_89;
  uint local_88 [7];
  char acStack_6a [2];
  uint local_68 [8];
  uint auStack_48 [9];
  
  __n = param_3 >> 3;
  if (((__n & 0xfffffff7) != 0x14) && (__n != 0x20)) {
    return 0;
  }
  local_104 = param_4;
  if (param_4 == (EVP_MD *)0x0) {
    local_104 = EVP_sha1();
  }
  if (param_2 < 0x200) {
    uVar14 = 0x200;
  }
  else {
    uVar14 = param_2 + 0x3f & 0xffffffc0;
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
    uVar14 = uVar14 - 1;
    BN_CTX_start(ctx);
    pBVar2 = BN_CTX_get(ctx);
    r = BN_CTX_get(ctx);
    pBVar3 = BN_CTX_get(ctx);
    ret = BN_CTX_get(ctx);
    a = BN_CTX_get(ctx);
    rem = BN_CTX_get(ctx);
    r_00 = BN_CTX_get(ctx);
    r_01 = BN_CTX_get(ctx);
    pBVar4 = BN_value_one();
    iVar5 = BN_lshift(r_01,pBVar4,uVar14);
    if (iVar5 != 0) {
      param_3 = param_3 >> 5;
      uVar6 = param_3 << 2;
      if (param_3 == 0 || __n < 4) {
        uVar6 = 0;
      }
      iVar5 = 0;
      while( true ) {
        iVar7 = BN_GENCB_call(param_10,0,iVar5);
        if (iVar7 == 0) break;
        if (param_6 == 0) {
          iVar7 = RAND_pseudo_bytes(auStack_a8,__n);
          if (iVar7 < 0) break;
          local_c8 = 1;
        }
        else {
          local_c8 = 0;
        }
        memcpy(acStack_6a + 2,auStack_a8,__n);
        memcpy(auStack_48,auStack_a8,__n);
        if ((-1 < (int)(__n - 1)) &&
           (cVar9 = acStack_6a[__n + 1], acStack_6a[__n + 1] = cVar9 + '\x01',
           (char)(cVar9 + '\x01') == '\0')) {
          pcVar12 = acStack_6a + __n;
          do {
            if (pcVar12 == acStack_6a + 1) break;
            cVar9 = *pcVar12;
            *pcVar12 = cVar9 + '\x01';
            pcVar12 = pcVar12 + -1;
          } while ((char)(cVar9 + '\x01') == '\0');
        }
        iVar7 = EVP_Digest(auStack_a8,__n,(uchar *)local_88,(uint *)0x0,local_104,(ENGINE *)0x0);
        if ((iVar7 == 0) ||
           (iVar7 = EVP_Digest(acStack_6a + 2,__n,(uchar *)auStack_48,(uint *)0x0,local_104,
                               (ENGINE *)0x0), iVar7 == 0)) break;
        if (__n != 0) {
          uVar11 = uVar6;
          if (param_3 != 0 && 3 < __n) {
            if (param_3 < 9) {
              uVar10 = 0;
              puVar15 = local_88;
              puVar17 = auStack_48;
            }
            else {
              puVar17 = auStack_48;
              uVar10 = 0;
              puVar1 = (uint *)(acStack_6a + 2);
              do {
                puVar15 = puVar1;
                puVar17 = puVar17 + 8;
                uVar18 = uVar10 + 9;
                uVar10 = uVar10 + 8;
                HintPreloadData(puVar15 + 0xc);
                puVar15[-8] = puVar17[-8] ^ puVar15[-8];
                puVar15[-7] = puVar17[-7] ^ puVar15[-7];
                puVar15[-6] = puVar17[-6] ^ puVar15[-6];
                puVar15[-5] = puVar17[-5] ^ puVar15[-5];
                puVar15[-4] = puVar17[-4] ^ puVar15[-4];
                puVar15[-3] = puVar17[-3] ^ puVar15[-3];
                puVar15[-2] = puVar15[-2] ^ puVar17[-2];
                puVar15[-1] = puVar15[-1] ^ puVar17[-1];
                puVar1 = puVar15 + 8;
              } while (uVar18 < param_3 - 7);
            }
            iVar7 = 0;
            do {
              uVar10 = uVar10 + 1;
              *(uint *)((int)puVar15 + iVar7) =
                   *(uint *)((int)puVar15 + iVar7) ^ *(uint *)((int)puVar17 + iVar7);
              iVar7 = iVar7 + 4;
            } while (uVar10 < param_3);
            if (__n == param_3 << 2) goto LAB_0012594a;
          }
          do {
            *(byte *)((int)local_88 + uVar11) =
                 *(byte *)((int)auStack_48 + uVar11) ^ *(byte *)((int)local_88 + uVar11);
            uVar11 = uVar11 + 1;
          } while ((int)uVar11 < (int)__n);
        }
LAB_0012594a:
        local_88[0]._0_1_ = (byte)local_88[0] | 0x80;
        *(byte *)((int)local_88 + (__n - 1)) = *(byte *)((int)local_88 + (__n - 1)) | 1;
        pBVar4 = BN_bin2bn((uchar *)local_88,__n,ret);
        if (pBVar4 == (BIGNUM *)0x0) break;
        iVar7 = BN_is_prime_fasttest_ex(ret,0x32,ctx,local_c8,param_10);
        if (iVar7 < 1) {
          if (iVar7 != 0) break;
        }
        else {
          iVar7 = BN_GENCB_call(param_10,2,0);
          if ((iVar7 == 0) || (iVar7 = BN_GENCB_call(param_10,3,0), iVar7 == 0)) break;
          local_114 = 0;
          while( true ) {
            iVar7 = 0;
            iVar16 = 0;
            BN_set_word(pBVar3,0);
            do {
              if (-1 < (int)(__n - 1)) {
                cVar9 = acStack_6a[__n + 1] + '\x01';
                acStack_6a[__n + 1] = cVar9;
                for (pcVar12 = acStack_6a + __n; (cVar9 == '\0' && (pcVar12 != acStack_6a + 1));
                    pcVar12 = pcVar12 + -1) {
                  cVar9 = *pcVar12 + '\x01';
                  *pcVar12 = cVar9;
                }
              }
              iVar8 = EVP_Digest(acStack_6a + 2,__n,(uchar *)local_88,(uint *)0x0,local_104,
                                 (ENGINE *)0x0);
              if ((((iVar8 == 0) ||
                   (pBVar4 = BN_bin2bn((uchar *)local_88,__n,pBVar2), pBVar4 == (BIGNUM *)0x0)) ||
                  (iVar8 = BN_lshift(pBVar2,pBVar2,iVar7), iVar8 == 0)) ||
                 (iVar8 = BN_add(pBVar3,pBVar3,pBVar2), iVar8 == 0)) goto LAB_001259a2;
              iVar16 = iVar16 + 1;
              iVar7 = iVar7 + __n * 8;
            } while (iVar16 <= (int)(uVar14 / 0xa0));
            iVar7 = BN_mask_bits(pBVar3,uVar14);
            if (((iVar7 == 0) || (pBVar4 = BN_copy(a,pBVar3), pBVar4 == (BIGNUM *)0x0)) ||
               ((iVar7 = BN_add(a,a,r_01), iVar7 == 0 ||
                ((iVar7 = BN_lshift1(pBVar2,ret), iVar7 == 0 ||
                 (iVar7 = BN_div((BIGNUM *)0x0,rem,a,pBVar2,ctx), iVar7 == 0))))))
            goto LAB_001259a2;
            pBVar4 = BN_value_one();
            iVar7 = BN_sub(pBVar2,rem,pBVar4);
            if ((iVar7 == 0) || (iVar7 = BN_sub(r_00,a,pBVar2), iVar7 == 0)) goto LAB_001259a2;
            iVar7 = BN_cmp(r_00,r_01);
            if (-1 < iVar7) {
              iVar7 = BN_is_prime_fasttest_ex(r_00,0x32,ctx,1,param_10);
              if (0 < iVar7) {
                iVar5 = BN_GENCB_call(param_10,2,1);
                if (iVar5 == 0) goto LAB_001259a2;
                pBVar3 = BN_value_one();
                iVar5 = BN_sub(r_01,r_00,pBVar3);
                if ((((iVar5 == 0) ||
                     (iVar5 = BN_div(pBVar2,(BIGNUM *)0x0,r_01,ret,ctx), iVar5 == 0)) ||
                    (iVar5 = BN_set_word(r_01,2), iVar5 == 0)) ||
                   (iVar5 = BN_MONT_CTX_set(local_fc,r_00,ctx), iVar5 == 0)) goto LAB_001259a2;
                iVar5 = 2;
                goto LAB_00125bb2;
              }
              if (iVar7 != 0) goto LAB_001259a2;
            }
            local_114 = local_114 + 1;
            if (local_114 == 0x1000) break;
            iVar7 = BN_GENCB_call(param_10,0,local_114);
            if (iVar7 == 0) goto LAB_001259a2;
          }
        }
        param_6 = 0;
        iVar5 = iVar5 + 1;
      }
    }
  }
LAB_001259a2:
  if (ctx == (BN_CTX *)0x0) {
    uVar13 = 0;
  }
  else {
LAB_001259b8:
    uVar13 = 0;
LAB_001259ba:
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
  }
  if (local_fc != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(local_fc);
  }
  return uVar13;
LAB_00125bb2:
  iVar7 = BN_mod_exp_mont(r,r_01,pBVar2,r_00,ctx,local_fc);
  if (iVar7 == 0) goto LAB_001259a2;
  if (((r->top != 1) || (*r->d != 1)) || (r->neg != 0)) {
    iVar7 = BN_GENCB_call(param_10,3,1);
    if (iVar7 != 0) {
      if (*(BIGNUM **)(param_1 + 0xc) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0xc));
      }
      if (*(BIGNUM **)(param_1 + 0x10) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0x10));
      }
      if (*(BIGNUM **)(param_1 + 0x14) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0x14));
      }
      pBVar2 = BN_dup(r_00);
      *(BIGNUM **)(param_1 + 0xc) = pBVar2;
      pBVar2 = BN_dup(ret);
      *(BIGNUM **)(param_1 + 0x10) = pBVar2;
      pBVar2 = BN_dup(r);
      *(BIGNUM **)(param_1 + 0x14) = pBVar2;
      if (((*(int *)(param_1 + 0xc) == 0) || (*(int *)(param_1 + 0x10) == 0)) ||
         (pBVar2 == (BIGNUM *)0x0)) goto LAB_001259b8;
      if (param_8 != (int *)0x0) {
        *param_8 = local_114;
      }
      if (param_9 != (int *)0x0) {
        *param_9 = iVar5;
      }
      uVar13 = 1;
      if (param_7 != (void *)0x0) {
        uVar13 = 1;
        memcpy(param_7,auStack_a8,__n);
      }
      goto LAB_001259ba;
    }
    goto LAB_001259a2;
  }
  pBVar3 = BN_value_one();
  iVar7 = BN_add(r_01,r_01,pBVar3);
  if (iVar7 == 0) goto LAB_001259a2;
  iVar5 = iVar5 + 1;
  goto LAB_00125bb2;
}

