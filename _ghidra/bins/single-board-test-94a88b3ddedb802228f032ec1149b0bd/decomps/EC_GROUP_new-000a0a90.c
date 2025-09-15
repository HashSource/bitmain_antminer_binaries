
EC_GROUP * EC_GROUP_new(EC_METHOD *meth)

{
  EC_GROUP *ptr;
  int iVar1;
  code *pcVar2;
  
  if (meth == (EC_METHOD *)0x0) {
    ERR_put_error(0x10,0x6c,0x6c,"ec_lib.c",0x50);
    ptr = (EC_GROUP *)0x0;
  }
  else if (*(int *)(meth + 8) == 0) {
    ERR_put_error(0x10,0x6c,0x42,"ec_lib.c",0x54);
    ptr = (EC_GROUP *)0x0;
  }
  else {
    ptr = (EC_GROUP *)CRYPTO_malloc(0xb0,"ec_lib.c",0x58);
    if (ptr == (EC_GROUP *)0x0) {
      ERR_put_error(0x10,0x6c,0x41,"ec_lib.c",0x5a);
    }
    else {
      *(EC_METHOD **)ptr = meth;
      *(undefined4 *)(ptr + 0x44) = 0;
      *(undefined4 *)(ptr + 0xac) = 0;
      *(undefined4 *)(ptr + 4) = 0;
      BN_init((BIGNUM *)(ptr + 8));
      BN_init((BIGNUM *)(ptr + 0x1c));
      pcVar2 = *(code **)(meth + 8);
      *(undefined4 *)(ptr + 0x30) = 0;
      *(undefined4 *)(ptr + 0x3c) = 0;
      *(undefined4 *)(ptr + 0x40) = 0;
      *(undefined4 *)(ptr + 0x34) = 0x80000000;
      *(undefined4 *)(ptr + 0x38) = 4;
      iVar1 = (*pcVar2)(ptr);
      if (iVar1 == 0) {
        CRYPTO_free(ptr);
        ptr = (EC_GROUP *)0x0;
      }
    }
  }
  return ptr;
}

