
undefined4 aria_ccm_init_key(EVP_CIPHER_CTX *param_1,int param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  void *__dest;
  undefined4 extraout_r3;
  undefined4 uVar3;
  bool bVar4;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  if (param_3 != (void *)0x0 || param_2 != 0) {
    if (param_2 != 0) {
      iVar2 = EVP_CIPHER_CTX_key_length(param_1);
      iVar2 = aria_set_encrypt_key(param_2,iVar2 << 3,iVar1);
      CRYPTO_ccm128_init(iVar1 + 0x138,*(undefined4 *)(iVar1 + 300),*(undefined4 *)(iVar1 + 0x128),
                         iVar1,0x17c325);
      bVar4 = -1 < iVar2;
      uVar3 = extraout_r3;
      if (bVar4) {
        uVar3 = 1;
      }
      if (bVar4) {
        *(undefined4 *)(iVar1 + 0x168) = 0;
      }
      if (!bVar4) {
        ERR_put_error(6,0xaf,0xb0,"crypto/evp/e_aria.c",0x206);
        return 0;
      }
      *(undefined4 *)(iVar1 + 0x118) = uVar3;
    }
    if (param_3 != (void *)0x0) {
      __dest = (void *)EVP_CIPHER_CTX_iv_noconst(param_1);
      memcpy(__dest,param_3,0xf - *(int *)(iVar1 + 0x128));
      *(undefined4 *)(iVar1 + 0x11c) = 1;
      return 1;
    }
  }
  return 1;
}

