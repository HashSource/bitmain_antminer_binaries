
int BN_generate_prime_ex(BIGNUM *ret,int bits,int safe,BIGNUM *add,BIGNUM *rem,BN_GENCB *cb)

{
  ushort *ptr;
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *pBVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  undefined2 uVar6;
  int extraout_r1;
  int extraout_r1_00;
  uint extraout_r1_01;
  uint extraout_r1_02;
  int extraout_r1_03;
  int extraout_r1_04;
  uint extraout_r1_05;
  uint extraout_r1_06;
  int iVar7;
  ulong w;
  uint uVar8;
  undefined2 *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  int b;
  uint uVar12;
  int local_5c;
  
  if (bits < 0xea3) {
    if (bits < 0x541) {
      if (bits < 0x1dc) {
        if (bits < 400) {
          if (bits < 0x15b) {
            if (bits < 0x134) {
              if (bits < 0x37) {
                local_5c = 0x22;
              }
              else {
                local_5c = 0x1b;
              }
            }
            else {
              local_5c = 8;
            }
          }
          else {
            local_5c = 7;
          }
        }
        else {
          local_5c = 6;
        }
      }
      else {
        local_5c = 5;
      }
      if (bits < 2) {
        iVar7 = 0x42;
        goto LAB_0018d01a;
      }
    }
    else {
      local_5c = 4;
    }
  }
  else {
    local_5c = 3;
  }
  if ((safe != 0 && add == (BIGNUM *)0x0) && (bits != 3 && bits < 6)) {
    iVar7 = 0x4a;
LAB_0018d01a:
    ERR_put_error(3,0x8d,0x76,"crypto/bn/bn_prime.c",iVar7);
    return 0;
  }
  ptr = (ushort *)CRYPTO_zalloc(0x1000,"crypto/bn/bn_prime.c",0x4e);
  if ((ptr == (ushort *)0x0) || (ctx = BN_CTX_new(), ctx == (BN_CTX *)0x0)) {
    ctx = (BN_CTX *)0x0;
    pBVar1 = (BIGNUM *)0x0;
  }
  else {
    BN_CTX_start(ctx);
    r = BN_CTX_get(ctx);
    pBVar1 = r;
    if (r != (BIGNUM *)0x0) {
      if (safe != 0) {
        iVar7 = 4;
        w = 3;
      }
      else {
        iVar7 = 2;
        w = 1;
      }
      b = 0;
      if (safe != 0) {
        uVar8 = 5;
      }
      else {
        uVar8 = 3;
      }
LAB_0018d0c6:
      if (add == (BIGNUM *)0x0) {
LAB_0018d21e:
        while ((iVar2 = BN_priv_rand(ret,bits,1), iVar2 != 0 &&
               ((safe == 0 || (iVar2 = BN_set_bit(ret,1), iVar2 != 0))))) {
          puVar11 = (ushort *)&primes;
          puVar10 = ptr;
          do {
            puVar11 = puVar11 + 1;
            uVar3 = BN_mod_word(ret,(uint)*puVar11);
            if (uVar3 == 0xffffffff) goto LAB_0018d258;
            puVar10 = puVar10 + 1;
            *puVar10 = (ushort)uVar3;
          } while (puVar11 != (ushort *)&UNK_00226372);
          uVar3 = 0;
          do {
            if ((int)uVar3 < 0 || 0x1f < bits) {
              if (safe == 0) {
                uVar6 = 3;
                puVar9 = &DAT_00225376;
                puVar10 = ptr;
                while( true ) {
                  puVar10 = puVar10 + 1;
                  __aeabi_uidivmod(*puVar10 + uVar3,uVar6);
                  if (extraout_r1_03 == 0) break;
                  if (puVar9 == (undefined2 *)&UNK_00226372) goto LAB_0018d4ac;
                  puVar9 = puVar9 + 1;
                  uVar6 = *puVar9;
                }
              }
              else {
                uVar6 = 3;
                puVar9 = &DAT_00225376;
                puVar10 = ptr;
                while( true ) {
                  puVar10 = puVar10 + 1;
                  __aeabi_uidivmod(*puVar10 + uVar3,uVar6);
                  if (extraout_r1_05 < 2) break;
                  if (puVar9 == (undefined2 *)&UNK_00226372) goto LAB_0018d4ac;
                  puVar9 = puVar9 + 1;
                  uVar6 = *puVar9;
                }
              }
            }
            else if (safe == 0) {
              uVar12 = 3;
              puVar11 = &DAT_00225376;
              puVar10 = ptr;
              while( true ) {
                uVar4 = BN_get_word(ret);
                if (uVar4 + uVar3 <= uVar12 * uVar12 && uVar12 * uVar12 - (uVar4 + uVar3) != 0)
                goto LAB_0018d4ac;
                puVar10 = puVar10 + 1;
                __aeabi_uidivmod(*puVar10 + uVar3,uVar12);
                if (extraout_r1_04 == 0) break;
                if (puVar11 == (ushort *)&UNK_00226372) goto LAB_0018d4ac;
                puVar11 = puVar11 + 1;
                uVar12 = (uint)*puVar11;
              }
            }
            else {
              uVar12 = 3;
              puVar11 = &DAT_00225376;
              puVar10 = ptr;
              while( true ) {
                uVar4 = BN_get_word(ret);
                if (uVar4 + uVar3 <= uVar12 * uVar12 && uVar12 * uVar12 - (uVar4 + uVar3) != 0)
                goto LAB_0018d4ac;
                puVar10 = puVar10 + 1;
                __aeabi_uidivmod(*puVar10 + uVar3,uVar12);
                if (extraout_r1_06 < 2) break;
                if (puVar11 == (ushort *)&UNK_00226372) goto LAB_0018d4ac;
                puVar11 = puVar11 + 1;
                uVar12 = (uint)*puVar11;
              }
            }
            uVar3 = uVar3 + iVar7;
          } while (uVar3 < 0xffffba39);
        }
        goto LAB_0018d258;
      }
      BN_CTX_start(ctx);
      pBVar1 = BN_CTX_get(ctx);
      if (pBVar1 != (BIGNUM *)0x0) {
        BN_get_word(add);
        while (((iVar2 = BN_rand(ret,bits,0,1), iVar2 != 0 &&
                (iVar2 = BN_div((BIGNUM *)0x0,pBVar1,ret,add,ctx), iVar2 != 0)) &&
               (iVar2 = BN_sub(ret,ret,pBVar1), iVar2 != 0))) {
          if (rem == (BIGNUM *)0x0) {
            iVar2 = BN_add_word(ret,w);
          }
          else {
            iVar2 = BN_add(ret,ret,rem);
          }
          if ((iVar2 == 0) ||
             (((iVar2 = BN_num_bits(ret), iVar2 < bits || (uVar3 = BN_get_word(ret), uVar3 < uVar8))
              && (iVar2 = BN_add(ret,ret,add), iVar2 == 0)))) break;
          puVar11 = (ushort *)&primes;
          puVar10 = ptr;
          do {
            puVar11 = puVar11 + 1;
            uVar3 = BN_mod_word(ret,(uint)*puVar11);
            if (uVar3 == 0xffffffff) goto LAB_0018d178;
            puVar10 = puVar10 + 1;
            *puVar10 = (ushort)uVar3;
          } while (puVar11 != (ushort *)&UNK_00226372);
          uVar3 = 0;
          do {
            if ((int)uVar3 < 0 || 0x1f < bits) {
              if (safe == 0) {
                uVar6 = 3;
                puVar9 = &DAT_00225376;
                puVar10 = ptr;
                while( true ) {
                  puVar10 = puVar10 + 1;
                  __aeabi_uidivmod(*puVar10 + uVar3,uVar6);
                  if (extraout_r1 == 0) break;
                  if (puVar9 == (undefined2 *)&UNK_00226372) goto LAB_0018d2f6;
                  puVar9 = puVar9 + 1;
                  uVar6 = *puVar9;
                }
              }
              else {
                uVar6 = 3;
                puVar9 = &DAT_00225376;
                puVar10 = ptr;
                while( true ) {
                  puVar10 = puVar10 + 1;
                  __aeabi_uidivmod(*puVar10 + uVar3,uVar6);
                  if (extraout_r1_01 < 2) break;
                  if (puVar9 == (undefined2 *)&UNK_00226372) goto LAB_0018d2f6;
                  puVar9 = puVar9 + 1;
                  uVar6 = *puVar9;
                }
              }
            }
            else if (safe == 0) {
              uVar12 = 3;
              puVar11 = &DAT_00225376;
              puVar10 = ptr;
              while( true ) {
                uVar4 = BN_get_word(ret);
                if (uVar4 + uVar3 <= uVar12 * uVar12 && uVar12 * uVar12 - (uVar4 + uVar3) != 0)
                goto LAB_0018d2f6;
                puVar10 = puVar10 + 1;
                __aeabi_uidivmod(*puVar10 + uVar3,uVar12);
                if (extraout_r1_00 == 0) break;
                if (puVar11 == (ushort *)&UNK_00226372) goto LAB_0018d2f6;
                puVar11 = puVar11 + 1;
                uVar12 = (uint)*puVar11;
              }
            }
            else {
              uVar12 = 3;
              puVar11 = &DAT_00225376;
              puVar10 = ptr;
              while( true ) {
                uVar4 = BN_get_word(ret);
                if (uVar4 + uVar3 <= uVar12 * uVar12 && uVar12 * uVar12 - (uVar4 + uVar3) != 0)
                goto LAB_0018d2f6;
                puVar10 = puVar10 + 1;
                __aeabi_uidivmod(*puVar10 + uVar3,uVar12);
                if (extraout_r1_02 < 2) break;
                if (puVar11 == (ushort *)&UNK_00226372) goto LAB_0018d2f6;
                puVar11 = puVar11 + 1;
                uVar12 = (uint)*puVar11;
              }
            }
            uVar4 = BN_get_word(add);
            uVar3 = uVar3 + uVar4;
          } while (uVar3 < 0xffffba39);
        }
      }
      goto LAB_0018d178;
    }
  }
  goto LAB_0018d18e;
LAB_0018d4ac:
  iVar2 = BN_add_word(ret,uVar3);
  if (iVar2 == 0) goto LAB_0018d258;
  iVar2 = BN_num_bits(ret);
  if (bits == iVar2) goto LAB_0018d310;
  goto LAB_0018d21e;
LAB_0018d2f6:
  iVar2 = BN_add_word(ret,uVar3);
  if (iVar2 == 0) {
LAB_0018d178:
    pBVar1 = (BIGNUM *)0x0;
    BN_CTX_end(ctx);
    goto LAB_0018d18e;
  }
  BN_CTX_end(ctx);
LAB_0018d310:
  pBVar1 = (BIGNUM *)BN_GENCB_call(cb,0,b);
  if (pBVar1 == (BIGNUM *)0x0) goto LAB_0018d18e;
  if (safe == 0) {
    iVar2 = BN_is_prime_fasttest_ex(ret,local_5c,ctx,0,cb);
    if (iVar2 == -1) {
      pBVar1 = (BIGNUM *)0x0;
      goto LAB_0018d18e;
    }
    if (iVar2 != 0) goto LAB_0018d398;
  }
  else {
    pBVar1 = (BIGNUM *)BN_rshift1(r,ret);
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_0018d18e;
    iVar2 = 0;
    while( true ) {
      iVar2 = iVar2 + 1;
      iVar5 = BN_is_prime_fasttest_ex(ret,1,ctx,0,cb);
      if (iVar5 == -1) goto LAB_0018d258;
      if (iVar5 == 0) break;
      iVar5 = BN_is_prime_fasttest_ex(r,1,ctx,0,cb);
      if (iVar5 == -1) goto LAB_0018d258;
      if (iVar5 == 0) break;
      pBVar1 = (BIGNUM *)BN_GENCB_call(cb,2,b);
      if (pBVar1 == (BIGNUM *)0x0) goto LAB_0018d18e;
      if (iVar2 == local_5c) goto LAB_0018d398;
    }
  }
  b = b + 1;
  goto LAB_0018d0c6;
LAB_0018d258:
  pBVar1 = (BIGNUM *)0x0;
  goto LAB_0018d18e;
LAB_0018d398:
  pBVar1 = (BIGNUM *)0x1;
LAB_0018d18e:
  CRYPTO_free(ptr);
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return (int)pBVar1;
}

