
int aes_wrap_cipher(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60);
  if (param_3 == 0) {
    return 0;
  }
  if ((param_4 & 7) == 0) {
    if (*(int *)(param_1 + 8) == 0) {
      if (param_4 < 0x10) {
        return -1;
      }
      if (param_2 == 0) {
        return param_4 - 8;
      }
      iVar1 = CRYPTO_128_unwrap(iVar1,*(undefined4 *)(iVar1 + 0xf8),param_2,param_3,param_4,
                                DAT_000b0724);
    }
    else {
      if (param_4 < 8) {
        return -1;
      }
      if (param_2 == 0) {
        return param_4 + 8;
      }
      iVar1 = CRYPTO_128_wrap(iVar1,*(undefined4 *)(iVar1 + 0xf8),param_2,param_3,param_4,
                              DAT_000b0720);
    }
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  return -1;
}

