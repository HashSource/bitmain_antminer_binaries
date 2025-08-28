
EC_POINT * EC_POINT_dup(EC_POINT *src,EC_GROUP *group)

{
  EC_POINT *ptr;
  code *pcVar1;
  int iVar2;
  
  if (src != (EC_POINT *)0x0) {
    if (group == (EC_GROUP *)0x0) {
      ERR_put_error(0x10,0x79,0x43,"ec_lib.c",0x2c3);
    }
    else if (*(int *)(*(int *)group + 0x28) == 0) {
      ERR_put_error(0x10,0x79,0x42,"ec_lib.c",0x2c7);
    }
    else {
      ptr = (EC_POINT *)CRYPTO_malloc(0x44,"ec_lib.c",0x2cb);
      if (ptr == (EC_POINT *)0x0) {
        ERR_put_error(0x10,0x79,0x41,"ec_lib.c",0x2cd);
      }
      else {
        iVar2 = *(int *)group;
        *(int *)ptr = iVar2;
        iVar2 = (**(code **)(iVar2 + 0x28))();
        if (iVar2 != 0) {
          pcVar1 = *(code **)(*(int *)ptr + 0x34);
          if (pcVar1 == (code *)0x0) {
            ERR_put_error(0x10,0x72,0x42,"ec_lib.c",0x2f5);
          }
          else if (*(int *)ptr == *(int *)src) {
            if (src == ptr) {
              return ptr;
            }
            iVar2 = (*pcVar1)(ptr,src);
            if (iVar2 != 0) {
              return ptr;
            }
          }
          else {
            ERR_put_error(0x10,0x72,0x65,"ec_lib.c",0x2f9);
          }
          if (*(code **)(*(int *)ptr + 0x2c) != (code *)0x0) {
            (**(code **)(*(int *)ptr + 0x2c))(ptr);
          }
          CRYPTO_free(ptr);
          return (EC_POINT *)0x0;
        }
        CRYPTO_free(ptr);
      }
    }
  }
  return (EC_POINT *)0x0;
}

