
undefined4 aes_ctr_cipher(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_1c [2];
  
  iVar1 = *(int *)(param_1 + 0x60);
  local_1c[0] = *(undefined4 *)(param_1 + 0x50);
  if (*(int *)(iVar1 + 0xfc) == 0) {
    CRYPTO_ctr128_encrypt
              (param_3,param_2,param_4,iVar1,param_1 + 0x20,param_1 + 0x30,local_1c,
               *(undefined4 *)(iVar1 + 0xf8));
  }
  else {
    CRYPTO_ctr128_encrypt_ctr32
              (param_3,param_2,param_4,iVar1,param_1 + 0x20,param_1 + 0x30,local_1c,
               *(int *)(iVar1 + 0xfc));
  }
  *(undefined4 *)(param_1 + 0x50) = local_1c[0];
  return 1;
}

