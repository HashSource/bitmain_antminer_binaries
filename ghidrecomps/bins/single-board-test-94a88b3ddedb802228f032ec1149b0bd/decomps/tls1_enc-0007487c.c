
/* WARNING: Type propagation algorithm not settling */

undefined4 tls1_enc(undefined4 *param_1,uint param_2)

{
  EVP_MD *pEVar1;
  int iVar2;
  EVP_CIPHER_CTX *cipher;
  ulong uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined uVar7;
  char cVar8;
  int extraout_r1;
  int iVar9;
  int extraout_r1_00;
  undefined4 *puVar10;
  undefined uVar11;
  undefined4 *puVar12;
  EVP_CIPHER_CTX *ctx;
  uint uVar13;
  undefined2 uStack_42;
  undefined2 uStack_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined local_30;
  undefined local_2f;
  undefined local_2e;
  undefined local_2d;
  undefined local_2c;
  
  if (param_2 == 0) {
    pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x21]);
    if (pEVar1 != (EVP_MD *)0x0) {
      pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x21]);
      iVar2 = EVP_MD_size(pEVar1);
      if (iVar2 < 0) {
        OpenSSLDie(DAT_00074ba4,0x30f,DAT_00074ba8);
      }
    }
    ctx = (EVP_CIPHER_CTX *)param_1[0x20];
    puVar12 = (undefined4 *)(param_1[0x16] + 0x10c);
    cipher = ctx;
    if (ctx != (EVP_CIPHER_CTX *)0x0) {
      cipher = (EVP_CIPHER_CTX *)EVP_CIPHER_CTX_cipher(ctx);
    }
  }
  else {
    pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
    if (pEVar1 != (EVP_MD *)0x0) {
      pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
      iVar2 = EVP_MD_size(pEVar1);
      if (iVar2 < 0) {
        OpenSSLDie(DAT_00074ba4,0x2f0,DAT_00074ba8);
      }
    }
    iVar2 = param_1[0x16];
    ctx = (EVP_CIPHER_CTX *)param_1[0x23];
    puVar12 = (undefined4 *)(iVar2 + 0x130);
    cipher = ctx;
    if ((((ctx != (EVP_CIPHER_CTX *)0x0) &&
         (cipher = (EVP_CIPHER_CTX *)EVP_CIPHER_CTX_cipher(ctx),
         *(int *)(*(int *)(param_1[2] + 100) + 0x38) << 0x1f < 0)) &&
        (uVar3 = EVP_CIPHER_flags((EVP_CIPHER *)cipher), (uVar3 & 0xf0007) == 2)) &&
       (iVar4 = EVP_CIPHER_iv_length((EVP_CIPHER *)cipher), 1 < iVar4)) {
      if (*(uchar **)(iVar2 + 0x13c) == *(uchar **)(iVar2 + 0x140)) {
        iVar2 = RAND_bytes(*(uchar **)(iVar2 + 0x13c),iVar4);
        if (iVar2 < 1) {
          return 0xffffffff;
        }
      }
      else {
        fprintf(*DAT_00074b9c,DAT_00074ba0,DAT_00074ba4,0x307);
      }
    }
  }
  if ((param_1[0x30] == 0) || (ctx == (EVP_CIPHER_CTX *)0x0 || cipher == (EVP_CIPHER_CTX *)0x0)) {
    memmove((void *)puVar12[3],(void *)puVar12[4],puVar12[1]);
    puVar12[4] = puVar12[3];
    return 1;
  }
  uVar13 = puVar12[1];
  iVar2 = EVP_CIPHER_block_size(ctx->cipher);
  uVar3 = EVP_CIPHER_flags(ctx->cipher);
  uVar5 = uVar13;
  if ((int)(uVar3 << 10) < 0) {
    if (param_2 == 0) {
      puVar10 = (undefined4 *)(param_1[0x16] + 8);
      if (*(int *)(*(int *)(param_1[2] + 100) + 0x38) << 0x1c < 0) {
        uVar7 = (undefined)((ushort)*(undefined2 *)(param_1[0x17] + 0x208) >> 8);
        uVar11 = (undefined)*(undefined2 *)(param_1[0x17] + 0x208);
        goto LAB_00074a82;
      }
LAB_00074b2a:
      uStack_34 = puVar10[1];
      local_38 = *puVar10;
      cVar8 = *(char *)((int)puVar10 + 7) + '\x01';
      *(char *)((int)puVar10 + 7) = cVar8;
      if (((cVar8 == '\0') &&
          (cVar8 = *(char *)((int)puVar10 + 6) + '\x01', *(char *)((int)puVar10 + 6) = cVar8,
          cVar8 == '\0')) &&
         ((cVar8 = *(char *)((int)puVar10 + 5) + '\x01', *(char *)((int)puVar10 + 5) = cVar8,
          cVar8 == '\0' &&
          ((((cVar8 = *(char *)(puVar10 + 1), *(char *)(puVar10 + 1) = cVar8 + '\x01',
             (char)(cVar8 + '\x01') == '\0' &&
             (cVar8 = *(char *)((int)puVar10 + 3) + '\x01', *(char *)((int)puVar10 + 3) = cVar8,
             cVar8 == '\0')) &&
            (cVar8 = *(char *)((int)puVar10 + 2) + '\x01', *(char *)((int)puVar10 + 2) = cVar8,
            cVar8 == '\0')) &&
           (cVar8 = *(char *)((int)puVar10 + 1) + '\x01', *(char *)((int)puVar10 + 1) = cVar8,
           cVar8 == '\0')))))) {
        *(char *)puVar10 = *(char *)puVar10 + '\x01';
      }
    }
    else {
      puVar10 = (undefined4 *)(param_1[0x16] + 0x54);
      if (-1 < *(int *)(*(int *)(param_1[2] + 100) + 0x38) << 0x1c) goto LAB_00074b2a;
      uVar7 = (undefined)((ushort)*(undefined2 *)(param_1[0x17] + 0x20a) >> 8);
      uVar11 = (undefined)*(undefined2 *)(param_1[0x17] + 0x20a);
LAB_00074a82:
      uStack_42 = (undefined2)*(undefined4 *)((int)puVar10 + 2);
      uStack_40 = (undefined2)((uint)*(undefined4 *)((int)puVar10 + 2) >> 0x10);
      local_38 = CONCAT22(uStack_42,CONCAT11(uVar11,uVar7));
      uStack_34 = CONCAT22(*(undefined2 *)((int)puVar10 + 6),uStack_40);
    }
    local_2e = (undefined)*param_1;
    local_30 = (undefined)*puVar12;
    local_2f = (undefined)((uint)*param_1 >> 8);
    local_2c = (undefined)puVar12[1];
    local_2d = (undefined)((uint)puVar12[1] >> 8);
    iVar4 = EVP_CIPHER_CTX_ctrl(ctx,0x16,0xd,&local_38);
    if (iVar4 < 1) {
      return 0xffffffff;
    }
    if (param_2 != 0) {
      puVar12[1] = puVar12[1] + iVar4;
      uVar5 = uVar13 + iVar4;
      goto LAB_00074ade;
    }
  }
  else {
    if (iVar2 != 1 && param_2 != 0) {
      __aeabi_idivmod(uVar13,iVar2);
      iVar9 = iVar2 - extraout_r1;
      uVar11 = (undefined)(iVar9 + -1);
      if ((int)(param_1[0x40] << 0x16) < 0) {
        iVar4 = iVar9 + -1;
        if ((*(uint *)param_1[0x16] & 8) != 0) {
          iVar4 = iVar9;
        }
        uVar11 = (undefined)iVar4;
      }
      uVar5 = uVar13 + iVar9;
      if ((int)uVar13 < (int)uVar5) {
        do {
          *(undefined *)(puVar12[4] + uVar13) = uVar11;
          uVar13 = uVar13 + 1;
        } while (uVar13 != uVar5);
      }
      iVar4 = 0;
      puVar12[1] = puVar12[1] + iVar9;
      goto LAB_000749de;
    }
    iVar4 = 0;
LAB_00074ade:
    if (param_2 != 0) goto LAB_000749de;
  }
  if (uVar5 == 0) {
    return 0;
  }
  __aeabi_uidivmod(uVar5,iVar2);
  if (extraout_r1_00 != 0) {
    return 0;
  }
