
int int_get_new_index(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 *ptr;
  int iVar2;
  int iVar3;
  
  iVar1 = def_get_class();
  if (iVar1 == 0) {
    iVar3 = -1;
  }
  else {
    ptr = (undefined4 *)CRYPTO_malloc(0x14,DAT_0008b0bc,0x162);
    if (ptr == (undefined4 *)0x0) {
      ERR_put_error(0xf,0x68,0x41,DAT_0008b0bc,0x164);
      iVar3 = -1;
    }
    else {
      *ptr = param_2;
      ptr[1] = param_3;
      ptr[4] = param_5;
      ptr[2] = param_4;
      ptr[3] = param_6;
      CRYPTO_lock(9,2,DAT_0008b0bc,0x16c);
      do {
        iVar2 = sk_num(*(_STACK **)(iVar1 + 4));
        iVar3 = *(int *)(iVar1 + 8);
        if (iVar3 < iVar2) {
          *(int *)(iVar1 + 8) = iVar3 + 1;
          sk_set(*(_STACK **)(iVar1 + 4),iVar3,ptr);
          goto LAB_0008b076;
        }
        iVar3 = sk_push(*(_STACK **)(iVar1 + 4),(void *)0x0);
      } while (iVar3 != 0);
      iVar3 = -1;
      ERR_put_error(0xf,0x68,0x41,DAT_0008b0bc,0x16f);
      CRYPTO_free(ptr);
LAB_0008b076:
      CRYPTO_lock(10,2,DAT_0008b0bc,0x177);
    }
  }
  return iVar3;
}

