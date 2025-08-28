
int OBJ_add_sigid(int signid,int dig_id,int pkey_id)

{
  int *data;
  int iVar1;
  
  if ((((sig_app != (_STACK *)0x0) || (sig_app = sk_new((cmp *)0x8cfed), sig_app != (_STACK *)0x0))
      && ((sigx_app != (_STACK *)0x0 ||
          (sigx_app = sk_new((cmp *)0x8cff9), sigx_app != (_STACK *)0x0)))) &&
     (data = (int *)CRYPTO_malloc(0xc,"obj_xref.c",0x9f), data != (int *)0x0)) {
    data[2] = pkey_id;
    *data = signid;
    data[1] = dig_id;
    iVar1 = sk_push(sig_app,data);
    if (iVar1 == 0) {
      CRYPTO_free(data);
      return 0;
    }
    iVar1 = sk_push(sigx_app,data);
    if (iVar1 != 0) {
      sk_sort(sig_app);
      sk_sort(sigx_app);
      return 1;
    }
  }
  return 0;
}

