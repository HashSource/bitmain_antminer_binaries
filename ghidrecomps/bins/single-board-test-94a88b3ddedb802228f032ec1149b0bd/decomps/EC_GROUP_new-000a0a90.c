
EC_GROUP * EC_GROUP_new(EC_METHOD *meth)

{
  EC_METHOD **ptr;
  int iVar1;
  code *pcVar2;
  
  if (meth == (EC_METHOD *)0x0) {
    ERR_put_error(0x10,0x6c,0x6c,DAT_000a0b2c,0x50);
    ptr = (EC_METHOD **)0x0;
  }
  else if (*(int *)(meth + 8) == 0) {
    ERR_put_error(0x10,0x6c,0x42,DAT_000a0b2c,0x54);
    ptr = (EC_METHOD **)0x0;
  }
  else {
    ptr = (EC_METHOD **)CRYPTO_malloc(0xb0,DAT_000a0b2c,0x58);
    if (ptr == (EC_METHOD **)0x0) {
      ERR_put_error(0x10,0x6c,0x41,DAT_000a0b2c,0x5a);
    }
    else {
      *ptr = meth;
      ptr[0x11] = (EC_METHOD *)0x0;
      ptr[0x2b] = (EC_METHOD *)0x0;
      ptr[1] = (EC_METHOD *)0x0;
      BN_init((BIGNUM *)(ptr + 2));
      BN_init((BIGNUM *)(ptr + 7));
      pcVar2 = *(code **)(meth + 8);
      ptr[0xc] = (EC_METHOD *)0x0;
      ptr[0xf] = (EC_METHOD *)0x0;
      ptr[0x10] = (EC_METHOD *)0x0;
      ptr[0xd] = (EC_METHOD *)0x80000000;
      ptr[0xe] = (EC_METHOD *)0x4;
      iVar1 = (*pcVar2)(ptr);
      if (iVar1 == 0) {
        CRYPTO_free(ptr);
        ptr = (EC_METHOD **)0x0;
      }
    }
  }
  return (EC_GROUP *)ptr;
}

