
EVP_PKEY * ibm_4758_load_pubkey(ENGINE *param_1,char *param_2)

{
  size_t __n;
  undefined4 *arg;
  int iVar1;
  int iVar2;
  RSA *r;
  BIGNUM *pBVar3;
  EVP_PKEY *pkey;
  uint __n_00;
  uint __n_01;
  undefined4 local_484;
  int local_480;
  undefined auStack_47c [4];
  undefined4 local_478;
  undefined4 local_474;
  undefined auStack_470 [8];
  undefined auStack_468 [8];
  undefined auStack_460 [64];
  uchar auStack_420 [512];
  uchar auStack_220 [516];
  
  local_484 = 0x9c4;
  local_478 = 0;
  local_474 = 0;
  __n = strlen(param_2);
  iVar1 = DAT_000d8b70;
  if (__n < 0x41) {
    memset(auStack_460,0x20,0x40);
    memcpy(auStack_460,param_2,__n);
    arg = (undefined4 *)CRYPTO_malloc(0x9c8,DAT_000d8b6c,0x201);
    iVar1 = DAT_000d8b70;
    if (arg == (undefined4 *)0x0) {
      iVar2 = *(int *)(DAT_000d8b70 + 0xc);
      if (iVar2 == 0) {
        iVar2 = ERR_get_next_error_library();
        *(int *)(iVar1 + 0xc) = iVar2;
      }
      ERR_put_error(iVar2,0x68,0x41,DAT_000d8b6c,0x203);
    }
    else {
      (**(code **)(DAT_000d8b70 + 0x18))
                (&local_480,auStack_47c,&local_478,auStack_470,&local_474,auStack_468,auStack_460,
                 &local_484,arg + 1);
      iVar2 = DAT_000d8b70;
      if (local_480 == 0) {
        if ((((*(char *)(arg + 1) == '\x1e') && (*(char *)((int)arg + 5) == '\0')) &&
            (*(char *)(arg + 3) == '\x04')) && (*(char *)((int)arg + 0xd) == '\0')) {
          __n_00 = (uint)CONCAT11(*(undefined *)((int)arg + 0x12),*(undefined *)((int)arg + 0x13));
          __n_01 = (uint)CONCAT11(*(undefined *)((int)arg + 0x16),*(undefined *)((int)arg + 0x17));
          memcpy(auStack_220,arg + 6,__n_00);
          memcpy(auStack_420,(void *)((int)(arg + 6) + __n_00),__n_01);
          *arg = local_484;
          r = RSA_new_method(param_1);
          RSA_set_ex_data(r,*DAT_000d8b74,arg);
          pBVar3 = BN_bin2bn(auStack_220,__n_00,(BIGNUM *)0x0);
          r->e = pBVar3;
          pBVar3 = BN_bin2bn(auStack_420,__n_01,(BIGNUM *)0x0);
          r->n = pBVar3;
          r->flags = r->flags | 0x20;
          pkey = EVP_PKEY_new();
          EVP_PKEY_assign(pkey,6,r);
          return pkey;
        }
        iVar1 = *(int *)(iVar1 + 0xc);
        if (iVar1 == 0) {
          iVar1 = ERR_get_next_error_library();
          *(int *)(iVar2 + 0xc) = iVar1;
        }
        ERR_put_error(iVar1,0x68,0x69,DAT_000d8b6c,0x214);
      }
      else {
        iVar2 = *(int *)(iVar1 + 0xc);
        if (iVar2 == 0) {
          iVar2 = ERR_get_next_error_library();
          *(int *)(iVar1 + 0xc) = iVar2;
        }
        ERR_put_error(iVar2,0x68,0x41,DAT_000d8b6c,0x20c);
      }
      CRYPTO_free(arg);
    }
  }
  else {
    iVar2 = *(int *)(DAT_000d8b70 + 0xc);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar1 + 0xc) = iVar2;
    }
    ERR_put_error(iVar2,0x68,0x6b,DAT_000d8b6c,0x1fa);
  }
  return (EVP_PKEY *)0x0;
}

