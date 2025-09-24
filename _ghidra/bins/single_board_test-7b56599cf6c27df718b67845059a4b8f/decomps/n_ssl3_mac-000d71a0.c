
undefined4 n_ssl3_mac(int param_1,int param_2,uchar *param_3,int param_4)

{
  size_t sVar1;
  EVP_MD *pEVar2;
  size_t sVar3;
  EVP_MD_CTX *out;
  EVP_CIPHER *cipher;
  ulong uVar4;
  int iVar5;
  void *__src;
  EVP_MD_CTX *ctx;
  undefined4 uVar6;
  undefined4 *d;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 local_79;
  size_t local_78;
  uint auStack_74 [2];
  undefined1 auStack_6c [72];
  
  if (param_4 == 0) {
    ctx = *(EVP_MD_CTX **)(param_1 + 0x3e0);
    d = (undefined4 *)(param_1 + 0xf20);
    iVar5 = *(int *)(param_1 + 0x7c);
    pEVar2 = EVP_MD_CTX_md(ctx);
    sVar3 = EVP_MD_size(pEVar2);
    __src = (void *)(iVar5 + 8);
    if ((int)sVar3 < 0) {
      return 0;
    }
    local_78 = sVar3;
    iVar5 = __aeabi_uidiv(0x30,sVar3);
    sVar3 = sVar3 * iVar5;
    cipher = EVP_CIPHER_CTX_cipher(*(EVP_CIPHER_CTX **)(param_1 + 0x3cc));
    uVar4 = EVP_CIPHER_flags(cipher);
    if (((uVar4 & 0xf0007) == 2) &&
       (iVar5 = ssl3_cbc_record_digest_supported(ctx), sVar1 = local_78, iVar5 != 0)) {
      memcpy(auStack_74,__src,local_78);
      memcpy((void *)((int)auStack_74 + sVar1),
             "666666666666666666666666666666666666666666666666\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ssl/record/ssl3_record.c"
             ,sVar3);
      uVar8 = *(undefined4 *)(param_2 + 8);
      uVar6 = *(undefined4 *)(param_2 + 4);
      iVar5 = sVar3 + sVar1;
      uVar7 = *(undefined4 *)(param_1 + 0xf24);
      *(undefined4 *)((int)auStack_74 + iVar5) = *d;
      *(undefined4 *)((int)auStack_74 + iVar5 + 4) = uVar7;
      auStack_6c[iVar5] = (char)uVar6;
      auStack_6c[iVar5 + 2] = (char)uVar8;
      auStack_6c[iVar5 + 1] = (char)((uint)uVar8 >> 8);
      iVar5 = ssl3_cbc_digest_record(ctx,param_3,&local_78,auStack_74);
      if (iVar5 < 1) {
        return 0;
      }
      goto LAB_000d7306;
    }
    out = (EVP_MD_CTX *)EVP_MD_CTX_new();
  }
  else {
    ctx = *(EVP_MD_CTX **)(param_1 + 0x400);
    d = (undefined4 *)(param_1 + 0xf28);
    iVar5 = *(int *)(param_1 + 0x7c);
    pEVar2 = EVP_MD_CTX_md(ctx);
    sVar3 = EVP_MD_size(pEVar2);
    __src = (void *)(iVar5 + 0x4c);
    if ((int)sVar3 < 0) {
      return 0;
    }
    local_78 = sVar3;
    iVar5 = __aeabi_uidiv(0x30,sVar3);
    sVar3 = sVar3 * iVar5;
    out = (EVP_MD_CTX *)EVP_MD_CTX_new();
  }
  if (out != (EVP_MD_CTX *)0x0) {
    local_79 = (undefined1)*(undefined4 *)(param_2 + 4);
    *param_3 = (uchar)((uint)*(undefined4 *)(param_2 + 8) >> 8);
    param_3[1] = (uchar)*(undefined4 *)(param_2 + 8);
    iVar5 = EVP_MD_CTX_copy_ex(out,ctx);
    if (((((0 < iVar5) && (iVar5 = EVP_DigestUpdate(out,__src,local_78), 0 < iVar5)) &&
         (iVar5 = EVP_DigestUpdate(out,
                                   "666666666666666666666666666666666666666666666666\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ssl/record/ssl3_record.c"
                                   ,sVar3), 0 < iVar5)) &&
        (((iVar5 = EVP_DigestUpdate(out,d,8), 0 < iVar5 &&
          (iVar5 = EVP_DigestUpdate(out,&local_79,1), 0 < iVar5)) &&
         ((iVar5 = EVP_DigestUpdate(out,param_3,2), 0 < iVar5 &&
          ((iVar5 = EVP_DigestUpdate(out,*(void **)(param_2 + 0x18),*(size_t *)(param_2 + 8)),
           0 < iVar5 && (iVar5 = EVP_DigestFinal_ex(out,param_3,(uint *)0x0), 0 < iVar5)))))))) &&
       ((iVar5 = EVP_MD_CTX_copy_ex(out,ctx), 0 < iVar5 &&
        ((((iVar5 = EVP_DigestUpdate(out,__src,local_78), 0 < iVar5 &&
           (iVar5 = EVP_DigestUpdate(out,
                                     "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ssl/record/ssl3_record.c"
                                     ,sVar3), 0 < iVar5)) &&
          (iVar5 = EVP_DigestUpdate(out,param_3,local_78), 0 < iVar5)) &&
         (iVar5 = EVP_DigestFinal_ex(out,param_3,auStack_74), 0 < iVar5)))))) {
      EVP_MD_CTX_free(out);
LAB_000d7306:
      ssl3_record_sequence_update(d);
      return 1;
    }
    EVP_MD_CTX_free(out);
  }
  return 0;
}

