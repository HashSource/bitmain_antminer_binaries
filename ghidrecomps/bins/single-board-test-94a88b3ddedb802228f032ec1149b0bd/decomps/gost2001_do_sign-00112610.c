
DSA_SIG * gost2001_do_sign(undefined4 param_1,int param_2,EC_KEY *param_3)

{
  bool bVar1;
  BIGNUM *pBVar2;
  BIGNUM *m;
  BN_CTX *ctx;
  EC_GROUP *group;
  BIGNUM *pBVar3;
  int iVar4;
  BIGNUM *a;
  BIGNUM *rem;
  BIGNUM *rnd;
  EC_POINT *r;
  BIGNUM *x;
  BIGNUM *r_00;
  BIGNUM *r_01;
  DSA_SIG *pDVar5;
  BIGNUM *local_40;
  BIGNUM *local_3c;
  DSA_SIG *local_2c;
  
  m = (BIGNUM *)hashsum2bn();
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0 || m == (BIGNUM *)0x0) {
    ERR_GOST_error(0x69,0x41,DAT_001128a8,0x8a);
    if (ctx == (BN_CTX *)0x0) {
      pDVar5 = (DSA_SIG *)0x0;
      bVar1 = false;
      local_2c = (DSA_SIG *)0x0;
    }
    else {
      bVar1 = false;
      BN_CTX_end(ctx);
      pDVar5 = (DSA_SIG *)0x0;
      BN_CTX_free(ctx);
      local_2c = (DSA_SIG *)0x0;
    }
  }
  else {
    BN_CTX_start(ctx);
    if (param_2 != 0x20) {
      OpenSSLDie(DAT_001128a8,0x8e,DAT_001128ac);
    }
    local_2c = DSA_SIG_new();
    pDVar5 = local_2c;
    if (local_2c == (DSA_SIG *)0x0) {
      ERR_GOST_error(0x69,0x76,DAT_0011298c,0x91);
      bVar1 = false;
      r = (EC_POINT *)0x0;
    }
    else {
      group = EC_KEY_get0_group(param_3);
      if (group == (EC_GROUP *)0x0) {
        ERR_GOST_error(0x69,0x44,DAT_0011298c,0x96);
        bVar1 = true;
        r = (EC_POINT *)0x0;
        pDVar5 = (DSA_SIG *)0x0;
      }
      else {
        pBVar3 = BN_CTX_get(ctx);
        if ((pBVar3 == (BIGNUM *)0x0) || (iVar4 = EC_GROUP_get_order(group,pBVar3,ctx), iVar4 == 0))
        {
          r = (EC_POINT *)0x0;
          bVar1 = true;
          ERR_GOST_error(0x69,0x44,DAT_001128a8,0x9b);
          pDVar5 = (DSA_SIG *)0x0;
        }
        else {
          a = EC_KEY_get0_private_key(param_3);
          if (a == (BIGNUM *)0x0) {
            ERR_GOST_error(0x69,0x44,DAT_0011298c,0xa0);
            bVar1 = true;
            r = (EC_POINT *)0x0;
            pDVar5 = (DSA_SIG *)0x0;
          }
          else {
            rem = BN_CTX_get(ctx);
            if ((rem == (BIGNUM *)0x0) ||
               (iVar4 = BN_div((BIGNUM *)0x0,rem,m,pBVar3,ctx), iVar4 == 0)) {
              r = (EC_POINT *)0x0;
              bVar1 = true;
              ERR_GOST_error(0x69,0x44,DAT_0011298c,0xa5);
              pDVar5 = (DSA_SIG *)0x0;
            }
            else {
              if (rem->top == 0) {
                BN_set_word(rem,1);
              }
              rnd = BN_CTX_get(ctx);
              r = EC_POINT_new(group);
              if (rnd == (BIGNUM *)0x0 || r == (EC_POINT *)0x0) {
                ERR_GOST_error(0x69,0x41,DAT_0011298c,0xb5);
                bVar1 = true;
                pDVar5 = (DSA_SIG *)0x0;
              }
              else {
                r_01 = (BIGNUM *)0x0;
                local_3c = (BIGNUM *)0x0;
                local_40 = (BIGNUM *)0x0;
                x = r_01;
                r_00 = r_01;
                do {
                  do {
                    iVar4 = BN_rand_range(rnd,pBVar3);
                    if (iVar4 == 0) {
                      bVar1 = true;
                      ERR_GOST_error(0x69,0x7d,DAT_0011298c,0xbc);
                      pDVar5 = (DSA_SIG *)0x0;
                      goto LAB_0011284c;
                    }
                    iVar4 = EC_POINT_mul(group,r,rnd,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
                    if (iVar4 == 0) {
                      bVar1 = true;
                      ERR_GOST_error(0x69,0x10,DAT_0011298c,0xc0);
                      pDVar5 = (DSA_SIG *)0x0;
                      goto LAB_0011284c;
                    }
                    if (x == (BIGNUM *)0x0) {
                      x = BN_CTX_get(ctx);
                    }
                    if (r_01 == (BIGNUM *)0x0) {
                      r_01 = BN_CTX_get(ctx);
                    }
                    if (x == (BIGNUM *)0x0 || r_01 == (BIGNUM *)0x0) {
                      ERR_GOST_error(0x69,0x41,DAT_0011298c,200);
                      bVar1 = true;
                      pDVar5 = (DSA_SIG *)0x0;
                      goto LAB_0011284c;
                    }
                    iVar4 = EC_POINT_get_affine_coordinates_GFp(group,r,x,(BIGNUM *)0x0,ctx);
                    if (iVar4 == 0) {
                      bVar1 = true;
                      ERR_GOST_error(0x69,0x10,DAT_0011298c,0xcc);
                      pDVar5 = (DSA_SIG *)0x0;
                      goto LAB_0011284c;
                    }
                    iVar4 = BN_nnmod(r_01,x,pBVar3,ctx);
                    if (iVar4 == 0) {
                      bVar1 = true;
                      ERR_GOST_error(0x69,0x44,DAT_0011298c,0xd1);
                      pDVar5 = (DSA_SIG *)0x0;
                      goto LAB_0011284c;
                    }
                  } while (r_01->top == 0);
                  if (local_3c == (BIGNUM *)0x0) {
                    local_3c = BN_CTX_get(ctx);
                    if (r_00 != (BIGNUM *)0x0) goto LAB_00112750;
LAB_001127a2:
                    r_00 = BN_CTX_get(ctx);
                    if (local_40 != (BIGNUM *)0x0) goto LAB_00112756;
LAB_001127b0:
                    local_40 = BN_CTX_get(ctx);
                    pBVar2 = local_40;
                    if (local_3c != (BIGNUM *)0x0 && r_00 != (BIGNUM *)0x0) goto joined_r0x001127c6;
LAB_00112762:
                    ERR_GOST_error(0x69,0x41,DAT_001128a8,0xde);
                    bVar1 = true;
                    pDVar5 = (DSA_SIG *)0x0;
                    goto LAB_0011284c;
                  }
                  if (r_00 == (BIGNUM *)0x0) goto LAB_001127a2;
LAB_00112750:
                  if (local_40 == (BIGNUM *)0x0) goto LAB_001127b0;
LAB_00112756:
                  pBVar2 = local_3c;
                  if (r_00 == (BIGNUM *)0x0) goto LAB_00112762;
joined_r0x001127c6:
                  if (pBVar2 == (BIGNUM *)0x0) goto LAB_00112762;
                  iVar4 = BN_mod_mul(local_3c,a,r_01,pBVar3,ctx);
                  if (((iVar4 == 0) || (iVar4 = BN_mod_mul(r_00,rnd,rem,pBVar3,ctx), iVar4 == 0)) ||
                     (iVar4 = BN_mod_add(local_40,local_3c,r_00,pBVar3,ctx), iVar4 == 0)) {
                    ERR_GOST_error(0x69,0x44,DAT_001128a8,0xe5);
                    bVar1 = true;
                    pDVar5 = (DSA_SIG *)0x0;
                    goto LAB_0011284c;
                  }
                } while (local_40->top == 0);
                pBVar3 = BN_dup(local_40);
                local_2c->s = pBVar3;
                pBVar3 = BN_dup(r_01);
                local_2c->r = pBVar3;
                if ((local_2c->s == (BIGNUM *)0x0) || (bVar1 = false, pBVar3 == (BIGNUM *)0x0)) {
                  ERR_GOST_error(0x69,0x41,DAT_001128a8,0xee);
                  bVar1 = true;
                  pDVar5 = (DSA_SIG *)0x0;
                }
              }
            }
          }
        }
      }
    }
LAB_0011284c:
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (r != (EC_POINT *)0x0) {
      EC_POINT_free(r);
    }
  }
  if (m != (BIGNUM *)0x0) {
    BN_free(m);
  }
  if (bVar1) {
    DSA_SIG_free(local_2c);
  }
  return pDVar5;
}

