
ECDSA_SIG *
ossl_ecdsa_sign_sig(uchar *param_1,int param_2,BIGNUM *param_3,BIGNUM *param_4,EC_KEY *param_5)

{
  EC_GROUP *pEVar1;
  BIGNUM *pBVar2;
  int iVar3;
  ECDSA_SIG *sig;
  BIGNUM *pBVar4;
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *a;
  uint uVar5;
  BIGNUM *pBVar6;
  EC_GROUP *group;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  BIGNUM *a_03;
  int iVar7;
  int local_58;
  BIGNUM *local_54;
  EC_POINT *local_40;
  
  pEVar1 = EC_KEY_get0_group(param_5);
  pBVar2 = EC_KEY_get0_private_key(param_5);
  if (pEVar1 == (EC_GROUP *)0x0) {
    ERR_put_error(0x10,0xf9,0x43,"crypto/ec/ecdsa_ossl.c",0xaa);
    return (ECDSA_SIG *)0x0;
  }
  if (pBVar2 == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0xf9,0x7d,"crypto/ec/ecdsa_ossl.c",0xae);
    return (ECDSA_SIG *)0x0;
  }
  iVar3 = EC_KEY_can_sign(param_5);
  if (iVar3 == 0) {
    ERR_put_error(0x10,0xf9,0x9f,"crypto/ec/ecdsa_ossl.c",0xb3);
    return (ECDSA_SIG *)0x0;
  }
  sig = ECDSA_SIG_new();
  if (sig == (ECDSA_SIG *)0x0) {
    ERR_put_error(0x10,0xf9,0x41,"crypto/ec/ecdsa_ossl.c",0xb9);
    return (ECDSA_SIG *)0x0;
  }
  pBVar4 = BN_new();
  sig->r = pBVar4;
  pBVar4 = BN_new();
  sig->s = pBVar4;
  if (pBVar4 == (BIGNUM *)0x0 || sig->r == (BIGNUM *)0x0) {
    local_54 = (BIGNUM *)0x0;
    ctx = (BN_CTX *)0x0;
    ERR_put_error(0x10,0xf9,0x41,"crypto/ec/ecdsa_ossl.c",0xbf);
    ret = (BIGNUM *)0x0;
    goto LAB_0011cc74;
  }
  ctx = BN_CTX_new();
  if ((ctx == (BN_CTX *)0x0) || (ret = BN_new(), ret == (BIGNUM *)0x0)) {
    ret = (BIGNUM *)0x0;
    local_54 = (BIGNUM *)0x0;
    ERR_put_error(0x10,0xf9,0x41,"crypto/ec/ecdsa_ossl.c",0xc6);
    goto LAB_0011cc74;
  }
  a = (BIGNUM *)EC_GROUP_get0_order(pEVar1);
  uVar5 = BN_num_bits(a);
  if ((int)(uVar5 + param_2 * -8) < 0 == SBORROW4(uVar5,param_2 * 8)) {
    pBVar6 = BN_bin2bn(param_1,param_2,ret);
    local_58 = param_2;
    if (pBVar6 == (BIGNUM *)0x0) {
LAB_0011ceca:
      ERR_put_error(0x10,0xf9,3,"crypto/ec/ecdsa_ossl.c",0xd2);
      local_54 = (BIGNUM *)0x0;
      goto LAB_0011cc74;
    }
  }
  else {
    local_58 = uVar5 + 0xe;
    if (-1 < (int)(uVar5 + 7)) {
      local_58 = uVar5 + 7;
    }
    local_58 = local_58 >> 3;
    pBVar6 = BN_bin2bn(param_1,local_58,ret);
    if (pBVar6 == (BIGNUM *)0x0) goto LAB_0011ceca;
    if (((int)(uVar5 + local_58 * -8) < 0 != SBORROW4(uVar5,local_58 * 8)) &&
       (iVar3 = BN_rshift(ret,ret,8 - (uVar5 & 7)), iVar3 == 0)) {
      ERR_put_error(0x10,0xf9,3,"crypto/ec/ecdsa_ossl.c",0xd7);
      local_54 = (BIGNUM *)0x0;
      goto LAB_0011cc74;
    }
  }
  local_54 = (BIGNUM *)0x0;
  do {
    if (param_3 == (BIGNUM *)0x0 || param_4 == (BIGNUM *)0x0) {
      if ((param_5 == (EC_KEY *)0x0) ||
         (group = EC_KEY_get0_group(param_5), group == (EC_GROUP *)0x0)) {
        ERR_put_error(0x10,0xf8,0x43,"crypto/ec/ecdsa_ossl.c",0x2f);
      }
      else {
        pBVar6 = EC_KEY_get0_private_key(param_5);
        if (pBVar6 == (BIGNUM *)0x0) {
          ERR_put_error(0x10,0xf8,0x7d,"crypto/ec/ecdsa_ossl.c",0x33);
        }
        else {
          iVar3 = EC_KEY_can_sign(param_5);
          if (iVar3 == 0) {
            ERR_put_error(0x10,0xf8,0x9f,"crypto/ec/ecdsa_ossl.c",0x38);
          }
          else {
            a_00 = BN_new();
            a_01 = BN_new();
            a_02 = BN_new();
            if (a_02 == (BIGNUM *)0x0 || (a_01 == (BIGNUM *)0x0 || a_00 == (BIGNUM *)0x0)) {
              ERR_put_error(0x10,0xf8,0x41,"crypto/ec/ecdsa_ossl.c",0x47);
              local_40 = (EC_POINT *)0x0;
            }
            else {
              local_40 = EC_POINT_new(group);
              if (local_40 == (EC_POINT *)0x0) {
                ERR_put_error(0x10,0xf8,0x10,"crypto/ec/ecdsa_ossl.c",0x4b);
              }
              else {
                a_03 = (BIGNUM *)EC_GROUP_get0_order(group);
                iVar3 = BN_num_bits(a_03);
                iVar7 = BN_set_bit(a_00,iVar3);
                if (((iVar7 != 0) && (iVar7 = BN_set_bit(a_01,iVar3), iVar7 != 0)) &&
                   (iVar3 = BN_set_bit(a_02,iVar3), iVar3 != 0)) {
                  do {
                    if (param_1 == (uchar *)0x0) {
LAB_0011ce98:
                      iVar3 = BN_priv_rand_range(a_00,a_03);
                      if (iVar3 != 0) goto LAB_0011ce8e;
                      iVar3 = 100;
LAB_0011ce80:
                      ERR_put_error(0x10,0xf8,0x9e,"crypto/ec/ecdsa_ossl.c",iVar3);
                      goto LAB_0011cc30;
                    }
                    do {
                      iVar3 = BN_generate_dsa_nonce(a_00,a_03,pBVar6,param_1,local_58,ctx);
                      if (iVar3 == 0) {
                        iVar3 = 0x5e;
                        goto LAB_0011ce80;
                      }
                      iVar3 = BN_is_zero(a_00);
                    } while (iVar3 != 0);
LAB_0011cf38:
                    iVar3 = EC_POINT_mul(group,local_40,a_00,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
                    if (iVar3 == 0) {
                      ERR_put_error(0x10,0xf8,0x10,"crypto/ec/ecdsa_ossl.c",0x6c);
                      goto LAB_0011cc30;
                    }
                    iVar3 = EC_POINT_get_affine_coordinates(group,local_40,a_02,0,ctx);
                    if (iVar3 == 0) {
                      ERR_put_error(0x10,0xf8,0x10,"crypto/ec/ecdsa_ossl.c",0x71);
                      goto LAB_0011cc30;
                    }
                    iVar3 = BN_nnmod(a_01,a_02,a_03,ctx);
                    if (iVar3 == 0) {
                      iVar3 = 0x76;
                      goto LAB_0011cf98;
                    }
                    iVar3 = BN_is_zero(a_01);
                  } while (iVar3 != 0);
                  iVar3 = ec_group_do_inverse_ord(group,a_00,a_00,ctx);
                  if (iVar3 != 0) {
                    BN_clear_free(sig->r);
                    BN_clear_free(local_54);
                    sig->r = a_01;
                    EC_POINT_free(local_40);
                    BN_clear_free(a_02);
                    local_54 = a_00;
                    goto LAB_0011cd1c;
                  }
                  iVar3 = 0x7d;
LAB_0011cf98:
                  ERR_put_error(0x10,0xf8,3,"crypto/ec/ecdsa_ossl.c",iVar3);
                }
              }
            }
LAB_0011cc30:
            BN_clear_free(a_00);
            BN_clear_free(a_01);
            EC_POINT_free(local_40);
            BN_clear_free(a_02);
          }
        }
      }
      ERR_put_error(0x10,0xf9,0x2a,"crypto/ec/ecdsa_ossl.c",0xdd);
      goto LAB_0011cc74;
    }
    pBVar6 = BN_copy(sig->r,param_4);
    a_00 = param_3;
    if (pBVar6 == (BIGNUM *)0x0) {
      ERR_put_error(0x10,0xf9,0x41,"crypto/ec/ecdsa_ossl.c",0xe4);
      goto LAB_0011cc74;
    }
LAB_0011cd1c:
    iVar3 = bn_to_mont_fixed_top(pBVar4,sig->r,*(undefined4 *)(pEVar1 + 0x5c),ctx);
    if ((iVar3 == 0) ||
       (iVar3 = bn_mul_mont_fixed_top(pBVar4,pBVar4,pBVar2,*(undefined4 *)(pEVar1 + 0x5c),ctx),
       iVar3 == 0)) {
      iVar3 = 0xf2;
LAB_0011cdf8:
      ERR_put_error(0x10,0xf9,3,"crypto/ec/ecdsa_ossl.c",iVar3);
      goto LAB_0011cc74;
    }
    iVar3 = bn_mod_add_fixed_top(pBVar4,pBVar4,ret,a);
    if (iVar3 == 0) {
      iVar3 = 0xf6;
      goto LAB_0011cdf8;
    }
    iVar3 = bn_to_mont_fixed_top(pBVar4,pBVar4,*(undefined4 *)(pEVar1 + 0x5c),ctx);
    if ((iVar3 == 0) ||
       (iVar3 = BN_mod_mul_montgomery(pBVar4,pBVar4,a_00,*(BN_MONT_CTX **)(pEVar1 + 0x5c),ctx),
       iVar3 == 0)) {
      iVar3 = 0xff;
      goto LAB_0011cdf8;
    }
    iVar3 = BN_is_zero(pBVar4);
    if (iVar3 == 0) goto LAB_0011cc7c;
  } while (param_4 == (BIGNUM *)0x0 || param_3 == (BIGNUM *)0x0);
  ERR_put_error(0x10,0xf9,0x9d,"crypto/ec/ecdsa_ossl.c",0x109);
LAB_0011cc74:
  ECDSA_SIG_free(sig);
  sig = (ECDSA_SIG *)0x0;
LAB_0011cc7c:
  BN_CTX_free(ctx);
  BN_clear_free(ret);
  BN_clear_free(local_54);
  return sig;
LAB_0011ce8e:
  iVar3 = BN_is_zero(a_00);
  if (iVar3 == 0) goto LAB_0011cf38;
  goto LAB_0011ce98;
}

