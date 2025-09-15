
undefined4 aes_cbc_cipher(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60);
  if (*(code **)(iVar1 + 0xfc) == (code *)0x0) {
    if (*(int *)(param_1 + 8) == 0) {
      CRYPTO_cbc128_decrypt
                (param_3,param_2,param_4,iVar1,param_1 + 0x20,*(undefined4 *)(iVar1 + 0xf8));
    }
    else {
      CRYPTO_cbc128_encrypt
                (param_3,param_2,param_4,iVar1,param_1 + 0x20,*(undefined4 *)(iVar1 + 0xf8));
    }
  }
  else {
    (**(code **)(iVar1 + 0xfc))
              (param_3,param_2,param_4,iVar1,param_1 + 0x20,*(undefined4 *)(param_1 + 8));
  }
  return 1;
}

