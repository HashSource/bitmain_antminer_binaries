
EC_POINT * EC_POINT_new(EC_GROUP *group)

{
  EC_POINT *ptr;
  int iVar1;
  
  if (group == (EC_GROUP *)0x0) {
    ERR_put_error(0x10,0x79,0x43,"ec_lib.c",0x2c3);
    ptr = (EC_POINT *)0x0;
  }
  else if (*(int *)(*(int *)group + 0x28) == 0) {
    ERR_put_error(0x10,0x79,0x42,"ec_lib.c",0x2c7);
    ptr = (EC_POINT *)0x0;
  }
  else {
    ptr = (EC_POINT *)CRYPTO_malloc(0x44,"ec_lib.c",0x2cb);
    if (ptr == (EC_POINT *)0x0) {
      ERR_put_error(0x10,0x79,0x41,"ec_lib.c",0x2cd);
    }
    else {
      iVar1 = *(int *)group;
      *(int *)ptr = iVar1;
      iVar1 = (**(code **)(iVar1 + 0x28))();
      if (iVar1 == 0) {
        CRYPTO_free(ptr);
        ptr = (EC_POINT *)0x0;
      }
    }
  }
  return ptr;
}

