
UI_METHOD * UI_create_method(char *name)

{
  UI_METHOD *__s;
  char *pcVar1;
  
  __s = (UI_METHOD *)CRYPTO_malloc(0x1c,"ui_lib.c",0x24e);
  if (__s != (UI_METHOD *)0x0) {
    memset(__s,0,0x1c);
    pcVar1 = BUF_strdup(name);
    *(char **)__s = pcVar1;
  }
  return __s;
}

