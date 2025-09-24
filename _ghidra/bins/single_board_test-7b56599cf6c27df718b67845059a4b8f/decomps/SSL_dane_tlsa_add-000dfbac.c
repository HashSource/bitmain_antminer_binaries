
undefined4
SSL_dane_tlsa_add(int param_1,uint param_2,uint param_3,X509 *param_4,uchar *param_5,size_t param_6)

{
  undefined1 *ptr;
  void *__dest;
  EVP_PKEY *pEVar1;
  byte *pbVar2;
  EVP_MD *md;
  size_t sVar3;
  X509 *pXVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uchar *local_2c;
  X509 *local_28;
  X509 *local_24;
  
  if (*(int *)(param_1 + 0x98) == 0) {
    ERR_put_error(0x14,0x18a,0xaf,"ssl/ssl_lib.c",0x12e);
    return 0xffffffff;
  }
  if ((int)param_6 < 0) {
    ERR_put_error(0x14,0x18a,0xbd,"ssl/ssl_lib.c",0x133);
    return 0;
  }
  if (3 < param_2) {
    ERR_put_error(0x14,0x18a,0xb8,"ssl/ssl_lib.c",0x138);
    return 0;
  }
  if (1 < param_3) {
    ERR_put_error(0x14,0x18a,0xca,"ssl/ssl_lib.c",0x13d);
    return 0;
  }
  if (param_4 != (X509 *)0x0) {
    if (((X509 *)(uint)*(byte *)(*(int **)(param_1 + 0x94) + 2) < param_4) ||
       (md = *(EVP_MD **)(**(int **)(param_1 + 0x94) + (int)param_4 * 4), md == (EVP_MD *)0x0)) {
      ERR_put_error(0x14,0x18a,200,"ssl/ssl_lib.c",0x144);
      return 0;
    }
    sVar3 = EVP_MD_size(md);
    if (param_6 != sVar3) {
      ERR_put_error(0x14,0x18a,0xc0,"ssl/ssl_lib.c",0x14a);
      return 0;
    }
  }
  if (param_5 == (uchar *)0x0) {
    ERR_put_error(0x14,0x18a,0xcb,"ssl/ssl_lib.c",0x14e);
    return 0;
  }
  ptr = (undefined1 *)CRYPTO_zalloc(0x10,"ssl/ssl_lib.c",0x152);
  iVar5 = 0x153;
  if (ptr != (undefined1 *)0x0) {
    *ptr = (char)param_2;
    ptr[1] = (char)param_3;
    ptr[2] = (char)param_4;
    __dest = CRYPTO_malloc(param_6,"ssl/ssl_lib.c",0x15a);
    *(void **)(ptr + 4) = __dest;
    if (__dest == (void *)0x0) {
      tlsa_free(ptr);
      iVar5 = 0x15d;
      goto LAB_000dfea8;
    }
    memcpy(__dest,param_5,param_6);
    *(size_t *)(ptr + 8) = param_6;
    if (param_4 == (X509 *)0x0) {
      local_2c = param_5;
      local_28 = param_4;
      local_24 = param_4;
      if (param_3 == 1) {
        pEVar1 = d2i_PUBKEY((EVP_PKEY **)&local_24,&local_2c,param_6);
        if (((pEVar1 == (EVP_PKEY *)0x0) || (local_2c < param_5)) ||
           (param_6 != (int)local_2c - (int)param_5)) {
          CRYPTO_free(*(void **)(ptr + 4));
          EVP_PKEY_free(*(EVP_PKEY **)(ptr + 0xc));
          CRYPTO_free(ptr);
          ERR_put_error(0x14,0x18a,0xc9,"ssl/ssl_lib.c",0x191);
          return 0;
        }
        if (param_2 == 2) {
          *(X509 **)(ptr + 0xc) = local_24;
        }
        else {
          EVP_PKEY_free((EVP_PKEY *)local_24);
        }
      }
      else {
        pXVar4 = d2i_X509(&local_28,&local_2c,param_6);
        if (((pXVar4 == (X509 *)0x0) || (local_2c < param_5)) ||
           (param_6 != (int)local_2c - (int)param_5)) {
          CRYPTO_free(*(void **)(ptr + 4));
          EVP_PKEY_free(*(EVP_PKEY **)(ptr + 0xc));
          CRYPTO_free(ptr);
          ERR_put_error(0x14,0x18a,0xb4,"ssl/ssl_lib.c",0x16e);
          return 0;
        }
        iVar5 = X509_get0_pubkey(local_28);
        if (iVar5 == 0) {
          tlsa_free(ptr);
          ERR_put_error(0x14,0x18a,0xb4,"ssl/ssl_lib.c",0x173);
          return 0;
        }
        if ((int)((5U >> (param_2 & 0xff)) << 0x1f) < 0) {
          iVar5 = *(int *)(param_1 + 0x9c);
          if (iVar5 == 0) {
            iVar5 = OPENSSL_sk_new_null();
            *(int *)(param_1 + 0x9c) = iVar5;
            if (iVar5 == 0) goto LAB_000dfdca;
          }
          iVar5 = OPENSSL_sk_push(iVar5,local_28);
          if (iVar5 == 0) {
LAB_000dfdca:
            ERR_put_error(0x14,0x18a,0x41,"ssl/ssl_lib.c",0x186);
            X509_free(local_28);
            tlsa_free(ptr);
            return 0xffffffff;
          }
        }
        else {
          X509_free(local_28);
        }
      }
    }
    iVar7 = 0;
    iVar5 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x98));
    if (0 < iVar5) {
      do {
        pbVar2 = (byte *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x98),iVar7);
        if ((*pbVar2 <= param_2) &&
           ((*pbVar2 < param_2 ||
            ((pbVar2[1] <= param_3 &&
             ((pbVar2[1] < param_3 ||
              (iVar6 = *(int *)(*(int *)(param_1 + 0x94) + 4),
              *(byte *)(iVar6 + (uint)pbVar2[2]) <= param_4->sha1_hash[iVar6 + -0x58])))))))) break;
        iVar7 = iVar7 + 1;
      } while (iVar5 != iVar7);
    }
    iVar5 = OPENSSL_sk_insert(*(undefined4 *)(param_1 + 0x98),ptr,iVar7);
    if (iVar5 != 0) {
      *(uint *)(param_1 + 0xa8) = 1 << (param_2 & 0xff) | *(uint *)(param_1 + 0xa8);
      return 1;
    }
    CRYPTO_free(*(void **)(ptr + 4));
    EVP_PKEY_free(*(EVP_PKEY **)(ptr + 0xc));
    CRYPTO_free(ptr);
    iVar5 = 0x1c3;
  }
LAB_000dfea8:
  ERR_put_error(0x14,0x18a,0x41,"ssl/ssl_lib.c",iVar5);
  return 0xffffffff;
}

