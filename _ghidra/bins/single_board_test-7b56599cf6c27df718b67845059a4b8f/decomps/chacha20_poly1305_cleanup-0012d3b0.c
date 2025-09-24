
undefined4 chacha20_poly1305_cleanup(int param_1)

{
  int iVar1;
  void *ptr;
  
  ptr = *(void **)(param_1 + 0x60);
  if (ptr != (void *)0x0) {
    iVar1 = Poly1305_ctx_size();
    OPENSSL_cleanse(ptr,iVar1 + 0xd0);
  }
  return 1;
}

