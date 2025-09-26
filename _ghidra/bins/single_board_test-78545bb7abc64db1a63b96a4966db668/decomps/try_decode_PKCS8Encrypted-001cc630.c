
int try_decode_PKCS8Encrypted
              (char *param_1,undefined4 param_2,uchar *param_3,long param_4,undefined4 param_5,
              undefined4 *param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  X509_SIG *a;
  BUF_MEM *a_00;
  char *__s;
  size_t passlen;
  uchar *puVar2;
  uchar *local_434;
  X509_ALGOR *local_430;
  int *local_42c;
  uchar *local_428;
  size_t local_424;
  undefined1 auStack_420 [1024];
  
  local_430 = (X509_ALGOR *)0x0;
  local_42c = (int *)0x0;
  local_428 = (uchar *)0x0;
  local_434 = param_3;
  if (param_1 != (char *)0x0) {
    iVar1 = strcmp(param_1,"ENCRYPTED PRIVATE KEY");
    if (iVar1 != 0) {
      return 0;
    }
    *param_6 = 1;
  }
  a = d2i_X509_SIG((X509_SIG **)0x0,&local_434,param_4);
  if (a != (X509_SIG *)0x0) {
    *param_6 = 1;
    a_00 = BUF_MEM_new();
    if (a_00 == (BUF_MEM *)0x0) {
      ERR_put_error(0x2c,0x7d,0x41,"crypto/store/loader_file.c",0x162);
    }
    else {
      __s = (char *)file_get_pass(param_7,auStack_420,0x400,"PKCS8 decrypt password",param_8);
      if (__s == (char *)0x0) {
        ERR_put_error(0x2c,0x7d,0x73,"crypto/store/loader_file.c",0x169);
      }
      else {
        X509_SIG_get0(a,&local_430,&local_42c);
        passlen = strlen(__s);
        puVar2 = PKCS12_pbe_crypt(local_430,__s,passlen,(uchar *)local_42c[2],*local_42c,&local_428,
                                  (int *)&local_424,0);
        if (puVar2 != (uchar *)0x0) {
          a_00->data = (char *)local_428;
          a_00->length = local_424;
          a_00->max = local_424;
          X509_SIG_free(a);
          iVar1 = ossl_store_info_new_EMBEDDED("PRIVATE KEY",a_00);
          if (iVar1 != 0) {
            return iVar1;
          }
          ERR_put_error(0x2c,0x7d,0x41,"crypto/store/loader_file.c",0x17a);
          a = (X509_SIG *)0x0;
        }
      }
    }
    X509_SIG_free(a);
    BUF_MEM_free(a_00);
  }
  return 0;
}

