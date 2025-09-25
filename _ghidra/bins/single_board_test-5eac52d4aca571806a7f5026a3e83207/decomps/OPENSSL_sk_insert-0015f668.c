
int OPENSSL_sk_insert(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  void *addr;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar1 = *param_1;
  if ((iVar1 != 0x3fffffff) && (0 < 0x3fffffff - iVar1)) {
    addr = (void *)param_1[1];
    iVar2 = iVar1 + 1;
    if (iVar2 < 4) {
      iVar2 = 4;
    }
    if (addr == (void *)0x0) {
      addr = (void *)CRYPTO_zalloc(iVar2 << 2,"crypto/stack/stack.c",0xb4);
      param_1[1] = (int)addr;
      if (addr != (void *)0x0) {
        iVar1 = *param_1;
        param_1[3] = iVar2;
        goto LAB_0015f6e4;
      }
      ERR_put_error(0xf,0x81,0x41,"crypto/stack/stack.c",0xb5);
    }
    else {
      iVar3 = param_1[3];
      if (iVar2 <= iVar3) {
LAB_0015f6e4:
        if (param_3 < iVar1 && -1 < param_3) {
          iVar2 = (param_3 + 1) * 4;
          iVar3 = iVar2 + -4;
          memmove((void *)(iVar2 + (int)addr),(void *)((int)addr + iVar3),(iVar1 - param_3) * 4);
          iVar1 = *param_1;
          *(undefined4 *)(param_1[1] + iVar3) = param_2;
        }
        else {
          *(undefined4 *)((int)addr + iVar1 * 4) = param_2;
        }
        *param_1 = iVar1 + 1;
        param_1[2] = 0;
        return iVar1 + 1;
      }
      do {
        if (0x3ffffffe < iVar3) {
          return 0;
        }
        if (0x2aaaaaa9 < iVar3) {
          if (0x3fffffff < iVar2) {
            return 0;
          }
          iVar1 = -4;
          iVar3 = 0x3fffffff;
          goto LAB_0015f736;
        }
        iVar3 = iVar3 + iVar3 / 2;
      } while (iVar3 < iVar2);
      if (iVar3 != 0) {
        iVar1 = iVar3 * 4;
LAB_0015f736:
        addr = CRYPTO_realloc(addr,iVar1,"crypto/stack/stack.c",0xc6);
        if (addr != (void *)0x0) {
          param_1[1] = (int)addr;
          param_1[3] = iVar3;
          iVar1 = *param_1;
          goto LAB_0015f6e4;
        }
      }
    }
  }
  return 0;
}

