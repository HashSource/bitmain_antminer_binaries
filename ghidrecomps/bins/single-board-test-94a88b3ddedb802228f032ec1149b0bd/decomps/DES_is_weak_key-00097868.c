
int DES_is_weak_key(const_DES_cblock *key)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = memcmp(DAT_0009794c,key,8);
  if (((((iVar1 != 0) && (iVar1 = memcmp(DAT_00097950,key,8), iVar1 != 0)) &&
       (iVar1 = memcmp(DAT_00097954,key,8), iVar1 != 0)) &&
      (((iVar1 = memcmp(DAT_00097958,key,8), iVar1 != 0 &&
        (iVar1 = memcmp(DAT_0009795c,key,8), iVar1 != 0)) &&
       ((iVar1 = memcmp(DAT_00097960,key,8), iVar1 != 0 &&
        ((iVar1 = memcmp(DAT_00097964,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(DAT_00097968,key,8), iVar1 != 0)))))))) &&
     ((iVar1 = memcmp(DAT_0009796c,key,8), iVar1 != 0 &&
      (((((iVar1 = memcmp(DAT_00097970,key,8), iVar1 != 0 &&
          (iVar1 = memcmp(DAT_00097974,key,8), iVar1 != 0)) &&
         (iVar1 = memcmp(DAT_00097978,key,8), iVar1 != 0)) &&
        ((iVar1 = memcmp(DAT_0009797c,key,8), iVar1 != 0 &&
         (iVar1 = memcmp(DAT_00097980,key,8), iVar1 != 0)))) &&
       (iVar1 = memcmp(DAT_00097984,key,8), iVar1 != 0)))))) {
    uVar2 = memcmp(DAT_00097988,key,8);
    iVar1 = 1 - uVar2;
    if (1 < uVar2) {
      iVar1 = 0;
    }
    return iVar1;
  }
  return 1;
}

