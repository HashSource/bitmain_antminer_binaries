
int X509_cmp(X509 *a,X509 *b)

{
  int iVar1;
  X509_POLICY_CACHE *__n;
  
  if (a == b) {
    return 0;
  }
  X509_check_purpose(a,-1,0);
  X509_check_purpose(b,-1,0);
  if (((a[1].references << 0xb < 0) || (b[1].references << 0xb < 0)) ||
     (iVar1 = memcmp(&a[1].policy_cache,&b[1].policy_cache,0x14), iVar1 == 0)) {
    if ((a->crldp != (stack_st_DIST_POINT *)0x0) || (b->crldp != (stack_st_DIST_POINT *)0x0)) {
      return 0;
    }
    __n = a->policy_cache;
    if ((int)__n < (int)b->policy_cache) {
      return -1;
    }
    if ((int)__n <= (int)b->policy_cache) {
      iVar1 = memcmp(a->akid,b->akid,(size_t)__n);
      return iVar1;
    }
    iVar1 = 1;
  }
  return iVar1;
}

