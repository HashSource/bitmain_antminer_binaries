
int DES_key_sched(const_DES_cblock *key,DES_key_schedule *schedule)

{
  int iVar1;
  
  if (*DAT_00097fa4 != 0) {
    if (((((uint)*(byte *)(DAT_00097fa8 + (uint)(*key)[0]) != (uint)(*key)[0]) ||
         ((uint)*(byte *)(DAT_00097fa8 + (uint)(*key)[1]) != (uint)(*key)[1])) ||
        ((uint)*(byte *)(DAT_00097fa8 + (uint)(*key)[2]) != (uint)(*key)[2])) ||
       ((((uint)*(byte *)(DAT_00097fa8 + (uint)(*key)[3]) != (uint)(*key)[3] ||
         ((uint)*(byte *)(DAT_00097fa8 + (uint)(*key)[4]) != (uint)(*key)[4])) ||
        (((uint)*(byte *)(DAT_00097fa8 + (uint)(*key)[5]) != (uint)(*key)[5] ||
         (((uint)*(byte *)(DAT_00097fa8 + (uint)(*key)[6]) != (uint)(*key)[6] ||
          ((uint)*(byte *)(DAT_00097fa8 + (uint)(*key)[7]) != (uint)(*key)[7])))))))) {
      return -1;
    }
    iVar1 = memcmp((void *)(DAT_00097fa8 + 0x100),key,8);
    if ((((((((iVar1 == 0) || (iVar1 = memcmp(DAT_00097fac,key,8), iVar1 == 0)) ||
            (iVar1 = memcmp(DAT_00097fb0,key,8), iVar1 == 0)) ||
           ((iVar1 = memcmp(DAT_00097fb4,key,8), iVar1 == 0 ||
            (iVar1 = memcmp(DAT_00097fb8,key,8), iVar1 == 0)))) ||
          ((iVar1 = memcmp(DAT_00097fbc,key,8), iVar1 == 0 ||
           ((iVar1 = memcmp(DAT_00097fc0,key,8), iVar1 == 0 ||
            (iVar1 = memcmp(DAT_00097fc4,key,8), iVar1 == 0)))))) ||
         (iVar1 = memcmp(DAT_00097fc8,key,8), iVar1 == 0)) ||
        (((iVar1 = memcmp(DAT_00097fcc,key,8), iVar1 == 0 ||
          (iVar1 = memcmp(DAT_00097fd0,key,8), iVar1 == 0)) ||
         (iVar1 = memcmp(DAT_00097fd4,key,8), iVar1 == 0)))) ||
       (((iVar1 = memcmp(DAT_00097fd8,key,8), iVar1 == 0 ||
         (iVar1 = memcmp(DAT_00097fdc,key,8), iVar1 == 0)) ||
        ((iVar1 = memcmp(DAT_00097fe0,key,8), iVar1 == 0 ||
         (iVar1 = memcmp(DAT_00097fe4,key,8), iVar1 == 0)))))) {
      return -2;
    }
  }
  DES_set_key_unchecked(key,schedule);
  return 0;
}

