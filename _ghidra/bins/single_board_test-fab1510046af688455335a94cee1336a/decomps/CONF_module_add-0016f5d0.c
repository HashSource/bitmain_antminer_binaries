
int CONF_module_add(char *name,undefined1 *ifunc,undefined1 *ffunc)

{
  undefined4 *data;
  char *pcVar1;
  int iVar2;
  
  if (((supported_modules != (_STACK *)0x0) ||
      (supported_modules = sk_new_null(), supported_modules != (_STACK *)0x0)) &&
     (data = (undefined4 *)CRYPTO_malloc(0x18,"conf_mod.c",0x11d), data != (undefined4 *)0x0)) {
    *data = 0;
    pcVar1 = BUF_strdup(name);
    data[4] = 0;
    data[1] = pcVar1;
    data[2] = ifunc;
    data[3] = ffunc;
    iVar2 = sk_push(supported_modules,data);
    if (iVar2 != 0) {
      return 1;
    }
    CRYPTO_free(data);
  }
  return 0;
}

