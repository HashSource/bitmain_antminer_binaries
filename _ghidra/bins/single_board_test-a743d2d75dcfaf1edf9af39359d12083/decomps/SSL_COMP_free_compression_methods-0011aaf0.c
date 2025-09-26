
void SSL_COMP_free_compression_methods(void)

{
  _STACK *st;
  
  st = ssl_comp_methods;
  ssl_comp_methods = (_STACK *)0x0;
  sk_pop_free(st,(func *)0x119221);
  return;
}

