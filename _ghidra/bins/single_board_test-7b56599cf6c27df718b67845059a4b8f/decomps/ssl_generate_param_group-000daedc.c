
EVP_PKEY * ssl_generate_param_group(void)

{
  int *piVar1;
  EVP_PKEY_CTX *ctx;
  int iVar2;
  EVP_PKEY *local_14;
  
  local_14 = (EVP_PKEY *)0x0;
  piVar1 = (int *)tls1_group_id_lookup();
  if (piVar1 != (int *)0x0) {
    if ((*(ushort *)(piVar1 + 2) & 3) == 2) {
      local_14 = EVP_PKEY_new();
      if ((local_14 != (EVP_PKEY *)0x0) && (iVar2 = EVP_PKEY_set_type(local_14,*piVar1), iVar2 != 0)
         ) {
        return local_14;
      }
      EVP_PKEY_free(local_14);
      return (EVP_PKEY *)0x0;
    }
    ctx = EVP_PKEY_CTX_new_id(0x198,(ENGINE *)0x0);
    if (ctx != (EVP_PKEY_CTX *)0x0) {
      iVar2 = EVP_PKEY_paramgen_init(ctx);
      if (((0 < iVar2) &&
          (iVar2 = EVP_PKEY_CTX_ctrl(ctx,0x198,6,0x1001,*piVar1,(void *)0x0), 0 < iVar2)) &&
         (iVar2 = EVP_PKEY_paramgen(ctx,&local_14), iVar2 < 1)) {
        EVP_PKEY_free(local_14);
        local_14 = (EVP_PKEY *)0x0;
      }
      goto LAB_000daf3e;
    }
  }
  ctx = (EVP_PKEY_CTX *)0x0;
LAB_000daf3e:
  EVP_PKEY_CTX_free(ctx);
  return local_14;
}

