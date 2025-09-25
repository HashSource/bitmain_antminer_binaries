
int EVP_DecryptFinal_ex(EVP_CIPHER_CTX *ctx,uchar *outm,int *outl)

{
  uint uVar1;
  uchar *puVar2;
  EVP_CIPHER *pEVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uchar *puVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  
  if (ctx->encrypt != 0) {
    ERR_put_error(6,0x65,0x94,"crypto/evp/evp_enc.c",0x23e);
    return 0;
  }
  pEVar3 = ctx->cipher;
  *outl = 0;
  iVar6 = 0;
  if ((int)(pEVar3->flags << 0xb) < 0) {
    iVar5 = (*pEVar3->do_cipher)(ctx,outm,(uchar *)0x0,0);
    if (-1 < iVar5) {
      *outl = iVar5;
      return 1;
    }
  }
  else {
    if ((int)(ctx->flags << 0x17) < 0) {
      if (ctx->buf_len != 0) {
        ERR_put_error(6,0x65,0x8a,"crypto/evp/evp_enc.c",0x251);
        return 0;
      }
    }
    else {
      uVar8 = pEVar3->block_size;
      if (1 < uVar8) {
        if ((ctx->buf_len != 0) || (ctx->final_used == 0)) {
          ERR_put_error(6,0x65,0x6d,"crypto/evp/evp_enc.c",0x259);
          return 0;
        }
        if (0x20 < uVar8) {
                    /* WARNING: Subroutine does not return */
          OPENSSL_die("assertion failed: b <= sizeof(ctx->final)","crypto/evp/evp_enc.c",0x25c);
        }
        uVar1 = (uint)ctx->final[uVar8 - 1];
        puVar2 = ctx->final + (uVar8 - 1);
        uVar4 = (uint)((int)uVar8 < (int)uVar1);
        if (uVar1 == 0) {
          uVar4 = 1;
        }
        if (uVar4 != 0) {
          ERR_put_error(6,0x65,100,"crypto/evp/evp_enc.c",0x264);
          return 0;
        }
        do {
          uVar4 = uVar4 + 1;
          if ((int)uVar1 <= (int)uVar4) {
            uVar8 = uVar8 - uVar1;
            if (0 < (int)uVar8) {
              bVar10 = outm <= ctx->final + 4;
              bVar9 = ctx->final + 4 == outm;
              if (bVar10 && !bVar9) {
                bVar10 = ctx->final <= outm + 4;
                bVar9 = outm + 4 == ctx->final;
              }
              if (((uint)outm & 3) != 0 || (uVar8 < 9 || bVar10 && !bVar9)) {
                puVar7 = outm + -1;
                puVar2 = (uchar *)((int)&ctx->block_mask + 3);
                do {
                  puVar2 = puVar2 + 1;
                  puVar7 = puVar7 + 1;
                  *puVar7 = *puVar2;
                } while (puVar2 != (uchar *)(uVar8 + 0x6b + (int)ctx));
              }
              else {
                uVar1 = uVar8 - 4 >> 2;
                *(undefined4 *)outm = *(undefined4 *)ctx->final;
                iVar5 = uVar1 + 1;
                iVar6 = uVar1 * 4;
                *(undefined4 *)(outm + 4) = *(undefined4 *)(ctx->final + 4);
                if ((((iVar5 != 2) &&
                     (*(undefined4 *)(outm + 8) = *(undefined4 *)(ctx->final + 8), iVar5 != 3)) &&
                    (*(undefined4 *)(outm + 0xc) = *(undefined4 *)(ctx->final + 0xc), iVar5 != 4))
                   && ((*(undefined4 *)(outm + 0x10) = *(undefined4 *)(ctx->final + 0x10),
                       iVar5 != 5 &&
                       (*(undefined4 *)(outm + 0x14) = *(undefined4 *)(ctx->final + 0x14),
                       iVar5 == 7)))) {
                  *(undefined4 *)(outm + 0x18) = *(undefined4 *)(ctx->final + 0x18);
                }
                if (uVar8 != iVar6 + 4U) {
                  outm[iVar5 * 4] = ctx->final[iVar6 + 4];
                  if (iVar6 + 5 < (int)uVar8) {
                    outm[iVar6 + 5] = ctx->final[iVar6 + 5];
                    if (iVar6 + 6 < (int)uVar8) {
                      outm[iVar6 + 6] = ctx->final[iVar6 + 6];
                    }
                  }
                }
              }
            }
            *outl = uVar8;
            return 1;
          }
          puVar2 = puVar2 + -1;
        } while (uVar1 == *puVar2);
        ERR_put_error(6,0x65,100,"crypto/evp/evp_enc.c",0x269);
        return 0;
      }
    }
    iVar6 = 1;
  }
  return iVar6;
}

