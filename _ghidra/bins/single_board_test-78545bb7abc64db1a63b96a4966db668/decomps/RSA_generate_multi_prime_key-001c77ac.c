
undefined4
RSA_generate_multi_prime_key(int param_1,int param_2,int param_3,BIGNUM *param_4,BN_GENCB *param_5)

{
  undefined4 uVar1;
  int iVar2;
  BIGNUM *pBVar3;
  BIGNUM *ret;
  BIGNUM *r;
  BIGNUM *pBVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  ulong uVar8;
  int extraout_r1;
  BIGNUM *pBVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 extraout_r3;
  code *UNRECOVERED_JUMPTABLE_00;
  int iVar13;
  int iVar14;
  BIGNUM *a;
  BN_CTX *ctx;
  bool bVar15;
  int local_60;
  int local_58;
  undefined4 *local_48;
  int local_3c [4];
  int local_2c;
  
  UNRECOVERED_JUMPTABLE_00 = *(code **)(*(int *)(param_1 + 8) + 0x38);
  if (UNRECOVERED_JUMPTABLE_00 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c77ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE_00)();
    return uVar1;
  }
  UNRECOVERED_JUMPTABLE_00 = *(code **)(*(int *)(param_1 + 8) + 0x34);
  if (UNRECOVERED_JUMPTABLE_00 != (code *)0x0) {
    if (param_3 != 2) {
      return 0;
    }
                    /* WARNING: Could not recover jumptable at 0x001c77ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE_00)(param_1,param_2,param_4,param_5);
    return uVar1;
  }
  if (param_2 < 0x200) {
    ERR_put_error(4,0x81,0x78,"crypto/rsa/rsa_gen.c",0x4e);
    uVar1 = 0;
    ctx = (BN_CTX *)0x0;
    goto LAB_001c7824;
  }
  if ((param_3 < 2) || (iVar2 = rsa_multip_cap(param_2), iVar2 < param_3)) {
    ctx = (BN_CTX *)0x0;
    uVar1 = 0;
    ERR_put_error(4,0x81,0xa5,"crypto/rsa/rsa_gen.c",0x54);
    goto LAB_001c7824;
  }
  ctx = BN_CTX_new();
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_start(ctx);
    pBVar3 = BN_CTX_get(ctx);
    ret = BN_CTX_get(ctx);
    r = BN_CTX_get(ctx);
    if (r != (BIGNUM *)0x0) {
      iVar2 = __aeabi_idiv(param_2,param_3);
      __aeabi_idivmod(param_2,param_3);
      iVar10 = iVar2 + 1;
      local_3c[0] = iVar2;
      if (0 < extraout_r1) {
        local_3c[0] = iVar10;
      }
      local_3c[1] = iVar2;
      if (1 < extraout_r1) {
        local_3c[1] = iVar10;
      }
      if (2 < param_3) {
        local_3c[2] = iVar2;
        if (2 < extraout_r1) {
          local_3c[2] = iVar10;
        }
        if (param_3 != 3) {
          local_3c[3] = iVar2;
          if (3 < extraout_r1) {
            local_3c[3] = iVar10;
          }
          if ((param_3 != 4) && (local_2c = iVar10, extraout_r1 < 5)) {
            local_2c = iVar2;
          }
        }
      }
      if (*(int *)(param_1 + 0x10) == 0) {
        pBVar4 = BN_new();
        *(BIGNUM **)(param_1 + 0x10) = pBVar4;
        if (pBVar4 == (BIGNUM *)0x0) goto LAB_001c7964;
      }
      if (*(int *)(param_1 + 0x18) == 0) {
        iVar2 = BN_secure_new();
        *(int *)(param_1 + 0x18) = iVar2;
        if (iVar2 == 0) goto LAB_001c7964;
      }
      if (*(int *)(param_1 + 0x14) == 0) {
        pBVar4 = BN_new();
        *(BIGNUM **)(param_1 + 0x14) = pBVar4;
        if (pBVar4 == (BIGNUM *)0x0) goto LAB_001c7964;
      }
      if (*(int *)(param_1 + 0x1c) == 0) {
        iVar2 = BN_secure_new();
        *(int *)(param_1 + 0x1c) = iVar2;
        if (iVar2 == 0) goto LAB_001c7964;
      }
      if (*(int *)(param_1 + 0x20) == 0) {
        iVar2 = BN_secure_new();
        *(int *)(param_1 + 0x20) = iVar2;
        if (iVar2 == 0) goto LAB_001c7964;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        iVar2 = BN_secure_new();
        *(int *)(param_1 + 0x24) = iVar2;
        if (iVar2 == 0) goto LAB_001c7964;
      }
      if (*(int *)(param_1 + 0x28) == 0) {
        iVar2 = BN_secure_new();
        *(int *)(param_1 + 0x28) = iVar2;
        if (iVar2 == 0) goto LAB_001c7964;
      }
      if (*(int *)(param_1 + 0x2c) == 0) {
        iVar2 = BN_secure_new();
        *(int *)(param_1 + 0x2c) = iVar2;
        if (iVar2 == 0) goto LAB_001c7964;
      }
      if (param_3 < 3) {
        iVar2 = 0;
        local_48 = (undefined4 *)0x0;
      }
      else {
        *(undefined4 *)(param_1 + 4) = 1;
        iVar2 = OPENSSL_sk_new_reserve(0,param_3 + -2);
        if (iVar2 == 0) goto LAB_001c7964;
        if (*(int *)(param_1 + 0x30) != 0) {
          OPENSSL_sk_pop_free(*(int *)(param_1 + 0x30),0x15a41d);
        }
        iVar10 = 2;
        *(int *)(param_1 + 0x30) = iVar2;
        do {
          local_48 = (undefined4 *)rsa_multip_info_new();
          iVar10 = iVar10 + 1;
          if (local_48 == (undefined4 *)0x0) goto LAB_001c7964;
          OPENSSL_sk_push(iVar2,local_48);
        } while (param_3 != iVar10);
      }
      pBVar4 = BN_copy(*(BIGNUM **)(param_1 + 0x14),param_4);
      if (pBVar4 != (BIGNUM *)0x0) {
        iVar13 = 0;
        iVar10 = 0;
        iVar12 = 0;
LAB_001c79a2:
        if (iVar13 == 0) {
          pBVar4 = *(BIGNUM **)(param_1 + 0x1c);
        }
        else if (iVar13 == 1) {
          pBVar4 = *(BIGNUM **)(param_1 + 0x20);
        }
        else {
          local_48 = (undefined4 *)OPENSSL_sk_value(iVar2,iVar13 + -2);
          pBVar4 = (BIGNUM *)*local_48;
        }
        BN_set_flags(pBVar4,4);
        local_60 = 0;
        local_58 = 0;
        iVar11 = local_3c[iVar13];
        iVar12 = iVar11 + iVar12;
        iVar14 = iVar11;
LAB_001c79d2:
        iVar5 = BN_generate_prime_ex(pBVar4,iVar14,0,(BIGNUM *)0x0,(BIGNUM *)0x0,param_5);
        if (iVar5 == 0) goto LAB_001c7964;
        if (0 < iVar13) {
          iVar5 = 0;
          do {
            if (iVar5 == 0) {
              pBVar9 = *(BIGNUM **)(param_1 + 0x1c);
            }
            else if (iVar5 == 1) {
              pBVar9 = *(BIGNUM **)(param_1 + 0x20);
            }
            else {
              puVar6 = (undefined4 *)OPENSSL_sk_value(iVar2);
              pBVar9 = (BIGNUM *)*puVar6;
            }
            iVar5 = iVar5 + 1;
            iVar7 = BN_cmp(pBVar4,pBVar9);
            if (iVar7 == 0) goto LAB_001c79d2;
          } while (iVar5 != iVar13);
        }
        pBVar9 = BN_value_one();
        iVar5 = BN_sub(r,pBVar4,pBVar9);
        if (iVar5 == 0) goto LAB_001c7964;
        ERR_set_mark();
        BN_set_flags(r,4);
        pBVar9 = BN_mod_inverse(ret,r,*(BIGNUM **)(param_1 + 0x14),ctx);
        if (pBVar9 == (BIGNUM *)0x0) {
          uVar8 = ERR_peek_last_error();
          if ((uVar8 >> 0x18 != 3) || ((uVar8 & 0xfff) != 0x6c)) goto LAB_001c7964;
          ERR_pop_to_mark();
          iVar5 = BN_GENCB_call(param_5,2,iVar10);
          iVar10 = iVar10 + 1;
          if (iVar5 == 0) goto LAB_001c7964;
          goto LAB_001c79d2;
        }
        if (iVar13 == 1) {
          iVar5 = BN_mul(ret,*(BIGNUM **)(param_1 + 0x1c),*(BIGNUM **)(param_1 + 0x20),ctx);
        }
        else {
          if (iVar13 == 0) {
            iVar13 = BN_GENCB_call(param_5,3,0);
            if (iVar13 == 0) goto LAB_001c7964;
            iVar13 = 1;
            goto LAB_001c79a2;
          }
          iVar5 = BN_mul(ret,*(BIGNUM **)(param_1 + 0x10),pBVar4,ctx);
        }
        if ((iVar5 == 0) || (iVar5 = BN_rshift(r,ret,iVar12 + -4), iVar5 == 0)) goto LAB_001c7964;
        uVar8 = BN_get_word(r);
        if (uVar8 - 9 < 7) {
          if ((((1 < iVar13) &&
               (pBVar4 = BN_copy((BIGNUM *)local_48[3],*(BIGNUM **)(param_1 + 0x10)),
               pBVar4 == (BIGNUM *)0x0)) ||
              (pBVar4 = BN_copy(*(BIGNUM **)(param_1 + 0x10),ret), pBVar4 == (BIGNUM *)0x0)) ||
             (iVar14 = BN_GENCB_call(param_5,3,iVar13), iVar14 == 0)) goto LAB_001c7964;
          iVar13 = iVar13 + 1;
          if (iVar13 < param_3) goto LAB_001c79a2;
          iVar10 = BN_cmp(*(BIGNUM **)(param_1 + 0x1c),*(BIGNUM **)(param_1 + 0x20));
          bVar15 = iVar10 < 0;
          if (bVar15) {
            pBVar4 = *(BIGNUM **)(param_1 + 0x20);
            uVar1 = *(undefined4 *)(param_1 + 0x1c);
          }
          else {
            pBVar4 = *(BIGNUM **)(param_1 + 0x1c);
            uVar1 = extraout_r3;
          }
          if (bVar15) {
            *(BIGNUM **)(param_1 + 0x1c) = pBVar4;
          }
          if (bVar15) {
            *(undefined4 *)(param_1 + 0x20) = uVar1;
          }
          pBVar9 = BN_value_one();
          iVar10 = BN_sub(ret,pBVar4,pBVar9);
          if (iVar10 == 0) goto LAB_001c7964;
          pBVar9 = *(BIGNUM **)(param_1 + 0x20);
          pBVar4 = BN_value_one();
          iVar10 = BN_sub(r,pBVar9,pBVar4);
          if ((iVar10 == 0) || (iVar10 = BN_mul(pBVar3,ret,r,ctx), iVar10 == 0)) goto LAB_001c7964;
          iVar10 = 2;
          goto LAB_001c7c4c;
        }
        iVar5 = BN_GENCB_call(param_5,2,iVar10);
        if (iVar5 == 0) goto LAB_001c7964;
        if (param_3 < 5) {
          if (local_60 == 4) goto code_r0x001c7abe;
        }
        else {
          if (uVar8 < 9) {
            local_58 = local_58 + 1;
          }
          else {
            local_58 = local_58 + -1;
          }
          iVar14 = local_58 + iVar11;
        }
        local_60 = local_60 + 1;
        iVar10 = iVar10 + 1;
        goto LAB_001c79d2;
      }
    }
  }
  goto LAB_001c7964;
LAB_001c7c4c:
  if (param_3 <= iVar10) {
    pBVar4 = BN_new();
    if (pBVar4 != (BIGNUM *)0x0) {
      BN_with_flags(pBVar4,pBVar3,4);
      pBVar3 = BN_mod_inverse(*(BIGNUM **)(param_1 + 0x18),*(BIGNUM **)(param_1 + 0x14),pBVar4,ctx);
      if (pBVar3 == (BIGNUM *)0x0) goto LAB_001c7d16;
      BN_free(pBVar4);
      pBVar4 = BN_new();
      if (pBVar4 != (BIGNUM *)0x0) {
        BN_with_flags(pBVar4,*(undefined4 *)(param_1 + 0x18),4);
        iVar10 = BN_div((BIGNUM *)0x0,*(BIGNUM **)(param_1 + 0x24),pBVar4,ret,ctx);
        if ((iVar10 == 0) ||
           (iVar10 = BN_div((BIGNUM *)0x0,*(BIGNUM **)(param_1 + 0x28),pBVar4,r,ctx), iVar10 == 0))
        goto LAB_001c7d16;
        iVar10 = 2;
        goto LAB_001c7cf0;
      }
    }
    goto LAB_001c7964;
  }
  puVar6 = (undefined4 *)OPENSSL_sk_value(iVar2,iVar10 + -2);
  pBVar9 = (BIGNUM *)puVar6[1];
  a = (BIGNUM *)*puVar6;
  pBVar4 = BN_value_one();
  iVar12 = BN_sub(pBVar9,a,pBVar4);
  if ((iVar12 == 0) ||
     (iVar12 = BN_mul(pBVar3,pBVar3,(BIGNUM *)puVar6[1],ctx), iVar10 = iVar10 + 1, iVar12 == 0))
  goto LAB_001c7964;
  goto LAB_001c7c4c;
  while( true ) {
    iVar12 = OPENSSL_sk_value(iVar2,iVar10 + -2);
    iVar12 = BN_div((BIGNUM *)0x0,*(BIGNUM **)(iVar12 + 4),pBVar4,*(BIGNUM **)(iVar12 + 4),ctx);
    iVar10 = iVar10 + 1;
    if (iVar12 == 0) break;
LAB_001c7cf0:
    if (param_3 <= iVar10) {
      BN_free(pBVar4);
      pBVar4 = BN_new();
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_001c7964;
      BN_with_flags(pBVar4,*(undefined4 *)(param_1 + 0x1c),4);
      pBVar3 = BN_mod_inverse(*(BIGNUM **)(param_1 + 0x2c),*(BIGNUM **)(param_1 + 0x20),pBVar4,ctx);
      if (pBVar3 != (BIGNUM *)0x0) {
        iVar10 = 2;
        goto LAB_001c7d4c;
      }
      break;
    }
  }
  goto LAB_001c7d16;
code_r0x001c7abe:
  iVar13 = 0;
  iVar10 = iVar10 + 1;
  iVar12 = iVar13;
  goto LAB_001c79a2;
  while( true ) {
    puVar6 = (undefined4 *)OPENSSL_sk_value(iVar2,iVar10 + -2);
    BN_with_flags(pBVar4,*puVar6,4);
    pBVar3 = BN_mod_inverse((BIGNUM *)puVar6[2],(BIGNUM *)puVar6[3],pBVar4,ctx);
    iVar10 = iVar10 + 1;
    if (pBVar3 == (BIGNUM *)0x0) break;
LAB_001c7d4c:
    if (param_3 <= iVar10) {
      uVar1 = 1;
      BN_free(pBVar4);
      goto LAB_001c7824;
    }
  }
LAB_001c7d16:
  BN_free(pBVar4);
LAB_001c7964:
  uVar1 = 0;
  ERR_put_error(4,0x81,3,"crypto/rsa/rsa_gen.c",0x183);
LAB_001c7824:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return uVar1;
}

