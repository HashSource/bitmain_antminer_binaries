
COMP_CTX * ssl3_change_cipher_state(int param_1,uint param_2)

{
  COMP_METHOD *meth;
  COMP_CTX *pCVar1;
  size_t __n;
  size_t sVar2;
  int iVar3;
  void *__src;
  int iVar4;
  int iVar5;
  int iVar6;
  uchar *key;
  EVP_CIPHER_CTX *pEVar7;
  EVP_MD *pEVar8;
  void *pvVar9;
  void *d;
  EVP_CIPHER *cipher;
  bool bVar10;
  size_t cnt;
  uint uVar11;
  void *local_9c;
  uchar *local_98;
  void *local_94;
  uchar auStack_90 [16];
  EVP_MD_CTX EStack_80;
  uchar auStack_68 [68];
  
  iVar5 = *(int *)(param_1 + 0x58);
  pEVar8 = *(EVP_MD **)(iVar5 + 0x380);
  cipher = *(EVP_CIPHER **)(iVar5 + 0x37c);
  uVar11 = *(uint *)(*(int *)(iVar5 + 0x344) + 0x20);
  if (pEVar8 == (EVP_MD *)0x0) {
    OpenSSLDie(DAT_0006adcc,0xeb,DAT_0006add0);
    iVar5 = *(int *)(param_1 + 0x58);
  }
  meth = *(COMP_METHOD **)(iVar5 + 0x38c);
  if (meth != (COMP_METHOD *)0x0) {
    meth = (COMP_METHOD *)meth->init;
  }
  if ((param_2 & 1) == 0) {
    pEVar7 = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
    if (pEVar7 == (EVP_CIPHER_CTX *)0x0) {
      pEVar7 = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,DAT_0006adcc,0x11b);
      *(EVP_CIPHER_CTX **)(param_1 + 0x8c) = pEVar7;
      if (pEVar7 == (EVP_CIPHER_CTX *)0x0) goto LAB_0006ad8a;
      EVP_CIPHER_CTX_init(pEVar7);
      pEVar7 = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
      bVar10 = false;
    }
    else {
      bVar10 = true;
    }
    ssl_replace_hash(param_1 + 0x90,pEVar8);
    if (*(COMP_CTX **)(param_1 + 0x94) != (COMP_CTX *)0x0) {
      COMP_CTX_free(*(COMP_CTX **)(param_1 + 0x94));
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    if (meth != (COMP_METHOD *)0x0) {
      pCVar1 = COMP_CTX_new(meth);
      *(COMP_CTX **)(param_1 + 0x94) = pCVar1;
      if (pCVar1 == (COMP_CTX *)0x0) {
        iVar5 = 0x12e;
        pCVar1 = (COMP_CTX *)0x0;
        goto LAB_0006adba;
      }
    }
    iVar5 = *(int *)(param_1 + 0x58);
    *(undefined *)(iVar5 + 0x54) = 0;
    *(undefined *)(iVar5 + 0x55) = 0;
    *(undefined *)(iVar5 + 0x56) = 0;
    *(undefined *)(iVar5 + 0x57) = 0;
    *(undefined *)(iVar5 + 0x58) = 0;
    *(undefined *)(iVar5 + 0x59) = 0;
    *(undefined *)(iVar5 + 0x5a) = 0;
    *(undefined *)(iVar5 + 0x5b) = 0;
    iVar5 = *(int *)(param_1 + 0x58);
    local_9c = (void *)(iVar5 + 0x60);
    if (bVar10) goto LAB_0006ac40;
  }
  else {
    pEVar7 = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
    if (pEVar7 == (EVP_CIPHER_CTX *)0x0) {
      pEVar7 = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,DAT_0006adcc,0xf7);
      *(EVP_CIPHER_CTX **)(param_1 + 0x80) = pEVar7;
      if (pEVar7 == (EVP_CIPHER_CTX *)0x0) goto LAB_0006ad8a;
      EVP_CIPHER_CTX_init(pEVar7);
      bVar10 = false;
      pEVar7 = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
    }
    else {
      bVar10 = true;
    }
    ssl_replace_hash(param_1 + 0x84,pEVar8);
    if (*(COMP_CTX **)(param_1 + 0x88) != (COMP_CTX *)0x0) {
      COMP_CTX_free(*(COMP_CTX **)(param_1 + 0x88));
      *(undefined4 *)(param_1 + 0x88) = 0;
    }
    if (meth == (COMP_METHOD *)0x0) {
      iVar5 = *(int *)(param_1 + 0x58);
    }
    else {
      pCVar1 = COMP_CTX_new(meth);
      iVar5 = 0x10b;
      *(COMP_CTX **)(param_1 + 0x88) = pCVar1;
      if (pCVar1 == (COMP_CTX *)0x0) {
LAB_0006adba:
        ERR_put_error(0x14,0x81,0x8e,DAT_0006adcc,iVar5);
        return pCVar1;
      }
      iVar5 = *(int *)(param_1 + 0x58);
      if (*(int *)(iVar5 + 0x120) == 0) {
        pvVar9 = CRYPTO_malloc(0x4000,DAT_0006adcc,0x110);
        *(void **)(iVar5 + 0x120) = pvVar9;
        iVar5 = *(int *)(param_1 + 0x58);
        if (*(int *)(iVar5 + 0x120) == 0) {
LAB_0006ad8a:
          ERR_put_error(0x14,0x81,0x41,DAT_0006adcc,399);
          return (COMP_CTX *)0x0;
        }
      }
    }
    *(undefined *)(iVar5 + 8) = 0;
    *(undefined *)(iVar5 + 9) = 0;
    *(undefined *)(iVar5 + 10) = 0;
    *(undefined *)(iVar5 + 0xb) = 0;
    *(undefined *)(iVar5 + 0xc) = 0;
    *(undefined *)(iVar5 + 0xd) = 0;
    *(undefined *)(iVar5 + 0xe) = 0;
    *(undefined *)(iVar5 + 0xf) = 0;
    iVar5 = *(int *)(param_1 + 0x58);
    local_9c = (void *)(iVar5 + 0x14);
    if (bVar10) {
LAB_0006ac40:
      EVP_CIPHER_CTX_cleanup(pEVar7);
      iVar5 = *(int *)(param_1 + 0x58);
    }
  }
  pvVar9 = *(void **)(iVar5 + 0x378);
  __n = EVP_MD_size(pEVar8);
  if ((int)__n < 0) {
    return (COMP_CTX *)0x0;
  }
  uVar11 = uVar11 & 2;
  sVar2 = EVP_CIPHER_key_length(cipher);
  cnt = sVar2;
  if (uVar11 != 0) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
    if (*(int *)(iVar5 + 0x20) << 0x1c < 0) {
      cnt = 5;
    }
    else if (*(int *)(iVar5 + 0x14) == 1) {
      cnt = 8;
    }
    else {
      cnt = 7;
    }
    if ((int)sVar2 <= (int)cnt) {
      cnt = sVar2;
    }
  }
  iVar5 = EVP_CIPHER_iv_length(cipher);
  if (param_2 == 0x12 || param_2 == 0x21) {
    iVar6 = __n * 2;
    iVar4 = *(int *)(param_1 + 0x58);
    iVar3 = iVar6 + cnt * 2;
    local_94 = (void *)(iVar4 + 0xc0);
    d = (void *)(iVar4 + 0xa0);
    __src = pvVar9;
    if (*(int *)(iVar4 + 0x374) < iVar3 + iVar5 * 2) {
LAB_0006ac74:
      ERR_put_error(0x14,0x81,0x44,DAT_0006adcc,0x15a);
      return (COMP_CTX *)0x0;
    }
  }
  else {
    iVar6 = cnt + __n * 2;
    iVar4 = *(int *)(param_1 + 0x58);
    iVar3 = iVar5 + cnt + iVar6;
    __src = (void *)((int)pvVar9 + __n);
    local_94 = (void *)(iVar4 + 0xa0);
    d = (void *)(iVar4 + 0xc0);
    if (*(int *)(iVar4 + 0x374) < iVar3 + iVar5) goto LAB_0006ac74;
  }
  local_98 = (uchar *)((int)pvVar9 + iVar3);
  key = (uchar *)((int)pvVar9 + iVar6);
  EVP_MD_CTX_init(&EStack_80);
  memcpy(local_9c,__src,__n);
  if (uVar11 != 0) {
    pEVar8 = EVP_md5();
    EVP_DigestInit_ex(&EStack_80,pEVar8,(ENGINE *)0x0);
    EVP_DigestUpdate(&EStack_80,key,cnt);
    EVP_DigestUpdate(&EStack_80,local_94,0x20);
    EVP_DigestUpdate(&EStack_80,d,0x20);
    EVP_DigestFinal_ex(&EStack_80,auStack_68,(uint *)0x0);
    key = auStack_68;
    if (0 < iVar5) {
      pEVar8 = EVP_md5();
      local_98 = auStack_90;
      EVP_DigestInit_ex(&EStack_80,pEVar8,(ENGINE *)0x0);
      EVP_DigestUpdate(&EStack_80,local_94,0x20);
      EVP_DigestUpdate(&EStack_80,d,0x20);
      EVP_DigestFinal_ex(&EStack_80,local_98,(uint *)0x0);
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0xc0) + 4) = 0;
  EVP_CipherInit_ex(pEVar7,cipher,(ENGINE *)0x0,key,local_98,param_2 & 2);
  OPENSSL_cleanse(auStack_68,0x40);
  OPENSSL_cleanse(auStack_90,0x10);
  EVP_MD_CTX_cleanup(&EStack_80);
  return (COMP_CTX *)0x1;
}

