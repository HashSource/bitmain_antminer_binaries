
EVP_PKEY * ibm_4758_load_privkey(ENGINE *param_1,char *param_2)

{
  size_t __n;
  undefined4 *arg;
  RSA *r;
  BIGNUM *pBVar1;
  EVP_PKEY *pkey;
  int line;
  uint __n_00;
  undefined4 local_c50;
  undefined4 local_c4c;
  int local_c48;
  undefined1 auStack_c44 [4];
  undefined4 local_c40;
  undefined4 local_c3c;
  undefined1 auStack_c38 [8];
  undefined1 auStack_c30 [8];
  undefined1 auStack_c28 [64];
  uchar auStack_be8 [256];
  uchar auStack_ae8 [256];
  char local_9e8;
  char local_9e7;
  char local_9e0;
  char local_9df;
  undefined1 local_9da;
  undefined1 local_9d9;
  undefined1 local_9d6;
  undefined1 local_9d5;
  undefined1 auStack_9d4 [2484];
  
  local_c50 = 0x9c4;
  local_c4c = 0x9c4;
  local_c40 = 0;
  local_c3c = 0;
  __n = strlen(param_2);
  if (__n < 0x41) {
    memset(auStack_c28,0x20,0x40);
    memcpy(auStack_c28,param_2,__n);
    arg = (undefined4 *)CRYPTO_malloc(0x9c8,"e_4758cca.c",0x1ad);
    if (arg == (undefined4 *)0x0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CCA4758_lib_error_code,0x67,0x41,"e_4758cca.c",0x1af);
    }
    else {
      (*keyRecordRead)(&local_c48,auStack_c44,&local_c40,auStack_c38,&local_c3c,auStack_c30,
                       auStack_c28,&local_c4c,arg + 1);
      if (local_c48 == 0) {
        (*publicKeyExtract)(&local_c48,auStack_c44,&local_c40,auStack_c38,&local_c3c,auStack_c30,
                            &local_c4c,arg + 1,&local_c50,&local_9e8);
        if (local_c48 == 0) {
          if ((((local_9e8 == '\x1e') && (local_9e7 == '\0')) && (local_9e0 == '\x04')) &&
             (local_9df == '\0')) {
            __n_00 = (uint)CONCAT11(local_9da,local_9d9);
            memcpy(auStack_ae8,auStack_9d4,__n_00);
            memcpy(auStack_be8,auStack_9d4 + __n_00,(uint)CONCAT11(local_9d6,local_9d5));
            *arg = local_c4c;
            r = RSA_new_method(param_1);
            RSA_set_ex_data(r,hndidx,arg);
            pBVar1 = BN_bin2bn(auStack_ae8,__n_00,(BIGNUM *)0x0);
            r->e = pBVar1;
            pBVar1 = BN_bin2bn(auStack_be8,(uint)CONCAT11(local_9d6,local_9d5),(BIGNUM *)0x0);
            r->n = pBVar1;
            r->flags = r->flags | 0x20;
            pkey = EVP_PKEY_new();
            EVP_PKEY_assign(pkey,6,r);
            return pkey;
          }
          if (CCA4758_lib_error_code == 0) {
            CCA4758_lib_error_code = ERR_get_next_error_library();
          }
          line = 0x1cc;
        }
        else {
          if (CCA4758_lib_error_code == 0) {
            CCA4758_lib_error_code = ERR_get_next_error_library();
          }
          line = 0x1c4;
        }
      }
      else {
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = ERR_get_next_error_library();
        }
        line = 0x1b9;
      }
      ERR_put_error(CCA4758_lib_error_code,0x67,0x68,"e_4758cca.c",line);
      CRYPTO_free(arg);
    }
  }
  else {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CCA4758_lib_error_code,0x67,0x6b,"e_4758cca.c",0x1a6);
  }
  return (EVP_PKEY *)0x0;
}

