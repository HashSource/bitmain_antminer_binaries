
int * OPENSSL_sk_deep_copy(int *param_1,code *param_2,code *param_3)

{
  int *piVar1;
  int *ptr;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  ptr = (int *)CRYPTO_malloc(0x14,"crypto/stack/stack.c",0x50);
  if (ptr == (int *)0x0) {
    ERR_put_error(0xf,0x7f,0x41,"crypto/stack/stack.c",0x51);
  }
  else {
    iVar2 = param_1[1];
    iVar3 = param_1[2];
    iVar4 = param_1[3];
    *ptr = *param_1;
    ptr[1] = iVar2;
    ptr[2] = iVar3;
    ptr[3] = iVar4;
    iVar2 = *param_1;
    ptr[4] = param_1[4];
    if (iVar2 == 0) {
      ptr[1] = 0;
      ptr[3] = 0;
      return ptr;
    }
    if (iVar2 < 4) {
      iVar2 = 4;
    }
    ptr[3] = iVar2;
    iVar2 = CRYPTO_zalloc(iVar2 << 2,"crypto/stack/stack.c",0x60);
    ptr[1] = iVar2;
    if (iVar2 == 0) {
      CRYPTO_free(ptr);
      ptr = (int *)0x0;
    }
    else {
      iVar2 = *ptr;
      if (0 < iVar2) {
        iVar3 = 0;
        do {
          iVar4 = *(int *)(param_1[1] + iVar3 * 4);
          if (iVar4 != 0) {
            iVar5 = ptr[1];
            iVar2 = (*param_2)(iVar4);
            *(int *)(iVar5 + iVar3 * 4) = iVar2;
            if (iVar2 == 0) {
              iVar3 = iVar3 + -1;
              iVar2 = iVar3 * 4;
              while (-1 < iVar3) {
                while( true ) {
                  iVar3 = iVar3 + -1;
                  piVar1 = (int *)(ptr[1] + iVar2);
                  iVar2 = iVar2 + -4;
                  if (*piVar1 == 0) break;
                  (*param_3)(*piVar1);
                  if (iVar3 < 0) goto LAB_00163d38;
                }
              }
LAB_00163d38:
              OPENSSL_sk_free(ptr);
              return (int *)0x0;
            }
            iVar2 = *ptr;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar2);
      }
    }
  }
  return ptr;
}

