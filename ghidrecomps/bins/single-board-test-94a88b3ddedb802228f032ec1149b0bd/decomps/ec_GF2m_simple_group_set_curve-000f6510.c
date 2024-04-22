
BIGNUM * ec_GF2m_simple_group_set_curve
                   (int param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4)

{
  BIGNUM *pBVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  BIGNUM *a;
  int iVar6;
  
  pBVar1 = BN_copy((BIGNUM *)(param_1 + 0x48),param_2);
  if (pBVar1 != (BIGNUM *)0x0) {
    iVar6 = param_1 + 0x5c;
    uVar2 = BN_GF2m_poly2arr((BIGNUM *)(param_1 + 0x48),iVar6,6);
    if ((uVar2 & 0xfffffffd) == 4) {
      a = (BIGNUM *)(param_1 + 0x74);
      pBVar1 = (BIGNUM *)BN_GF2m_mod_arr(a,param_3,iVar6);
      if (pBVar1 != (BIGNUM *)0x0) {
        iVar4 = *(int *)(param_1 + 0x5c) + 0x1f;
        iVar5 = *(int *)(param_1 + 0x5c) + 0x3e;
        if (-1 < iVar4) {
          iVar5 = iVar4;
        }
        if (*(int *)(param_1 + 0x7c) < iVar5 >> 5) {
          pBVar1 = bn_expand2(a,iVar5 >> 5);
          iVar5 = 1 - (int)pBVar1;
          if ((BIGNUM *)0x1 < pBVar1) {
            iVar5 = 0;
          }
        }
        else {
          iVar5 = 1 - (int)a;
          if ((BIGNUM *)0x1 < a) {
            iVar5 = 0;
          }
        }
        pBVar1 = (BIGNUM *)0x0;
        if (iVar5 == 0) {
          iVar5 = *(int *)(param_1 + 0x78);
          if (iVar5 < *(int *)(param_1 + 0x7c)) {
            puVar3 = (undefined4 *)(*(int *)(param_1 + 0x74) + (iVar5 + -1) * 4);
            do {
              puVar3 = puVar3 + 1;
              *puVar3 = 0;
              iVar5 = iVar5 + 1;
            } while (iVar5 < *(int *)(param_1 + 0x7c));
          }
          pBVar1 = (BIGNUM *)BN_GF2m_mod_arr((BIGNUM *)(param_1 + 0x88),param_4,iVar6);
          if (pBVar1 != (BIGNUM *)0x0) {
            iVar5 = *(int *)(param_1 + 0x90);
            iVar4 = *(int *)(param_1 + 0x5c) + 0x1f;
            iVar6 = *(int *)(param_1 + 0x5c) + 0x3e;
            if (-1 < iVar4) {
              iVar6 = iVar4;
            }
            if (iVar5 < iVar6 >> 5) {
              pBVar1 = bn_expand2((BIGNUM *)(param_1 + 0x88),iVar6 >> 5);
              if (pBVar1 == (BIGNUM *)0x0) {
                return (BIGNUM *)0x0;
              }
              iVar5 = *(int *)(param_1 + 0x90);
            }
            iVar6 = *(int *)(param_1 + 0x8c);
            if (iVar6 < iVar5) {
              puVar3 = (undefined4 *)(*(int *)(param_1 + 0x88) + (iVar6 + -1) * 4);
              do {
                puVar3 = puVar3 + 1;
                *puVar3 = 0;
                iVar6 = iVar6 + 1;
              } while (iVar6 < *(int *)(param_1 + 0x90));
            }
            pBVar1 = (BIGNUM *)0x1;
          }
        }
      }
    }
    else {
      ERR_put_error(0x10,0xc3,0x83,DAT_000f6614,0xdb);
      pBVar1 = (BIGNUM *)0x0;
    }
  }
  return pBVar1;
}

