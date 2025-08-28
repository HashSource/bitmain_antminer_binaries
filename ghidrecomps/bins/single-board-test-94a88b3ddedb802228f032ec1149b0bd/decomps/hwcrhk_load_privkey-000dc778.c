
EVP_PKEY *
hwcrhk_load_privkey(ENGINE *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *arg;
  int iVar1;
  RSA *r;
  BIGNUM *pBVar2;
  EVP_PKEY *pkey;
  ulong *puVar3;
  uint uVar4;
  ulong *local_440;
  uint local_43c;
  ulong *local_438;
  uint local_434;
  undefined1 *local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  undefined1 auStack_420 [1024];
  
  local_430 = auStack_420;
  local_42c = 0x400;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x69,0x6a,"e_chil.c",0x316);
  }
  else {
    arg = (int *)CRYPTO_malloc(4,"e_chil.c",0x31a);
    if (arg == (int *)0x0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(HWCRHK_lib_error_code,0x69,0x41,"e_chil.c",0x31c);
    }
    else {
      local_428 = param_3;
      local_424 = param_4;
      iVar1 = (*p_hwcrhk_RSALoadKey)(hwcrhk_context,param_2,arg,&local_430,&local_428);
      if (iVar1 == 0) {
        if (*arg != 0) {
          r = RSA_new_method(param_1);
          RSA_set_ex_data(r,hndidx_rsa,arg);
          pBVar2 = BN_new();
          r->e = pBVar2;
          pBVar2 = BN_new();
          local_434 = pBVar2->dmax << 2;
          local_438 = pBVar2->d;
          iVar1 = r->e->dmax;
          local_440 = r->e->d;
          r->n = pBVar2;
          local_43c = iVar1 << 2;
          r->flags = r->flags | 0x20;
          iVar1 = (*p_hwcrhk_RSAGetPublicKey)(*arg,&local_438,&local_440,&local_430);
          if (iVar1 == -3) {
            bn_expand2(r->e,local_43c >> 2);
            bn_expand2(r->n,local_434 >> 2);
            local_440 = r->e->d;
            local_438 = r->n->d;
            local_43c = r->e->dmax << 2;
            local_434 = r->n->dmax << 2;
            iVar1 = (*p_hwcrhk_RSAGetPublicKey)(*arg,&local_438,&local_440,&local_430);
            if (iVar1 == 0) {
              pBVar2 = r->e;
              uVar4 = local_43c >> 2;
              pBVar2->top = uVar4;
              if (uVar4 != 0) {
                puVar3 = pBVar2->d + (uVar4 - 1);
                do {
                  if (*puVar3 != 0) break;
                  uVar4 = uVar4 - 1;
                  puVar3 = puVar3 + -1;
                } while (uVar4 != 0);
                pBVar2->top = uVar4;
              }
              pBVar2 = r->n;
              uVar4 = local_434 >> 2;
              pBVar2->top = uVar4;
              if (uVar4 != 0) {
                puVar3 = pBVar2->d + (uVar4 - 1);
                do {
                  if (*puVar3 != 0) break;
                  uVar4 = uVar4 - 1;
                  puVar3 = puVar3 + -1;
                } while (uVar4 != 0);
                pBVar2->top = uVar4;
              }
              pkey = EVP_PKEY_new();
              EVP_PKEY_assign(pkey,6,r);
              if (pkey != (EVP_PKEY *)0x0) {
                return pkey;
              }
              if (HWCRHK_lib_error_code == 0) {
                HWCRHK_lib_error_code = ERR_get_next_error_library();
              }
              ERR_put_error(HWCRHK_lib_error_code,0x69,0x6e,"e_chil.c",0x34f);
              return (EVP_PKEY *)0x0;
            }
            if (HWCRHK_lib_error_code == 0) {
              HWCRHK_lib_error_code = ERR_get_next_error_library();
            }
            iVar1 = 0x340;
          }
          else {
            if (HWCRHK_lib_error_code == 0) {
              HWCRHK_lib_error_code = ERR_get_next_error_library();
            }
            iVar1 = 0x335;
          }
          ERR_put_error(HWCRHK_lib_error_code,0x69,0x66,"e_chil.c",iVar1);
          ERR_add_error_data(1,local_430);
          RSA_free(r);
          return (EVP_PKEY *)0x0;
        }
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x69,0x6d,"e_chil.c",0x327);
      }
      else {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x69,0x66,"e_chil.c",0x322);
        ERR_add_error_data(1,local_430);
      }
    }
  }
  return (EVP_PKEY *)0x0;
}

