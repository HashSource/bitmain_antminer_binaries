
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

UI * UI_new(void)

{
  UI *obj;
  
  obj = (UI *)CRYPTO_malloc(0x18,"ui_lib.c",0x51);
  if (obj == (UI *)0x0) {
    ERR_put_error(0x28,0x68,0x41,"ui_lib.c",0x53);
  }
  else {
    if (default_UI_meth == (UI_METHOD *)0x0) {
      default_UI_meth = UI_OpenSSL();
    }
    *(UI_METHOD **)obj = default_UI_meth;
    *(int *)(obj + 4) = 0;
    *(int *)(obj + 8) = 0;
    *(int *)(obj + 0x14) = 0;
    CRYPTO_new_ex_data(0xb,obj,(CRYPTO_EX_DATA *)(obj + 0xc));
  }
  return obj;
}

