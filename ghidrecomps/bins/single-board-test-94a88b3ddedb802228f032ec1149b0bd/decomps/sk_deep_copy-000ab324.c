
int * sk_deep_copy(int *param_1,code *param_2,code *param_3)

{
  int *piVar1;
  char *file;
  int *ptr;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  ptr = (int *)CRYPTO_malloc(0x14,DAT_000ab3fc,0x7c);
  if (ptr != (int *)0x0) {
    iVar4 = param_1[4];
    iVar5 = param_1[2];
    *ptr = *param_1;
    iVar2 = *param_1;
    ptr[4] = iVar4;
    ptr[2] = iVar5;
    file = DAT_000ab3fc;
    if (iVar2 < 4) {
      iVar2 = 4;
    }
    ptr[3] = iVar2;
    pvVar3 = CRYPTO_malloc(iVar2 << 2,file,0x82);
    ptr[1] = (int)pvVar3;
    if (pvVar3 == (void *)0x0) {
      CRYPTO_free(ptr);
      ptr = (int *)0x0;
    }
    else {
      iVar2 = ptr[3];
      if (0 < iVar2) {
        iVar4 = 0;
        while( true ) {
          *(undefined4 *)((int)pvVar3 + iVar4 * 4) = 0;
          iVar4 = iVar4 + 1;
          if (iVar4 == iVar2) break;
          pvVar3 = (void *)ptr[1];
        }
      }
      iVar2 = *ptr;
      if (0 < iVar2) {
        iVar4 = 0;
        do {
          iVar5 = *(int *)(param_1[1] + iVar4 * 4);
          if (iVar5 != 0) {
            iVar6 = ptr[1];
            iVar2 = (*param_2)(iVar5);
            *(int *)(iVar6 + iVar4 * 4) = iVar2;
            if (iVar2 == 0) {
              iVar4 = iVar4 + -1;
              pvVar3 = (void *)ptr[1];
              iVar2 = iVar4 * 4;
              while (-1 < iVar4) {
                while( true ) {
                  iVar4 = iVar4 + -1;
                  piVar1 = (int *)((int)pvVar3 + iVar2);
                  iVar2 = iVar2 + -4;
                  if (*piVar1 == 0) break;
                  (*param_3)(*piVar1);
                  pvVar3 = (void *)ptr[1];
                  if (iVar4 < 0) goto LAB_000ab3dc;
                }
              }
LAB_000ab3dc:
              if (pvVar3 != (void *)0x0) {
                CRYPTO_free(pvVar3);
              }
              CRYPTO_free(ptr);
              return (int *)0x0;
            }
            iVar2 = *ptr;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar2);
      }
    }
  }
  return ptr;
}

