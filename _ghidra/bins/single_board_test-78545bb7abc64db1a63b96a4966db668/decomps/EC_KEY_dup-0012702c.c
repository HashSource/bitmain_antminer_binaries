
EC_KEY * EC_KEY_dup(EC_KEY *src)

{
  EC_KEY *dst;
  EC_KEY *pEVar1;
  
  dst = (EC_KEY *)EC_KEY_new_method(*(undefined4 *)(src + 4));
  if ((dst != (EC_KEY *)0x0) && (pEVar1 = EC_KEY_copy(dst,src), pEVar1 == (EC_KEY *)0x0)) {
    EC_KEY_free(dst);
    dst = (EC_KEY *)0x0;
  }
  return dst;
}

