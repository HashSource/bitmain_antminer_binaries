
int BN_BLINDING_invert_ex(BIGNUM *n,BIGNUM *r,BN_BLINDING *b,BN_CTX *param_4)

{
  int iVar1;
  ulong *puVar2;
  ulong *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  BN_MONT_CTX *mont;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  if ((r == (BIGNUM *)0x0) && (r = *(BIGNUM **)(b + 4), r == (BIGNUM *)0x0)) {
    ERR_put_error(3,0x65,0x6b,"crypto/bn/bn_blind.c",0xaf);
    iVar1 = 0;
  }
  else {
    mont = *(BN_MONT_CTX **)(b + 0x1c);
    if (mont == (BN_MONT_CTX *)0x0) {
      iVar1 = BN_mod_mul(n,n,r,*(BIGNUM **)(b + 0xc),param_4);
    }
    else {
      uVar10 = r->top;
      if ((int)uVar10 <= n->dmax) {
        uVar6 = n->top;
        if (uVar10 != 0) {
          puVar2 = n->d;
          if (uVar10 < 9) {
            uVar9 = 0;
          }
          else {
            iVar1 = 1 - uVar6;
            uVar9 = 0;
            puVar3 = puVar2 + 0x14;
            do {
              HintPreloadData(puVar3);
              iVar8 = iVar1 + 4;
              puVar3[-0x12] = puVar3[-0x12] & iVar1 + 1 >> 0x1f;
              puVar3[-0x14] = puVar3[-0x14] & iVar1 + -1 >> 0x1f;
              puVar3[-0x13] = puVar3[-0x13] & iVar1 >> 0x1f;
              iVar7 = iVar1 + 6;
              puVar3[-0x11] = puVar3[-0x11] & iVar1 + 2 >> 0x1f;
              puVar3[-0x10] = puVar3[-0x10] & iVar1 + 3 >> 0x1f;
              iVar4 = iVar1 + 5;
              iVar1 = iVar1 + 8;
              puVar3[-0xf] = puVar3[-0xf] & iVar8 >> 0x1f;
              puVar3[-0xe] = puVar3[-0xe] & iVar4 >> 0x1f;
              uVar5 = uVar9 + 9;
              uVar9 = uVar9 + 8;
              puVar3[-0xd] = puVar3[-0xd] & iVar7 >> 0x1f;
              puVar3 = puVar3 + 8;
            } while (uVar5 < uVar10 - 7);
          }
          puVar2 = puVar2 + uVar9;
          do {
            iVar1 = uVar9 - uVar6;
            uVar9 = uVar9 + 1;
            *puVar2 = *puVar2 & iVar1 >> 0x1f;
            puVar2 = puVar2 + 1;
          } while (uVar9 < uVar10);
        }
        n->top = (uVar10 ^ uVar6) & (int)(uVar10 - uVar6) >> 0x1f ^ uVar10;
      }
      iVar1 = BN_mod_mul_montgomery(n,n,r,mont,param_4);
    }
  }
  return iVar1;
}

