
undefined4 ssl_cipher_strength_sort(int **param_1,int **param_2)

{
  int *piVar1;
  int *piVar2;
  void *__s;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  size_t __n;
  int *piVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  bool bVar12;
  
  piVar7 = *param_1;
  if (piVar7 == (int *)0x0) {
    __n = 4;
    iVar9 = 0;
  }
  else {
    iVar9 = 0;
    do {
      if ((piVar7[1] != 0) && (iVar9 < *(int *)(*piVar7 + 0x28))) {
        iVar9 = *(int *)(*piVar7 + 0x28);
      }
      piVar7 = (int *)piVar7[3];
    } while (piVar7 != (int *)0x0);
    __n = (iVar9 + 1) * 4;
  }
  __s = CRYPTO_malloc(__n,DAT_0007fa4c,0x464);
  if (__s == (void *)0x0) {
    ERR_put_error(0x14,0xe7,0x41,DAT_0007fa4c,0x466);
    uVar4 = 0;
  }
  else {
    memset(__s,0,__n);
    for (piVar7 = *param_1; piVar7 != (int *)0x0; piVar7 = (int *)piVar7[3]) {
      if (piVar7[1] != 0) {
        *(int *)((int)__s + *(int *)(*piVar7 + 0x28) * 4) =
             *(int *)((int)__s + *(int *)(*piVar7 + 0x28) * 4) + 1;
      }
    }
    if (-1 < iVar9) {
      piVar7 = (int *)((int)__s + (iVar9 + 1) * 4);
      do {
        piVar7 = piVar7 + -1;
        if (0 < *piVar7) {
          piVar8 = *param_2;
          piVar3 = *param_1;
          piVar11 = piVar8;
          piVar1 = piVar3;
          if (piVar8 != (int *)0x0) {
            do {
              if (piVar1 == (int *)0x0) break;
              piVar6 = (int *)piVar1[3];
              piVar2 = piVar11;
              if (((iVar9 == *(int *)(*piVar1 + 0x28)) && (piVar1[1] != 0)) &&
                 (piVar2 = piVar1, piVar1 != piVar11)) {
                iVar5 = piVar1[4];
                if (piVar1 == piVar3) {
                  piVar3 = piVar6;
                }
                piVar10 = piVar6;
                if (iVar5 != 0) {
                  *(int **)(iVar5 + 0xc) = piVar6;
                  piVar10 = (int *)piVar1[3];
                }
                if (piVar10 != (int *)0x0) {
                  piVar10[4] = iVar5;
                }
                piVar11[3] = (int)piVar1;
                piVar1[4] = (int)piVar11;
                piVar1[3] = 0;
              }
              piVar11 = piVar2;
              bVar12 = piVar8 != piVar1;
              piVar1 = piVar6;
            } while (bVar12);
          }
          *param_1 = piVar3;
          *param_2 = piVar11;
        }
        bVar12 = iVar9 != 0;
        iVar9 = iVar9 + -1;
      } while (bVar12);
    }
    CRYPTO_free(__s);
    uVar4 = 1;
  }
  return uVar4;
}

