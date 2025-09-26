
int DES_set_key_checked(const_DES_cblock *key,DES_key_schedule *schedule)

{
  int iVar1;
  
  if (((((uint)(byte)(&odd_parity)[(*key)[0]] != (uint)(*key)[0]) ||
       ((uint)(byte)(&odd_parity)[(*key)[1]] != (uint)(*key)[1])) ||
      ((uint)(byte)(&odd_parity)[(*key)[2]] != (uint)(*key)[2])) ||
     ((((uint)(byte)(&odd_parity)[(*key)[3]] != (uint)(*key)[3] ||
       ((uint)(byte)(&odd_parity)[(*key)[4]] != (uint)(*key)[4])) ||
      (((uint)(byte)(&odd_parity)[(*key)[5]] != (uint)(*key)[5] ||
       (((uint)(byte)(&odd_parity)[(*key)[6]] != (uint)(*key)[6] ||
        ((uint)(byte)(&odd_parity)[(*key)[7]] != (uint)(*key)[7])))))))) {
    return -1;
  }
  iVar1 = memcmp(weak_keys,key,8);
  if ((((((((iVar1 != 0) && (iVar1 = memcmp(weak_keys + 8,key,8), iVar1 != 0)) &&
          (iVar1 = memcmp(weak_keys + 0x10,key,8), iVar1 != 0)) &&
         ((iVar1 = memcmp(weak_keys + 0x18,key,8), iVar1 != 0 &&
          (iVar1 = memcmp(weak_keys + 0x20,key,8), iVar1 != 0)))) &&
        ((iVar1 = memcmp(weak_keys + 0x28,key,8), iVar1 != 0 &&
         ((iVar1 = memcmp(weak_keys + 0x30,key,8), iVar1 != 0 &&
          (iVar1 = memcmp(weak_keys + 0x38,key,8), iVar1 != 0)))))) &&
       (iVar1 = memcmp(weak_keys + 0x40,key,8), iVar1 != 0)) &&
      (((iVar1 = memcmp(weak_keys + 0x48,key,8), iVar1 != 0 &&
        (iVar1 = memcmp(weak_keys + 0x50,key,8), iVar1 != 0)) &&
       (iVar1 = memcmp(weak_keys + 0x58,key,8), iVar1 != 0)))) &&
     (((iVar1 = memcmp(weak_keys + 0x60,key,8), iVar1 != 0 &&
       (iVar1 = memcmp(weak_keys + 0x68,key,8), iVar1 != 0)) &&
      ((iVar1 = memcmp(weak_keys + 0x70,key,8), iVar1 != 0 &&
       (iVar1 = memcmp(weak_keys + 0x78,key,8), iVar1 != 0)))))) {
    DES_set_key_unchecked(key,schedule);
    return 0;
  }
  return -2;
}

