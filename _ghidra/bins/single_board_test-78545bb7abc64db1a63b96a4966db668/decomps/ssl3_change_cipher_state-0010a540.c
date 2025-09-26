
undefined4 ssl3_change_cipher_state(int param_1,uint param_2)

{
  COMP_METHOD *meth;
  COMP_CTX *pCVar1;
  size_t __n;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  EVP_CIPHER_CTX *pEVar5;
  EVP_CIPHER *cipher;
  void *__dest;
  EVP_MD *md;
  int iVar6;
  bool bVar7;
  void *pvVar8;
  void *__src;
  
  iVar3 = *(int *)(param_1 + 0x7c);
  md = *(EVP_MD **)(iVar3 + 0x234);
  cipher = *(EVP_CIPHER **)(iVar3 + 0x230);
  if (md == (EVP_MD *)0x0) {
    ossl_statem_fatal(param_1,0x50,0x81,0x44,"ssl/s3_enc.c",0x6d);
    return 0;
  }
  meth = *(COMP_METHOD **)(iVar3 + 0x240);
  if (meth != (COMP_METHOD *)0x0) {
    meth = (COMP_METHOD *)meth->init;
  }
  if ((param_2 & 1) == 0) {
    pEVar5 = *(EVP_CIPHER_CTX **)(param_1 + 0x3ec);
    *(undefined4 *)(param_1 + 0x60) = 1;
    bVar7 = true;
    if (pEVar5 == (EVP_CIPHER_CTX *)0x0) {
      pEVar5 = EVP_CIPHER_CTX_new();
      *(EVP_CIPHER_CTX **)(param_1 + 0x3ec) = pEVar5;
      if (pEVar5 == (EVP_CIPHER_CTX *)0x0) {
        uVar4 = 0xa1;
        goto LAB_0010a738;
      }
      EVP_CIPHER_CTX_reset();
      pEVar5 = *(EVP_CIPHER_CTX **)(param_1 + 0x3ec);
      bVar7 = false;
    }
    iVar3 = ssl_replace_hash(param_1 + 0x400,md);
    if (iVar3 == 0) {
      uVar4 = 0xac;
LAB_0010a738:
      ossl_statem_fatal(param_1,0x50,0x81,0x41,"ssl/s3_enc.c",uVar4);
      return 0;
    }
    COMP_CTX_free(*(COMP_CTX **)(param_1 + 0x3e4));
    *(undefined4 *)(param_1 + 0x3e4) = 0;
    if (meth != (COMP_METHOD *)0x0) {
      pCVar1 = COMP_CTX_new(meth);
      *(COMP_CTX **)(param_1 + 0x3e4) = pCVar1;
      if (pCVar1 == (COMP_CTX *)0x0) {
        uVar4 = 0xb8;
        goto LAB_0010a770;
      }
    }
    RECORD_LAYER_reset_write_sequence(param_1 + 0x650);
    iVar3 = *(int *)(param_1 + 0x7c);
    __dest = (void *)(iVar3 + 0x4c);
    if (!bVar7) goto LAB_0010a5c8;
LAB_0010a68c:
    EVP_CIPHER_CTX_reset(pEVar5);
    pvVar8 = *(void **)(*(int *)(param_1 + 0x7c) + 0x22c);
    __n = EVP_MD_size(md);
  }
  else {
    pEVar5 = *(EVP_CIPHER_CTX **)(param_1 + 0x3cc);
    bVar7 = true;
    if (pEVar5 == (EVP_CIPHER_CTX *)0x0) {
      pEVar5 = EVP_CIPHER_CTX_new();
      *(EVP_CIPHER_CTX **)(param_1 + 0x3cc) = pEVar5;
      if (pEVar5 == (EVP_CIPHER_CTX *)0x0) {
        uVar4 = 0x7c;
        goto LAB_0010a738;
      }
      EVP_CIPHER_CTX_reset();
      pEVar5 = *(EVP_CIPHER_CTX **)(param_1 + 0x3cc);
      bVar7 = false;
    }
    iVar3 = ssl_replace_hash(param_1 + 0x3e0,md);
    if (iVar3 == 0) {
      uVar4 = 0x88;
      goto LAB_0010a6ea;
    }
    COMP_CTX_free(*(COMP_CTX **)(param_1 + 1000));
    *(undefined4 *)(param_1 + 1000) = 0;
    if (meth != (COMP_METHOD *)0x0) {
      pCVar1 = COMP_CTX_new(meth);
      *(COMP_CTX **)(param_1 + 1000) = pCVar1;
      if (pCVar1 == (COMP_CTX *)0x0) {
        uVar4 = 0x94;
LAB_0010a770:
        ossl_statem_fatal(param_1,0x50,0x81,0x8e,"ssl/s3_enc.c",uVar4);
        return 0;
      }
    }
    RECORD_LAYER_reset_read_sequence(param_1 + 0x650);
    iVar3 = *(int *)(param_1 + 0x7c);
    __dest = (void *)(iVar3 + 8);
    if (bVar7) goto LAB_0010a68c;
LAB_0010a5c8:
    pvVar8 = *(void **)(iVar3 + 0x22c);
    __n = EVP_MD_size(md);
  }
  if ((int)__n < 0) {
    uVar4 = 200;
    goto LAB_0010a6ca;
  }
  iVar3 = EVP_CIPHER_key_length(cipher);
  iVar2 = EVP_CIPHER_iv_length(cipher);
  if (param_2 == 0x21 || param_2 == 0x12) {
    iVar6 = __n * 2;
    iVar3 = iVar6 + iVar3 * 2;
    __src = pvVar8;
    if (*(uint *)(*(int *)(param_1 + 0x7c) + 0x228) < (uint)(iVar3 + iVar2 * 2)) {
LAB_0010a6c4:
      uVar4 = 0xe3;
LAB_0010a6ca:
      ossl_statem_fatal(param_1,0x50,0x81,0x44,"ssl/s3_enc.c",uVar4);
      return 0;
    }
  }
  else {
    iVar6 = iVar3 + __n * 2;
    iVar3 = iVar3 + iVar2 + iVar6;
    __src = (void *)((int)pvVar8 + __n);
    if (*(uint *)(*(int *)(param_1 + 0x7c) + 0x228) < (uint)(iVar2 + iVar3)) goto LAB_0010a6c4;
  }
  memcpy(__dest,__src,__n);
  iVar3 = EVP_CipherInit_ex(pEVar5,cipher,(ENGINE *)0x0,(uchar *)(iVar6 + (int)pvVar8),
                            (uchar *)(iVar3 + (int)pvVar8),param_2 & 2);
  if (iVar3 != 0) {
    *(undefined4 *)(param_1 + 0x60) = 0;
    return 1;
  }
  uVar4 = 0xeb;
LAB_0010a6ea:
  ossl_statem_fatal(param_1,0x50,0x81,0x44,"ssl/s3_enc.c",uVar4);
  return 0;
}

