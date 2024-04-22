
EVP_PKEY * ibm_4758_load_privkey(ENGINE *param_1,char *param_2)

{
  size_t __n;
  undefined4 *arg;
  int lib;
  int iVar1;
  RSA *r;
  BIGNUM *pBVar2;
  EVP_PKEY *pkey;
  int iVar3;
  uint __n_00;
  undefined4 local_c50;
  undefined4 local_c4c;
  int local_c48;
  undefined auStack_c44 [4];
  undefined4 local_c40;
  undefined4 local_c3c;
  undefined auStack_c38 [8];
  undefined auStack_c30 [8];
  undefined auStack_c28 [64];
  uchar auStack_be8 [256];
  uchar auStack_ae8 [256];
  char local_9e8;
  char local_9e7;
  char local_9e0;
  char local_9df;
  undefined local_9da;
  undefined local_9d9;
  undefined local_9d6;
  undefined local_9d5;
  undefined auStack_9d4 [2484];
  
  local_c50 = 0x9c4;
  local_c4c = 0x9c4;
  local_c40 = 0;
  local_c3c = 0;
  __n = strlen(param_2);
  iVar3 = DAT_000d91e4;
  if (__n < 0x41) {
    memset(auStack_c28,0x20,0x40);
    memcpy(auStack_c28,param_2,__n);
    arg = (undefined4 *)CRYPTO_malloc(0x9c8,DAT_000d91e0,0x1ad);
    iVar3 = DAT_000d91e4;
    if (arg == (undefined4 *)0x0) {
      iVar1 = *(int *)(DAT_000d91e4 + 0xc);
      if (iVar1 == 0) {
        iVar1 = ERR_get_next_error_library();
        *(int *)(iVar3 + 0xc) = iVar1;
      }
      ERR_put_error(iVar1,0x67,0x41,DAT_000d91e0,0x1af);
    }
    else {
      (**(code **)(DAT_000d91e4 + 0x18))
                (&local_c48,auStack_c44,&local_c40,auStack_c38,&local_c3c,auStack_c30,auStack_c28,
                 &local_c4c,arg + 1);
      if (local_c48 == 0) {
        (**(code **)(iVar3 + 0x24))
                  (&local_c48,auStack_c44,&local_c40,auStack_c38,&local_c3c,auStack_c30,&local_c4c,
                   arg + 1,&local_c50,&local_9e8);
        iVar1 = DAT_000d91e4;
        if (local_c48 == 0) {
          if ((((local_9e8 == '\x1e') && (local_9e7 == '\0')) && (local_9e0 == '\x04')) &&
             (local_9df == '\0')) {
            __n_00 = (uint)CONCAT11(local_9da,local_9d9);
            memcpy(auStack_ae8,auStack_9d4,__n_00);
            memcpy(auStack_be8,auStack_9d4 + __n_00,(uint)CONCAT11(local_9d6,local_9d5));
            *arg = local_c4c;
            r = RSA_new_method(param_1);
            RSA_set_ex_data(r,*DAT_000d91e8,arg);
            pBVar2 = BN_bin2bn(auStack_ae8,__n_00,(BIGNUM *)0x0);
            r->e = pBVar2;
            pBVar2 = BN_bin2bn(auStack_be8,(uint)CONCAT11(local_9d6,local_9d5),(BIGNUM *)0x0);
            r->n = pBVar2;
            r->flags = r->flags | 0x20;
            pkey = EVP_PKEY_new();
            EVP_PKEY_assign(pkey,6,r);
            return pkey;
          }
          lib = *(int *)(iVar3 + 0xc);
          if (lib == 0) {
            lib = ERR_get_next_error_library();
            *(int *)(iVar1 + 0xc) = lib;
          }
          iVar3 = 0x1cc;
        }
        else {
          lib = *(int *)(iVar3 + 0xc);
          if (lib == 0) {
            lib = ERR_get_next_error_library();
            *(int *)(iVar3 + 0xc) = lib;
          }
          iVar3 = 0x1c4;
        }
      }
      else {
        lib = *(int *)(iVar3 + 0xc);
        if (lib == 0) {
          lib = ERR_get_next_error_library();
          *(int *)(iVar3 + 0xc) = lib;
        }
        iVar3 = 0x1b9;
      }
      ERR_put_error(lib,0x67,0x68,DAT_000d91e0,iVar3);
      CRYPTO_free(arg);
    }
  }
  else {
    iVar1 = *(int *)(DAT_000d91e4 + 0xc);
    if (iVar1 == 0) {
      iVar1 = ERR_get_next_error_library();
      *(int *)(iVar3 + 0xc) = iVar1;
    }
    ERR_put_error(iVar1,0x67,0x6b,DAT_000d91e0,0x1a6);
  }
  return (EVP_PKEY *)0x0;
}

