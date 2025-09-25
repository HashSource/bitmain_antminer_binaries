
int OBJ_add_sigid(int signid,int dig_id,int pkey_id)

{
  int *ptr;
  int iVar1;
  
  if (((sig_app != 0) || (sig_app = OPENSSL_sk_new(0x13ef2d), sig_app != 0)) &&
     ((sigx_app != 0 || (sigx_app = OPENSSL_sk_new(0x13ef65), sigx_app != 0)))) {
    ptr = (int *)CRYPTO_malloc(0xc,"crypto/objects/obj_xref.c",0x6a);
    if (ptr == (int *)0x0) {
      ERR_put_error(8,0x6b,0x41,"crypto/objects/obj_xref.c",0x6b);
    }
    else {
      ptr[2] = pkey_id;
      *ptr = signid;
      ptr[1] = dig_id;
      iVar1 = OPENSSL_sk_push(sig_app,ptr);
      if (iVar1 == 0) {
        CRYPTO_free(ptr);
        return 0;
      }
      iVar1 = OPENSSL_sk_push(sigx_app,ptr);
      if (iVar1 != 0) {
        OPENSSL_sk_sort(sig_app);
        OPENSSL_sk_sort(sigx_app);
        return 1;
      }
    }
  }
  return 0;
}

