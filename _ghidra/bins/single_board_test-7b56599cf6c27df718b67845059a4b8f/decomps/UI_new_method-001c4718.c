
UI * UI_new_method(UI_METHOD *method)

{
  UI *ptr;
  int iVar1;
  
  ptr = (UI *)CRYPTO_zalloc(0x18,"crypto/ui/ui_lib.c",0x19);
  if (ptr == (UI *)0x0) {
    ERR_put_error(0x28,0x68,0x41,"crypto/ui/ui_lib.c",0x1c);
  }
  else {
    iVar1 = CRYPTO_THREAD_lock_new();
    *(int *)(ptr + 0x14) = iVar1;
    if (iVar1 == 0) {
      ERR_put_error(0x28,0x68,0x41,"crypto/ui/ui_lib.c",0x22);
      CRYPTO_free(ptr);
      ptr = (UI *)0x0;
    }
    else {
      if ((method == (UI_METHOD *)0x0) &&
         (method = UI_get_default_method(), method == (UI_METHOD *)0x0)) {
        method = (UI_METHOD *)UI_null();
      }
      *(UI_METHOD **)ptr = method;
      iVar1 = CRYPTO_new_ex_data(0xb,ptr,(CRYPTO_EX_DATA *)(ptr + 0xc));
      if (iVar1 == 0) {
        CRYPTO_free(ptr);
        ptr = (UI *)0x0;
      }
    }
  }
  return ptr;
}

