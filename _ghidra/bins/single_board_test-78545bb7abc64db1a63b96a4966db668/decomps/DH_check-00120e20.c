
int DH_check(DH *dh,int *codes)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *rem;
  BIGNUM *pBVar2;
  uint extraout_r3;
  uint uVar3;
  BIGNUM *a;
  
  iVar1 = DH_check_params();
  if (iVar1 == 0) {
    return 0;
  }
  ctx = BN_CTX_new();
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_start(ctx);
    r = BN_CTX_get(ctx);
    rem = BN_CTX_get(ctx);
    if (rem != (BIGNUM *)0x0) {
      if (dh->q == (BIGNUM *)0x0) {
LAB_00120eea:
        iVar1 = BN_is_prime_ex(dh->p,0x40,ctx,(BN_GENCB *)0x0);
        if (-1 < iVar1) {
          if (iVar1 == 0) {
            iVar1 = 1;
            *codes = *codes | 1;
            goto LAB_00120eb2;
          }
          if (dh->q != (BIGNUM *)0x0) {
LAB_00120f00:
            iVar1 = 1;
            goto LAB_00120eb2;
          }
          iVar1 = BN_rshift1(r,dh->p);
          if (iVar1 != 0) {
            iVar1 = BN_is_prime_ex(r,0x40,ctx,(BN_GENCB *)0x0);
            if (-1 < iVar1) {
              if (iVar1 == 0) {
                iVar1 = 1;
                *codes = *codes | 2;
                goto LAB_00120eb2;
              }
              goto LAB_00120f00;
            }
          }
        }
      }
      else {
        a = dh->g;
        pBVar2 = BN_value_one();
        iVar1 = BN_cmp(a,pBVar2);
        if ((iVar1 < 1) || (iVar1 = BN_cmp(dh->g,dh->p), -1 < iVar1)) {
LAB_00120e7c:
          *codes = *codes | 8;
        }
        else {
          iVar1 = BN_mod_exp(r,dh->g,dh->q,dh->p,ctx);
          if (iVar1 == 0) goto LAB_00120eb0;
          iVar1 = BN_is_one(r);
          if (iVar1 == 0) goto LAB_00120e7c;
        }
        iVar1 = BN_is_prime_ex(dh->q,0x40,ctx,(BN_GENCB *)0x0);
        if (-1 < iVar1) {
          uVar3 = extraout_r3;
          if (iVar1 == 0) {
            uVar3 = *codes;
          }
          pBVar2 = dh->p;
          if (iVar1 == 0) {
            *codes = uVar3 | 0x10;
          }
          iVar1 = BN_div(r,rem,pBVar2,dh->q,ctx);
          if (iVar1 != 0) {
            iVar1 = BN_is_one(rem);
            if (iVar1 == 0) {
              *codes = *codes | 0x20;
            }
            if ((dh->j != (BIGNUM *)0x0) && (iVar1 = BN_cmp(dh->j,r), iVar1 != 0)) {
              *codes = *codes | 0x40;
            }
            goto LAB_00120eea;
          }
        }
      }
    }
  }
LAB_00120eb0:
  iVar1 = 0;
LAB_00120eb2:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return iVar1;
}

