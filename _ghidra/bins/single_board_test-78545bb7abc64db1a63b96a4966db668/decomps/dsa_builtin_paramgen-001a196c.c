
undefined4
dsa_builtin_paramgen
          (int param_1,uint param_2,uint param_3,EVP_MD *param_4,void *param_5,uint param_6,
          void *param_7,int *param_8,int *param_9,BN_GENCB *param_10)

{
  char cVar1;
  BN_MONT_CTX *mont;
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
  int iVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  bool bVar14;
  EVP_MD *local_fc;
  int local_d4;
  int local_cc;
  uchar auStack_a8 [31];
  byte bStack_89;
  undefined4 local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  undefined4 local_6c;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  param_3 = param_3 >> 3;
  if ((param_3 & 0xfffffff7) != 0x14 && param_3 != 0x20) {
    return 0;
  }
  if (param_4 == (EVP_MD *)0x0) {
    if (param_3 == 0x14) {
      local_fc = EVP_sha1();
    }
    else if (param_3 == 0x1c) {
      local_fc = EVP_sha224();
    }
    else {
      local_fc = EVP_sha256();
    }
  }
  else {
    param_3 = EVP_MD_size(param_4);
    local_fc = param_4;
  }
  if (param_2 < 0x200) {
    uVar13 = 0x200;
  }
  else {
    uVar13 = param_2 + 0x3f & 0xffffffc0;
  }
  if (param_5 != (void *)0x0) {
    if (param_6 < param_3) {
      ERR_put_error(10,0x7d,0x6e,"crypto/dsa/dsa_gen.c",0x55);
      return 0;
    }
    if (param_3 <= param_6) {
      param_6 = param_3;
    }
    memcpy(auStack_a8,param_5,param_6);
  }
  mont = BN_MONT_CTX_new();
  if ((mont == (BN_MONT_CTX *)0x0) || (ctx = BN_CTX_new(), ctx == (BN_CTX *)0x0)) {
    ctx = (BN_CTX *)0x0;
  }
  else {
    BN_CTX_start(ctx);
    pBVar2 = BN_CTX_get(ctx);
    r = BN_CTX_get(ctx);
    pBVar3 = BN_CTX_get(ctx);
    ret = BN_CTX_get(ctx);
    a = BN_CTX_get(ctx);
    rem = BN_CTX_get(ctx);
    r_00 = BN_CTX_get(ctx);
    r_01 = BN_CTX_get(ctx);
    if (r_01 != (BIGNUM *)0x0) {
      uVar13 = uVar13 - 1;
      pBVar4 = BN_value_one();
      iVar5 = BN_lshift(r_01,pBVar4,uVar13);
      if (iVar5 != 0) {
        iVar5 = (param_3 - 4 >> 2) + 1;
        uVar9 = param_3 - 1;
        local_d4 = 0;
        while( true ) {
          iVar6 = BN_GENCB_call(param_10,0,local_d4);
          if ((iVar6 == 0) ||
             ((param_5 == (void *)0x0 && (iVar6 = RAND_bytes(auStack_a8,param_3), iVar6 < 1))))
          break;
          memcpy(auStack_68,auStack_a8,param_3);
          memcpy(&local_48,auStack_a8,param_3);
          if ((-1 < (int)uVar9) &&
             (cVar1 = auStack_68[param_3 - 1], auStack_68[param_3 - 1] = cVar1 + '\x01',
             (char)(cVar1 + '\x01') == '\0')) {
            pcVar8 = auStack_68 + (param_3 - 2);
            uVar10 = uVar9;
            do {
              bVar14 = uVar10 == 0;
              uVar10 = uVar10 - 1;
              if (bVar14) break;
              cVar1 = *pcVar8;
              *pcVar8 = cVar1 + '\x01';
              pcVar8 = pcVar8 + -1;
            } while ((char)(cVar1 + '\x01') == '\0');
          }
          iVar6 = EVP_Digest(auStack_a8,param_3,(uchar *)&local_88,(uint *)0x0,local_fc,
                             (ENGINE *)0x0);
          if ((iVar6 == 0) ||
             (iVar6 = EVP_Digest(auStack_68,param_3,(uchar *)&local_48,(uint *)0x0,local_fc,
                                 (ENGINE *)0x0), iVar6 == 0)) break;
          if (0 < (int)param_3) {
            uVar10 = 0;
            if (2 < uVar9) {
              local_88 = local_88 ^ local_48;
              if ((((iVar5 != 1) && (local_84 = local_44 ^ local_84, iVar5 != 2)) &&
                  (local_80 = local_40 ^ local_80, iVar5 != 3)) &&
                 (((local_7c = local_3c ^ local_7c, iVar5 != 4 &&
                   (local_78 = local_38 ^ local_78, iVar5 != 5)) &&
                  ((local_74 = local_34 ^ local_74, iVar5 != 6 &&
                   (local_70 = local_30 ^ local_70, iVar5 != 7)))))) {
                local_6c = local_2c ^ local_6c;
              }
              uVar10 = iVar5 * 4;
              if (param_3 == iVar5 * 4) goto LAB_001a1bf8;
            }
            *(byte *)((int)&local_88 + uVar10) =
                 *(byte *)((int)&local_48 + uVar10) ^ *(byte *)((int)&local_88 + uVar10);
            if (((int)(uVar10 + 1) < (int)param_3) &&
               (*(byte *)((int)&local_88 + uVar10 + 1) =
                     *(byte *)((int)&local_48 + uVar10 + 1) ^ *(byte *)((int)&local_88 + uVar10 + 1)
               , (int)(uVar10 + 2) < (int)param_3)) {
              *(byte *)((int)&local_88 + uVar10 + 2) =
                   *(byte *)((int)&local_48 + uVar10 + 2) ^ *(byte *)((int)&local_88 + uVar10 + 2);
            }
          }
LAB_001a1bf8:
          local_88 = local_88 | 0x80;
          (&bStack_89)[param_3] = (&bStack_89)[param_3] | 1;
          pBVar4 = BN_bin2bn((uchar *)&local_88,param_3,ret);
          if (pBVar4 == (BIGNUM *)0x0) break;
          iVar6 = BN_is_prime_fasttest_ex(ret,0x40,ctx,(uint)(param_5 == (void *)0x0),param_10);
          if (0 < iVar6) {
            iVar6 = BN_GENCB_call(param_10,2,0);
            if ((iVar6 != 0) && (iVar6 = BN_GENCB_call(param_10,3,0), iVar6 != 0)) {
              local_cc = 0;
              do {
                iVar6 = 0;
                iVar11 = 0;
                BN_set_word(pBVar3,0);
                do {
                  if ((-1 < (int)uVar9) &&
                     (cVar1 = auStack_68[param_3 - 1], auStack_68[param_3 - 1] = cVar1 + '\x01',
                     (char)(cVar1 + '\x01') == '\0')) {
                    pcVar8 = auStack_68 + (param_3 - 2);
                    uVar10 = uVar9;
                    do {
                      bVar14 = uVar10 == 0;
                      uVar10 = uVar10 - 1;
                      if (bVar14) break;
                      cVar1 = *pcVar8;
                      *pcVar8 = cVar1 + '\x01';
                      pcVar8 = pcVar8 + -1;
                    } while ((char)(cVar1 + '\x01') == '\0');
                  }
                  iVar7 = EVP_Digest(auStack_68,param_3,(uchar *)&local_88,(uint *)0x0,local_fc,
                                     (ENGINE *)0x0);
                  if ((((iVar7 == 0) ||
                       (pBVar4 = BN_bin2bn((uchar *)&local_88,param_3,pBVar2),
                       pBVar4 == (BIGNUM *)0x0)) ||
                      (iVar7 = BN_lshift(pBVar2,pBVar2,iVar6), iVar7 == 0)) ||
                     (iVar7 = BN_add(pBVar3,pBVar3,pBVar2), iVar7 == 0)) goto LAB_001a1db6;
                  iVar11 = iVar11 + 1;
                  iVar6 = iVar6 + param_3 * 8;
                } while (iVar11 <= (int)(uVar13 / 0xa0));
                iVar6 = BN_mask_bits(pBVar3,uVar13);
                if (((iVar6 == 0) || (pBVar4 = BN_copy(a,pBVar3), pBVar4 == (BIGNUM *)0x0)) ||
                   ((iVar6 = BN_add(a,a,r_01), iVar6 == 0 ||
                    ((iVar6 = BN_lshift1(pBVar2,ret), iVar6 == 0 ||
                     (iVar6 = BN_div((BIGNUM *)0x0,rem,a,pBVar2,ctx), iVar6 == 0)))))) break;
                pBVar4 = BN_value_one();
                iVar6 = BN_sub(pBVar2,rem,pBVar4);
                if ((iVar6 == 0) || (iVar6 = BN_sub(r_00,a,pBVar2), iVar6 == 0)) break;
                iVar6 = BN_cmp(r_00,r_01);
                if (-1 < iVar6) {
                  iVar6 = BN_is_prime_fasttest_ex(r_00,0x40,ctx,1,param_10);
                  if (0 < iVar6) {
                    iVar5 = BN_GENCB_call(param_10,2,1);
                    if (iVar5 == 0) break;
                    pBVar3 = BN_value_one();
                    iVar5 = BN_sub(r_01,r_00,pBVar3);
                    if ((((iVar5 == 0) ||
                         (iVar5 = BN_div(pBVar2,(BIGNUM *)0x0,r_01,ret,ctx), iVar5 == 0)) ||
                        (iVar5 = BN_set_word(r_01,2), iVar5 == 0)) ||
                       (iVar5 = BN_MONT_CTX_set(mont,r_00,ctx), iVar5 == 0)) break;
                    iVar5 = 2;
                    goto LAB_001a1e76;
                  }
                  if (iVar6 != 0) break;
                }
                local_cc = local_cc + 1;
                if (local_cc == 0x1000) goto LAB_001a1c3e;
                iVar6 = BN_GENCB_call(param_10,0,local_cc);
                if (iVar6 == 0) break;
              } while( true );
            }
            break;
          }
          if (iVar6 != 0) break;
LAB_001a1c3e:
          param_5 = (void *)0x0;
          local_d4 = local_d4 + 1;
        }
      }
    }
  }
LAB_001a1db6:
  uVar12 = 0;
LAB_001a1db8:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  BN_MONT_CTX_free(mont);
  return uVar12;
LAB_001a1e76:
  iVar6 = BN_mod_exp_mont(r,r_01,pBVar2,r_00,ctx,mont);
  if (iVar6 == 0) goto LAB_001a1db6;
  iVar6 = BN_is_one(r);
  if (iVar6 == 0) {
    iVar6 = BN_GENCB_call(param_10,3,1);
    if (iVar6 != 0) {
      BN_free(*(BIGNUM **)(param_1 + 8));
      BN_free(*(BIGNUM **)(param_1 + 0xc));
      BN_free(*(BIGNUM **)(param_1 + 0x10));
      pBVar2 = BN_dup(r_00);
      *(BIGNUM **)(param_1 + 8) = pBVar2;
      pBVar2 = BN_dup(ret);
      *(BIGNUM **)(param_1 + 0xc) = pBVar2;
      pBVar2 = BN_dup(r);
      *(BIGNUM **)(param_1 + 0x10) = pBVar2;
      if (*(int *)(param_1 + 8) == 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = 0;
        if (pBVar2 != (BIGNUM *)0x0 && *(int *)(param_1 + 0xc) != 0) {
          if (param_8 != (int *)0x0) {
            *param_8 = local_cc;
          }
          if (param_9 != (int *)0x0) {
            *param_9 = iVar5;
          }
          uVar12 = 1;
          if (param_7 != (void *)0x0) {
            uVar12 = 1;
            memcpy(param_7,auStack_a8,param_3);
          }
        }
      }
      goto LAB_001a1db8;
    }
    goto LAB_001a1db6;
  }
  pBVar3 = BN_value_one();
  iVar6 = BN_add(r_01,r_01,pBVar3);
  if (iVar6 == 0) goto LAB_001a1db6;
  iVar5 = iVar5 + 1;
  goto LAB_001a1e76;
}

