
int DES_set_key_checked(const_DES_cblock *key,DES_key_schedule *schedule)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00097cdc;
  if (((((uint)*(byte *)(DAT_00097cdc + (uint)(*key)[0]) != (uint)(*key)[0]) ||
       ((uint)*(byte *)(DAT_00097cdc + (uint)(*key)[1]) != (uint)(*key)[1])) ||
      ((uint)*(byte *)(DAT_00097cdc + (uint)(*key)[2]) != (uint)(*key)[2])) ||
     ((((uint)*(byte *)(DAT_00097cdc + (uint)(*key)[3]) != (uint)(*key)[3] ||
       ((uint)*(byte *)(DAT_00097cdc + (uint)(*key)[4]) != (uint)(*key)[4])) ||
      (((uint)*(byte *)(DAT_00097cdc + (uint)(*key)[5]) != (uint)(*key)[5] ||
       (((uint)*(byte *)(DAT_00097cdc + (uint)(*key)[6]) != (uint)(*key)[6] ||
        ((uint)*(byte *)(DAT_00097cdc + (uint)(*key)[7]) != (uint)(*key)[7])))))))) {
    return -1;
  }
  iVar1 = memcmp((void *)(DAT_00097cdc + 0x100),key,8);
  if ((((((((iVar1 != 0) && (iVar1 = memcmp((void *)(iVar2 + 0x108),key,8), iVar1 != 0)) &&
          (iVar1 = memcmp((void *)(iVar2 + 0x110),key,8), iVar1 != 0)) &&
         ((iVar1 = memcmp((void *)(iVar2 + 0x118),key,8), iVar1 != 0 &&
          (iVar1 = memcmp((void *)(iVar2 + 0x120),key,8), iVar1 != 0)))) &&
        ((iVar1 = memcmp((void *)(iVar2 + 0x128),key,8), iVar1 != 0 &&
         ((iVar1 = memcmp((void *)(iVar2 + 0x130),key,8), iVar1 != 0 &&
          (iVar1 = memcmp((void *)(iVar2 + 0x138),key,8), iVar1 != 0)))))) &&
       (iVar1 = memcmp((void *)(iVar2 + 0x140),key,8), iVar1 != 0)) &&
      (((iVar1 = memcmp((void *)(iVar2 + 0x148),key,8), iVar1 != 0 &&
        (iVar1 = memcmp((void *)(iVar2 + 0x150),key,8), iVar1 != 0)) &&
       (iVar1 = memcmp((void *)(iVar2 + 0x158),key,8), iVar1 != 0)))) &&
     (((iVar1 = memcmp((void *)(iVar2 + 0x160),key,8), iVar1 != 0 &&
       (iVar1 = memcmp((void *)(iVar2 + 0x168),key,8), iVar1 != 0)) &&
      ((iVar1 = memcmp((void *)(iVar2 + 0x170),key,8), iVar1 != 0 &&
       (iVar2 = memcmp((void *)(iVar2 + 0x178),key,8), iVar2 != 0)))))) {
    DES_set_key_unchecked(key,schedule);
    return 0;
  }
  return -2;
}

