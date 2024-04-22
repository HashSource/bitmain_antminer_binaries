
int EVP_EncryptFinal(EVP_CIPHER_CTX *ctx,uchar *out,int *outl)

{
  uchar uVar1;
  void **ppvVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  uint uVar8;
  EVP_CIPHER *pEVar9;
  uint uVar10;
  uint uVar11;
  void **ppvVar12;
  uint inl;
  uint uVar13;
  
  pEVar9 = ctx->cipher;
  if ((pEVar9->flags & 0x100000) == 0) {
    inl = pEVar9->block_size;
    if (inl < 0x21) {
      if (inl == 1) {
        *outl = 0;
        return 1;
      }
      uVar7 = ctx->flags;
      uVar3 = ctx->buf_len;
    }
    else {
      OpenSSLDie(DAT_000af0fc,0x193,DAT_000af100);
      uVar7 = ctx->flags;
      uVar3 = ctx->buf_len;
    }
    if (-1 < (int)(uVar7 << 0x17)) {
      if (uVar3 < inl) {
        uVar11 = inl - uVar3;
        uVar13 = inl - uVar3 & 0xff;
        uVar6 = -(int)(ctx->buf + uVar3) & 3;
        if (uVar11 <= uVar6) {
          uVar6 = uVar11;
        }
        if (uVar11 < 4) {
          uVar6 = uVar11;
        }
        uVar1 = (uchar)(inl - uVar3);
        uVar8 = uVar3;
        uVar10 = uVar3;
        if (uVar6 != 0) {
          do {
            uVar10 = uVar8 + 1;
            ctx->buf[uVar8] = uVar1;
            uVar8 = uVar10;
          } while (uVar10 - uVar3 < uVar6);
          if (uVar11 == uVar6) goto LAB_000af096;
        }
        uVar11 = uVar11 - uVar6;
        uVar8 = uVar11 >> 2;
        if (uVar8 != 0) {
          ppvVar12 = (void **)(ctx->buf + uVar3 + uVar6);
          pvVar4 = (void *)(uVar13 | uVar13 << 8 | uVar13 << 0x10 | uVar13 << 0x18);
          if (uVar8 < 9) {
            uVar3 = 0;
          }
          else {
            uVar3 = 0;
            ppvVar2 = ppvVar12;
            do {
              uVar6 = uVar3 + 9;
              uVar3 = uVar3 + 8;
              HintPreloadData(ppvVar2 + 0x28);
              *ppvVar2 = pvVar4;
              ppvVar2[1] = pvVar4;
              ppvVar2[2] = pvVar4;
              ppvVar2[3] = pvVar4;
              ppvVar2[4] = pvVar4;
              ppvVar2[5] = pvVar4;
              ppvVar2[6] = pvVar4;
              ppvVar2[7] = pvVar4;
              ppvVar12 = ppvVar2 + 8;
              ppvVar2 = ppvVar2 + 8;
            } while (uVar6 < uVar8 - 7);
          }
          do {
            uVar3 = uVar3 + 1;
            *ppvVar12 = pvVar4;
            ppvVar12 = ppvVar12 + 1;
          } while (uVar3 < uVar8);
          uVar10 = uVar10 + (uVar11 & 0xfffffffc);
          if (uVar11 == (uVar11 & 0xfffffffc)) goto LAB_000af096;
        }
        do {
          uVar3 = uVar10 + 1;
          ctx->buf[uVar10] = uVar1;
          uVar10 = uVar3;
        } while (uVar3 < inl);
      }
LAB_000af096:
      iVar5 = (*ctx->cipher->do_cipher)(ctx,out,ctx->buf,inl);
      if (iVar5 == 0) {
        return 0;
      }
      *outl = inl;
      return iVar5;
    }
    if (uVar3 != 0) {
      ERR_put_error(6,0x7f,0x8a,DAT_000af0fc,0x19c);
      return 0;
    }
  }
  else {
    uVar3 = (*pEVar9->do_cipher)(ctx,out,(uchar *)0x0,0);
    if ((int)uVar3 < 0) {
      return 0;
    }
  }
  *outl = uVar3;
  return 1;
}

