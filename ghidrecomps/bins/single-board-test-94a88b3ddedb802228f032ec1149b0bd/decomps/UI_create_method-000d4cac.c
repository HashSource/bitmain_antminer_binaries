
UI_METHOD * UI_create_method(char *name)

{
  char **__s;
  char *pcVar1;
  
  __s = (char **)CRYPTO_malloc(0x1c,DAT_000d4cd4,0x24e);
  if (__s != (char **)0x0) {
    memset(__s,0,0x1c);
    pcVar1 = BUF_strdup(name);
    *__s = pcVar1;
  }
  return (UI_METHOD *)__s;
}

