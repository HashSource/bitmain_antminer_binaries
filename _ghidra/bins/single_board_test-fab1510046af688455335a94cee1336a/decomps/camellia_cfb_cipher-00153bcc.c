
undefined4 camellia_cfb_cipher(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  CRYPTO_cfb128_encrypt
            (param_3,param_2,param_4,*(int *)(param_1 + 0x60),param_1 + 0x20,param_1 + 0x50,
             *(undefined4 *)(param_1 + 8),*(undefined4 *)(*(int *)(param_1 + 0x60) + 0x118));
  return 1;
}

