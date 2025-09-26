
undefined4 ASYNC_WAIT_CTX_clear_fd(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *ptr;
  int *piVar3;
  int *piVar4;
  
  piVar4 = (int *)*param_1;
  if (piVar4 != (int *)0x0) {
    piVar1 = piVar4;
    piVar3 = (int *)0x0;
    do {
      ptr = piVar1;
      if ((ptr[5] != 1) && (*ptr == param_2)) {
        if (ptr[4] == 1) {
          iVar2 = ptr[6];
          if (piVar4 == ptr) {
            *param_1 = iVar2;
          }
          if (piVar4 != ptr) {
            piVar3[6] = iVar2;
          }
          CRYPTO_free(ptr);
          param_1[1] = param_1[1] + -1;
          return 1;
        }
        iVar2 = param_1[2];
        ptr[5] = 1;
        param_1[2] = iVar2 + 1;
        return 1;
      }
      piVar1 = (int *)ptr[6];
      piVar3 = ptr;
    } while ((int *)ptr[6] != (int *)0x0);
  }
  return 0;
}

