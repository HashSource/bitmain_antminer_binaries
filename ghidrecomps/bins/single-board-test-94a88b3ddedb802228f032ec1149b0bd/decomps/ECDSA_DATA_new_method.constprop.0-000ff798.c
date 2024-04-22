
undefined4 * ECDSA_DATA_new_method_constprop_0(void)

{
  ECDSA_METHOD **ppEVar1;
  undefined4 *ptr;
  ECDSA_METHOD *pEVar2;
  ENGINE *e;
  
  ptr = (undefined4 *)CRYPTO_malloc(0x18,DAT_000ff824,0x77);
  ppEVar1 = DAT_000ff828;
  if (ptr == (undefined4 *)0x0) {
    ERR_put_error(0x2a,100,0x41,DAT_000ff824,0x79);
  }
  else {
    *ptr = 0;
    pEVar2 = *ppEVar1;
    if (pEVar2 == (ECDSA_METHOD *)0x0) {
      pEVar2 = ECDSA_OpenSSL();
      *ppEVar1 = pEVar2;
    }
    ptr[3] = pEVar2;
    ptr[1] = 0;
    e = ENGINE_get_default_ECDSA();
    ptr[1] = e;
    if (e == (ENGINE *)0x0) {
      pEVar2 = (ECDSA_METHOD *)ptr[3];
    }
    else {
      pEVar2 = ENGINE_get_ECDSA(e);
      ptr[3] = pEVar2;
      if (pEVar2 == (ECDSA_METHOD *)0x0) {
        ERR_put_error(0x2a,100,0x26,DAT_000ff824,0x87);
        ENGINE_finish((ENGINE *)ptr[1]);
        CRYPTO_free(ptr);
        return (undefined4 *)0x0;
      }
    }
    ptr[2] = *(undefined4 *)(pEVar2 + 0x10);
    CRYPTO_new_ex_data(0xc,ptr,(CRYPTO_EX_DATA *)(ptr + 4));
  }
  return ptr;
}

