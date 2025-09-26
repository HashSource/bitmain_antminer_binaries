
undefined4 aes_ofb_cipher(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  CRYPTO_ofb128_encrypt
            (param_3,param_2,param_4,*(int *)(param_1 + 0x60),param_1 + 0x20,param_1 + 0x50,
             *(undefined4 *)(*(int *)(param_1 + 0x60) + 0xf8));
  return 1;
}

