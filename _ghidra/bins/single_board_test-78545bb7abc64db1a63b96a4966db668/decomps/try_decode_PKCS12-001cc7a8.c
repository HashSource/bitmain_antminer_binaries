
undefined4
try_decode_PKCS12(X509 *param_1,undefined4 param_2,uchar *param_3,long param_4,int *param_5,
                 undefined4 *param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  PKCS12 *p12;
  size_t passlen;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *__s;
  uchar *local_43c [2];
  X509 *local_434;
  X509 *local_430;
  X509 *local_42c;
  undefined1 auStack_428 [1028];
  
  iVar5 = *param_5;
  local_43c[0] = param_3;
  if (iVar5 != 0) {
LAB_001cc7c0:
    *param_6 = 1;
    uVar1 = OPENSSL_sk_shift(iVar5);
    return uVar1;
  }
  if (param_1 != (X509 *)0x0) {
    return 0;
  }
  p12 = d2i_PKCS12((PKCS12 **)0x0,local_43c,param_4);
  if (p12 == (PKCS12 *)0x0) goto LAB_001cc88c;
  *param_6 = 1;
  local_434 = param_1;
  local_430 = param_1;
  local_42c = param_1;
  iVar5 = PKCS12_verify_mac(p12,"",0);
  if ((iVar5 == 0) && (iVar5 = PKCS12_verify_mac(p12,(char *)0x0,0), iVar5 == 0)) {
    __s = (char *)file_get_pass(param_7,auStack_428,0x400,"PKCS12 import password",param_8);
    if (__s == (char *)0x0) {
      ERR_put_error(0x2c,0x7a,0x72,"crypto/store/loader_file.c",0xe8);
LAB_001cc88c:
      PKCS12_free(p12);
      return 0;
    }
    passlen = strlen(__s);
    iVar5 = PKCS12_verify_mac(p12,__s,passlen);
    if (iVar5 == 0) {
      ERR_put_error(0x2c,0x7a,0x71,"crypto/store/loader_file.c",0xed);
      goto LAB_001cc88c;
    }
  }
  else {
    __s = "";
  }
  iVar5 = PKCS12_parse(p12,__s,(EVP_PKEY **)&local_434,&local_430,(stack_st_X509 **)&local_42c);
  if (iVar5 == 0) {
    PKCS12_free(p12);
    return 0;
  }
  iVar5 = OPENSSL_sk_new_null();
  if ((iVar5 == 0) || (iVar2 = OSSL_STORE_INFO_new_PKEY(local_434), iVar2 == 0)) {
LAB_001cc8fe:
    iVar3 = 0;
    iVar4 = 0;
    iVar2 = 0;
  }
  else {
    iVar3 = OPENSSL_sk_push(iVar5,iVar2);
    iVar4 = iVar3;
    if (iVar3 != 0) {
      iVar4 = OSSL_STORE_INFO_new_CERT(local_430);
      if (iVar4 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = OPENSSL_sk_push(iVar5,iVar4);
        if (iVar3 != 0) {
          while (iVar2 = OPENSSL_sk_num(local_42c), 0 < iVar2) {
            OPENSSL_sk_value(local_42c,0);
            iVar3 = OSSL_STORE_INFO_new_CERT();
            if (iVar3 == 0) goto LAB_001cc8fe;
            iVar2 = OPENSSL_sk_push(iVar5,iVar3);
            if (iVar2 == 0) {
              iVar4 = 0;
              iVar2 = 0;
              goto LAB_001cc8b6;
            }
            OPENSSL_sk_shift(local_42c);
          }
          *param_5 = iVar5;
          PKCS12_free(p12);
          goto LAB_001cc7c0;
        }
      }
    }
  }
LAB_001cc8b6:
  OSSL_STORE_INFO_free(iVar3);
  OSSL_STORE_INFO_free(iVar4);
  OSSL_STORE_INFO_free(iVar2);
  OPENSSL_sk_pop_free(iVar5,(undefined *)0x1cdc4d);
  EVP_PKEY_free((EVP_PKEY *)local_434);
  X509_free(local_430);
  OPENSSL_sk_pop_free(local_42c,(undefined *)0x178169);
  *param_5 = 0;
  PKCS12_free(p12);
  return 0;
}

