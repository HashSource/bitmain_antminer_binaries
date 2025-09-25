
EVP_PKEY_CTX * EVP_PKEY_CTX_dup(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  EVP_PKEY_CTX *ctx_00;
  
  ctx_00 = *(EVP_PKEY_CTX **)ctx;
  if ((ctx_00 != (EVP_PKEY_CTX *)0x0) &&
     (ctx_00 = *(EVP_PKEY_CTX **)(ctx_00 + 0xc), ctx_00 != (EVP_PKEY_CTX *)0x0)) {
    if ((*(ENGINE **)(ctx + 4) == (ENGINE *)0x0) ||
       (iVar1 = ENGINE_init(*(ENGINE **)(ctx + 4)), iVar1 != 0)) {
      ctx_00 = (EVP_PKEY_CTX *)CRYPTO_malloc(0x28,"crypto/evp/pmeth_lib.c",0x109);
      if (ctx_00 == (EVP_PKEY_CTX *)0x0) {
        ERR_put_error(6,0x9c,0x41,"crypto/evp/pmeth_lib.c",0x10b);
      }
      else {
        iVar1 = *(int *)(ctx + 8);
        uVar2 = *(undefined4 *)(ctx + 4);
        *(undefined4 *)ctx_00 = *(undefined4 *)ctx;
        *(undefined4 *)(ctx_00 + 4) = uVar2;
        if (iVar1 != 0) {
          EVP_PKEY_up_ref();
          iVar1 = *(int *)(ctx + 8);
        }
        iVar3 = *(int *)(ctx + 0xc);
        *(int *)(ctx_00 + 8) = iVar1;
        if (iVar3 != 0) {
          EVP_PKEY_up_ref(iVar3);
          iVar3 = *(int *)(ctx + 0xc);
        }
        iVar1 = *(int *)ctx;
        uVar2 = *(undefined4 *)(ctx + 0x10);
        *(int *)(ctx_00 + 0xc) = iVar3;
        pcVar4 = *(code **)(iVar1 + 0xc);
        *(undefined4 *)(ctx_00 + 0x10) = uVar2;
        *(undefined4 *)(ctx_00 + 0x14) = 0;
        *(undefined4 *)(ctx_00 + 0x18) = 0;
        iVar1 = (*pcVar4)(ctx_00,ctx);
        if (iVar1 < 1) {
          *(undefined4 *)ctx_00 = 0;
          EVP_PKEY_CTX_free(ctx_00);
          ctx_00 = (EVP_PKEY_CTX *)0x0;
        }
      }
    }
    else {
      ERR_put_error(6,0x9c,0x26,"crypto/evp/pmeth_lib.c",0x105);
      ctx_00 = (EVP_PKEY_CTX *)0x0;
    }
  }
  return ctx_00;
}

