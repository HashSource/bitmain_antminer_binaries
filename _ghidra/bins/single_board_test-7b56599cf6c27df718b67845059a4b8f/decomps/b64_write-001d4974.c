
/* WARNING: Type propagation algorithm not settling */

uchar * b64_write(BIO *param_1,uchar *param_2,uchar *param_3)

{
  int *outl;
  BIO *b;
  int extraout_r0;
  uchar *puVar1;
  uchar *puVar2;
  int iVar3;
  uchar *local_38;
  int *local_30;
  
  outl = (int *)BIO_get_data();
  b = BIO_next(param_1);
  if (b != (BIO *)0x0 && outl != (int *)0x0) {
    BIO_clear_flags(param_1,0xf);
    if (outl[4] != 1) {
      *outl = 0;
      outl[1] = 0;
      outl[2] = 0;
      outl[4] = 1;
      EVP_EncodeInit((EVP_ENCODE_CTX *)outl[7]);
    }
    puVar1 = (uchar *)outl[1];
    if (0x5dd < (int)puVar1) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: ctx->buf_off < (int)sizeof(ctx->buf)","crypto/evp/bio_b64.c",
                  0x15f);
    }
    iVar3 = *outl;
    if (0x5de < iVar3) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: ctx->buf_len <= (int)sizeof(ctx->buf)","crypto/evp/bio_b64.c",
                  0x160);
    }
    if (iVar3 < (int)puVar1) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: ctx->buf_len >= ctx->buf_off","crypto/evp/bio_b64.c",0x161);
    }
    for (iVar3 = iVar3 - (int)puVar1; 0 < iVar3; iVar3 = iVar3 - (int)puVar2) {
      puVar2 = (uchar *)BIO_write(b,puVar1 + 0x20 + (int)outl,iVar3);
      if ((int)puVar2 < 1) {
        BIO_copy_next_retry(param_1);
        return puVar2;
      }
      if (iVar3 < (int)puVar2) {
                    /* WARNING: Subroutine does not return */
        OPENSSL_die("assertion failed: i <= n","crypto/evp/bio_b64.c",0x169);
      }
      puVar1 = puVar2 + outl[1];
      outl[1] = (int)puVar1;
      if (0x5de < (int)puVar1) {
                    /* WARNING: Subroutine does not return */
        OPENSSL_die("assertion failed: ctx->buf_off <= (int)sizeof(ctx->buf)","crypto/evp/bio_b64.c"
                    ,0x16b);
      }
      if (*outl < (int)puVar1) {
                    /* WARNING: Subroutine does not return */
        OPENSSL_die("assertion failed: ctx->buf_len >= ctx->buf_off","crypto/evp/bio_b64.c",0x16c);
      }
    }
    puVar1 = param_2;
    if (param_2 != (uchar *)0x0) {
      puVar1 = param_3;
    }
    outl[1] = 0;
    *outl = 0;
    if ((param_2 != (uchar *)0x0 && param_3 != (uchar *)0x0) && -1 < (int)puVar1) {
      local_38 = (uchar *)0x0;
      do {
        puVar1 = param_3;
        if (0x3ff < (int)param_3) {
          puVar1 = (uchar *)0x400;
        }
        iVar3 = BIO_test_flags(param_1,-1);
        if (iVar3 << 0x17 < 0) {
          iVar3 = outl[2];
          if (iVar3 < 1) {
            if ((int)puVar1 < 3) {
              memcpy((void *)((int)outl + 0x5fe),param_2,(size_t)puVar1);
              outl[2] = (int)puVar1;
              return local_38 + (int)puVar1;
            }
            puVar1 = (uchar *)(((int)puVar1 / 3) * 3);
            iVar3 = EVP_EncodeBlock((uchar *)(outl + 8),param_2,(int)puVar1);
            *outl = iVar3;
            if (0x5de < iVar3) {
                    /* WARNING: Subroutine does not return */
              OPENSSL_die("assertion failed: ctx->buf_len <= (int)sizeof(ctx->buf)",
                          "crypto/evp/bio_b64.c",0x19c);
            }
            if (iVar3 < outl[1]) {
                    /* WARNING: Subroutine does not return */
              OPENSSL_die("assertion failed: ctx->buf_len >= ctx->buf_off","crypto/evp/bio_b64.c",
                          0x19d);
            }
            local_38 = local_38 + (int)puVar1;
          }
          else {
            if (3 < iVar3) {
                    /* WARNING: Subroutine does not return */
              OPENSSL_die("assertion failed: ctx->tmp_len <= 3","crypto/evp/bio_b64.c",0x17b);
            }
            puVar1 = (uchar *)(3 - iVar3);
            if ((int)param_3 < (int)puVar1) {
              puVar1 = (uchar *)0x1;
            }
            memcpy((void *)((int)outl + iVar3 + 0x5fe),param_2,(size_t)puVar1);
            puVar2 = puVar1 + outl[2];
            local_38 = local_38 + (int)puVar1;
            outl[2] = (int)puVar2;
            if ((int)puVar2 < 3) {
              return local_38;
            }
            iVar3 = EVP_EncodeBlock((uchar *)(outl + 8),(uchar *)((int)outl + 0x5fe),(int)puVar2);
            *outl = iVar3;
            if (0x5de < iVar3) {
                    /* WARNING: Subroutine does not return */
              OPENSSL_die("assertion failed: ctx->buf_len <= (int)sizeof(ctx->buf)",
                          "crypto/evp/bio_b64.c",0x18a);
            }
            if (iVar3 < outl[1]) {
                    /* WARNING: Subroutine does not return */
              OPENSSL_die("assertion failed: ctx->buf_len >= ctx->buf_off","crypto/evp/bio_b64.c",
                          0x18b);
            }
            outl[2] = 0;
          }
        }
        else {
          EVP_EncodeUpdate((EVP_ENCODE_CTX *)outl[7],(uchar *)(outl + 8),outl,param_2,(int)puVar1);
          if (extraout_r0 == 0) {
            if (local_38 != (uchar *)0x0) {
              return local_38;
            }
            return (uchar *)0xffffffff;
          }
          iVar3 = *outl;
          if (0x5de < iVar3) {
                    /* WARNING: Subroutine does not return */
            OPENSSL_die("assertion failed: ctx->buf_len <= (int)sizeof(ctx->buf)",
                        "crypto/evp/bio_b64.c",0x1a5);
          }
          if (iVar3 < outl[1]) {
                    /* WARNING: Subroutine does not return */
            OPENSSL_die("assertion failed: ctx->buf_len >= ctx->buf_off","crypto/evp/bio_b64.c",
                        0x1a6);
          }
          local_38 = local_38 + (int)puVar1;
        }
        local_30 = outl + 8;
        param_2 = param_2 + (int)puVar1;
        outl[1] = 0;
        if (0 < iVar3) {
          while( true ) {
            puVar2 = (uchar *)BIO_write(b,local_30,iVar3);
            if ((int)puVar2 < 1) {
              BIO_copy_next_retry(param_1);
              if (local_38 == (uchar *)0x0) {
                local_38 = puVar2;
              }
              return local_38;
            }
            if (iVar3 < (int)puVar2) {
                    /* WARNING: Subroutine does not return */
              OPENSSL_die("assertion failed: i <= n","crypto/evp/bio_b64.c",0x1b4);
            }
            iVar3 = iVar3 - (int)puVar2;
            puVar2 = puVar2 + outl[1];
            outl[1] = (int)puVar2;
            if (0x5de < (int)puVar2) {
                    /* WARNING: Subroutine does not return */
              OPENSSL_die("assertion failed: ctx->buf_off <= (int)sizeof(ctx->buf)",
                          "crypto/evp/bio_b64.c",0x1b7);
            }
            if (*outl < (int)puVar2) {
                    /* WARNING: Subroutine does not return */
              OPENSSL_die("assertion failed: ctx->buf_len >= ctx->buf_off","crypto/evp/bio_b64.c",
                          0x1b8);
            }
            if (iVar3 < 1) break;
            local_30 = (int *)((int)outl + (int)(puVar2 + 0x20));
          }
        }
        param_3 = param_3 + -(int)puVar1;
        *outl = 0;
        outl[1] = 0;
        if ((int)param_3 < 1) {
          return local_38;
        }
      } while( true );
    }
  }
  return (uchar *)0x0;
}

