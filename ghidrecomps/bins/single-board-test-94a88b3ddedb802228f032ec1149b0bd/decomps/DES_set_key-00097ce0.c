
int DES_set_key(const_DES_cblock *key,DES_key_schedule *schedule)

{
  int iVar1;
  
  if (*DAT_00097e20 != 0) {
    if (((((uint)*(byte *)(DAT_00097e24 + (uint)(*key)[0]) != (uint)(*key)[0]) ||
         ((uint)*(byte *)(DAT_00097e24 + (uint)(*key)[1]) != (uint)(*key)[1])) ||
        ((uint)*(byte *)(DAT_00097e24 + (uint)(*key)[2]) != (uint)(*key)[2])) ||
       ((((uint)*(byte *)(DAT_00097e24 + (uint)(*key)[3]) != (uint)(*key)[3] ||
         ((uint)*(byte *)(DAT_00097e24 + (uint)(*key)[4]) != (uint)(*key)[4])) ||
        (((uint)*(byte *)(DAT_00097e24 + (uint)(*key)[5]) != (uint)(*key)[5] ||
         (((uint)*(byte *)(DAT_00097e24 + (uint)(*key)[6]) != (uint)(*key)[6] ||
          ((uint)*(byte *)(DAT_00097e24 + (uint)(*key)[7]) != (uint)(*key)[7])))))))) {
      return -1;
    }
    iVar1 = memcmp((void *)(DAT_00097e24 + 0x100),key,8);
    if ((((((((iVar1 == 0) || (iVar1 = memcmp(DAT_00097e28,key,8), iVar1 == 0)) ||
            (iVar1 = memcmp(DAT_00097e2c,key,8), iVar1 == 0)) ||
           ((iVar1 = memcmp(DAT_00097e30,key,8), iVar1 == 0 ||
            (iVar1 = memcmp(DAT_00097e34,key,8), iVar1 == 0)))) ||
          ((iVar1 = memcmp(DAT_00097e38,key,8), iVar1 == 0 ||
           ((iVar1 = memcmp(DAT_00097e3c,key,8), iVar1 == 0 ||
            (iVar1 = memcmp(DAT_00097e40,key,8), iVar1 == 0)))))) ||
         (iVar1 = memcmp(DAT_00097e44,key,8), iVar1 == 0)) ||
        (((iVar1 = memcmp(DAT_00097e48,key,8), iVar1 == 0 ||
          (iVar1 = memcmp(DAT_00097e4c,key,8), iVar1 == 0)) ||
         (iVar1 = memcmp(DAT_00097e50,key,8), iVar1 == 0)))) ||
       (((iVar1 = memcmp(DAT_00097e54,key,8), iVar1 == 0 ||
         (iVar1 = memcmp(DAT_00097e58,key,8), iVar1 == 0)) ||
        ((iVar1 = memcmp(DAT_00097e5c,key,8), iVar1 == 0 ||
         (iVar1 = memcmp(DAT_00097e60,key,8), iVar1 == 0)))))) {
      return -2;
    }
  }
  DES_set_key_unchecked(key,schedule);
  return 0;
}

