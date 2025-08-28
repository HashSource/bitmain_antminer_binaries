
EVP_PKEY * ibm_4758_load_pubkey(ENGINE *param_1,char *param_2)

{
  size_t __n;
  undefined4 *arg;
  RSA *r;
  BIGNUM *pBVar1;
  EVP_PKEY *pkey;
  uint __n_00;
  uint __n_01;
  undefined4 local_484;
  int local_480;
  undefined1 auStack_47c [4];
  undefined4 local_478;
  undefined4 local_474;
  undefined1 auStack_470 [8];
  undefined1 auStack_468 [8];
  undefined1 auStack_460 [64];
  uchar auStack_420 [512];
  uchar auStack_220 [516];
  
  local_484 = 0x9c4;
  local_478 = 0;
  local_474 = 0;
  __n = strlen(param_2);
  if (__n < 0x41) {
    memset(auStack_460,0x20,0x40);
    memcpy(auStack_460,param_2,__n);
    arg = (undefined4 *)CRYPTO_malloc(0x9c8,"e_4758cca.c",0x201);
    if (arg == (undefined4 *)0x0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CCA4758_lib_error_code,0x68,0x41,"e_4758cca.c",0x203);
    }
    else {
      (*keyRecordRead)(&local_480,auStack_47c,&local_478,auStack_470,&local_474,auStack_468,
                       auStack_460,&local_484,arg + 1);
      if (local_480 == 0) {
        if ((((*(char *)(arg + 1) == '\x1e') && (*(char *)((int)arg + 5) == '\0')) &&
            (*(char *)(arg + 3) == '\x04')) && (*(char *)((int)arg + 0xd) == '\0')) {
          __n_00 = (uint)CONCAT11(*(undefined1 *)((int)arg + 0x12),*(undefined1 *)((int)arg + 0x13))
          ;
          __n_01 = (uint)CONCAT11(*(undefined1 *)((int)arg + 0x16),*(undefined1 *)((int)arg + 0x17))
          ;
          memcpy(auStack_220,arg + 6,__n_00);
          memcpy(auStack_420,(void *)((int)(arg + 6) + __n_00),__n_01);
          *arg = local_484;
          r = RSA_new_method(param_1);
          RSA_set_ex_data(r,hndidx,arg);
          pBVar1 = BN_bin2bn(auStack_220,__n_00,(BIGNUM *)0x0);
          r->e = pBVar1;
          pBVar1 = BN_bin2bn(auStack_420,__n_01,(BIGNUM *)0x0);
          r->n = pBVar1;
          r->flags = r->flags | 0x20;
          pkey = EVP_PKEY_new();
          EVP_PKEY_assign(pkey,6,r);
          return pkey;
        }
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CCA4758_lib_error_code,0x68,0x69,"e_4758cca.c",0x214);
      }
      else {
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CCA4758_lib_error_code,0x68,0x41,"e_4758cca.c",0x20c);
      }
      CRYPTO_free(arg);
    }
  }
  else {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CCA4758_lib_error_code,0x68,0x6b,"e_4758cca.c",0x1fa);
  }
  return (EVP_PKEY *)0x0;
}

