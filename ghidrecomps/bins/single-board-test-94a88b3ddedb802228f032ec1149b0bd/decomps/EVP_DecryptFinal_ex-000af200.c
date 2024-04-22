
int EVP_DecryptFinal_ex(EVP_CIPHER_CTX *ctx,uchar *outm,int *outl)

{
  EVP_CIPHER_CTX *pEVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uchar *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  EVP_CIPHER *pEVar9;
  uint uVar10;
  uint uVar11;
  EVP_CIPHER_CTX *pEVar12;
  
  pEVar9 = ctx->cipher;
  *outl = 0;
  if ((pEVar9->flags & 0x100000) != 0) {
    iVar8 = (*pEVar9->do_cipher)(ctx,outm,(uchar *)0x0,0);
    if (iVar8 < 0) {
      return 0;
    }
    *outl = iVar8;
    return 1;
  }
  uVar10 = pEVar9->block_size;
  if ((int)(ctx->flags << 0x17) < 0) {
    if (ctx->buf_len != 0) {
      ERR_put_error(6,0x65,0x8a,DAT_000af3e8,0x1fe);
      return 0;
    }
  }
  else if (1 < uVar10) {
    if ((ctx->buf_len != 0) || (ctx->final_used == 0)) {
      ERR_put_error(6,0x65,0x6d,DAT_000af3e8,0x206);
      return 0;
    }
    if (0x20 < uVar10) {
      OpenSSLDie(DAT_000af3e8,0x209,DAT_000af3ec);
    }
    uVar5 = (uint)ctx->final[uVar10 - 1];
    puVar4 = ctx->final + uVar10;
    uVar6 = 1 - uVar5;
    if (1 < uVar5) {
      uVar6 = 0;
    }
    if ((int)uVar10 < (int)uVar5) {
      uVar6 = uVar6 | 1;
    }
    if (uVar6 != 0) {
      iVar8 = 0x211;
LAB_000af3ba:
      ERR_put_error(6,0x65,100,DAT_000af3e8,iVar8);
      return 0;
    }
    do {
      puVar4 = puVar4 + -1;
      uVar6 = uVar6 + 1;
      if (*puVar4 != uVar5) {
        iVar8 = 0x216;
        goto LAB_000af3ba;
      }
    } while ((int)uVar6 < (int)uVar5);
    uVar5 = ctx->cipher->block_size - uVar5;
    if (0 < (int)uVar5) {
      pEVar12 = (EVP_CIPHER_CTX *)ctx->final;
      uVar6 = uVar5 >> 2;
      uVar10 = uVar5 & 0xfffffffc;
      if (uVar6 == 0 ||
          (outm < ctx->final + 4 && pEVar12 < outm + 4 || (uVar5 < 4 || ((uint)outm & 3) != 0))) {
        uVar10 = 0;
      }
      else {
        if (uVar6 < 9) {
          uVar7 = 0;
          puVar3 = (undefined4 *)outm;
        }
        else {
          uVar7 = 0;
          pEVar1 = ctx + 1;
          puVar2 = (undefined4 *)(outm + 0x20);
          do {
            puVar3 = puVar2;
            pEVar12 = pEVar1;
            uVar11 = uVar7 + 9;
            uVar7 = uVar7 + 8;
            HintPreloadData(&pEVar12->app_data);
            puVar3[-8] = *(undefined4 *)pEVar12[-1].final;
            puVar3[-7] = *(undefined4 *)(pEVar12[-1].final + 4);
            puVar3[-6] = *(undefined4 *)(pEVar12[-1].final + 8);
            puVar3[-5] = *(undefined4 *)(pEVar12[-1].final + 0xc);
            puVar3[-4] = *(undefined4 *)(pEVar12[-1].final + 0x10);
            puVar3[-3] = *(undefined4 *)(pEVar12[-1].final + 0x14);
            puVar3[-2] = *(undefined4 *)(pEVar12[-1].final + 0x18);
            puVar3[-1] = *(undefined4 *)(pEVar12[-1].final + 0x1c);
            pEVar1 = (EVP_CIPHER_CTX *)pEVar12->iv;
            puVar2 = puVar3 + 8;
          } while (uVar11 < uVar6 - 7);
        }
        puVar4 = pEVar12[-1].final + 0x1c;
        do {
          puVar4 = puVar4 + 4;
          uVar7 = uVar7 + 1;
          *puVar3 = *(undefined4 *)puVar4;
          puVar3 = puVar3 + 1;
        } while (uVar7 < uVar6);
        if (uVar5 == uVar10) goto LAB_000af36e;
      }
      do {
        outm[uVar10] = ctx->final[uVar10];
        uVar10 = uVar10 + 1;
      } while ((int)uVar10 < (int)uVar5);
    }
LAB_000af36e:
    *outl = uVar5;
    return 1;
  }
  return 1;
}

