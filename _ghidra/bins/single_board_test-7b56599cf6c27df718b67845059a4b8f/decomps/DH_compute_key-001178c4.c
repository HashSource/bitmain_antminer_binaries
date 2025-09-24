
int DH_compute_key(uchar *key,BIGNUM *pub_key,DH *dh)

{
  size_t __n;
  uchar *puVar1;
  uchar *puVar2;
  size_t local_18;
  int local_14;
  
  local_18 = 0;
  local_14 = 1;
  __n = (**(code **)((dh->ex_data).dummy + 8))();
  if (0 < (int)__n) {
    puVar1 = key;
    do {
      puVar2 = puVar1 + 1;
      if (*puVar1 != '\0') {
        local_14 = 0;
      }
      local_18 = local_18 + local_14;
      puVar1 = puVar2;
    } while (key + __n != puVar2);
    __n = __n - local_18;
    memmove(key,key + local_18,__n);
    memset(key + __n,0,local_18);
  }
  return __n;
}

