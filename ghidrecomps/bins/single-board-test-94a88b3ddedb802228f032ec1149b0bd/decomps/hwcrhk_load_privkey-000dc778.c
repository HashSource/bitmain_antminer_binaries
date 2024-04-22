
EVP_PKEY *
hwcrhk_load_privkey(ENGINE *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *arg;
  int iVar1;
  RSA *r;
  BIGNUM *pBVar2;
  EVP_PKEY *pkey;
  ulong *puVar3;
  int iVar4;
  uint uVar5;
  ulong *local_440;
  uint local_43c;
  ulong *local_438;
  uint local_434;
  undefined *local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  undefined auStack_420 [1024];
  
  iVar4 = DAT_000dc9b4;
  local_430 = auStack_420;
  local_42c = 0x400;
  if (*(int *)(DAT_000dc9b4 + 0x14) == 0) {
    iVar1 = *(int *)(DAT_000dc9b4 + 0x1c);
    if (iVar1 == 0) {
      iVar1 = ERR_get_next_error_library();
      *(int *)(iVar4 + 0x1c) = iVar1;
    }
    ERR_put_error(iVar1,0x69,0x6a,DAT_000dc9b8,0x316);
  }
  else {
    arg = (int *)CRYPTO_malloc(4,DAT_000dc9b8,0x31a);
    if (arg == (int *)0x0) {
      iVar1 = *(int *)(iVar4 + 0x1c);
      if (iVar1 == 0) {
        iVar1 = ERR_get_next_error_library();
        *(int *)(iVar4 + 0x1c) = iVar1;
      }
      ERR_put_error(iVar1,0x69,0x41,DAT_000dc9b8,0x31c);
    }
    else {
      local_428 = param_3;
      local_424 = param_4;
      iVar1 = (**(code **)(iVar4 + 0x30))
                        (*(undefined4 *)(iVar4 + 0x14),param_2,arg,&local_430,&local_428);
      if (iVar1 == 0) {
        if (*arg != 0) {
          r = RSA_new_method(param_1);
          RSA_set_ex_data(r,*DAT_000dc9bc,arg);
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
          iVar1 = (**(code **)(iVar4 + 0x34))(*arg,&local_438,&local_440,&local_430);
          if (iVar1 == -3) {
            bn_expand2(r->e,local_43c >> 2);
            bn_expand2(r->n,local_434 >> 2);
            local_440 = r->e->d;
            local_438 = r->n->d;
            local_43c = r->e->dmax << 2;
            local_434 = r->n->dmax << 2;
            iVar1 = (**(code **)(iVar4 + 0x34))(*arg,&local_438,&local_440,&local_430);
            if (iVar1 == 0) {
              pBVar2 = r->e;
              uVar5 = local_43c >> 2;
              pBVar2->top = uVar5;
              if (uVar5 != 0) {
                puVar3 = pBVar2->d + (uVar5 - 1);
                do {
                  if (*puVar3 != 0) break;
                  uVar5 = uVar5 - 1;
                  puVar3 = puVar3 + -1;
                } while (uVar5 != 0);
                pBVar2->top = uVar5;
              }
              pBVar2 = r->n;
              uVar5 = local_434 >> 2;
              pBVar2->top = uVar5;
              if (uVar5 != 0) {
                puVar3 = pBVar2->d + (uVar5 - 1);
                do {
                  if (*puVar3 != 0) break;
                  uVar5 = uVar5 - 1;
                  puVar3 = puVar3 + -1;
                } while (uVar5 != 0);
                pBVar2->top = uVar5;
              }
              pkey = EVP_PKEY_new();
              EVP_PKEY_assign(pkey,6,r);
              iVar1 = DAT_000dc9b4;
              if (pkey != (EVP_PKEY *)0x0) {
                return pkey;
              }
              iVar4 = *(int *)(iVar4 + 0x1c);
              if (iVar4 == 0) {
                iVar4 = ERR_get_next_error_library();
                *(int *)(iVar1 + 0x1c) = iVar4;
              }
              ERR_put_error(iVar4,0x69,0x6e,DAT_000dc9b8,0x34f);
              return (EVP_PKEY *)0x0;
            }
            iVar1 = *(int *)(iVar4 + 0x1c);
            if (iVar1 == 0) {
              iVar1 = ERR_get_next_error_library();
              *(int *)(iVar4 + 0x1c) = iVar1;
            }
            iVar4 = 0x340;
          }
          else {
            iVar1 = *(int *)(iVar4 + 0x1c);
            if (iVar1 == 0) {
              iVar1 = ERR_get_next_error_library();
              *(int *)(iVar4 + 0x1c) = iVar1;
            }
            iVar4 = 0x335;
          }
          ERR_put_error(iVar1,0x69,0x66,DAT_000dc9b8,iVar4);
          ERR_add_error_data(1,local_430);
          RSA_free(r);
          return (EVP_PKEY *)0x0;
        }
        iVar1 = *(int *)(iVar4 + 0x1c);
        if (iVar1 == 0) {
          iVar1 = ERR_get_next_error_library();
          *(int *)(iVar4 + 0x1c) = iVar1;
        }
        ERR_put_error(iVar1,0x69,0x6d,DAT_000dc9b8,0x327);
      }
      else {
        iVar1 = *(int *)(iVar4 + 0x1c);
        if (iVar1 == 0) {
          iVar1 = ERR_get_next_error_library();
          *(int *)(iVar4 + 0x1c) = iVar1;
        }
        ERR_put_error(iVar1,0x69,0x66,DAT_000dc9b8,0x322);
        ERR_add_error_data(1,local_430);
      }
    }
  }
  return (EVP_PKEY *)0x0;
}

