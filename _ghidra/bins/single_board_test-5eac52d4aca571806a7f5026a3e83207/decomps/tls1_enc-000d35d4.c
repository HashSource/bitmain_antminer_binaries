
/* WARNING: Type propagation algorithm not settling */

uint tls1_enc(undefined4 *param_1,int param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  char cVar3;
  EVP_MD *pEVar4;
  int iVar5;
  uchar *buf;
  EVP_CIPHER *pEVar6;
  ulong uVar7;
  int extraout_r1;
  uint uVar8;
  int extraout_r1_00;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  char *pcVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  uint uVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  uint *puVar21;
  EVP_CIPHER_CTX *ctx;
  char *pcVar22;
  int local_304;
  int local_300;
  EVP_CIPHER *local_2f0;
  uint local_2c8 [31];
  undefined4 uStack_24c;
  undefined1 local_248;
  undefined1 uStack_247;
  undefined2 uStack_246;
  undefined2 uStack_244;
  undefined2 local_242;
  undefined4 local_1c8 [105];
  
  if (param_3 == 0) {
    ossl_statem_fatal(param_1,0x50,0x191,0x44,"ssl/record/ssl3_record.c",0x3b6);
    return 0;
  }
  if (param_4 == 0) {
    pEVar4 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0xf8]);
    if (pEVar4 == (EVP_MD *)0x0) {
LAB_000d3606:
      ctx = (EVP_CIPHER_CTX *)param_1[0xf3];
      if (ctx == (EVP_CIPHER_CTX *)0x0) goto LAB_000d3624;
      local_2f0 = EVP_CIPHER_CTX_cipher(ctx);
      goto LAB_000d3618;
    }
    pEVar4 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0xf8]);
    iVar5 = EVP_MD_size(pEVar4);
    if (-1 < iVar5) goto LAB_000d3606;
    uVar16 = 0x3e6;
  }
  else {
    pEVar4 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x100]);
    if (pEVar4 != (EVP_MD *)0x0) {
      pEVar4 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x100]);
      iVar5 = EVP_MD_size(pEVar4);
      if (iVar5 < 0) {
        uVar16 = 0x3bf;
        goto LAB_000d3a64;
      }
    }
    ctx = (EVP_CIPHER_CTX *)param_1[0xfb];
    if (ctx == (EVP_CIPHER_CTX *)0x0) goto LAB_000d3624;
    local_2f0 = EVP_CIPHER_CTX_cipher(ctx);
    if (((*(int *)(*(int *)(param_1[1] + 100) + 0x30) << 0x1f < 0) &&
        (uVar7 = EVP_CIPHER_flags(local_2f0), (uVar7 & 0xf0007) == 2)) &&
       (iVar5 = EVP_CIPHER_iv_length(local_2f0), 1 < iVar5)) {
      buf = *(uchar **)(param_2 + 0x18);
      if (buf == *(uchar **)(param_2 + 0x14)) {
        uVar18 = 0;
        iVar15 = param_2;
        do {
          uVar18 = uVar18 + 1;
          iVar14 = RAND_bytes(buf,iVar5);
          if (iVar14 < 1) {
            uVar16 = 0x3db;
            goto LAB_000d3a64;
          }
          if (param_3 == uVar18) goto LAB_000d3618;
          buf = *(uchar **)(iVar15 + 0x44);
          puVar19 = (undefined4 *)(iVar15 + 0x48);
          iVar15 = iVar15 + 0x30;
        } while (buf == (uchar *)*puVar19);
      }
      uVar16 = 0x3d7;
      goto LAB_000d3a64;
    }
