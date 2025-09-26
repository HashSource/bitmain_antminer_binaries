
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_VERIFY_PARAM * X509_VERIFY_PARAM_new(void)

{
  X509_VERIFY_PARAM *ptr;
  char *__s;
  _STACK *st;
  
  ptr = (X509_VERIFY_PARAM *)CRYPTO_malloc(0x24,"x509_vpm.c",0xb0);
  if (ptr != (X509_VERIFY_PARAM *)0x0) {
    __s = (char *)CRYPTO_malloc(0x1c,"x509_vpm.c",0xb3);
    if (__s == (char *)0x0) {
      CRYPTO_free(ptr);
      ptr = (X509_VERIFY_PARAM *)0x0;
    }
    else {
      memset(ptr,0,0x24);
      memset(__s,0,0x1c);
      st = &ptr->policies->stack;
      ptr[1].name = __s;
      ptr->name = (char *)0x0;
      ptr->purpose = 0;
      ptr->trust = 0;
      ptr->inh_flags = 0;
      ptr->flags = 0;
      ptr->depth = -1;
      if (st != (_STACK *)0x0) {
        sk_pop_free(st,(func *)0x156099);
        __s = ptr[1].name;
        ptr->policies = (stack_st_ASN1_OBJECT *)0x0;
      }
      if (*(_STACK **)__s != (_STACK *)0x0) {
        sk_pop_free(*(_STACK **)__s,(func *)0x163de9);
        __s[0] = '\0';
        __s[1] = '\0';
        __s[2] = '\0';
        __s[3] = '\0';
      }
      if (*(void **)(__s + 8) != (void *)0x0) {
        CRYPTO_free(*(void **)(__s + 8));
      }
      if (*(void **)(__s + 0xc) != (void *)0x0) {
        CRYPTO_free(*(void **)(__s + 0xc));
        __s[0xc] = '\0';
        __s[0xd] = '\0';
        __s[0xe] = '\0';
        __s[0xf] = '\0';
        __s[0x10] = '\0';
        __s[0x11] = '\0';
        __s[0x12] = '\0';
        __s[0x13] = '\0';
      }
      if (*(void **)(__s + 0x14) != (void *)0x0) {
        CRYPTO_free(*(void **)(__s + 0x14));
        __s[0x14] = '\0';
        __s[0x15] = '\0';
        __s[0x16] = '\0';
        __s[0x17] = '\0';
        __s[0x18] = '\0';
        __s[0x19] = '\0';
        __s[0x1a] = '\0';
        __s[0x1b] = '\0';
      }
    }
  }
  return ptr;
}

