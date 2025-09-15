
size_t enc_read(BIO *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  size_t sVar2;
  size_t __n;
  size_t sVar3;
  void *pvVar4;
  size_t *outm;
  size_t __n_00;
  size_t *outl;
  bool bVar5;
  
  if (param_2 == (void *)0x0) {
    sVar2 = 0;
  }
  else {
    outl = (size_t *)param_1->ptr;
    if (outl == (size_t *)0x0) {
      sVar2 = 0;
    }
    else if (param_1->next_bio == (bio_st *)0x0) {
      sVar2 = 0;
    }
    else {
      if ((int)*outl < 1) {
        __n_00 = 0;
      }
      else {
        __n_00 = *outl - outl[1];
        if ((int)param_3 < (int)__n_00) {
          __n_00 = param_3;
        }
        param_3 = param_3 - __n_00;
        memcpy(param_2,(void *)(outl[1] + 0xa0 + (int)outl),__n_00);
        param_2 = (void *)((int)param_2 + __n_00);
        sVar2 = outl[1] + __n_00;
        bVar5 = sVar2 == *outl;
        outl[1] = sVar2;
        if (bVar5) {
          sVar2 = 0;
          *outl = 0;
        }
        if (bVar5) {
          outl[1] = sVar2;
        }
      }
      sVar2 = __n_00;
      if ((0 < (int)param_3) && (0 < (int)outl[2])) {
        outm = outl + 0x28;
        do {
          sVar2 = BIO_read(param_1->next_bio,outl + 0x38,0x1000);
          if ((int)sVar2 < 1) {
            iVar1 = BIO_test_flags(param_1->next_bio,8);
            if (iVar1 != 0) {
              if (__n_00 != 0) {
                BIO_clear_flags(param_1,0xf);
                BIO_copy_next_retry(param_1);
                return __n_00;
              }
              break;
            }
            outl[2] = sVar2;
            sVar2 = EVP_CipherFinal_ex((EVP_CIPHER_CTX *)(outl + 5),(uchar *)outm,(int *)outl);
            outl[4] = sVar2;
            outl[1] = 0;
            __n = *outl;
LAB_00104cfa:
            if ((int)param_3 < (int)__n) {
              sVar3 = 0;
              __n = param_3;
            }
            else {
              sVar2 = __n_00;
              if ((int)__n < 1) break;
              sVar3 = param_3 - __n;
            }
            __n_00 = __n_00 + __n;
            pvVar4 = (void *)((int)param_2 + __n);
            memcpy(param_2,outm,__n);
            outl[1] = __n;
          }
          else {
            EVP_CipherUpdate((EVP_CIPHER_CTX *)(outl + 5),(uchar *)outm,(int *)outl,
                             (uchar *)(outl + 0x38),sVar2);
            __n = *outl;
            outl[2] = 1;
            sVar3 = param_3;
            pvVar4 = param_2;
            if (__n != 0) goto LAB_00104cfa;
          }
          sVar2 = __n_00;
          if (((int)sVar3 < 1) || (param_3 = sVar3, param_2 = pvVar4, (int)outl[2] < 1)) break;
        } while( true );
      }
      BIO_clear_flags(param_1,0xf);
      BIO_copy_next_retry(param_1);
      if (sVar2 == 0) {
        sVar2 = outl[2];
      }
    }
  }
  return sVar2;
}

