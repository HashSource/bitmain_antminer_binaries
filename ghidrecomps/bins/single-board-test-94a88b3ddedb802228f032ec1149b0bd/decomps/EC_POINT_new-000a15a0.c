
EC_POINT * EC_POINT_new(EC_GROUP *group)

{
  int *ptr;
  int iVar1;
  
  if (group == (EC_GROUP *)0x0) {
    ERR_put_error(0x10,0x79,0x43,DAT_000a161c,0x2c3);
    ptr = (int *)0x0;
  }
  else if (*(int *)(*(int *)group + 0x28) == 0) {
    ERR_put_error(0x10,0x79,0x42,DAT_000a161c,0x2c7);
    ptr = (int *)0x0;
  }
  else {
    ptr = (int *)CRYPTO_malloc(0x44,DAT_000a161c,0x2cb);
    if (ptr == (int *)0x0) {
      ERR_put_error(0x10,0x79,0x41,DAT_000a161c,0x2cd);
    }
    else {
      iVar1 = *(int *)group;
      *ptr = iVar1;
      iVar1 = (**(code **)(iVar1 + 0x28))();
      if (iVar1 == 0) {
        CRYPTO_free(ptr);
        ptr = (int *)0x0;
      }
    }
  }
  return (EC_POINT *)ptr;
}

