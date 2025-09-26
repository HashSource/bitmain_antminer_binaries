
int CRYPTO_set_mem_functions(m *m,r *r,f *f)

{
  OPENSSL_init();
  if (((allow_customize != 0) && (m != (m *)0x0 && r != (r *)0x0)) && (f != (f *)0x0)) {
    malloc_func = m;
    realloc_func = r;
    free_func = f;
    malloc_locked_func = m;
    free_locked_func = f;
    malloc_ex_func = 0x132bad;
    realloc_ex_func = 0x132bbd;
    malloc_locked_ex_func = 0x132bcd;
    return 1;
  }
  return 0;
}

