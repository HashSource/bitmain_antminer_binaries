
undefined4 aria_gcm_init_key(EVP_CIPHER_CTX *param_1,int param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  if (param_3 == (void *)0x0 && param_2 == 0) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
    if (param_2 == 0) {
      if (*(int *)(iVar1 + 0x118) == 0) {
        memcpy(*(void **)(iVar1 + 0x2c8),param_3,*(size_t *)(iVar1 + 0x2cc));
      }
      else {
        CRYPTO_gcm128_setiv(iVar1 + 0x120);
      }
      *(undefined4 *)(iVar1 + 0x11c) = 1;
      *(undefined4 *)(iVar1 + 0x2d4) = 0;
      return 1;
    }
    iVar2 = EVP_CIPHER_CTX_key_length(param_1);
    iVar2 = aria_set_encrypt_key(param_2,iVar2 << 3,iVar1);
    CRYPTO_gcm128_init(iVar1 + 0x120,iVar1,0x1780d5);
    if (iVar2 < 0) {
      ERR_put_error(6,0xb0,0xb0,"crypto/evp/e_aria.c",0xdd);
    }
    else {
      if ((param_3 != (void *)0x0) ||
         ((*(int *)(iVar1 + 0x11c) != 0 &&
          (param_3 = *(void **)(iVar1 + 0x2c8), param_3 != (void *)0x0)))) {
        CRYPTO_gcm128_setiv(iVar1 + 0x120,param_3,*(undefined4 *)(iVar1 + 0x2cc));
        *(undefined4 *)(iVar1 + 0x11c) = 1;
      }
      uVar3 = 1;
      *(undefined4 *)(iVar1 + 0x118) = 1;
    }
  }
  return uVar3;
}

