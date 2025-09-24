
int EVP_PKEY_derive_set_peer(EVP_PKEY_CTX *ctx,EVP_PKEY *peer)

{
  int iVar1;
  undefined4 extraout_r3;
  undefined4 uVar2;
  
  if ((((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
      ((*(int *)(iVar1 + 0x60) == 0 &&
       ((*(int *)(iVar1 + 0x50) == 0 && (*(int *)(iVar1 + 0x58) == 0)))))) ||
     (*(code **)(iVar1 + 100) == (code *)0x0)) {
    ERR_put_error(6,0x9b,0x96,"crypto/evp/pmeth_fn.c",0xe4);
    iVar1 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 0x400 || (*(int *)(ctx + 0x10) - 0x100U & 0xfffffeff) == 0) {
    iVar1 = (**(code **)(iVar1 + 100))(ctx,2,0,peer);
    if (0 < iVar1) {
      if (iVar1 == 2) {
        iVar1 = 1;
      }
      else if (*(int **)(ctx + 8) == (int *)0x0) {
        ERR_put_error(6,0x9b,0x9a,"crypto/evp/pmeth_fn.c",0xf8);
        iVar1 = -1;
      }
      else if (**(int **)(ctx + 8) == peer->type) {
        iVar1 = EVP_PKEY_missing_parameters(peer);
        if ((iVar1 == 0) &&
           (iVar1 = EVP_PKEY_cmp_parameters(*(EVP_PKEY **)(ctx + 8),peer), iVar1 == 0)) {
          ERR_put_error(6,0x9b,0x99,"crypto/evp/pmeth_fn.c",0x10a);
          iVar1 = -1;
        }
        else {
          EVP_PKEY_free(*(EVP_PKEY **)(ctx + 0xc));
          *(EVP_PKEY **)(ctx + 0xc) = peer;
          iVar1 = (**(code **)(*(int *)ctx + 100))(ctx,2,1,peer);
          uVar2 = extraout_r3;
          if (iVar1 < 1) {
            uVar2 = 0;
          }
          if (iVar1 < 1) {
            *(undefined4 *)(ctx + 0xc) = uVar2;
          }
          else {
            EVP_PKEY_up_ref(peer);
            iVar1 = 1;
          }
        }
      }
      else {
        ERR_put_error(6,0x9b,0x65,"crypto/evp/pmeth_fn.c",0xfd);
        iVar1 = -1;
      }
    }
  }
  else {
    ERR_put_error(6,0x9b,0x97,"crypto/evp/pmeth_fn.c",0xeb);
    iVar1 = -1;
  }
  return iVar1;
}

