
size_t enc_read(BIO *param_1,uchar *param_2,size_t param_3)

{
  size_t *outl;
  BIO *b;
  int iVar1;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  uchar *in;
  size_t *data;
  size_t __n;
  uchar *puVar5;
  size_t *out;
  size_t sVar6;
  int local_2c [2];
  
  if (param_2 != (uchar *)0x0) {
    outl = (size_t *)BIO_get_data();
    b = BIO_next(param_1);
    if (b != (BIO *)0x0 && outl != (size_t *)0x0) {
      __n = 0;
      if (0 < (int)*outl) {
        __n = *outl - outl[1];
        if ((int)param_3 <= (int)__n) {
          __n = param_3;
        }
        param_3 = param_3 - __n;
        memcpy(param_2,(void *)(outl[1] + 0x20 + (int)outl),__n);
        param_2 = param_2 + __n;
        sVar3 = *outl;
        sVar4 = outl[1] + __n;
        outl[1] = sVar4;
        if (sVar4 == sVar3) {
          *outl = 0;
        }
        if (sVar4 == sVar3) {
          outl[1] = 0;
        }
      }
      iVar1 = EVP_CIPHER_CTX_block_size((EVP_CIPHER_CTX *)outl[5]);
      if (iVar1 == 1) {
        iVar1 = 0;
      }
      sVar3 = __n;
      if ((0 < (int)param_3) && (0 < (int)outl[2])) {
        in = (uchar *)outl[6];
        out = outl + 8;
        do {
          puVar5 = (uchar *)outl[7];
          if (puVar5 == in) goto LAB_001bd69a;
LAB_001bd5e6:
          sVar3 = (int)puVar5 - (int)in;
          puVar5 = param_2;
          if ((int)sVar3 < 1) goto LAB_001bd64a;
          if (0x100 < (int)param_3) goto LAB_001bd6c0;
LAB_001bd5f2:
          if (0xff < (int)sVar3) {
            sVar3 = 0x100;
          }
          iVar2 = EVP_CipherUpdate((EVP_CIPHER_CTX *)outl[5],(uchar *)out,(int *)outl,in,sVar3);
          if (iVar2 == 0) {
            BIO_clear_flags(param_1,0xf);
            outl[4] = 0;
            return 0;
          }
          sVar4 = *outl;
          outl[2] = 1;
          in = (uchar *)(outl[6] + sVar3);
          outl[6] = (size_t)in;
          puVar5 = param_2;
          sVar3 = __n;
          if (sVar4 != 0) {
            while( true ) {
              if ((int)param_3 <= (int)sVar4) {
                sVar4 = param_3;
              }
              if ((int)sVar4 < 1) goto LAB_001bd61e;
              param_3 = param_3 - sVar4;
              param_2 = puVar5 + sVar4;
              memcpy(puVar5,out,sVar4);
              outl[1] = sVar4;
              sVar3 = sVar3 + sVar4;
              while( true ) {
                if (((int)param_3 < 1) || ((int)outl[2] < 1)) goto LAB_001bd61e;
                in = (uchar *)outl[6];
                puVar5 = (uchar *)outl[7];
                __n = sVar3;
                if (puVar5 != in) goto LAB_001bd5e6;
LAB_001bd69a:
                data = outl + 0x50;
                outl[6] = (size_t)data;
                outl[7] = (size_t)data;
                sVar3 = BIO_read(b,data,0x1000);
                puVar5 = param_2;
                if ((int)sVar3 < 1) break;
                in = (uchar *)outl[6];
                outl[7] = outl[7] + sVar3;
                if ((int)param_3 < 0x101) goto LAB_001bd5f2;
LAB_001bd6c0:
                sVar6 = param_3 - iVar1;
                sVar4 = sVar6;
                if ((int)sVar3 <= (int)sVar6) {
                  sVar4 = sVar3;
                }
                iVar2 = EVP_CipherUpdate((EVP_CIPHER_CTX *)outl[5],param_2,local_2c,in,sVar4);
                if (iVar2 == 0) {
                  BIO_clear_flags(param_1,0xf);
                  return 0;
                }
                sVar3 = sVar3 - sVar6;
                __n = __n + local_2c[0];
                param_2 = param_2 + local_2c[0];
                param_3 = param_3 - local_2c[0];
                if (0 < (int)sVar3) {
                  in = (uchar *)(outl[6] + sVar6);
                  outl[6] = (size_t)in;
                  goto LAB_001bd5f2;
                }
                outl[6] = outl[7];
                sVar3 = __n;
              }
LAB_001bd64a:
              iVar2 = BIO_test_flags(b,8);
              if (iVar2 != 0) break;
              outl[2] = sVar3;
              sVar3 = EVP_CipherFinal_ex((EVP_CIPHER_CTX *)outl[5],(uchar *)out,(int *)outl);
              sVar4 = *outl;
              outl[1] = 0;
              outl[4] = sVar3;
              sVar3 = __n;
            }
            if (__n != 0) {
              BIO_clear_flags(param_1,0xf);
              BIO_copy_next_retry(param_1);
              return __n;
            }
            break;
          }
        } while (0 < (int)param_3);
      }
LAB_001bd61e:
      BIO_clear_flags(param_1,0xf);
      BIO_copy_next_retry(param_1);
      if (sVar3 != 0) {
        return sVar3;
      }
      return outl[2];
    }
  }
  return 0;
}

