
size_t tls1_mac(undefined4 *param_1,uchar *param_2,int param_3)

{
  char cVar1;
  undefined2 uVar2;
  size_t sVar3;
  EVP_MD *md;
  ulong uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  uint *puVar9;
  EVP_MD_CTX *ctx;
  uint uVar10;
  uint uVar11;
  size_t local_5c;
  undefined1 local_58;
  undefined1 uStack_57;
  undefined2 uStack_56;
  undefined2 uStack_54;
  undefined2 local_52;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined1 local_48;
  undefined1 local_47;
  undefined1 local_46;
  undefined1 local_45;
  undefined1 local_44;
  EVP_MD_CTX EStack_40;
  
  iVar7 = param_1[0x16];
  if (param_3 == 0) {
    puVar9 = (uint *)(iVar7 + 0x10c);
    ctx = (EVP_MD_CTX *)param_1[0x21];
    uVar11 = param_1[0x1f] & 1;
    pcVar8 = (char *)(iVar7 + 8);
  }
  else {
    ctx = (EVP_MD_CTX *)param_1[0x24];
    puVar9 = (uint *)(iVar7 + 0x130);
    uVar11 = param_1[0x1f] & 2;
    pcVar8 = (char *)(iVar7 + 0x54);
  }
  md = EVP_MD_CTX_md(ctx);
  local_5c = EVP_MD_size(md);
  if ((int)local_5c < 0) {
    OpenSSLDie("t1_enc.c",0x3fb,"t >= 0");
  }
  if (uVar11 == 0) {
    iVar7 = EVP_MD_CTX_copy(&EStack_40,ctx);
    if (iVar7 == 0) {
      return -1;
    }
    ctx = &EStack_40;
  }
  sVar3 = local_5c;
  if (*(int *)(*(int *)(param_1[2] + 100) + 0x38) << 0x1c < 0) {
    if (param_3 == 0) {
      uVar2 = *(undefined2 *)(param_1[0x17] + 0x208);
      local_58 = (undefined1)((ushort)uVar2 >> 8);
      uStack_57 = (undefined1)uVar2;
    }
    else {
      uVar2 = *(undefined2 *)(param_1[0x17] + 0x20a);
      local_58 = (undefined1)((ushort)uVar2 >> 8);
      uStack_57 = (undefined1)uVar2;
    }
    uStack_56 = (undefined2)*(undefined4 *)(pcVar8 + 2);
    uStack_54 = (undefined2)((uint)*(undefined4 *)(pcVar8 + 2) >> 0x10);
    local_52 = *(undefined2 *)(pcVar8 + 6);
    local_50 = CONCAT22(uStack_56,CONCAT11(uStack_57,local_58));
    uStack_4c = CONCAT22(local_52,uStack_54);
  }
  else {
    local_50 = *(undefined4 *)pcVar8;
    uStack_4c = *(undefined4 *)(pcVar8 + 4);
  }
  uVar5 = *puVar9;
  uVar10 = puVar9[1];
  uVar6 = *param_1;
  *puVar9 = uVar5 & 0xff;
  local_48 = (undefined1)uVar5;
  local_44 = (undefined1)uVar10;
  local_45 = (undefined1)(uVar10 >> 8);
  local_46 = (undefined1)uVar6;
  local_47 = (undefined1)((uint)uVar6 >> 8);
  if (((param_3 == 0) &&
      (uVar4 = EVP_CIPHER_CTX_flags((EVP_CIPHER_CTX *)param_1[0x20]), (uVar4 & 0xf0007) == 2)) &&
     (iVar7 = ssl3_cbc_record_digest_supported(ctx), iVar7 != 0)) {
    ssl3_cbc_digest_record
              (ctx,param_2,&local_5c,&local_50,puVar9[4],local_5c + puVar9[1],
               sVar3 + uVar10 + (uVar5 >> 8),param_1[0x16] + 0x14,
               *(undefined4 *)(param_1[0x16] + 0x10),0);
  }
  else {
    EVP_DigestUpdate(ctx,&local_50,0xd);
    EVP_DigestUpdate(ctx,(void *)puVar9[4],puVar9[1]);
    iVar7 = EVP_DigestSignFinal(ctx,param_2,&local_5c);
    if (iVar7 < 1) {
      OpenSSLDie("t1_enc.c",0x430,"t > 0");
    }
  }
  if (uVar11 == 0) {
    EVP_MD_CTX_cleanup(&EStack_40);
  }
  if (((((-1 < *(int *)(*(int *)(param_1[2] + 100) + 0x38) << 0x1c) &&
        (cVar1 = pcVar8[7], pcVar8[7] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
       ((cVar1 = pcVar8[6], pcVar8[6] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
        ((cVar1 = pcVar8[5], pcVar8[5] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
         (cVar1 = pcVar8[4], pcVar8[4] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')))))) &&
      (cVar1 = pcVar8[3], pcVar8[3] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
     ((cVar1 = pcVar8[2], pcVar8[2] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
      (cVar1 = pcVar8[1], pcVar8[1] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')))) {
    *pcVar8 = *pcVar8 + '\x01';
  }
  return local_5c;
}

