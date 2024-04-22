
undefined4 ssl3_digest_cached_records(int param_1)

{
  void *pvVar1;
  size_t cnt;
  EVP_MD_CTX *pEVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  EVP_MD_CTX **ptr;
  int iVar6;
  int iVar7;
  uint local_2c;
  EVP_MD *local_28;
  void *local_24 [2];
  
  iVar7 = *(int *)(param_1 + 0x58);
  ptr = *(EVP_MD_CTX ***)(iVar7 + 0x17c);
  if (ptr != (EVP_MD_CTX **)0x0) {
    if (*ptr != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(*ptr);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if (ptr[1] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ptr[1]);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if (ptr[2] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ptr[2]);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if (ptr[3] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ptr[3]);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if (ptr[4] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ptr[4]);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if (ptr[5] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ptr[5]);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    CRYPTO_free(ptr);
    iVar7 = *(int *)(param_1 + 0x58);
    *(undefined4 *)(iVar7 + 0x17c) = 0;
  }
  pvVar1 = CRYPTO_malloc(0x18,DAT_0006b474,0x25b);
  iVar6 = *(int *)(param_1 + 0x58);
  *(void **)(iVar7 + 0x17c) = pvVar1;
  memset(*(void **)(iVar6 + 0x17c),0,0x18);
  cnt = BIO_ctrl(*(BIO **)(*(int *)(param_1 + 0x58) + 0x178),3,0,local_24);
  if ((int)cnt < 1) {
    ERR_put_error(0x14,0x125,0x14c,DAT_0006b474,0x25f);
    uVar5 = 0;
  }
  else {
    iVar6 = 0;
    iVar7 = iVar6;
    while (iVar3 = ssl_get_handshake_digest(iVar7,&local_2c,&local_28), iVar3 != 0) {
      uVar4 = ssl_get_algorithm2(param_1);
      if (((uVar4 & local_2c) == 0) || (local_28 == (EVP_MD *)0x0)) {
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar6) = 0;
      }
      else {
        iVar3 = *(int *)(*(int *)(param_1 + 0x58) + 0x17c);
        pEVar2 = EVP_MD_CTX_create();
        *(EVP_MD_CTX **)(iVar3 + iVar6) = pEVar2;
        EVP_DigestInit_ex(*(EVP_MD_CTX **)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar6),
                          local_28,(ENGINE *)0x0);
        EVP_DigestUpdate(*(EVP_MD_CTX **)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar6),
                         local_24[0],cnt);
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 4;
    }
    if ((**(uint **)(param_1 + 0x58) & 0x20) == 0) {
      BIO_free((BIO *)(*(uint **)(param_1 + 0x58))[0x5e]);
      uVar5 = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x178) = 0;
    }
    else {
      uVar5 = 1;
    }
  }
  return uVar5;
}

