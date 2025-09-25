
int BN_mod_exp_mont_word(BIGNUM *r,ulong a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *m_ctx)

{
  int iVar1;
  BIGNUM *a_00;
  BIGNUM *rem;
  ulong uVar2;
  int iVar3;
  ulong extraout_r1;
  BIGNUM *pBVar4;
  ulong w;
  ulong w_00;
  bool bVar5;
  bool bVar6;
  BN_MONT_CTX *local_38;
  
  iVar1 = BN_get_flags(p,4);
  if ((iVar1 != 0) || (iVar1 = BN_get_flags(m,4), iVar1 != 0)) {
    ERR_put_error(3,0x75,0x42,"crypto/bn/bn_exp.c",0x48f);
    return 0;
  }
  iVar1 = BN_is_odd(m);
  if (iVar1 == 0) {
    ERR_put_error(3,0x75,0x66,"crypto/bn/bn_exp.c",0x497);
    return 0;
  }
  if (m->top == 1) {
    __aeabi_uidivmod(a,*m->d);
    a = extraout_r1;
  }
  iVar1 = BN_num_bits(p);
  if (iVar1 == 0) {
    iVar1 = BN_abs_is_word(m,1);
    if (iVar1 == 0) {
      iVar1 = BN_set_word(r,1);
      return iVar1;
    }
LAB_00185e1a:
    BN_set_word(r,0);
    return 1;
  }
  if (a == 0) goto LAB_00185e1a;
  BN_CTX_start(ctx);
  a_00 = BN_CTX_get(ctx);
  rem = BN_CTX_get(ctx);
  if (rem == (BIGNUM *)0x0) {
    iVar3 = 0;
    local_38 = (BN_MONT_CTX *)0x0;
    goto LAB_00185dc8;
  }
  if (m_ctx == (BN_MONT_CTX *)0x0) {
    local_38 = BN_MONT_CTX_new();
    if ((local_38 != (BN_MONT_CTX *)0x0) && (iVar3 = BN_MONT_CTX_set(local_38,m,ctx), iVar3 != 0))
    goto LAB_00185ce6;
    iVar3 = 0;
  }
  else {
    local_38 = m_ctx;
LAB_00185ce6:
    iVar1 = iVar1 + -2;
    if (iVar1 < 0) {
      if (a == 1) {
LAB_00185ef0:
        iVar3 = BN_set_word(r,1);
        if (iVar3 != 0) {
          iVar3 = 1;
        }
      }
      else {
LAB_00185e64:
        rem = a_00;
        iVar3 = BN_set_word(rem,a);
        if ((iVar3 != 0) && (iVar3 = BN_to_montgomery(rem,rem,local_38,ctx), iVar3 != 0))
        goto LAB_00185eb2;
      }
    }
    else {
      bVar5 = true;
      w = a;
      do {
        w_00 = w * w;
        uVar2 = __aeabi_uidiv(w_00,w);
        if (w == uVar2) {
          if (!bVar5) goto LAB_00185d2a;
          bVar5 = true;
          pBVar4 = rem;
        }
        else {
          if (bVar5) {
            iVar3 = BN_set_word(a_00,w);
            if ((iVar3 == 0) ||
               (iVar3 = BN_to_montgomery(a_00,a_00,local_38,ctx), pBVar4 = a_00, iVar3 == 0))
            goto LAB_00185dc8;
          }
          else {
            iVar3 = BN_mul_word(a_00,w);
            if ((iVar3 == 0) ||
               (iVar3 = BN_div((BIGNUM *)0x0,rem,a_00,m,ctx), pBVar4 = rem, rem = a_00, iVar3 == 0))
            goto LAB_00185dc6;
          }
          w_00 = 1;
          a_00 = pBVar4;
LAB_00185d2a:
          iVar3 = BN_mod_mul_montgomery(a_00,a_00,a_00,local_38,ctx);
          if (iVar3 == 0) goto LAB_00185dc8;
          bVar5 = false;
          pBVar4 = rem;
        }
        iVar3 = BN_is_bit_set(p,iVar1);
        rem = pBVar4;
        w = w_00;
        if (iVar3 != 0) {
          uVar2 = __aeabi_uidiv(w_00 * a,a);
          w = w_00 * a;
          if (uVar2 != w_00) {
            if (bVar5) {
              iVar3 = BN_set_word(a_00,w_00);
              if ((iVar3 == 0) || (iVar3 = BN_to_montgomery(a_00,a_00,local_38,ctx), iVar3 == 0))
              goto LAB_00185dc8;
              bVar5 = false;
              w = a;
            }
            else {
              iVar3 = BN_mul_word(a_00,w_00);
              if ((iVar3 == 0) ||
                 (iVar3 = BN_div((BIGNUM *)0x0,pBVar4,a_00,m,ctx), rem = a_00, w = a, a_00 = pBVar4,
                 iVar3 == 0)) goto LAB_00185dc6;
            }
          }
        }
        bVar6 = iVar1 != 0;
        iVar1 = iVar1 + -1;
      } while (bVar6);
      if (w == 1) {
        rem = a_00;
        if (bVar5) goto LAB_00185ef0;
      }
      else {
        a = w;
        if (bVar5) goto LAB_00185e64;
        iVar1 = BN_mul_word(a_00,w);
        if ((iVar1 == 0) || (iVar1 = BN_div((BIGNUM *)0x0,rem,a_00,m,ctx), iVar1 == 0)) {
LAB_00185dc6:
          iVar3 = 0;
          goto LAB_00185dc8;
        }
      }
LAB_00185eb2:
      iVar3 = BN_from_montgomery(r,rem,local_38,ctx);
      if (iVar3 != 0) {
        iVar3 = 1;
      }
    }
LAB_00185dc8:
    if (m_ctx != (BN_MONT_CTX *)0x0) goto LAB_00185dd0;
  }
  BN_MONT_CTX_free(local_38);
LAB_00185dd0:
  BN_CTX_end(ctx);
  return iVar3;
}

