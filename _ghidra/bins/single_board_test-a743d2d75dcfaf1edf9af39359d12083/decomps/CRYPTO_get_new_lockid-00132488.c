
int CRYPTO_get_new_lockid(char *name)

{
  char *data;
  int iVar1;
  
  if ((app_locks == (_STACK *)0x0) && (app_locks = sk_new_null(), app_locks == (_STACK *)0x0)) {
    ERR_put_error(0xf,0x65,0x41,"cryptlib.c",0xdd);
    return 0;
  }
  data = BUF_strdup(name);
  if (data == (char *)0x0) {
    ERR_put_error(0xf,0x65,0x41,"cryptlib.c",0xe1);
    iVar1 = 0;
  }
  else {
    iVar1 = sk_push(app_locks,data);
    if (iVar1 == 0) {
      CRYPTO_free(data);
      iVar1 = 0;
    }
    else {
      iVar1 = iVar1 + 0x29;
    }
  }
  return iVar1;
}

