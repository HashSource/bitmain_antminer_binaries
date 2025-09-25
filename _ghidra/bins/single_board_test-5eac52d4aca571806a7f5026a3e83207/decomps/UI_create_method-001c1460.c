
UI_METHOD * UI_create_method(char *name)

{
  UI_METHOD *obj;
  char *ptr;
  int iVar1;
  
  obj = (UI_METHOD *)CRYPTO_zalloc(0x28,"crypto/ui/ui_lib.c",0x259);
  if (obj != (UI_METHOD *)0x0) {
    ptr = CRYPTO_strdup(name,"crypto/ui/ui_lib.c",0x25a);
    *(char **)obj = ptr;
    if (ptr != (char *)0x0) {
      iVar1 = CRYPTO_new_ex_data(0xe,obj,(CRYPTO_EX_DATA *)(obj + 0x24));
      if (iVar1 != 0) {
        return obj;
      }
      ptr = *(char **)obj;
    }
    CRYPTO_free(ptr);
  }
  CRYPTO_free(obj);
  ERR_put_error(0x28,0x70,0x41,"crypto/ui/ui_lib.c",0x260);
  return (UI_METHOD *)0x0;
}

