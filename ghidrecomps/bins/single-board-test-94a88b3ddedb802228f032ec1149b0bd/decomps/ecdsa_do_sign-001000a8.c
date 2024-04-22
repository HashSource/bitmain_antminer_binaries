
ECDSA_SIG *
ecdsa_do_sign(uchar *param_1,int param_2,BIGNUM *param_3,BIGNUM *param_4,EC_KEY *param_5)

{
  int iVar1;
  EC_GROUP *group;
  BIGNUM *a;
  ECDSA_SIG *sig;
  ECDSA_SIG *ctx;
  BIGNUM *order;
  BIGNUM *r;
  BIGNUM *ret;
  uint uVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  BIGNUM *r_00;
  int local_40;
  BIGNUM *local_2c [2];
  
  local_2c[0] = (BIGNUM *)0x0;
  iVar1 = ecdsa_check(param_5);
  group = EC_KEY_get0_group(param_5);
  a = EC_KEY_get0_private_key(param_5);
  if ((group == (EC_GROUP *)0x0 || a == (BIGNUM *)0x0) || (iVar1 == 0)) {
    ERR_put_error(0x2a,0x65,0x43,DAT_00100330,0xfd);
    return (ECDSA_SIG *)0x0;
  }
  sig = ECDSA_SIG_new();
  if (sig == (ECDSA_SIG *)0x0) {
    ERR_put_error(0x2a,0x65,0x41,DAT_00100330,0x103);
    return (ECDSA_SIG *)0x0;
  }
  r_00 = sig->s;
  ctx = (ECDSA_SIG *)BN_CTX_new();
  if ((ctx == (ECDSA_SIG *)0x0) || (order = BN_new(), order == (BIGNUM *)0x0)) {
    order = (BIGNUM *)0x0;
    r = (BIGNUM *)0x0;
LAB_00100216:
    ERR_put_error(0x2a,0x65,0x41,DAT_00100330,0x10a);
    ECDSA_SIG_free(sig);
    if (ctx == (ECDSA_SIG *)0x0) goto LAB_00100248;
    sig = (ECDSA_SIG *)0x0;
    ret = (BIGNUM *)0x0;
  }
  else {
    r = BN_new();
    if ((r == (BIGNUM *)0x0) || (ret = BN_new(), ret == (BIGNUM *)0x0)) goto LAB_00100216;
    iVar1 = EC_GROUP_get_order(group,order,(BN_CTX *)ctx);
    if (iVar1 == 0) {
      ERR_put_error(0x2a,0x65,0x10,DAT_00100330,0x10f);
    }
    else {
      uVar2 = BN_num_bits(order);
      local_40 = param_2;
      if ((int)(uVar2 + param_2 * -8) < 0 != SBORROW4(uVar2,param_2 * 8)) {
        local_40 = uVar2 + 7;
        if ((int)(uVar2 + 7) < 0) {
          local_40 = uVar2 + 0xe;
        }
        local_40 = local_40 >> 3;
      }
      pBVar3 = BN_bin2bn(param_1,local_40,ret);
      iVar1 = 0x119;
      if (pBVar3 == (BIGNUM *)0x0) {
LAB_001002b0:
        ERR_put_error(0x2a,0x65,3,DAT_00100330,iVar1);
      }
      else {
        if ((int)(uVar2 + local_40 * -8) < 0 != SBORROW4(uVar2,local_40 * 8)) {
          iVar5 = BN_rshift(ret,ret,8 - (uVar2 & 7));
          iVar1 = 0x11e;
          if (iVar5 == 0) goto LAB_001002b0;
        }
        uVar2 = 1 - (int)param_3;
        if ((BIGNUM *)0x1 < param_3) {
          uVar2 = 0;
        }
        if (param_4 == (BIGNUM *)0x0) {
          uVar2 = uVar2 | 1;
        }
        do {
          if (uVar2 == 0) {
            pBVar4 = BN_copy(sig->r,param_4);
            pBVar3 = param_3;
            if (pBVar4 == (BIGNUM *)0x0) {
              ERR_put_error(0x2a,0x65,0x41,DAT_00100330,299);
              goto LAB_0010027a;
            }
          }
          else {
            iVar1 = ECDSA_sign_setup(param_5,(BN_CTX *)ctx,local_2c,&sig->r);
            pBVar3 = local_2c[0];
            if (iVar1 == 0) {
              ERR_put_error(0x2a,0x65,0x2a,DAT_00100330,0x124);
              goto LAB_0010027a;
            }
          }
          iVar1 = BN_mod_mul(r,a,sig->r,order,(BN_CTX *)ctx);
          if (iVar1 == 0) {
            iVar1 = 0x131;
            goto LAB_001002b0;
          }
          iVar1 = BN_mod_add_quick(r_00,r,ret,order);
          if (iVar1 == 0) {
            iVar1 = 0x135;
            goto LAB_001002b0;
          }
          iVar1 = BN_mod_mul(r_00,r_00,pBVar3,order,(BN_CTX *)ctx);
          if (iVar1 == 0) {
            iVar1 = 0x139;
            goto LAB_001002b0;
          }
          if (r_00->top != 0) goto LAB_00100236;
        } while (param_3 == (BIGNUM *)0x0 || param_4 == (BIGNUM *)0x0);
        ERR_put_error(0x2a,0x65,0x6a,DAT_00100330,0x143);
      }
    }
LAB_0010027a:
    ECDSA_SIG_free(sig);
    sig = (ECDSA_SIG *)0x0;
  }
LAB_00100236:
  BN_CTX_free((BN_CTX *)ctx);
  ctx = sig;
  if (ret != (BIGNUM *)0x0) {
    BN_clear_free(ret);
  }
LAB_00100248:
  if (r != (BIGNUM *)0x0) {
    BN_clear_free(r);
  }
  if (order != (BIGNUM *)0x0) {
    BN_free(order);
  }
  if (local_2c[0] != (BIGNUM *)0x0) {
    BN_clear_free(local_2c[0]);
  }
  return ctx;
}

