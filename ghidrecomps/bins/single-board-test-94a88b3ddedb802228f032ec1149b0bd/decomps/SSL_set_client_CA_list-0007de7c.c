
void SSL_set_client_CA_list(SSL *s,stack_st_X509_NAME *name_list)

{
  _STACK *st;
  
  st = (_STACK *)(s->ex_data).dummy;
  if (st != (_STACK *)0x0) {
    sk_pop_free(st,DAT_0007de94);
  }
  (s->ex_data).dummy = (int)name_list;
  return;
}