LAB_000749de:
  uVar5 = EVP_Cipher(ctx,(uchar *)puVar12[3],(uchar *)puVar12[4],uVar5);
  uVar3 = EVP_CIPHER_flags(ctx->cipher);
  if ((int)(uVar3 << 0xb) < 0) {
    uVar13 = uVar5 >> 0x1f;
  }
  else {
    uVar13 = 1 - uVar5;
    if (1 < uVar5) {
      uVar13 = 0;
    }
  }
  if (uVar13 != 0) {
    return 0xffffffff;
  }
  uVar3 = EVP_CIPHER_flags((EVP_CIPHER *)cipher);
  if (((uVar3 & 0xf0007) == 6) && (param_2 == 0)) {
    puVar12[3] = puVar12[3] + 8;
    puVar12[4] = puVar12[4] + 8;
    puVar12[1] = puVar12[1] + -8;
  }
  pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x21]);
  if (pEVar1 != (EVP_MD *)0x0) {
    pEVar1 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x21]);
    EVP_MD_size(pEVar1);
  }
  uVar5 = 1 - param_2;
  uVar6 = 1;
  if (1 < param_2) {
    uVar5 = 0;
  }
  if (iVar2 == 1) {
    uVar13 = 0;
  }
  else {
    uVar13 = uVar5 & 1;
  }
  if (uVar13 != 0) {
    uVar6 = tls1_cbc_remove_padding(param_1,puVar12,iVar2);
  }
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = uVar5 & 1;
  }
  if (uVar5 != 0) {
    puVar12[1] = puVar12[1] - iVar4;
    return uVar6;
  }
  return uVar6;
}

