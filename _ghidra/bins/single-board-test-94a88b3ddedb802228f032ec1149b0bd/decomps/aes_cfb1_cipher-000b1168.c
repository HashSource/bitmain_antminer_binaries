
undefined4 aes_cfb1_cipher(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x60);
  if (*(int *)(param_1 + 0x5c) << 0x12 < 0) {
    CRYPTO_cfb128_1_encrypt
              (param_3,param_2,param_4,iVar1,param_1 + 0x20,param_1 + 0x50,
               *(undefined4 *)(param_1 + 8),*(undefined4 *)(iVar1 + 0xf8));
  }
  else {
    if (0xfffffff < param_4) {
      uVar2 = param_4;
      do {
        param_4 = param_4 + 0xf0000000;
        CRYPTO_cfb128_1_encrypt
                  (param_3,param_2,0x80000000,iVar1,param_1 + 0x20,param_1 + 0x50,
                   *(undefined4 *)(param_1 + 8),*(undefined4 *)(iVar1 + 0xf8));
      } while (0xfffffff < param_4);
      param_4 = uVar2 & 0xfffffff;
    }
    if (param_4 != 0) {
      CRYPTO_cfb128_1_encrypt
                (param_3,param_2,param_4 << 3,iVar1,param_1 + 0x20,param_1 + 0x50,
                 *(undefined4 *)(param_1 + 8),*(undefined4 *)(iVar1 + 0xf8),param_2,param_4);
    }
  }
  return 1;
}

