
undefined4 ssl_cipher_strength_sort(int *param_1,int *param_2)

{
  int iVar1;
  void *ptr;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  bool bVar12;
  
  piVar6 = (int *)*param_1;
  if (piVar6 == (int *)0x0) {
    iVar1 = 4;
    iVar9 = 0;
  }
  else {
    iVar9 = 0;
    do {
      if ((piVar6[1] != 0) && (iVar9 < *(int *)(*piVar6 + 0x38))) {
        iVar9 = *(int *)(*piVar6 + 0x38);
      }
      piVar6 = (int *)piVar6[3];
    } while (piVar6 != (int *)0x0);
    iVar1 = (iVar9 + 1) * 4;
  }
  ptr = (void *)CRYPTO_zalloc(iVar1,"ssl/ssl_ciph.c",0x3a1);
  if (ptr == (void *)0x0) {
    ERR_put_error(0x14,0xe7,0x41,"ssl/ssl_ciph.c",0x3a3);
    uVar3 = 0;
  }
  else {
    for (piVar6 = (int *)*param_1; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[3]) {
      if (piVar6[1] != 0) {
        *(int *)((int)ptr + *(int *)(*piVar6 + 0x38) * 4) =
             *(int *)((int)ptr + *(int *)(*piVar6 + 0x38) * 4) + 1;
      }
    }
    piVar6 = (int *)((int)ptr + iVar9 * 4);
    do {
      if (0 < *piVar6) {
        piVar7 = (int *)*param_1;
        piVar2 = (int *)*param_2;
        piVar4 = (int *)0x0;
        piVar5 = piVar7;
        piVar11 = piVar2;
        while (piVar8 = piVar5, piVar8 != (int *)0x0 && piVar2 != piVar4) {
          piVar5 = (int *)piVar8[3];
          piVar4 = piVar8;
          if ((iVar9 == *(int *)(*piVar8 + 0x38)) && (piVar8 != piVar11 && piVar8[1] != 0)) {
            iVar1 = piVar8[4];
            if (piVar8 == piVar7) {
              piVar7 = piVar5;
            }
            piVar10 = piVar5;
            if (iVar1 != 0) {
              *(int **)(iVar1 + 0xc) = piVar5;
              piVar10 = (int *)piVar8[3];
            }
            if (piVar10 != (int *)0x0) {
              piVar10[4] = iVar1;
            }
            piVar11[3] = (int)piVar8;
            piVar8[4] = (int)piVar11;
            piVar8[3] = 0;
            piVar11 = piVar8;
          }
        }
        *param_1 = (int)piVar7;
        *param_2 = (int)piVar11;
      }
      bVar12 = iVar9 != 0;
      iVar9 = iVar9 + -1;
      piVar6 = piVar6 + -1;
    } while (bVar12);
    CRYPTO_free(ptr);
    uVar3 = 1;
  }
  return uVar3;
}

