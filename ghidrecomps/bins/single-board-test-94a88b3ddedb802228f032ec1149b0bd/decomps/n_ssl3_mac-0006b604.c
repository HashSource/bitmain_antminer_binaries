
size_t n_ssl3_mac(int param_1,uchar *param_2,int param_3)

{
  char cVar1;
  size_t sVar2;
  EVP_MD *md;
  size_t sVar3;
  ulong uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  char *d;
  uint *puVar9;
  EVP_MD_CTX *ctx;
  void *__src;
  size_t __n;
  undefined1 local_7d;
  size_t local_7c;
  size_t local_78;
  EVP_MD_CTX aEStack_74 [3];
  
  iVar8 = *(int *)(param_1 + 0x58);
  if (param_3 == 0) {
    puVar9 = (uint *)(iVar8 + 0x10c);
    __src = (void *)(iVar8 + 0x14);
    ctx = *(EVP_MD_CTX **)(param_1 + 0x84);
    d = (char *)(iVar8 + 8);
  }
  else {
    ctx = *(EVP_MD_CTX **)(param_1 + 0x90);
    puVar9 = (uint *)(iVar8 + 0x130);
    __src = (void *)(iVar8 + 0x60);
    d = (char *)(iVar8 + 0x54);
  }
  md = EVP_MD_CTX_md(ctx);
  sVar3 = EVP_MD_size(md);
  if ((int)sVar3 < 0) {
    local_7c = 0xffffffff;
  }
  else {
    local_7c = sVar3;
    iVar8 = __aeabi_uidiv(0x30,sVar3);
    uVar7 = *puVar9;
    __n = sVar3 * iVar8;
    uVar5 = puVar9[1];
    *puVar9 = uVar7 & 0xff;
    if (((param_3 == 0) &&
        (uVar4 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80)), (uVar4 & 0xf0007) == 2)
        ) && (iVar8 = ssl3_cbc_record_digest_supported(ctx), sVar2 = local_7c, iVar8 != 0)) {
      memcpy(aEStack_74,__src,local_7c);
      memcpy((void *)((int)&aEStack_74[0].digest + sVar2),&ssl3_pad_1,__n);
      iVar8 = __n + sVar2;
      uVar6 = *(undefined4 *)(d + 4);
      *(undefined4 *)((int)&aEStack_74[0].digest + iVar8) = *(undefined4 *)d;
      *(undefined4 *)((int)&aEStack_74[0].engine + iVar8) = uVar6;
      *(char *)((int)&aEStack_74[0].flags + iVar8) = (char)*puVar9;
      *(char *)((int)&aEStack_74[0].flags + iVar8 + 1) = (char)(puVar9[1] >> 8);
      *(char *)((int)&aEStack_74[0].flags + iVar8 + 2) = (char)puVar9[1];
      ssl3_cbc_digest_record
                (ctx,param_2,&local_7c,aEStack_74,puVar9[4],sVar2 + puVar9[1],
                 uVar5 + (uVar7 >> 8) + sVar3,__src,sVar2,1);
    }
    else {
      EVP_MD_CTX_init(aEStack_74);
      EVP_MD_CTX_copy_ex(aEStack_74,ctx);
      EVP_DigestUpdate(aEStack_74,__src,local_7c);
      EVP_DigestUpdate(aEStack_74,&ssl3_pad_1,__n);
      EVP_DigestUpdate(aEStack_74,d,8);
      local_7d = (undefined1)*puVar9;
      EVP_DigestUpdate(aEStack_74,&local_7d,1);
      *param_2 = (uchar)(puVar9[1] >> 8);
      param_2[1] = (uchar)puVar9[1];
      EVP_DigestUpdate(aEStack_74,param_2,2);
      EVP_DigestUpdate(aEStack_74,(void *)puVar9[4],puVar9[1]);
      EVP_DigestFinal_ex(aEStack_74,param_2,(uint *)0x0);
      EVP_MD_CTX_copy_ex(aEStack_74,ctx);
      EVP_DigestUpdate(aEStack_74,__src,local_7c);
      EVP_DigestUpdate(aEStack_74,ssl3_pad_2,__n);
      EVP_DigestUpdate(aEStack_74,param_2,local_7c);
      EVP_DigestFinal_ex(aEStack_74,param_2,&local_78);
      local_7c = local_78;
      EVP_MD_CTX_cleanup(aEStack_74);
    }
    cVar1 = d[7];
    d[7] = cVar1 + '\x01';
    if ((((((char)(cVar1 + '\x01') == '\0') &&
          (cVar1 = d[6], d[6] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
         ((cVar1 = d[5], d[5] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
          ((cVar1 = d[4], d[4] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
           (cVar1 = d[3], d[3] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')))))) &&
        (cVar1 = d[2], d[2] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
       (cVar1 = d[1], d[1] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) {
      *d = *d + '\x01';
    }
  }
  return local_7c;
}

