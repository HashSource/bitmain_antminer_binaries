
size_t n_ssl3_mac(int param_1,uchar *param_2,int param_3)

{
  size_t sVar1;
  EVP_MD *md;
  size_t sVar2;
  ulong uVar3;
  uint uVar4;
  undefined4 uVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  undefined4 *d;
  uint *puVar9;
  EVP_MD_CTX *ctx;
  void *__src;
  size_t __n;
  undefined local_7d;
  size_t local_7c;
  size_t local_78;
  undefined auStack_74 [9];
  undefined auStack_6b [71];
  
  iVar8 = *(int *)(param_1 + 0x58);
  if (param_3 == 0) {
    puVar9 = (uint *)(iVar8 + 0x10c);
    __src = (void *)(iVar8 + 0x14);
    ctx = *(EVP_MD_CTX **)(param_1 + 0x84);
    d = (undefined4 *)(iVar8 + 8);
  }
  else {
    ctx = *(EVP_MD_CTX **)(param_1 + 0x90);
    puVar9 = (uint *)(iVar8 + 0x130);
    __src = (void *)(iVar8 + 0x60);
    d = (undefined4 *)(iVar8 + 0x54);
  }
  md = EVP_MD_CTX_md(ctx);
  sVar2 = EVP_MD_size(md);
  if ((int)sVar2 < 0) {
    local_7c = 0xffffffff;
  }
  else {
    local_7c = sVar2;
    iVar8 = __aeabi_uidiv(0x30,sVar2);
    uVar7 = *puVar9;
    __n = sVar2 * iVar8;
    uVar4 = puVar9[1];
    *puVar9 = uVar7 & 0xff;
    if (((param_3 == 0) &&
        (uVar3 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80)), (uVar3 & 0xf0007) == 2)
        ) && (iVar8 = ssl3_cbc_record_digest_supported(ctx), sVar1 = local_7c, iVar8 != 0)) {
      memcpy(auStack_74,__src,local_7c);
      memcpy(auStack_74 + sVar1,DAT_0006b80c,__n);
      iVar8 = __n + sVar1;
      uVar5 = d[1];
      *(undefined4 *)(auStack_74 + iVar8) = *d;
      *(undefined4 *)(auStack_74 + iVar8 + 4) = uVar5;
      auStack_74[iVar8 + 8] = (char)*puVar9;
      auStack_6b[iVar8] = (char)(puVar9[1] >> 8);
      auStack_6b[iVar8 + 1] = (char)puVar9[1];
      ssl3_cbc_digest_record
                (ctx,param_2,&local_7c,auStack_74,puVar9[4],sVar1 + puVar9[1],
                 uVar4 + (uVar7 >> 8) + sVar2,__src,sVar1,1);
    }
    else {
      EVP_MD_CTX_init((EVP_MD_CTX *)auStack_74);
      EVP_MD_CTX_copy_ex((EVP_MD_CTX *)auStack_74,ctx);
      EVP_DigestUpdate((EVP_MD_CTX *)auStack_74,__src,local_7c);
      EVP_DigestUpdate((EVP_MD_CTX *)auStack_74,DAT_0006b80c,__n);
      EVP_DigestUpdate((EVP_MD_CTX *)auStack_74,d,8);
      local_7d = (undefined)*puVar9;
      EVP_DigestUpdate((EVP_MD_CTX *)auStack_74,&local_7d,1);
      *param_2 = (uchar)(puVar9[1] >> 8);
      param_2[1] = (uchar)puVar9[1];
      EVP_DigestUpdate((EVP_MD_CTX *)auStack_74,param_2,2);
      EVP_DigestUpdate((EVP_MD_CTX *)auStack_74,(void *)puVar9[4],puVar9[1]);
      EVP_DigestFinal_ex((EVP_MD_CTX *)auStack_74,param_2,(uint *)0x0);
      EVP_MD_CTX_copy_ex((EVP_MD_CTX *)auStack_74,ctx);
      EVP_DigestUpdate((EVP_MD_CTX *)auStack_74,__src,local_7c);
      EVP_DigestUpdate((EVP_MD_CTX *)auStack_74,DAT_0006b810,__n);
      EVP_DigestUpdate((EVP_MD_CTX *)auStack_74,param_2,local_7c);
      EVP_DigestFinal_ex((EVP_MD_CTX *)auStack_74,param_2,&local_78);
      local_7c = local_78;
      EVP_MD_CTX_cleanup((EVP_MD_CTX *)auStack_74);
    }
    cVar6 = *(char *)((int)d + 7) + '\x01';
    *(char *)((int)d + 7) = cVar6;
    if (((((cVar6 == '\0') &&
          (cVar6 = *(char *)((int)d + 6) + '\x01', *(char *)((int)d + 6) = cVar6, cVar6 == '\0')) &&
         ((cVar6 = *(char *)((int)d + 5) + '\x01', *(char *)((int)d + 5) = cVar6, cVar6 == '\0' &&
          ((cVar6 = *(char *)(d + 1), *(char *)(d + 1) = cVar6 + '\x01',
           (char)(cVar6 + '\x01') == '\0' &&
           (cVar6 = *(char *)((int)d + 3) + '\x01', *(char *)((int)d + 3) = cVar6, cVar6 == '\0'))))
         )) && (cVar6 = *(char *)((int)d + 2) + '\x01', *(char *)((int)d + 2) = cVar6, cVar6 == '\0'
               )) &&
       (cVar6 = *(char *)((int)d + 1) + '\x01', *(char *)((int)d + 1) = cVar6, cVar6 == '\0')) {
      *(char *)d = *(char *)d + '\x01';
    }
  }
  return local_7c;
}

