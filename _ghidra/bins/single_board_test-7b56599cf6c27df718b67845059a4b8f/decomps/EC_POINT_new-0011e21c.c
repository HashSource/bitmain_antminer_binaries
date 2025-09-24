
EC_POINT * EC_POINT_new(EC_GROUP *group)

{
  EC_POINT *ptr;
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  
  if (group == (EC_GROUP *)0x0) {
    ERR_put_error(0x10,0x79,0x43,"crypto/ec/ec_lib.c",0x28f);
    ptr = (EC_POINT *)0x0;
  }
  else if (*(int *)(*(int *)group + 0x2c) == 0) {
    ERR_put_error(0x10,0x79,0x42,"crypto/ec/ec_lib.c",0x293);
    ptr = (EC_POINT *)0x0;
  }
  else {
    ptr = (EC_POINT *)CRYPTO_zalloc(0x18,"crypto/ec/ec_lib.c",0x297);
    if (ptr == (EC_POINT *)0x0) {
      ERR_put_error(0x10,0x79,0x41,"crypto/ec/ec_lib.c",0x299);
    }
    else {
      iVar2 = *(int *)group;
      uVar1 = *(undefined4 *)(group + 0x10);
      *(int *)ptr = iVar2;
      pcVar3 = *(code **)(iVar2 + 0x2c);
      *(undefined4 *)(ptr + 4) = uVar1;
      iVar2 = (*pcVar3)();
      if (iVar2 == 0) {
        CRYPTO_free(ptr);
        ptr = (EC_POINT *)0x0;
      }
    }
  }
  return ptr;
}

