
undefined4 * ECDSA_DATA_new_method_constprop_0(void)

{
  undefined4 *ptr;
  ENGINE *e;
  ECDSA_METHOD *pEVar1;
  
  ptr = (undefined4 *)CRYPTO_malloc(0x18,"ecs_lib.c",0x77);
  if (ptr == (undefined4 *)0x0) {
    ERR_put_error(0x2a,100,0x41,"ecs_lib.c",0x79);
  }
  else {
    *ptr = 0;
    if (default_ECDSA_method == (ECDSA_METHOD *)0x0) {
      default_ECDSA_method = ECDSA_OpenSSL();
    }
    ptr[3] = default_ECDSA_method;
    ptr[1] = 0;
    e = ENGINE_get_default_ECDSA();
    ptr[1] = e;
    if (e == (ENGINE *)0x0) {
      pEVar1 = (ECDSA_METHOD *)ptr[3];
    }
    else {
      pEVar1 = ENGINE_get_ECDSA(e);
      ptr[3] = pEVar1;
      if (pEVar1 == (ECDSA_METHOD *)0x0) {
        ERR_put_error(0x2a,100,0x26,"ecs_lib.c",0x87);
        ENGINE_finish((ENGINE *)ptr[1]);
        CRYPTO_free(ptr);
        return (undefined4 *)0x0;
      }
    }
    ptr[2] = *(undefined4 *)(pEVar1 + 0x10);
    CRYPTO_new_ex_data(0xc,ptr,(CRYPTO_EX_DATA *)(ptr + 4));
  }
  return ptr;
}

