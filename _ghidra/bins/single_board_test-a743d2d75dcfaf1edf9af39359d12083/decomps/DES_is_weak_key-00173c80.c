
int DES_is_weak_key(const_DES_cblock *key)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = memcmp(weak_keys,key,8);
  if (((((iVar1 != 0) && (iVar1 = memcmp(weak_keys + 8,key,8), iVar1 != 0)) &&
       (iVar1 = memcmp(weak_keys + 0x10,key,8), iVar1 != 0)) &&
      (((iVar1 = memcmp(weak_keys + 0x18,key,8), iVar1 != 0 &&
        (iVar1 = memcmp(weak_keys + 0x20,key,8), iVar1 != 0)) &&
       ((iVar1 = memcmp(weak_keys + 0x28,key,8), iVar1 != 0 &&
        ((iVar1 = memcmp(weak_keys + 0x30,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(weak_keys + 0x38,key,8), iVar1 != 0)))))))) &&
     ((iVar1 = memcmp(weak_keys + 0x40,key,8), iVar1 != 0 &&
      (((((iVar1 = memcmp(weak_keys + 0x48,key,8), iVar1 != 0 &&
          (iVar1 = memcmp(weak_keys + 0x50,key,8), iVar1 != 0)) &&
         (iVar1 = memcmp(weak_keys + 0x58,key,8), iVar1 != 0)) &&
        ((iVar1 = memcmp(weak_keys + 0x60,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(weak_keys + 0x68,key,8), iVar1 != 0)))) &&
       (iVar1 = memcmp(weak_keys + 0x70,key,8), iVar1 != 0)))))) {
    uVar2 = memcmp(weak_keys + 0x78,key,8);
    iVar1 = 1 - uVar2;
    if (1 < uVar2) {
      iVar1 = 0;
    }
    return iVar1;
  }
  return 1;
}

