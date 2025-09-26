
BIGNUM * ec_GF2m_simple_group_copy(int param_1,int param_2)

{
  BIGNUM *pBVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  BIGNUM *a;
  BIGNUM *a_00;
  
  pBVar1 = BN_copy((BIGNUM *)(param_1 + 0x48),(BIGNUM *)(param_2 + 0x48));
  if (pBVar1 != (BIGNUM *)0x0) {
    a = (BIGNUM *)(param_1 + 0x74);
    pBVar1 = BN_copy(a,(BIGNUM *)(param_2 + 0x74));
    if (pBVar1 != (BIGNUM *)0x0) {
      a_00 = (BIGNUM *)(param_1 + 0x88);
      pBVar1 = BN_copy(a_00,(BIGNUM *)(param_2 + 0x88));
      if (pBVar1 != (BIGNUM *)0x0) {
        iVar4 = *(int *)(param_2 + 0x5c);
        *(int *)(param_1 + 0x5c) = iVar4;
        iVar2 = iVar4 + 0x3e;
        if (-1 < iVar4 + 0x1f) {
          iVar2 = iVar4 + 0x1f;
        }
        *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 0x60);
        *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 100);
        *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_2 + 0x68);
        *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_2 + 0x6c);
        *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_2 + 0x70);
        if (*(int *)(param_1 + 0x7c) < iVar2 >> 5) {
          pBVar1 = bn_expand2(a,iVar2 >> 5);
          iVar2 = 1 - (int)pBVar1;
          if ((BIGNUM *)0x1 < pBVar1) {
            iVar2 = 0;
          }
        }
        else {
          iVar2 = 1 - (int)a;
          if ((BIGNUM *)0x1 < a) {
            iVar2 = 0;
          }
        }
        if (iVar2 == 0) {
          iVar4 = *(int *)(param_1 + 0x5c) + 0x1f;
          iVar2 = *(int *)(param_1 + 0x5c) + 0x3e;
          if (-1 < iVar4) {
            iVar2 = iVar4;
          }
          if (*(int *)(param_1 + 0x90) < iVar2 >> 5) {
            pBVar1 = bn_expand2(a_00,iVar2 >> 5);
            iVar2 = 1 - (int)pBVar1;
            if ((BIGNUM *)0x1 < pBVar1) {
              iVar2 = 0;
            }
          }
          else {
            iVar2 = 1 - (int)a_00;
            if ((BIGNUM *)0x1 < a_00) {
              iVar2 = 0;
            }
          }
          if (iVar2 == 0) {
            iVar2 = *(int *)(param_1 + 0x78);
            if (iVar2 < *(int *)(param_1 + 0x7c)) {
              puVar3 = (undefined4 *)(*(int *)(param_1 + 0x74) + (iVar2 + -1) * 4);
              do {
                puVar3 = puVar3 + 1;
                *puVar3 = 0;
                iVar2 = iVar2 + 1;
              } while (iVar2 < *(int *)(param_1 + 0x7c));
            }
            iVar2 = *(int *)(param_1 + 0x8c);
            if (iVar2 < *(int *)(param_1 + 0x90)) {
              puVar3 = (undefined4 *)(*(int *)(param_1 + 0x88) + (iVar2 + -1) * 4);
              do {
                puVar3 = puVar3 + 1;
                *puVar3 = 0;
                iVar2 = iVar2 + 1;
              } while (iVar2 < *(int *)(param_1 + 0x90));
            }
            return (BIGNUM *)0x1;
          }
        }
        return (BIGNUM *)0x0;
      }
    }
  }
  return pBVar1;
}

