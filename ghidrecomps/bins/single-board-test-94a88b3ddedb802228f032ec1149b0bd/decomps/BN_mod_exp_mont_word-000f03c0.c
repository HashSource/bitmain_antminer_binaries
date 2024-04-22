
int BN_mod_exp_mont_word(BIGNUM *r,ulong a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *m_ctx)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *a_00;
  BIGNUM *rem;
  ulong uVar3;
  int iVar4;
  ulong extraout_r1;
  ulong w;
  bool bVar5;
  ulong w_00;
  bool bVar6;
  BN_MONT_CTX *local_38;
  
  if (p->flags << 0x1d < 0) {
    ERR_put_error(3,0x75,0x42,DAT_000f069c,0x492);
    return -1;
  }
  if ((m->top < 1) || (-1 < (int)(*m->d << 0x1f))) {
    ERR_put_error(3,0x75,0x66,DAT_000f069c,0x49a);
    return 0;
  }
  if (m->top == 1) {
    __aeabi_uidivmod(a);
    iVar1 = BN_num_bits(p);
    a = extraout_r1;
  }
  else {
    iVar1 = BN_num_bits(p);
  }
  if (iVar1 == 0) {
    if (((m->top != 1) || (*m->d != 1)) || (m->neg != 0)) {
      iVar1 = BN_set_word(r,1);
      return iVar1;
    }
LAB_000f055e:
    BN_set_word(r,0);
    return 1;
  }
  if (a == 0) goto LAB_000f055e;
  BN_CTX_start(ctx);
  pBVar2 = BN_CTX_get(ctx);
  a_00 = BN_CTX_get(ctx);
  rem = BN_CTX_get(ctx);
  if ((pBVar2 == (BIGNUM *)0x0 || a_00 == (BIGNUM *)0x0) || (rem == (BIGNUM *)0x0)) {
LAB_000f05b8:
    iVar1 = 0;
  }
  else {
    if (m_ctx == (BN_MONT_CTX *)0x0) {
      local_38 = BN_MONT_CTX_new();
      if (local_38 == (BN_MONT_CTX *)0x0) goto LAB_000f05b8;
      iVar4 = BN_MONT_CTX_set(local_38,m,ctx);
      if (iVar4 != 0) goto LAB_000f0456;
      iVar1 = 0;
    }
    else {
      local_38 = m_ctx;
LAB_000f0456:
      iVar1 = iVar1 + -2;
      if (iVar1 < 0) {
        if (a != 1) {
LAB_000f060e:
          iVar1 = BN_set_word(a_00,a);
          if (iVar1 != 0) {
            iVar1 = BN_mod_mul_montgomery(a_00,a_00,&local_38->RR,local_38,ctx);
joined_r0x000f05ea:
            if (iVar1 != 0) goto LAB_000f062e;
          }
          goto LAB_000f05ec;
        }
LAB_000f0660:
        iVar1 = BN_set_word(r,1);
        if (iVar1 != 0) {
          iVar1 = 1;
        }
      }
      else {
        bVar5 = true;
        w_00 = a;
        do {
          w = w_00 * w_00;
          uVar3 = __aeabi_uidiv(w,w_00);
          if (uVar3 == w_00) {
            if (!bVar5) goto LAB_000f04f2;
            bVar5 = true;
            pBVar2 = a_00;
          }
          else {
            if (bVar5) {
              iVar4 = BN_set_word(a_00,w_00);
              if (iVar4 == 0) goto LAB_000f05ec;
              iVar4 = BN_mod_mul_montgomery(a_00,a_00,&local_38->RR,local_38,ctx);
              pBVar2 = rem;
            }
            else {
              iVar4 = BN_mul_word(a_00,w_00);
              if (iVar4 == 0) goto LAB_000f05ec;
              iVar4 = BN_div((BIGNUM *)0x0,rem,a_00,m,ctx);
              pBVar2 = a_00;
              a_00 = rem;
            }
            rem = pBVar2;
            if (iVar4 == 0) goto LAB_000f05ec;
            w = 1;
LAB_000f04f2:
            iVar4 = BN_mod_mul_montgomery(a_00,a_00,a_00,local_38,ctx);
            if (iVar4 == 0) goto LAB_000f05ec;
            bVar5 = false;
            pBVar2 = a_00;
          }
          iVar4 = BN_is_bit_set(p,iVar1);
          a_00 = pBVar2;
          w_00 = w;
          if (iVar4 != 0) {
            uVar3 = __aeabi_uidiv(a * w,a);
            w_00 = a * w;
            if (w != uVar3) {
              if (bVar5) {
                iVar4 = BN_set_word(pBVar2,w);
                if ((iVar4 == 0) ||
                   (iVar4 = BN_mod_mul_montgomery(pBVar2,pBVar2,&local_38->RR,local_38,ctx),
                   iVar4 == 0)) goto LAB_000f05ec;
                bVar5 = false;
                w_00 = a;
              }
              else {
                iVar4 = BN_mul_word(pBVar2,w);
                if ((iVar4 == 0) ||
                   (iVar4 = BN_div((BIGNUM *)0x0,rem,pBVar2,m,ctx), a_00 = rem, w_00 = a,
                   rem = pBVar2, iVar4 == 0)) goto LAB_000f05ec;
              }
            }
          }
          bVar6 = iVar1 != 0;
          iVar1 = iVar1 + -1;
        } while (bVar6);
        if (w_00 == 1) {
          if (bVar5) goto LAB_000f0660;
LAB_000f062e:
          iVar1 = BN_from_montgomery(r,a_00,local_38,ctx);
          if (iVar1 != 0) {
            iVar1 = 1;
          }
        }
        else {
          a = w_00;
          if (bVar5) goto LAB_000f060e;
          iVar1 = BN_mul_word(a_00,w_00);
          if (iVar1 != 0) {
            iVar1 = BN_div((BIGNUM *)0x0,rem,a_00,m,ctx);
            a_00 = rem;
            goto joined_r0x000f05ea;
          }
LAB_000f05ec:
          iVar1 = 0;
        }
      }
      if (m_ctx != (BN_MONT_CTX *)0x0) goto LAB_000f05ba;
    }
    BN_MONT_CTX_free(local_38);
  }
LAB_000f05ba:
  BN_CTX_end(ctx);
  return iVar1;
}

