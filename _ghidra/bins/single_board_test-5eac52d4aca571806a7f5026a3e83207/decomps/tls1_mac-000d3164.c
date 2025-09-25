
undefined4 tls1_mac(undefined4 *param_1,int param_2,uchar *param_3,int param_4)

{
  char cVar1;
  undefined2 uVar2;
  EVP_MD *md;
  int iVar3;
  EVP_MD_CTX *out;
  EVP_CIPHER *cipher;
  ulong uVar4;
  char *pcVar5;
  EVP_MD_CTX *ctx;
  uint uVar6;
  EVP_MD_CTX *pEVar7;
  size_t local_44;
  undefined1 local_40;
  undefined1 uStack_3f;
  undefined2 uStack_3e;
  undefined2 uStack_3c;
  undefined2 local_3a;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  
  if (param_4 == 0) {
    pcVar5 = (char *)(param_1 + 0x3c8);
    ctx = (EVP_MD_CTX *)param_1[0xf8];
    uVar6 = param_1[0x32] & 1;
  }
  else {
    pcVar5 = (char *)(param_1 + 0x3ca);
    ctx = (EVP_MD_CTX *)param_1[0x100];
    uVar6 = param_1[0x32] & 2;
  }
  md = EVP_MD_CTX_md(ctx);
  local_44 = EVP_MD_size(md);
  if ((int)local_44 < 0) {
    return 0;
  }
  if (uVar6 == 0) {
    out = (EVP_MD_CTX *)EVP_MD_CTX_new();
    pEVar7 = out;
    if ((out == (EVP_MD_CTX *)0x0) || (iVar3 = EVP_MD_CTX_copy(out,ctx), iVar3 == 0))
    goto LAB_000d32e0;
  }
  else {
    out = ctx;
    pEVar7 = (EVP_MD_CTX *)0x0;
  }
  if (*(int *)(*(int *)(param_1[1] + 100) + 0x30) << 0x1c < 0) {
    if (param_4 == 0) {
      uVar2 = *(undefined2 *)param_1[0x3ce];
      local_40 = (undefined1)((ushort)uVar2 >> 8);
      uStack_3f = (undefined1)uVar2;
    }
    else {
      uVar2 = ((undefined2 *)param_1[0x3ce])[1];
      local_40 = (undefined1)((ushort)uVar2 >> 8);
      uStack_3f = (undefined1)uVar2;
    }
    local_3a = *(undefined2 *)(pcVar5 + 6);
    uStack_3e = (undefined2)*(undefined4 *)(pcVar5 + 2);
    uStack_3c = (undefined2)((uint)*(undefined4 *)(pcVar5 + 2) >> 0x10);
    local_38 = CONCAT22(uStack_3e,CONCAT11(uStack_3f,local_40));
    uStack_34 = CONCAT22(local_3a,uStack_3c);
  }
  else {
    local_38 = *(undefined4 *)pcVar5;
    uStack_34 = *(undefined4 *)(pcVar5 + 4);
  }
  local_2e = (undefined1)*param_1;
  local_2c = (undefined1)*(undefined4 *)(param_2 + 8);
  local_30 = (undefined1)*(undefined4 *)(param_2 + 4);
  local_2f = (undefined1)((uint)*param_1 >> 8);
  local_2d = (undefined1)((uint)*(undefined4 *)(param_2 + 8) >> 8);
  if ((param_4 == 0) && (-1 < *(int *)param_1[0x1f] << 0x17)) {
    cipher = EVP_CIPHER_CTX_cipher((EVP_CIPHER_CTX *)param_1[0xf3]);
    uVar4 = EVP_CIPHER_flags(cipher);
    if (((uVar4 & 0xf0007) == 2) && (iVar3 = ssl3_cbc_record_digest_supported(out), iVar3 != 0)) {
      iVar3 = ssl3_cbc_digest_record
                        (out,param_3,&local_44,&local_38,*(undefined4 *)(param_2 + 0x18),
                         *(int *)(param_2 + 8) + local_44,*(undefined4 *)(param_2 + 0xc),
                         param_1[0x1f] + 8,*(undefined4 *)(param_1[0x1f] + 4),0);
      if (iVar3 < 1) {
        EVP_MD_CTX_free(pEVar7);
        return 0;
      }
      goto LAB_000d3246;
    }
  }
  iVar3 = EVP_DigestUpdate(out,&local_38,0xd);
  if (((iVar3 < 1) ||
      (iVar3 = EVP_DigestUpdate(out,*(void **)(param_2 + 0x18),*(size_t *)(param_2 + 8)), iVar3 < 1)
      ) || (iVar3 = EVP_DigestSignFinal(out,param_3,&local_44), iVar3 < 1)) {
LAB_000d32e0:
    EVP_MD_CTX_free(pEVar7);
    return 0;
  }
LAB_000d3246:
  EVP_MD_CTX_free(pEVar7);
  if (((((-1 < *(int *)(*(int *)(param_1[1] + 100) + 0x30) << 0x1c) &&
        (cVar1 = pcVar5[7], pcVar5[7] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
       ((cVar1 = pcVar5[6], pcVar5[6] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
        ((cVar1 = pcVar5[5], pcVar5[5] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
         (cVar1 = pcVar5[4], pcVar5[4] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')))))) &&
      (cVar1 = pcVar5[3], pcVar5[3] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
     ((cVar1 = pcVar5[2], pcVar5[2] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
      (cVar1 = pcVar5[1], pcVar5[1] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')))) {
    *pcVar5 = *pcVar5 + '\x01';
  }
  return 1;
}

