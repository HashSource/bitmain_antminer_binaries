
int EVP_PKEY_derive_set_peer(EVP_PKEY_CTX *ctx,EVP_PKEY *peer)

{
  int iVar1;
  int iVar2;
  EVP_PKEY *pEVar3;
  
  if ((((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
      ((*(int *)(iVar1 + 0x60) == 0 &&
       ((*(int *)(iVar1 + 0x50) == 0 && (*(int *)(iVar1 + 0x58) == 0)))))) ||
     (*(code **)(iVar1 + 100) == (code *)0x0)) {
    ERR_put_error(6,0x9b,0x96,DAT_000b44c8,0x114);
    iVar1 = -2;
  }
  else {
    iVar2 = *(int *)(ctx + 0x10);
    if ((iVar2 == 0x100 || iVar2 == 0x400) || (iVar2 == 0x200)) {
      iVar1 = (**(code **)(iVar1 + 100))(ctx,2,0,peer);
      if (0 < iVar1) {
        if (iVar1 == 2) {
          iVar1 = 1;
        }
        else if (*(int **)(ctx + 8) == (int *)0x0) {
          ERR_put_error(6,0x9b,0x9a,DAT_000b44c8,0x128);
          iVar1 = -1;
        }
        else if (**(int **)(ctx + 8) == peer->type) {
          iVar1 = EVP_PKEY_missing_parameters(peer);
          if ((iVar1 == 0) &&
             (iVar1 = EVP_PKEY_cmp_parameters(*(EVP_PKEY **)(ctx + 8),peer), iVar1 == 0)) {
            ERR_put_error(6,0x9b,0x99,DAT_000b44c8,0x13a);
            iVar1 = -1;
          }
          else {
            if (*(EVP_PKEY **)(ctx + 0xc) != (EVP_PKEY *)0x0) {
              EVP_PKEY_free(*(EVP_PKEY **)(ctx + 0xc));
            }
            *(EVP_PKEY **)(ctx + 0xc) = peer;
            pEVar3 = peer;
            iVar1 = (**(code **)(*(int *)ctx + 100))(ctx,2,1);
            if (iVar1 < 1) {
              pEVar3 = (EVP_PKEY *)0x0;
            }
            if (iVar1 < 1) {
              *(EVP_PKEY **)(ctx + 0xc) = pEVar3;
            }
            else {
              CRYPTO_add_lock(&peer->references,1,10,DAT_000b44c8,0x149);
              iVar1 = 1;
            }
          }
        }
        else {
          ERR_put_error(6,0x9b,0x65,DAT_000b44c8,0x12d);
          iVar1 = -1;
        }
      }
    }
    else {
      ERR_put_error(6,0x9b,0x97,DAT_000b44c8,0x11b);
      iVar1 = -1;
    }
  }
  return iVar1;
}

