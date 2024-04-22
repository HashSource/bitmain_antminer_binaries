
undefined4 * ECDH_DATA_new_method_constprop_0(void)

{
  ECDH_METHOD **ppEVar1;
  undefined4 *ptr;
  ECDH_METHOD *pEVar2;
  ENGINE *e;
  
  ptr = (undefined4 *)CRYPTO_malloc(0x18,DAT_00100e00,0x8c);
  ppEVar1 = DAT_00100e04;
  if (ptr == (undefined4 *)0x0) {
    ERR_put_error(0x2b,0x65,0x41,DAT_00100e00,0x8e);
  }
  else {
    *ptr = 0;
    pEVar2 = *ppEVar1;
    if (pEVar2 == (ECDH_METHOD *)0x0) {
      pEVar2 = ECDH_OpenSSL();
      *ppEVar1 = pEVar2;
    }
    ptr[3] = pEVar2;
    ptr[1] = 0;
    e = ENGINE_get_default_ECDH();
    ptr[1] = e;
    if (e == (ENGINE *)0x0) {
      pEVar2 = (ECDH_METHOD *)ptr[3];
    }
    else {
      pEVar2 = ENGINE_get_ECDH(e);
      ptr[3] = pEVar2;
      if (pEVar2 == (ECDH_METHOD *)0x0) {
        ERR_put_error(0x2b,0x65,0x26,DAT_00100e00,0x9c);
        ENGINE_finish((ENGINE *)ptr[1]);
        CRYPTO_free(ptr);
        return (undefined4 *)0x0;
      }
    }
    ptr[2] = *(undefined4 *)(pEVar2 + 8);
    CRYPTO_new_ex_data(0xd,ptr,(CRYPTO_EX_DATA *)(ptr + 4));
  }
  return ptr;
}

