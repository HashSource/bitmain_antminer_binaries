
undefined4 tls1_setup_key_block(int param_1)

{
  char *file;
  int iVar1;
  int iVar2;
  void *ptr;
  void *ptr_00;
  undefined4 uVar3;
  size_t len;
  EVP_CIPHER *local_2c;
  undefined4 local_28;
  undefined auStack_24 [4];
  undefined4 local_20;
  int local_1c;
  
  local_20 = 0;
  local_1c = 0;
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x374) != 0) {
    return 1;
  }
  iVar1 = ssl_cipher_get_evp(*(undefined4 *)(param_1 + 0xc0),&local_2c,&local_28,&local_20,&local_1c
                             ,auStack_24);
  if (iVar1 == 0) {
    ERR_put_error(0x14,0xd3,0x8a,DAT_00074874,0x282);
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x58);
  *(int *)(iVar1 + 0x388) = local_1c;
  *(undefined4 *)(iVar1 + 0x380) = local_28;
  *(undefined4 *)(iVar1 + 900) = local_20;
  *(EVP_CIPHER **)(iVar1 + 0x37c) = local_2c;
  iVar1 = EVP_CIPHER_key_length(local_2c);
  iVar1 = iVar1 + local_1c;
  iVar2 = EVP_CIPHER_iv_length(local_2c);
  len = (iVar1 + iVar2) * 2;
  ssl3_cleanup_key_block(param_1);
  ptr = CRYPTO_malloc(len,DAT_00074874,0x290);
  file = DAT_00074874;
  if (ptr == (void *)0x0) {
    ERR_put_error(0x14,0xd3,0x41,DAT_00074874,0x291);
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x58);
  *(size_t *)(iVar1 + 0x374) = len;
  *(void **)(iVar1 + 0x378) = ptr;
  ptr_00 = CRYPTO_malloc(len,file,0x298);
  if (ptr_00 == (void *)0x0) {
    ERR_put_error(0x14,0xd3,0x41,DAT_00074874,0x299);
    CRYPTO_free(ptr);
    return 0;
  }
  uVar3 = ssl_get_algorithm2(param_1);
  iVar1 = tls1_PRF_constprop_0
                    (uVar3,DAT_00074878,0xd,*(int *)(param_1 + 0x58) + 0xa0,0x20,
                     *(int *)(param_1 + 0x58) + 0xc0,0x20,0,0,*(int *)(param_1 + 0xc0) + 0x14,
                     *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0x10),ptr,ptr_00,len);
  if (iVar1 == 0) {
    uVar3 = 0;
    goto LAB_00074818;
  }
  if (((*(uint *)(param_1 + 0x100) & 0x800) == 0) && (**(int **)(param_1 + 8) < 0x302)) {
    iVar1 = *(int *)(param_1 + 0x58);
    iVar2 = *(int *)(*(int *)(param_1 + 0xc0) + 0xb4);
    *(undefined4 *)(iVar1 + 0xe0) = 1;
    if (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 0x14);
      if (iVar2 == 0x20) {
        *(undefined4 *)(iVar1 + 0xe0) = 0;
        uVar3 = 1;
        goto LAB_00074818;
      }
      if (iVar2 == 4) {
        uVar3 = 1;
        *(undefined4 *)(iVar1 + 0xe0) = 0;
        goto LAB_00074818;
      }
    }
  }
  uVar3 = 1;
LAB_00074818:
  OPENSSL_cleanse(ptr_00,len);
  CRYPTO_free(ptr_00);
  return uVar3;
}

