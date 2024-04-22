
size_t tls1_mac(undefined4 *param_1,uchar *param_2,int param_3)

{
  undefined2 uVar1;
  size_t sVar2;
  EVP_MD *md;
  ulong uVar3;
  uint uVar4;
  undefined4 uVar5;
  char cVar6;
  int iVar7;
  undefined4 *puVar8;
  uint *puVar9;
  EVP_MD_CTX *ctx;
  uint uVar10;
  uint uVar11;
  size_t local_5c;
  undefined local_58;
  undefined uStack_57;
  undefined2 uStack_56;
  undefined2 uStack_54;
  undefined2 local_52;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined local_48;
  undefined local_47;
  undefined local_46;
  undefined local_45;
  undefined local_44;
  EVP_MD_CTX EStack_40;
  
  iVar7 = param_1[0x16];
  if (param_3 == 0) {
    puVar9 = (uint *)(iVar7 + 0x10c);
    ctx = (EVP_MD_CTX *)param_1[0x21];
    uVar11 = param_1[0x1f] & 1;
    puVar8 = (undefined4 *)(iVar7 + 8);
  }
  else {
    ctx = (EVP_MD_CTX *)param_1[0x24];
    puVar9 = (uint *)(iVar7 + 0x130);
    uVar11 = param_1[0x1f] & 2;
    puVar8 = (undefined4 *)(iVar7 + 0x54);
  }
  md = EVP_MD_CTX_md(ctx);
  local_5c = EVP_MD_size(md);
  if ((int)local_5c < 0) {
    OpenSSLDie(DAT_00075008,0x3fb,DAT_00075010);
  }
  if (uVar11 == 0) {
    iVar7 = EVP_MD_CTX_copy(&EStack_40,ctx);
    if (iVar7 == 0) {
      return -1;
    }
    ctx = &EStack_40;
  }
  sVar2 = local_5c;
  if (*(int *)(*(int *)(param_1[2] + 100) + 0x38) << 0x1c < 0) {
    if (param_3 == 0) {
      uVar1 = *(undefined2 *)(param_1[0x17] + 0x208);
      local_58 = (undefined)((ushort)uVar1 >> 8);
      uStack_57 = (undefined)uVar1;
    }
    else {
      uVar1 = *(undefined2 *)(param_1[0x17] + 0x20a);
      local_58 = (undefined)((ushort)uVar1 >> 8);
      uStack_57 = (undefined)uVar1;
    }
    uStack_56 = (undefined2)*(undefined4 *)((int)puVar8 + 2);
    uStack_54 = (undefined2)((uint)*(undefined4 *)((int)puVar8 + 2) >> 0x10);
    local_52 = *(undefined2 *)((int)puVar8 + 6);
    local_50 = CONCAT22(uStack_56,CONCAT11(uStack_57,local_58));
    uStack_4c = CONCAT22(local_52,uStack_54);
  }
  else {
    local_50 = *puVar8;
    uStack_4c = puVar8[1];
  }
  uVar4 = *puVar9;
  uVar10 = puVar9[1];
  uVar5 = *param_1;
  *puVar9 = uVar4 & 0xff;
  local_48 = (undefined)uVar4;
  local_44 = (undefined)uVar10;
  local_45 = (undefined)(uVar10 >> 8);
  local_46 = (undefined)uVar5;
  local_47 = (undefined)((uint)uVar5 >> 8);
  if (((param_3 == 0) &&
      (uVar3 = EVP_CIPHER_CTX_flags((EVP_CIPHER_CTX *)param_1[0x20]), (uVar3 & 0xf0007) == 2)) &&
     (iVar7 = ssl3_cbc_record_digest_supported(ctx), iVar7 != 0)) {
    ssl3_cbc_digest_record
              (ctx,param_2,&local_5c,&local_50,puVar9[4],local_5c + puVar9[1],
               sVar2 + uVar10 + (uVar4 >> 8),param_1[0x16] + 0x14,
               *(undefined4 *)(param_1[0x16] + 0x10),0);
  }
  else {
    EVP_DigestUpdate(ctx,&local_50,0xd);
    EVP_DigestUpdate(ctx,(void *)puVar9[4],puVar9[1]);
    iVar7 = EVP_DigestSignFinal(ctx,param_2,&local_5c);
    if (iVar7 < 1) {
      OpenSSLDie(DAT_00075008,0x430,DAT_0007500c);
    }
  }
  if (uVar11 == 0) {
    EVP_MD_CTX_cleanup(&EStack_40);
  }
  if (((((-1 < *(int *)(*(int *)(param_1[2] + 100) + 0x38) << 0x1c) &&
        (cVar6 = *(char *)((int)puVar8 + 7) + '\x01', *(char *)((int)puVar8 + 7) = cVar6,
        cVar6 == '\0')) &&
       ((cVar6 = *(char *)((int)puVar8 + 6) + '\x01', *(char *)((int)puVar8 + 6) = cVar6,
        cVar6 == '\0' &&
        ((cVar6 = *(char *)((int)puVar8 + 5) + '\x01', *(char *)((int)puVar8 + 5) = cVar6,
         cVar6 == '\0' &&
         (cVar6 = *(char *)(puVar8 + 1), *(char *)(puVar8 + 1) = cVar6 + '\x01',
         (char)(cVar6 + '\x01') == '\0')))))) &&
      (cVar6 = *(char *)((int)puVar8 + 3) + '\x01', *(char *)((int)puVar8 + 3) = cVar6,
      cVar6 == '\0')) &&
     ((cVar6 = *(char *)((int)puVar8 + 2) + '\x01', *(char *)((int)puVar8 + 2) = cVar6,
      cVar6 == '\0' &&
      (cVar6 = *(char *)((int)puVar8 + 1) + '\x01', *(char *)((int)puVar8 + 1) = cVar6,
      cVar6 == '\0')))) {
    *(char *)puVar8 = *(char *)puVar8 + '\x01';
  }
  return local_5c;
}

