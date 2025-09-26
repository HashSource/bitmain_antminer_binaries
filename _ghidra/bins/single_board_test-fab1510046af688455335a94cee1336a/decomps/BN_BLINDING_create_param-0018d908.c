
BN_BLINDING *
BN_BLINDING_create_param
          (BN_BLINDING *b,BIGNUM *e,BIGNUM *m,BN_CTX *ctx,bn_mod_exp *bn_mod_exp,BN_MONT_CTX *m_ctx)

{
  BIGNUM *pBVar1;
  int iVar2;
  ulong uVar3;
  BN_BLINDING *ptr;
  BN_BLINDING *pBVar4;
  int iVar5;
  
  ptr = b;
  if ((b == (BN_BLINDING *)0x0) &&
     (ptr = BN_BLINDING_new((BIGNUM *)0x0,(BIGNUM *)0x0,m), ptr == (BN_BLINDING *)0x0)) {
    return (BN_BLINDING *)0x0;
  }
  if (*(int *)ptr == 0) {
    pBVar1 = BN_new();
    *(BIGNUM **)ptr = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_0018d98e;
  }
  if (*(int *)(ptr + 4) == 0) {
    pBVar1 = BN_new();
    *(BIGNUM **)(ptr + 4) = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_0018d98e;
  }
  if (e == (BIGNUM *)0x0) {
    pBVar1 = *(BIGNUM **)(ptr + 8);
  }
  else {
    if (*(BIGNUM **)(ptr + 8) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(ptr + 8));
    }
    pBVar1 = BN_dup(e);
    *(BIGNUM **)(ptr + 8) = pBVar1;
  }
  if (pBVar1 != (BIGNUM *)0x0) {
    if (bn_mod_exp != (bn_mod_exp *)0x0) {
      *(bn_mod_exp **)(ptr + 0x28) = bn_mod_exp;
    }
    if (m_ctx != (BN_MONT_CTX *)0x0) {
      *(BN_MONT_CTX **)(ptr + 0x24) = m_ctx;
    }
    iVar5 = 0x21;
    while (iVar2 = BN_rand_range(*(BIGNUM **)ptr,*(BIGNUM **)(ptr + 0xc)), iVar2 != 0) {
      pBVar1 = BN_mod_inverse(*(BIGNUM **)(ptr + 4),*(BIGNUM **)ptr,*(BIGNUM **)(ptr + 0xc),ctx);
      if (pBVar1 != (BIGNUM *)0x0) {
        if ((*(code **)(ptr + 0x28) == (code *)0x0) || (*(int *)(ptr + 0x24) == 0)) {
          iVar5 = BN_mod_exp(*(BIGNUM **)ptr,*(BIGNUM **)ptr,*(BIGNUM **)(ptr + 8),
                             *(BIGNUM **)(ptr + 0xc),ctx);
        }
        else {
          iVar5 = (**(code **)(ptr + 0x28))
                            (*(undefined4 *)ptr,*(undefined4 *)ptr,*(undefined4 *)(ptr + 8),
                             *(undefined4 *)(ptr + 0xc),ctx,*(int *)(ptr + 0x24));
        }
        if (iVar5 != 0) {
          return ptr;
        }
        break;
      }
      uVar3 = ERR_peek_last_error();
      if ((uVar3 & 0xfff) != 0x6c) break;
      iVar5 = iVar5 + -1;
      if (iVar5 == 0) {
        ERR_put_error(3,0x80,0x71,"bn_blind.c",0x166);
        break;
      }
      ERR_clear_error();
    }
  }
LAB_0018d98e:
  pBVar4 = ptr;
  if (b == (BN_BLINDING *)0x0) {
    if (*(BIGNUM **)ptr != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)ptr);
    }
    if (*(BIGNUM **)(ptr + 4) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(ptr + 4));
    }
    if (*(BIGNUM **)(ptr + 8) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(ptr + 8));
    }
    if (*(BIGNUM **)(ptr + 0xc) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(ptr + 0xc));
    }
    pBVar4 = (BN_BLINDING *)0x0;
    CRYPTO_free(ptr);
  }
  return pBVar4;
}

