
/* WARNING: Type propagation algorithm not settling */

undefined4 tls1_enc(undefined4 *param_1,uint param_2)

{
  char cVar1;
  EVP_MD *pEVar2;
  int iVar3;
  EVP_CIPHER_CTX *cipher;
  ulong uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined1 uVar8;
  int extraout_r1;
  int iVar9;
  int extraout_r1_00;
  char *pcVar10;
  undefined1 uVar11;
  undefined4 *puVar12;
  EVP_CIPHER_CTX *ctx;
  uint uVar13;
  undefined2 uStack_42;
  undefined2 uStack_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  
  if (param_2 == 0) {
    pEVar2 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x21]);
    if (pEVar2 != (EVP_MD *)0x0) {
      pEVar2 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x21]);
      iVar3 = EVP_MD_size(pEVar2);
      if (iVar3 < 0) {
        OpenSSLDie("t1_enc.c",0x30f,"n >= 0");
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
    pEVar2 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
    if (pEVar2 != (EVP_MD *)0x0) {
      pEVar2 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
      iVar3 = EVP_MD_size(pEVar2);
      if (iVar3 < 0) {
        OpenSSLDie("t1_enc.c",0x2f0,"n >= 0");
      }
    }
    iVar3 = param_1[0x16];
    ctx = (EVP_CIPHER_CTX *)param_1[0x23];
    puVar12 = (undefined4 *)(iVar3 + 0x130);
    cipher = ctx;
    if ((((ctx != (EVP_CIPHER_CTX *)0x0) &&
         (cipher = (EVP_CIPHER_CTX *)EVP_CIPHER_CTX_cipher(ctx),
         *(int *)(*(int *)(param_1[2] + 100) + 0x38) << 0x1f < 0)) &&
        (uVar4 = EVP_CIPHER_flags((EVP_CIPHER *)cipher), (uVar4 & 0xf0007) == 2)) &&
       (iVar5 = EVP_CIPHER_iv_length((EVP_CIPHER *)cipher), 1 < iVar5)) {
      if (*(uchar **)(iVar3 + 0x13c) == *(uchar **)(iVar3 + 0x140)) {
        iVar3 = RAND_bytes(*(uchar **)(iVar3 + 0x13c),iVar5);
        if (iVar3 < 1) {
          return 0xffffffff;
        }
      }
      else {
        fprintf(stderr,"%s:%d: rec->data != rec->input\n","t1_enc.c",0x307);
      }
    }
  }
  if ((param_1[0x30] == 0) || (ctx == (EVP_CIPHER_CTX *)0x0 || cipher == (EVP_CIPHER_CTX *)0x0)) {
    memmove((void *)puVar12[3],(void *)puVar12[4],puVar12[1]);
    puVar12[4] = puVar12[3];
    return 1;
  }
  uVar13 = puVar12[1];
  iVar3 = EVP_CIPHER_block_size(ctx->cipher);
  uVar4 = EVP_CIPHER_flags(ctx->cipher);
  uVar6 = uVar13;
  if ((int)(uVar4 << 10) < 0) {
    if (param_2 == 0) {
      pcVar10 = (char *)(param_1[0x16] + 8);
      if (*(int *)(*(int *)(param_1[2] + 100) + 0x38) << 0x1c < 0) {
        uVar8 = (undefined1)((ushort)*(undefined2 *)(param_1[0x17] + 0x208) >> 8);
        uVar11 = (undefined1)*(undefined2 *)(param_1[0x17] + 0x208);
        goto LAB_001122d2;
      }
LAB_0011237a:
      uStack_34 = *(undefined4 *)(pcVar10 + 4);
      local_38 = *(undefined4 *)pcVar10;
      cVar1 = pcVar10[7];
      pcVar10[7] = cVar1 + '\x01';
      if ((((char)(cVar1 + '\x01') == '\0') &&
          (cVar1 = pcVar10[6], pcVar10[6] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
         ((cVar1 = pcVar10[5], pcVar10[5] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
          ((((cVar1 = pcVar10[4], pcVar10[4] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
             (cVar1 = pcVar10[3], pcVar10[3] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
            (cVar1 = pcVar10[2], pcVar10[2] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
           (cVar1 = pcVar10[1], pcVar10[1] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')))))) {
        *pcVar10 = *pcVar10 + '\x01';
      }
    }
    else {
      pcVar10 = (char *)(param_1[0x16] + 0x54);
      if (-1 < *(int *)(*(int *)(param_1[2] + 100) + 0x38) << 0x1c) goto LAB_0011237a;
      uVar8 = (undefined1)((ushort)*(undefined2 *)(param_1[0x17] + 0x20a) >> 8);
      uVar11 = (undefined1)*(undefined2 *)(param_1[0x17] + 0x20a);
LAB_001122d2:
      uStack_42 = (undefined2)*(undefined4 *)(pcVar10 + 2);
      uStack_40 = (undefined2)((uint)*(undefined4 *)(pcVar10 + 2) >> 0x10);
      local_38 = CONCAT22(uStack_42,CONCAT11(uVar11,uVar8));
      uStack_34 = CONCAT22(*(undefined2 *)(pcVar10 + 6),uStack_40);
    }
    local_2e = (undefined1)*param_1;
    local_30 = (undefined1)*puVar12;
    local_2f = (undefined1)((uint)*param_1 >> 8);
    local_2c = (undefined1)puVar12[1];
    local_2d = (undefined1)((uint)puVar12[1] >> 8);
    iVar5 = EVP_CIPHER_CTX_ctrl(ctx,0x16,0xd,&local_38);
    if (iVar5 < 1) {
      return 0xffffffff;
    }
    if (param_2 != 0) {
      puVar12[1] = puVar12[1] + iVar5;
      uVar6 = uVar13 + iVar5;
      goto LAB_0011232e;
    }
  }
  else {
    if (iVar3 != 1 && param_2 != 0) {
      __aeabi_idivmod(uVar13,iVar3);
      iVar9 = iVar3 - extraout_r1;
      uVar11 = (undefined1)(iVar9 + -1);
      if ((int)(param_1[0x40] << 0x16) < 0) {
        iVar5 = iVar9 + -1;
        if ((*(uint *)param_1[0x16] & 8) != 0) {
          iVar5 = iVar9;
        }
        uVar11 = (undefined1)iVar5;
      }
      uVar6 = uVar13 + iVar9;
      if ((int)uVar13 < (int)uVar6) {
        do {
          *(undefined1 *)(puVar12[4] + uVar13) = uVar11;
          uVar13 = uVar13 + 1;
        } while (uVar13 != uVar6);
      }
      iVar5 = 0;
      puVar12[1] = puVar12[1] + iVar9;
      goto LAB_0011222e;
    }
    iVar5 = 0;
LAB_0011232e:
    if (param_2 != 0) goto LAB_0011222e;
  }
  if (uVar6 == 0) {
    return 0;
  }
  __aeabi_uidivmod(uVar6,iVar3);
  if (extraout_r1_00 != 0) {
    return 0;
  }
LAB_0011222e:
  uVar6 = EVP_Cipher(ctx,(uchar *)puVar12[3],(uchar *)puVar12[4],uVar6);
  uVar4 = EVP_CIPHER_flags(ctx->cipher);
  if ((int)(uVar4 << 0xb) < 0) {
    uVar13 = uVar6 >> 0x1f;
  }
  else {
    uVar13 = 1 - uVar6;
    if (1 < uVar6) {
      uVar13 = 0;
    }
  }
  if (uVar13 != 0) {
    return 0xffffffff;
  }
  uVar4 = EVP_CIPHER_flags((EVP_CIPHER *)cipher);
  if (((uVar4 & 0xf0007) == 6) && (param_2 == 0)) {
    puVar12[3] = puVar12[3] + 8;
    puVar12[4] = puVar12[4] + 8;
    puVar12[1] = puVar12[1] + -8;
  }
  pEVar2 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x21]);
  if (pEVar2 != (EVP_MD *)0x0) {
    pEVar2 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x21]);
    EVP_MD_size(pEVar2);
  }
  uVar6 = 1 - param_2;
  uVar7 = 1;
  if (1 < param_2) {
    uVar6 = 0;
  }
  if (iVar3 == 1) {
    uVar13 = 0;
  }
  else {
    uVar13 = uVar6 & 1;
  }
  if (uVar13 != 0) {
    uVar7 = tls1_cbc_remove_padding(param_1,puVar12,iVar3);
  }
  if (iVar5 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = uVar6 & 1;
  }
  if (uVar6 != 0) {
    puVar12[1] = puVar12[1] - iVar5;
    return uVar7;
  }
  return uVar7;
}

