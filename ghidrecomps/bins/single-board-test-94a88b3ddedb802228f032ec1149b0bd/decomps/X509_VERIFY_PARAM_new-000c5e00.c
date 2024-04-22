
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_VERIFY_PARAM * X509_VERIFY_PARAM_new(void)

{
  X509_VERIFY_PARAM *ptr;
  _STACK **__s;
  _STACK *st;
  
  ptr = (X509_VERIFY_PARAM *)CRYPTO_malloc(0x24,DAT_000c5e98,0xb0);
  if (ptr != (X509_VERIFY_PARAM *)0x0) {
    __s = (_STACK **)CRYPTO_malloc(0x1c,DAT_000c5e98,0xb3);
    if (__s == (_STACK **)0x0) {
      CRYPTO_free(ptr);
      ptr = (X509_VERIFY_PARAM *)0x0;
    }
    else {
      memset(ptr,0,0x24);
      memset(__s,0,0x1c);
      st = &ptr->policies->stack;
      ptr[1].name = (char *)__s;
      ptr->name = (char *)0x0;
      ptr->purpose = 0;
      ptr->trust = 0;
      ptr->inh_flags = 0;
      ptr->flags = 0;
      ptr->depth = -1;
      if (st != (_STACK *)0x0) {
        sk_pop_free(st,DAT_000c5e9c);
        __s = (_STACK **)ptr[1].name;
        ptr->policies = (stack_st_ASN1_OBJECT *)0x0;
      }
      if (*__s != (_STACK *)0x0) {
        sk_pop_free(*__s,DAT_000c5ea0);
        *__s = (_STACK *)0x0;
      }
      if (__s[2] != (_STACK *)0x0) {
        CRYPTO_free(__s[2]);
      }
      if (__s[3] != (_STACK *)0x0) {
        CRYPTO_free(__s[3]);
        __s[3] = (_STACK *)0x0;
        __s[4] = (_STACK *)0x0;
      }
      if (__s[5] != (_STACK *)0x0) {
        CRYPTO_free(__s[5]);
        __s[5] = (_STACK *)0x0;
        __s[6] = (_STACK *)0x0;
      }
    }
  }
  return ptr;
}

