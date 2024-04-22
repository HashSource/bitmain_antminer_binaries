
COMP_CTX * tls1_change_cipher_state(int param_1,uint param_2)

{
  bool bVar1;
  EVP_MD *type;
  int iVar2;
  COMP_CTX *pCVar3;
  ulong uVar4;
  undefined4 uVar5;
  EVP_PKEY *pkey;
  void *__src;
  int iVar6;
  uint uVar7;
  EVP_CIPHER *cipher;
  EVP_CIPHER_CTX *pEVar8;
  int iVar9;
  size_t __n;
  void *pvVar10;
  uint uVar11;
  uchar *key;
  int local_110;
  int local_10c;
  size_t *local_108;
  uchar *local_104;
  EVP_MD_CTX *local_100;
  uchar *local_fc;
  undefined4 local_f0;
  uchar auStack_e8 [32];
  undefined auStack_c8 [32];
  uchar auStack_a8 [64];
  undefined auStack_68 [68];
  
  iVar6 = *(int *)(param_1 + 0x58);
  type = *(EVP_MD **)(iVar6 + 0x380);
  cipher = *(EVP_CIPHER **)(iVar6 + 0x37c);
  iVar2 = *(int *)(iVar6 + 900);
  iVar9 = *(int *)(iVar6 + 0x38c);
  uVar11 = *(uint *)(*(int *)(iVar6 + 0x344) + 0x20) & 2;
  uVar7 = *(uint *)(*(int *)(iVar6 + 0x344) + 0x24);
  if ((int)(param_2 << 0x1f) < 0) {
    pEVar8 = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
    if ((uVar7 & 4) == 0) {
      uVar7 = *(uint *)(param_1 + 0x7c) & 0xfffffffe;
    }
    else {
      uVar7 = *(uint *)(param_1 + 0x7c) | 1;
    }
    *(uint *)(param_1 + 0x7c) = uVar7;
    if (pEVar8 == (EVP_CIPHER_CTX *)0x0) {
      pEVar8 = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,DAT_000746ec,0x17a);
      *(EVP_CIPHER_CTX **)(param_1 + 0x80) = pEVar8;
      if (pEVar8 == (EVP_CIPHER_CTX *)0x0) goto LAB_0007454c;
      EVP_CIPHER_CTX_init(pEVar8);
      bVar1 = false;
      pEVar8 = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
    }
    else {
      bVar1 = true;
    }
    local_100 = (EVP_MD_CTX *)ssl_replace_hash(param_1 + 0x84,0);
    if (*(COMP_CTX **)(param_1 + 0x88) != (COMP_CTX *)0x0) {
      COMP_CTX_free(*(COMP_CTX **)(param_1 + 0x88));
      *(undefined4 *)(param_1 + 0x88) = 0;
    }
    if (iVar9 == 0) {
      iVar6 = *(int *)(param_1 + 0x58);
    }
    else {
      pCVar3 = COMP_CTX_new(*(COMP_METHOD **)(iVar9 + 8));
      iVar6 = 0x18c;
      *(COMP_CTX **)(param_1 + 0x88) = pCVar3;
      if (pCVar3 == (COMP_CTX *)0x0) goto LAB_000746d0;
      iVar6 = *(int *)(param_1 + 0x58);
      if (*(int *)(iVar6 + 0x120) == 0) {
        pvVar10 = CRYPTO_malloc(0x4540,DAT_000745f0,0x191);
        *(void **)(iVar6 + 0x120) = pvVar10;
        iVar6 = *(int *)(param_1 + 0x58);
        if (*(int *)(iVar6 + 0x120) == 0) goto LAB_0007454c;
      }
    }
    if ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) & 8) == 0) {
      *(undefined *)(iVar6 + 8) = 0;
      *(undefined *)(iVar6 + 9) = 0;
      *(undefined *)(iVar6 + 10) = 0;
      *(undefined *)(iVar6 + 0xb) = 0;
      *(undefined *)(iVar6 + 0xc) = 0;
      *(undefined *)(iVar6 + 0xd) = 0;
      *(undefined *)(iVar6 + 0xe) = 0;
      *(undefined *)(iVar6 + 0xf) = 0;
      iVar6 = *(int *)(param_1 + 0x58);
    }
    local_104 = (uchar *)(iVar6 + 0x14);
    local_108 = (size_t *)(iVar6 + 0x10);
    if (bVar1) {
LAB_0007451c:
      EVP_CIPHER_CTX_cleanup(pEVar8);
      iVar6 = *(int *)(param_1 + 0x58);
    }
  }
  else {
    pEVar8 = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
    if ((uVar7 & 4) == 0) {
      uVar7 = *(uint *)(param_1 + 0x7c) & 0xfffffffd;
    }
    else {
      uVar7 = *(uint *)(param_1 + 0x7c) | 2;
    }
    *(uint *)(param_1 + 0x7c) = uVar7;
    if ((pEVar8 == (EVP_CIPHER_CTX *)0x0) ||
       (*(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) << 0x1c < 0)) {
      pEVar8 = EVP_CIPHER_CTX_new();
      *(EVP_CIPHER_CTX **)(param_1 + 0x8c) = pEVar8;
      if (pEVar8 == (EVP_CIPHER_CTX *)0x0) {
LAB_0007454c:
        ERR_put_error(0x14,0xd1,0x41,DAT_000745f0,0x26a);
        return (COMP_CTX *)0x0;
      }
      if ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) & 8) == 0) {
        bVar1 = false;
        goto LAB_000744c2;
      }
      local_100 = EVP_MD_CTX_create();
      if (local_100 == (EVP_MD_CTX *)0x0) goto LAB_0007454c;
      *(EVP_MD_CTX **)(param_1 + 0x90) = local_100;
      bVar1 = false;
    }
    else {
      bVar1 = true;
LAB_000744c2:
      local_100 = (EVP_MD_CTX *)ssl_replace_hash(param_1 + 0x90,0);
    }
    if (*(COMP_CTX **)(param_1 + 0x94) != (COMP_CTX *)0x0) {
      COMP_CTX_free(*(COMP_CTX **)(param_1 + 0x94));
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    if (iVar9 != 0) {
      pCVar3 = COMP_CTX_new(*(COMP_METHOD **)(iVar9 + 8));
      *(COMP_CTX **)(param_1 + 0x94) = pCVar3;
      if (pCVar3 == (COMP_CTX *)0x0) {
        iVar6 = 0x1b7;
        pCVar3 = (COMP_CTX *)0x0;
LAB_000746d0:
        ERR_put_error(0x14,0xd1,0x8e,DAT_000746ec,iVar6);
        return pCVar3;
      }
    }
    if ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) & 8) == 0) {
      iVar6 = *(int *)(param_1 + 0x58);
      *(undefined *)(iVar6 + 0x54) = 0;
      *(undefined *)(iVar6 + 0x55) = 0;
      *(undefined *)(iVar6 + 0x56) = 0;
      *(undefined *)(iVar6 + 0x57) = 0;
      *(undefined *)(iVar6 + 0x58) = 0;
      *(undefined *)(iVar6 + 0x59) = 0;
      *(undefined *)(iVar6 + 0x5a) = 0;
      *(undefined *)(iVar6 + 0x5b) = 0;
    }
    iVar6 = *(int *)(param_1 + 0x58);
    local_104 = (uchar *)(iVar6 + 0x60);
    local_108 = (size_t *)(iVar6 + 0x5c);
    if (bVar1) goto LAB_0007451c;
  }
  __n = *(size_t *)(iVar6 + 0x388);
  pvVar10 = *(void **)(iVar6 + 0x378);
  *local_108 = __n;
  iVar6 = EVP_CIPHER_key_length(cipher);
  local_10c = iVar6;
  if (uVar11 != 0) {
    iVar9 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
    if (*(int *)(iVar9 + 0x20) << 0x1c < 0) {
      local_10c = 5;
    }
    else if (*(int *)(iVar9 + 0x14) == 1) {
      local_10c = 8;
    }
    else {
      local_10c = 7;
    }
    if (iVar6 <= local_10c) {
      local_10c = iVar6;
    }
  }
  uVar4 = EVP_CIPHER_flags(cipher);
  if ((uVar4 & 0xf0007) == 6) {
    local_110 = 4;
  }
  else {
    local_110 = EVP_CIPHER_iv_length(cipher);
  }
  if (param_2 == 0x12 || param_2 == 0x21) {
    iVar9 = __n * 2;
    bVar1 = true;
    iVar6 = iVar9 + local_10c * 2;
    local_f0 = DAT_000745e4;
    __src = pvVar10;
    if (*(int *)(*(int *)(param_1 + 0x58) + 0x374) < iVar6 + local_110 * 2) {
LAB_000745cc:
      iVar2 = 0x1ed;
      goto LAB_000745d0;
    }
  }
  else {
    bVar1 = false;
    iVar9 = local_10c + __n * 2;
    local_f0 = DAT_000745f4;
    iVar6 = local_110 + local_10c + iVar9;
    __src = (void *)((int)pvVar10 + __n);
    if (*(int *)(*(int *)(param_1 + 0x58) + 0x374) < iVar6 + local_110) goto LAB_000745cc;
  }
  local_fc = (uchar *)((int)pvVar10 + iVar6);
  memcpy(local_104,__src,__n);
  uVar4 = EVP_CIPHER_flags(cipher);
  if ((uVar4 & 0x200000) == 0) {
    pkey = EVP_PKEY_new_mac_key(iVar2,(ENGINE *)0x0,local_104,*local_108);
    EVP_DigestSignInit(local_100,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey);
    EVP_PKEY_free(pkey);
  }
  key = (uchar *)(iVar9 + (int)pvVar10);
  if (uVar11 != 0) {
    uVar5 = ssl_get_algorithm2(param_1);
    iVar6 = *(int *)(param_1 + 0x58);
    iVar2 = EVP_CIPHER_key_length(cipher);
    key = auStack_a8;
    iVar2 = tls1_PRF_constprop_0
                      (uVar5,local_f0,0x10,iVar6 + 0xc0,0x20,iVar6 + 0xa0,0x20,0,0,
                       (uchar *)(iVar9 + (int)pvVar10),local_10c,key,auStack_68,iVar2);
    if (iVar2 == 0) {
      return (COMP_CTX *)0x0;
    }
    if (0 < local_110) {
      local_fc = auStack_e8;
      uVar5 = ssl_get_algorithm2(param_1);
      iVar2 = tls1_PRF_constprop_0
                        (uVar5,DAT_000745ec,8,*(int *)(param_1 + 0x58) + 0xc0,0x20,
                         *(int *)(param_1 + 0x58) + 0xa0,0x20,0,0,DAT_000745e8,0,local_fc,auStack_c8
                         ,local_110 << 1);
      if (iVar2 == 0) {
        return (COMP_CTX *)0x0;
      }
      if (!bVar1) {
        local_fc = local_fc + local_110;
      }
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0xc0) + 4) = 0;
  uVar4 = EVP_CIPHER_flags(cipher);
  if ((uVar4 & 0xf0007) == 6) {
    iVar2 = EVP_CipherInit_ex(pEVar8,cipher,(ENGINE *)0x0,key,(uchar *)0x0,param_2 & 2);
    if ((iVar2 == 0) || (iVar2 = EVP_CIPHER_CTX_ctrl(pEVar8,0x12,local_110,local_fc), iVar2 == 0)) {
      iVar2 = 0x230;
      goto LAB_000745d0;
    }
  }
  else {
    iVar6 = EVP_CipherInit_ex(pEVar8,cipher,(ENGINE *)0x0,key,local_fc,param_2 & 2);
    iVar2 = 0x235;
    if (iVar6 == 0) goto LAB_000745d0;
  }
  uVar4 = EVP_CIPHER_flags(cipher);
  if (((int)(uVar4 << 10) < 0) && (*local_108 != 0)) {
    iVar6 = EVP_CIPHER_CTX_ctrl(pEVar8,0x17,*local_108,local_104);
    iVar2 = 0x23d;
    if (iVar6 == 0) {
LAB_000745d0:
      ERR_put_error(0x14,0xd1,0x44,DAT_000745f0,iVar2);
      return (COMP_CTX *)0x0;
    }
  }
  OPENSSL_cleanse(auStack_a8,0x40);
  OPENSSL_cleanse(auStack_68,0x40);
  OPENSSL_cleanse(auStack_e8,0x20);
  OPENSSL_cleanse(auStack_c8,0x20);
  return (COMP_CTX *)0x1;
}

