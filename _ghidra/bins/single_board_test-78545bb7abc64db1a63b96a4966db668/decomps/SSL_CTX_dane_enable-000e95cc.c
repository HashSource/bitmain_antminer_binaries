
undefined4 SSL_CTX_dane_enable(int param_1)

{
  undefined4 uVar1;
  void *ptr;
  void *ptr_00;
  char *pcVar2;
  EVP_MD *pEVar3;
  
  if (*(int *)(param_1 + 0x200) == 0) {
    ptr = (void *)CRYPTO_zalloc(0xc,"ssl/ssl_lib.c",0x90);
    ptr_00 = (void *)CRYPTO_zalloc(3,"ssl/ssl_lib.c",0x91);
    if (ptr == (void *)0x0 || ptr_00 == (void *)0x0) {
      CRYPTO_free(ptr_00);
      CRYPTO_free(ptr);
      ERR_put_error(0x14,0x15b,0x41,"ssl/ssl_lib.c",0x96);
      uVar1 = 0;
    }
    else {
      pcVar2 = OBJ_nid2sn(0x2a0);
      pEVar3 = EVP_get_digestbyname(pcVar2);
      if (pEVar3 != (EVP_MD *)0x0) {
        *(EVP_MD **)((int)ptr + 4) = pEVar3;
        *(undefined1 *)((int)ptr_00 + 1) = 1;
      }
      pcVar2 = OBJ_nid2sn(0x2a2);
      pEVar3 = EVP_get_digestbyname(pcVar2);
      if (pEVar3 != (EVP_MD *)0x0) {
        *(EVP_MD **)((int)ptr + 8) = pEVar3;
        *(undefined1 *)((int)ptr_00 + 2) = 2;
      }
      *(void **)(param_1 + 0x200) = ptr;
      *(void **)(param_1 + 0x204) = ptr_00;
      uVar1 = 1;
      *(undefined1 *)(param_1 + 0x208) = 2;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

