
void ec_pre_comp_clear_free(void *param_1)

{
  int iVar1;
  EC_POINT **ptr;
  EC_POINT *point;
  
  if ((param_1 != (void *)0x0) &&
     (iVar1 = CRYPTO_add_lock((int *)((int)param_1 + 0x18),-1,0x24,DAT_000a1f44,0x9f), iVar1 < 1)) {
    ptr = *(EC_POINT ***)((int)param_1 + 0x10);
    if (ptr != (EC_POINT **)0x0) {
      point = *ptr;
      if (point != (EC_POINT *)0x0) {
        do {
          EC_POINT_clear_free(point);
          OPENSSL_cleanse(ptr,4);
          ptr = ptr + 1;
          point = *ptr;
        } while (point != (EC_POINT *)0x0);
        ptr = *(EC_POINT ***)((int)param_1 + 0x10);
      }
      CRYPTO_free(ptr);
    }
    OPENSSL_cleanse(param_1,0x1c);
    CRYPTO_free(param_1);
    return;
  }
  return;
}

