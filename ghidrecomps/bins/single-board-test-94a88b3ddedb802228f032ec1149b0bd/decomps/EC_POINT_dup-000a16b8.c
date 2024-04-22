
EC_POINT * EC_POINT_dup(EC_POINT *src,EC_GROUP *group)

{
  int *ptr;
  code *pcVar1;
  int iVar2;
  
  if (src != (EC_POINT *)0x0) {
    if (group == (EC_GROUP *)0x0) {
      ERR_put_error(0x10,0x79,0x43,DAT_000a1794,0x2c3);
    }
    else if (*(int *)(*(int *)group + 0x28) == 0) {
      ERR_put_error(0x10,0x79,0x42,DAT_000a1794,0x2c7);
    }
    else {
      ptr = (int *)CRYPTO_malloc(0x44,DAT_000a1794,0x2cb);
      if (ptr == (int *)0x0) {
        ERR_put_error(0x10,0x79,0x41,DAT_000a1794,0x2cd);
      }
      else {
        iVar2 = *(int *)group;
        *ptr = iVar2;
        iVar2 = (**(code **)(iVar2 + 0x28))();
        if (iVar2 != 0) {
          pcVar1 = *(code **)(*ptr + 0x34);
          if (pcVar1 == (code *)0x0) {
            ERR_put_error(0x10,0x72,0x42,DAT_000a1794,0x2f5);
          }
          else if (*ptr == *(int *)src) {
            if ((int *)src == ptr) {
              return (EC_POINT *)ptr;
            }
            iVar2 = (*pcVar1)(ptr,src);
            if (iVar2 != 0) {
              return (EC_POINT *)ptr;
            }
          }
          else {
            ERR_put_error(0x10,0x72,0x65,DAT_000a1794,0x2f9);
          }
          if (*(code **)(*ptr + 0x2c) != (code *)0x0) {
            (**(code **)(*ptr + 0x2c))(ptr);
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

