
size_t obj_cmp_BSEARCH_CMP_FN(int *param_1,int *param_2)

{
  size_t __n;
  size_t sVar1;
  
  __n = *(size_t *)(*param_1 + 0xc);
  sVar1 = __n - *(int *)(&DAT_0025c150 + *param_2 * 0x18);
  if ((sVar1 == 0) && (sVar1 = __n, __n != 0)) {
    sVar1 = memcmp(*(void **)(*param_1 + 0x10),*(void **)(&DAT_0025c154 + *param_2 * 0x18),__n);
    return sVar1;
  }
  return sVar1;
}

