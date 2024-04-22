
int dsa_do_verify(uchar *param_1,int param_2,BIGNUM **param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  BN_CTX *ctx;
  BIGNUM *pBVar3;
  BN_MONT_CTX *m_ctx;
  code *pcVar4;
  BIGNUM BStack_5c;
  BIGNUM BStack_48;
  BIGNUM BStack_34;
  
  if (((*(int *)(param_4 + 0xc) == 0) || (*(BIGNUM **)(param_4 + 0x10) == (BIGNUM *)0x0)) ||
     (*(int *)(param_4 + 0x14) == 0)) {
    ERR_put_error(10,0x71,0x65,DAT_000fe768,0x143);
    return -1;
  }
  uVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if (((uVar1 & 0xffffffbf) != 0xa0) && (uVar1 != 0x100)) {
    ERR_put_error(10,0x71,0x66,DAT_000fe768,0x14a);
    return -1;
  }
  iVar2 = BN_num_bits(*(BIGNUM **)(param_4 + 0xc));
  if (10000 < iVar2) {
    ERR_put_error(10,0x71,0x67,DAT_000fe768,0x14f);
    return -1;
  }
  BN_init(&BStack_5c);
  BN_init(&BStack_48);
  BN_init(&BStack_34);
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    ERR_put_error(10,0x71,3,DAT_000fe768,0x192);
    iVar2 = -1;
    goto LAB_000fe5e2;
  }
  pBVar3 = *param_3;
  if (((pBVar3->top == 0) || (pBVar3->neg != 0)) ||
     ((iVar2 = BN_ucmp(pBVar3,*(BIGNUM **)(param_4 + 0x10)), -1 < iVar2 ||
      (((pBVar3 = param_3[1], pBVar3->top == 0 || (pBVar3->neg != 0)) ||
       (iVar2 = BN_ucmp(pBVar3,*(BIGNUM **)(param_4 + 0x10)), -1 < iVar2)))))) {
    iVar2 = 0;
  }
  else {
    pBVar3 = BN_mod_inverse(&BStack_48,param_3[1],*(BIGNUM **)(param_4 + 0x10),ctx);
    if (pBVar3 != (BIGNUM *)0x0) {
      iVar2 = (int)uVar1 >> 3;
      if (param_2 <= (int)uVar1 >> 3) {
        iVar2 = param_2;
      }
      pBVar3 = BN_bin2bn(param_1,iVar2,&BStack_5c);
      if (((pBVar3 != (BIGNUM *)0x0) &&
          (iVar2 = BN_mod_mul(&BStack_5c,&BStack_5c,&BStack_48,*(BIGNUM **)(param_4 + 0x10),ctx),
          iVar2 != 0)) &&
         (iVar2 = BN_mod_mul(&BStack_48,*param_3,&BStack_48,*(BIGNUM **)(param_4 + 0x10),ctx),
         iVar2 != 0)) {
        if ((*(uint *)(param_4 + 0x28) & 1) == 0) {
          m_ctx = (BN_MONT_CTX *)0x0;
        }
        else {
          m_ctx = BN_MONT_CTX_set_locked
                            ((BN_MONT_CTX **)(param_4 + 0x2c),8,*(BIGNUM **)(param_4 + 0xc),ctx);
          if (m_ctx == (BN_MONT_CTX *)0x0) goto LAB_000fe656;
        }
        pcVar4 = *(code **)(*(int *)(param_4 + 0x3c) + 0x10);
        if (pcVar4 == (code *)0x0) {
          iVar2 = BN_mod_exp2_mont(&BStack_34,*(BIGNUM **)(param_4 + 0x14),&BStack_5c,
                                   *(BIGNUM **)(param_4 + 0x18),&BStack_48,
                                   *(BIGNUM **)(param_4 + 0xc),ctx,m_ctx);
        }
        else {
          iVar2 = (*pcVar4)(param_4,&BStack_34,*(undefined4 *)(param_4 + 0x14),&BStack_5c,
                            *(undefined4 *)(param_4 + 0x18),&BStack_48,
                            *(undefined4 *)(param_4 + 0xc),ctx,m_ctx);
        }
        if ((iVar2 != 0) &&
           (iVar2 = BN_div((BIGNUM *)0x0,&BStack_5c,&BStack_34,*(BIGNUM **)(param_4 + 0x10),ctx),
           iVar2 != 0)) {
          uVar1 = BN_ucmp(&BStack_5c,*param_3);
          iVar2 = 1 - uVar1;
          if (1 < uVar1) {
            iVar2 = 0;
          }
          goto LAB_000fe5dc;
        }
      }
    }
LAB_000fe656:
    ERR_put_error(10,0x71,3,DAT_000fe768,0x192);
    iVar2 = -1;
  }
LAB_000fe5dc:
  BN_CTX_free(ctx);
LAB_000fe5e2:
  BN_free(&BStack_5c);
  BN_free(&BStack_48);
  BN_free(&BStack_34);
  return iVar2;
}

