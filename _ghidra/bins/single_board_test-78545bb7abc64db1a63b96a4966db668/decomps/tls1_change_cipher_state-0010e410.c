
/* WARNING: Type propagation algorithm not settling */

undefined4 tls1_change_cipher_state(int param_1,uint param_2)

{
  bool bVar1;
  COMP_CTX *pCVar2;
  ulong uVar3;
  int arg;
  EVP_PKEY *pkey;
  EVP_MD *type;
  uint type_00;
  uint uVar4;
  uchar *key;
  size_t *psVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  EVP_CIPHER *cipher;
  EVP_CIPHER_CTX *pEVar10;
  size_t __n;
  uint uVar11;
  void *pvVar12;
  void *__src;
  EVP_MD_CTX *local_40;
  uchar *local_30;
  uchar *local_2c;
  
  puVar6 = *(uint **)(param_1 + 0x7c);
  type = (EVP_MD *)puVar6[0x8d];
  cipher = (EVP_CIPHER *)puVar6[0x8c];
  uVar11 = puVar6[0x90];
  type_00 = puVar6[0x8e];
  if ((param_2 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x60) = 1;
    if (*(int *)(param_1 + 0x5a8) == 0) {
      uVar4 = *puVar6 & 0xfffffbff;
    }
    else {
      uVar4 = *puVar6 | 0x400;
    }
    *puVar6 = uVar4;
    pEVar10 = *(EVP_CIPHER_CTX **)(param_1 + 0x3ec);
    if ((*(uint *)(puVar6[0x84] + 0x34) & 0x10000) == 0) {
      uVar4 = *(uint *)(param_1 + 200) & 0xfffffffd;
    }
    else {
      uVar4 = *(uint *)(param_1 + 200) | 2;
    }
    *(uint *)(param_1 + 200) = uVar4;
    if ((pEVar10 == (EVP_CIPHER_CTX *)0x0) ||
       (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0)) {
      pEVar10 = EVP_CIPHER_CTX_new();
      *(EVP_CIPHER_CTX **)(param_1 + 0x3ec) = pEVar10;
      if (pEVar10 == (EVP_CIPHER_CTX *)0x0) {
        uVar9 = 0xa7;
        goto LAB_0010e88e;
      }
      if ((*(uint *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) & 8) == 0) {
        bVar1 = false;
        goto LAB_0010e638;
      }
      local_40 = (EVP_MD_CTX *)EVP_MD_CTX_new();
      if (local_40 == (EVP_MD_CTX *)0x0) {
        uVar9 = 0xb0;
        goto LAB_0010e88e;
      }
      *(EVP_MD_CTX **)(param_1 + 0x400) = local_40;
      bVar1 = false;
    }
    else {
      bVar1 = true;
LAB_0010e638:
      local_40 = (EVP_MD_CTX *)ssl_replace_hash(param_1 + 0x400,0);
      if (local_40 == (EVP_MD_CTX *)0x0) {
        uVar9 = 0xb9;
LAB_0010e88e:
        ossl_statem_fatal(param_1,0x50,0xd1,0x41,"ssl/t1_enc.c",uVar9);
        return 0;
      }
    }
    COMP_CTX_free(*(COMP_CTX **)(param_1 + 0x3e4));
    *(undefined4 *)(param_1 + 0x3e4) = 0;
    if (uVar11 != 0) {
      pCVar2 = COMP_CTX_new(*(COMP_METHOD **)(uVar11 + 8));
      *(COMP_CTX **)(param_1 + 0x3e4) = pCVar2;
      if (pCVar2 == (COMP_CTX *)0x0) {
        uVar9 = 0xc5;
LAB_0010e86e:
        ossl_statem_fatal(param_1,0x50,0xd1,0x8e,"ssl/t1_enc.c",uVar9);
        return 0;
      }
    }
    if (-1 < *(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c) {
      RECORD_LAYER_reset_write_sequence(param_1 + 0x650);
    }
    iVar7 = *(int *)(param_1 + 0x7c);
    key = (uchar *)(iVar7 + 0x4c);
    psVar5 = (size_t *)(iVar7 + 0x48);
  }
  else {
    if (*(int *)(param_1 + 0x5a8) == 0) {
      uVar4 = *puVar6 & 0xfffffeff;
    }
    else {
      uVar4 = *puVar6 | 0x100;
    }
    bVar1 = true;
    *puVar6 = uVar4;
    pEVar10 = *(EVP_CIPHER_CTX **)(param_1 + 0x3cc);
    if ((*(uint *)(puVar6[0x84] + 0x34) & 0x10000) == 0) {
      uVar4 = *(uint *)(param_1 + 200) & 0xfffffffe;
    }
    else {
      uVar4 = *(uint *)(param_1 + 200) | 1;
    }
    *(uint *)(param_1 + 200) = uVar4;
    if (pEVar10 == (EVP_CIPHER_CTX *)0x0) {
      pEVar10 = EVP_CIPHER_CTX_new();
      *(EVP_CIPHER_CTX **)(param_1 + 0x3cc) = pEVar10;
      if (pEVar10 == (EVP_CIPHER_CTX *)0x0) {
        uVar9 = 0x78;
        goto LAB_0010e88e;
      }
      EVP_CIPHER_CTX_reset();
      pEVar10 = *(EVP_CIPHER_CTX **)(param_1 + 0x3cc);
      bVar1 = false;
    }
    local_40 = (EVP_MD_CTX *)ssl_replace_hash(param_1 + 0x3e0,0);
    if (local_40 == (EVP_MD_CTX *)0x0) {
      return 0;
    }
    COMP_CTX_free(*(COMP_CTX **)(param_1 + 1000));
    *(undefined4 *)(param_1 + 1000) = 0;
    if (uVar11 != 0) {
      pCVar2 = COMP_CTX_new(*(COMP_METHOD **)(uVar11 + 8));
      *(COMP_CTX **)(param_1 + 1000) = pCVar2;
      if (pCVar2 == (COMP_CTX *)0x0) {
        uVar9 = 0x8c;
        goto LAB_0010e86e;
      }
    }
    if (-1 < *(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c) {
      RECORD_LAYER_reset_read_sequence(param_1 + 0x650);
    }
    iVar7 = *(int *)(param_1 + 0x7c);
    key = (uchar *)(iVar7 + 8);
    psVar5 = (size_t *)(iVar7 + 4);
  }
  if (bVar1) {
    EVP_CIPHER_CTX_reset(pEVar10);
    iVar7 = *(int *)(param_1 + 0x7c);
  }
  __n = *(size_t *)(iVar7 + 0x23c);
  pvVar12 = *(void **)(iVar7 + 0x22c);
  *psVar5 = __n;
  iVar7 = EVP_CIPHER_key_length(cipher);
  uVar3 = EVP_CIPHER_flags(cipher);
  if (((uVar3 & 0xf0007) == 6) || (uVar3 = EVP_CIPHER_flags(cipher), (uVar3 & 0xf0007) == 7)) {
    arg = 4;
    if (param_2 == 0x21 || param_2 == 0x12) goto LAB_0010e520;
LAB_0010e6ba:
    iVar8 = iVar7 + __n * 2;
    iVar7 = iVar7 + iVar8 + arg;
    __src = (void *)((int)pvVar12 + __n);
    if (*(uint *)(*(int *)(param_1 + 0x7c) + 0x228) < (uint)(iVar7 + arg)) {
LAB_0010e6dc:
      uVar9 = 0xf8;
      goto LAB_0010e6e2;
    }
  }
  else {
    arg = EVP_CIPHER_iv_length(cipher);
    if (param_2 != 0x21 && param_2 != 0x12) goto LAB_0010e6ba;
LAB_0010e520:
    iVar8 = __n * 2;
    iVar7 = iVar8 + iVar7 * 2;
    __src = pvVar12;
    if (*(uint *)(*(int *)(param_1 + 0x7c) + 0x228) < (uint)(iVar7 + arg * 2)) goto LAB_0010e6dc;
  }
  local_2c = (uchar *)((int)pvVar12 + iVar7);
  local_30 = (uchar *)(iVar8 + (int)pvVar12);
  memcpy(key,__src,__n);
  uVar3 = EVP_CIPHER_flags(cipher);
  if ((uVar3 & 0x200000) == 0) {
    pkey = EVP_PKEY_new_mac_key(type_00,(ENGINE *)0x0,key,*psVar5);
    if ((pkey == (EVP_PKEY *)0x0) ||
       (iVar7 = EVP_DigestSignInit(local_40,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey), iVar7 < 1
       )) {
      EVP_PKEY_free(pkey);
      uVar9 = 0x106;
      goto LAB_0010e78e;
    }
    EVP_PKEY_free(pkey);
  }
  uVar3 = EVP_CIPHER_flags(cipher);
  if ((uVar3 & 0xf0007) == 6) {
    iVar7 = EVP_CipherInit_ex(pEVar10,cipher,(ENGINE *)0x0,local_30,(uchar *)0x0,param_2 & 2);
    if ((iVar7 == 0) || (iVar7 = EVP_CIPHER_CTX_ctrl(pEVar10,0x12,arg,local_2c), iVar7 == 0)) {
      uVar9 = 0x119;
LAB_0010e6e2:
      ossl_statem_fatal(param_1,0x50,0xd1,0x44,"ssl/t1_enc.c",uVar9);
      return 0;
    }
  }
  else {
    uVar3 = EVP_CIPHER_flags(cipher);
    if ((uVar3 & 0xf0007) == 7) {
      if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x7c) + 0x210) + 0x18) & 0x30000) == 0) {
        iVar7 = 0x10;
      }
      else {
        iVar7 = 8;
      }
      iVar8 = EVP_CipherInit_ex(pEVar10,cipher,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,param_2 & 2);
      if ((((iVar8 == 0) || (iVar8 = EVP_CIPHER_CTX_ctrl(pEVar10,9,0xc,(void *)0x0), iVar8 == 0)) ||
          (iVar7 = EVP_CIPHER_CTX_ctrl(pEVar10,0x11,iVar7,(void *)0x0), iVar7 == 0)) ||
         ((iVar7 = EVP_CIPHER_CTX_ctrl(pEVar10,0x12,arg,local_2c), iVar7 == 0 ||
          (iVar7 = EVP_CipherInit_ex(pEVar10,(EVP_CIPHER *)0x0,(ENGINE *)0x0,local_30,(uchar *)0x0,
                                     -1), iVar7 == 0)))) {
        uVar9 = 0x129;
        goto LAB_0010e6e2;
      }
    }
    else {
      iVar7 = EVP_CipherInit_ex(pEVar10,cipher,(ENGINE *)0x0,local_30,local_2c,param_2 & 2);
      if (iVar7 == 0) {
        uVar9 = 0x12f;
        goto LAB_0010e78e;
      }
    }
  }
  uVar3 = EVP_CIPHER_flags(cipher);
  if (((-1 < (int)(uVar3 << 10)) || (*psVar5 == 0)) ||
     (iVar7 = EVP_CIPHER_CTX_ctrl(pEVar10,0x17,*psVar5,key), iVar7 != 0)) {
    *(undefined4 *)(param_1 + 0x60) = 0;
    return 1;
  }
  uVar9 = 0x138;
LAB_0010e78e:
  ossl_statem_fatal(param_1,0x50,0xd1,0x44,"ssl/t1_enc.c",uVar9);
  return 0;
}

