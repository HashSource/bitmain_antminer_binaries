
EC_GROUP * EC_GROUP_dup(EC_GROUP *src)

{
  EC_GROUP *dst;
  int iVar1;
  
  if (src == (EC_GROUP *)0x0) {
    return (EC_GROUP *)0x0;
  }
  dst = EC_GROUP_new(*(EC_METHOD **)src);
  if (dst != (EC_GROUP *)0x0) {
    iVar1 = EC_GROUP_copy(dst,src);
    if (iVar1 == 0) {
      EC_GROUP_free(dst);
      return (EC_GROUP *)0x0;
    }
    return dst;
  }
  return (EC_GROUP *)0x0;
}

