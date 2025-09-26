
int EVP_DecryptFinal(EVP_CIPHER_CTX *ctx,uchar *outm,int *outl)

{
  EVP_CIPHER_CTX *pEVar1;
  uchar *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  EVP_CIPHER *pEVar7;
  uint uVar8;
  uint uVar9;
  EVP_CIPHER_CTX *pEVar10;
  uchar *puVar11;
  
  pEVar7 = ctx->cipher;
  *outl = 0;
  if ((pEVar7->flags & 0x100000) != 0) {
    iVar6 = (*pEVar7->do_cipher)(ctx,outm,(uchar *)0x0,0);
    if (iVar6 < 0) {
      return 0;
    }
    *outl = iVar6;
    return 1;
  }
  uVar8 = pEVar7->block_size;
  if ((int)(ctx->flags << 0x17) < 0) {
    if (ctx->buf_len != 0) {
      ERR_put_error(6,0x65,0x8a,"evp_enc.c",0x1fe);
      return 0;
    }
  }
  else if (1 < uVar8) {
    if ((ctx->buf_len != 0) || (ctx->final_used == 0)) {
      ERR_put_error(6,0x65,0x6d,"evp_enc.c",0x206);
      return 0;
    }
    if (0x20 < uVar8) {
      OpenSSLDie("evp_enc.c",0x209,"b <= sizeof ctx->final");
    }
    uVar3 = (uint)ctx->final[uVar8 - 1];
    puVar2 = ctx->final + uVar8;
    uVar4 = 1 - uVar3;
    if (1 < uVar3) {
      uVar4 = 0;
    }
    if ((int)uVar8 < (int)uVar3) {
      uVar4 = uVar4 | 1;
    }
    if (uVar4 != 0) {
      iVar6 = 0x211;
LAB_00150016:
      ERR_put_error(6,0x65,100,"evp_enc.c",iVar6);
      return 0;
    }
    do {
      puVar2 = puVar2 + -1;
      uVar4 = uVar4 + 1;
      if (*puVar2 != uVar3) {
        iVar6 = 0x216;
        goto LAB_00150016;
      }
    } while ((int)uVar4 < (int)uVar3);
    uVar3 = ctx->cipher->block_size - uVar3;
    if (0 < (int)uVar3) {
      pEVar10 = (EVP_CIPHER_CTX *)ctx->final;
      uVar4 = uVar3 >> 2;
      uVar8 = uVar4 << 2;
      if (uVar4 == 0 ||
          (outm < ctx->final + 4 && pEVar10 < outm + 4 || (uVar3 < 4 || ((uint)outm & 3) != 0))) {
        uVar8 = 0;
      }
      else {
        if (uVar4 < 9) {
          uVar5 = 0;
          puVar2 = outm;
        }
        else {
          uVar5 = 0;
          pEVar1 = ctx + 1;
          puVar11 = outm + 0x20;
          do {
            puVar2 = puVar11;
            pEVar10 = pEVar1;
            uVar9 = uVar5 + 9;
            uVar5 = uVar5 + 8;
            HintPreloadData(&pEVar10->app_data);
            *(undefined4 *)(puVar2 + -0x20) = *(undefined4 *)pEVar10[-1].final;
            *(undefined4 *)(puVar2 + -0x1c) = *(undefined4 *)(pEVar10[-1].final + 4);
            *(undefined4 *)(puVar2 + -0x18) = *(undefined4 *)(pEVar10[-1].final + 8);
            *(undefined4 *)(puVar2 + -0x14) = *(undefined4 *)(pEVar10[-1].final + 0xc);
            *(undefined4 *)(puVar2 + -0x10) = *(undefined4 *)(pEVar10[-1].final + 0x10);
            *(undefined4 *)(puVar2 + -0xc) = *(undefined4 *)(pEVar10[-1].final + 0x14);
            *(undefined4 *)(puVar2 + -8) = *(undefined4 *)(pEVar10[-1].final + 0x18);
            *(undefined4 *)(puVar2 + -4) = *(undefined4 *)(pEVar10[-1].final + 0x1c);
            pEVar1 = (EVP_CIPHER_CTX *)pEVar10->iv;
            puVar11 = puVar2 + 0x20;
          } while (uVar9 < uVar4 - 7);
        }
        puVar11 = pEVar10[-1].final + 0x1c;
        do {
          puVar11 = puVar11 + 4;
          uVar5 = uVar5 + 1;
          *(undefined4 *)puVar2 = *(undefined4 *)puVar11;
          puVar2 = puVar2 + 4;
        } while (uVar5 < uVar4);
        if (uVar3 == uVar8) goto LAB_0014ffca;
      }
      do {
        outm[uVar8] = ctx->final[uVar8];
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)uVar3);
    }
LAB_0014ffca:
    *outl = uVar3;
    return 1;
  }
  return 1;
}

