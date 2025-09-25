
int tls13_export_keying_material_early
              (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,void *param_6,size_t param_7)

{
  EVP_MD_CTX *ctx;
  int iVar1;
  EVP_MD *type;
  uint local_f0;
  uint local_ec;
  undefined1 auStack_e8 [64];
  uchar auStack_a8 [64];
  uchar auStack_68 [68];
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if ((ctx != (EVP_MD_CTX *)0x0) && (iVar1 = ossl_statem_export_early_allowed(param_1), iVar1 != 0))
  {
    if ((*(int *)(param_1 + 0x1c) == 0) && (*(int *)(param_1 + 0xf50) != 0)) {
      iVar1 = *(int *)(param_1 + 0x474);
      if (*(int *)(iVar1 + 0x1e0) != 0) goto LAB_000f9fee;
      iVar1 = SSL_SESSION_get0_cipher(*(undefined4 *)(param_1 + 0x478));
    }
    else {
      iVar1 = *(int *)(param_1 + 0x474);
LAB_000f9fee:
      iVar1 = SSL_SESSION_get0_cipher(iVar1);
    }
    type = (EVP_MD *)ssl_md(*(undefined4 *)(iVar1 + 0x34));
    iVar1 = EVP_DigestInit_ex(ctx,type,(ENGINE *)0x0);
    if ((0 < iVar1) && (iVar1 = EVP_DigestUpdate(ctx,param_6,param_7), 0 < iVar1)) {
      iVar1 = EVP_DigestFinal_ex(ctx,auStack_a8,&local_f0);
      if ((0 < iVar1) && (iVar1 = EVP_DigestInit_ex(ctx,type,(ENGINE *)0x0), 0 < iVar1)) {
        iVar1 = EVP_DigestFinal_ex(ctx,auStack_68,&local_ec);
        if (0 < iVar1) {
          iVar1 = tls13_hkdf_expand(param_1,type,param_1 + 0x38c,param_4,param_5,auStack_68,local_ec
                                    ,auStack_e8,local_f0,0);
          if (iVar1 != 0) {
            iVar1 = tls13_hkdf_expand(param_1,type,auStack_e8,"exporter",8,auStack_a8,local_f0,
                                      param_2,param_3,0);
            if (iVar1 != 0) {
              iVar1 = 1;
            }
            goto LAB_000fa0a6;
          }
        }
      }
    }
  }
  iVar1 = 0;
LAB_000fa0a6:
  EVP_MD_CTX_free(ctx);
  return iVar1;
}