LAB_000d3618:
    if ((param_1[0x11d] == 0) || (local_2f0 == (EVP_CIPHER *)0x0)) {
LAB_000d3624:
      uVar18 = 0;
      do {
        uVar18 = uVar18 + 1;
        memmove(*(void **)(param_2 + 0x14),*(void **)(param_2 + 0x18),*(size_t *)(param_2 + 8));
        *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_2 + 0x14);
        param_2 = param_2 + 0x30;
      } while (param_3 != uVar18);
      return 1;
    }
    pEVar6 = EVP_CIPHER_CTX_cipher(ctx);
    iVar5 = EVP_CIPHER_block_size(pEVar6);
    if (1 < param_3) {
      pEVar6 = EVP_CIPHER_CTX_cipher(ctx);
      uVar7 = EVP_CIPHER_flags(pEVar6);
      if (-1 < (int)(uVar7 << 8)) {
        uVar16 = 0x402;
        uVar17 = 0x196;
        goto LAB_000d3a6a;
      }
    }
    puVar19 = local_1c8;
    uVar18 = iVar5 - 1;
    if (uVar18 != 0) {
      uVar18 = 1;
    }
    puVar10 = (undefined4 *)((int)puVar19 + param_3 * 0xd);
    uVar11 = uVar18 & 1;
    if (param_4 == 0) {
      uVar11 = 0;
    }
    local_300 = 0;
    iVar15 = param_2;
    puVar21 = local_2c8;
    pcVar22 = (char *)(param_1 + 0x3ca);
    if (param_4 == 0) {
      pcVar22 = (char *)(param_1 + 0x3c8);
    }
    do {
      *puVar21 = *(uint *)(iVar15 + 8);
      pEVar6 = EVP_CIPHER_CTX_cipher(ctx);
      uVar7 = EVP_CIPHER_flags(pEVar6);
      if ((int)(uVar7 << 10) < 0) {
        iVar14 = *(int *)(*(int *)(param_1[1] + 100) + 0x30);
        if (param_4 == 0) {
          if (-1 < iVar14 << 0x1c) goto LAB_000d3892;
          local_248 = (undefined1)((ushort)*(undefined2 *)param_1[0x3ce] >> 8);
          uStack_247 = (undefined1)*(undefined2 *)param_1[0x3ce];
          pcVar12 = (char *)(param_1 + 0x3c8);
LAB_000d3796:
          local_242 = *(undefined2 *)(pcVar12 + 6);
          uStack_246 = (undefined2)*(undefined4 *)(pcVar12 + 2);
          uStack_244 = (undefined2)((uint)*(undefined4 *)(pcVar12 + 2) >> 0x10);
          *puVar19 = CONCAT22(uStack_246,CONCAT11(uStack_247,local_248));
          puVar19[1] = CONCAT22(local_242,uStack_244);
        }
        else {
          if (iVar14 << 0x1c < 0) {
            local_248 = (undefined1)((ushort)*(undefined2 *)(param_1[0x3ce] + 2) >> 8);
            uStack_247 = (undefined1)*(undefined2 *)(param_1[0x3ce] + 2);
            pcVar12 = (char *)(param_1 + 0x3ca);
            goto LAB_000d3796;
          }
LAB_000d3892:
          cVar3 = pcVar22[7];
          uVar16 = *(undefined4 *)pcVar22;
          puVar19[1] = *(undefined4 *)(pcVar22 + 4);
          *puVar19 = uVar16;
          pcVar22[7] = cVar3 + '\x01';
          if ((((char)(cVar3 + '\x01') == '\0') &&
              (cVar3 = pcVar22[6], pcVar22[6] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0')) &&
             ((cVar3 = pcVar22[5], pcVar22[5] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0' &&
              ((((cVar3 = pcVar22[4], pcVar22[4] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0' &&
                 (cVar3 = pcVar22[3], pcVar22[3] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0'))
                && (cVar3 = pcVar22[2], pcVar22[2] = cVar3 + '\x01', (char)(cVar3 + '\x01') == '\0')
                ) && (cVar3 = pcVar22[1], pcVar22[1] = cVar3 + '\x01',
                     (char)(cVar3 + '\x01') == '\0')))))) {
            *pcVar22 = *pcVar22 + '\x01';
          }
        }
        uVar16 = *(undefined4 *)(iVar15 + 8);
        uVar17 = *param_1;
        *(char *)(puVar19 + 3) = (char)uVar16;
        uVar2 = *(undefined1 *)(iVar15 + 4);
        *(char *)((int)puVar19 + 10) = (char)uVar17;
        *(char *)((int)puVar19 + 0xb) = (char)((uint)uVar16 >> 8);
        *(undefined1 *)(puVar19 + 2) = uVar2;
        *(char *)((int)puVar19 + 9) = (char)((uint)uVar17 >> 8);
        local_300 = EVP_CIPHER_CTX_ctrl(ctx,0x16,0xd,puVar19);
        if (local_300 < 1) {
          uVar16 = 0x42a;
          goto LAB_000d3a64;
        }
        if (param_4 == 0) goto LAB_000d386c;
        iVar14 = *(int *)(iVar15 + 8);
        *puVar21 = *puVar21 + local_300;
        *(int *)(iVar15 + 8) = iVar14 + local_300;
      }
      else if (uVar11 == 0) {
        if (param_4 == 0) {
LAB_000d386c:
          if (*puVar21 == 0) {
            return 0;
          }
          __aeabi_uidivmod(*puVar21,iVar5);
          if (extraout_r1_00 != 0) {
            return 0;
          }
        }
      }
      else {
        uVar13 = *puVar21;
        __aeabi_uidivmod(uVar13,iVar5);
        uVar8 = iVar5 - extraout_r1;
        if (0x100 < uVar8) {
          uVar16 = 0x43a;
          goto LAB_000d3a64;
        }
        uVar9 = uVar13 + uVar8;
        if (uVar13 < uVar9) {
          do {
            *(char *)(*(int *)(iVar15 + 0x18) + uVar13) = (char)uVar8 + -1;
            uVar13 = uVar13 + 1;
            uVar9 = *puVar21 + uVar8;
          } while (uVar13 < uVar9);
        }
        iVar14 = *(int *)(iVar15 + 8);
        *puVar21 = uVar9;
        *(uint *)(iVar15 + 8) = uVar8 + iVar14;
      }
      puVar19 = (undefined4 *)((int)puVar19 + 0xd);
      iVar15 = iVar15 + 0x30;
      puVar21 = puVar21 + 1;
    } while (puVar10 != puVar19);
    if (1 < param_3) {
      puVar19 = &uStack_24c;
      puVar20 = (undefined4 *)((int)&local_248 + (param_3 + 0x3fffffff) * 4);
      puVar10 = puVar19;
      iVar15 = param_2;
      do {
        puVar1 = (undefined4 *)(iVar15 + 0x14);
        iVar15 = iVar15 + 0x30;
        puVar10 = puVar10 + 1;
        *puVar10 = *puVar1;
      } while (puVar20 != puVar10);
      iVar14 = EVP_CIPHER_CTX_ctrl(ctx,0x22,param_3,&local_248);
      iVar15 = param_2;
      if (iVar14 < 1) {
        uVar16 = 0x454;
LAB_000d3b7a:
        ossl_statem_fatal(param_1,0x50,0x191,0x196,"ssl/record/ssl3_record.c",uVar16);
        return 0xffffffff;
      }
      do {
        puVar19 = puVar19 + 1;
        *puVar19 = *(undefined4 *)(iVar15 + 0x18);
        iVar15 = iVar15 + 0x30;
      } while (puVar20 != puVar19);
      iVar15 = EVP_CIPHER_CTX_ctrl(ctx,0x23,param_3,&local_248);
      if ((iVar15 < 1) || (iVar15 = EVP_CIPHER_CTX_ctrl(ctx,0x24,param_3,local_2c8), iVar15 < 1)) {
        uVar16 = 0x460;
        goto LAB_000d3b7a;
      }
    }
    uVar11 = EVP_Cipher(ctx,*(uchar **)(param_2 + 0x14),*(uchar **)(param_2 + 0x18),local_2c8[0]);
    pEVar6 = EVP_CIPHER_CTX_cipher(ctx);
    uVar7 = EVP_CIPHER_flags(pEVar6);
    if ((int)(uVar7 << 0xb) < 0) {
      uVar11 = uVar11 >> 0x1f;
    }
    else {
      uVar11 = (uint)(uVar11 == 0);
    }
    if (uVar11 != 0) {
      return 0xffffffff;
    }
    if (param_4 == 0) {
      uVar7 = EVP_CIPHER_flags(local_2f0);
      if ((uVar7 & 0xf0007) == 6) {
        iVar15 = param_2;
        do {
          iVar14 = iVar15 + 0x30;
          *(int *)(iVar15 + 0x14) = *(int *)(iVar15 + 0x14) + 8;
          *(int *)(iVar15 + 0x18) = *(int *)(iVar15 + 0x18) + 8;
          *(int *)(iVar15 + 8) = *(int *)(iVar15 + 8) + -8;
          iVar15 = iVar14;
        } while (iVar14 != param_2 + param_3 * 0x30);
      }
      else {
        uVar7 = EVP_CIPHER_flags(local_2f0);
        if ((uVar7 & 0xf0007) == 7) {
          iVar15 = param_2;
          do {
            iVar14 = iVar15 + 0x30;
            *(int *)(iVar15 + 0x14) = *(int *)(iVar15 + 0x14) + 8;
            *(int *)(iVar15 + 0x18) = *(int *)(iVar15 + 0x18) + 8;
            *(int *)(iVar15 + 8) = *(int *)(iVar15 + 8) + -8;
            iVar15 = iVar14;
          } while (iVar14 != param_2 + param_3 * 0x30);
        }
      }
    }
    if ((*(int *)param_1[0x1f] << 0x17 < 0) ||
       (pEVar4 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0xf8]), pEVar4 == (EVP_MD *)0x0)) {
      local_304 = 0;
LAB_000d39d2:
      uVar11 = (uint)(param_4 == 0);
      if ((uVar18 & uVar11) == 0) {
        if (local_300 == 0) {
          uVar11 = 0;
        }
        if (uVar11 == 0) {
          return 1;
        }
        uVar18 = 1;
      }
      else {
        uVar11 = 0;
        uVar18 = 1;
        iVar15 = param_2;
        do {
          uVar11 = uVar11 + 1;
          uVar8 = tls1_cbc_remove_padding(param_1,iVar15,iVar5,local_304);
          if (uVar8 == 0) {
            return 0;
          }
          uVar8 = (int)((uVar8 ^ 1) - 1 & ~(uVar8 ^ 1)) >> 0x1f;
          uVar13 = ~uVar8;
          local_248 = (undefined1)uVar13;
          uStack_247 = (undefined1)(uVar13 >> 8);
          uStack_246 = (undefined2)(uVar13 >> 0x10);
          uVar18 = uVar18 & uVar8 | uVar13;
          iVar15 = iVar15 + 0x30;
        } while (param_3 != uVar11);
        if (local_300 == 0) {
          return uVar18;
        }
      }
      iVar5 = param_2;
      do {
        iVar15 = iVar5 + 0x30;
        *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) - local_300;
        iVar5 = iVar15;
      } while (iVar15 != param_2 + param_3 * 0x30);
      return uVar18;
    }
    pEVar4 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0xf8]);
    local_304 = EVP_MD_size(pEVar4);
    if (-1 < local_304) goto LAB_000d39d2;
    uVar16 = 0x483;
  }
LAB_000d3a64:
  uVar17 = 0x44;
LAB_000d3a6a:
  ossl_statem_fatal(param_1,0x50,0x191,uVar17,"ssl/record/ssl3_record.c",uVar16);
  return 0xffffffff;
}

