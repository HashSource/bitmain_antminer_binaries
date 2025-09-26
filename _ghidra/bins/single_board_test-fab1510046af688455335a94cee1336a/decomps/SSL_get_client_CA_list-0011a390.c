
stack_st_X509_NAME * SSL_get_client_CA_list(SSL *s)

{
  ssl3_state_st *psVar1;
  
  if (s->type == 0x1000) {
    if (s->version >> 8 == 3) {
      psVar1 = s->s3;
      if (psVar1 != (ssl3_state_st *)0x0) {
        return (psVar1->tmp).ca_names;
      }
    }
    else {
      psVar1 = (ssl3_state_st *)0x0;
    }
  }
  else {
    psVar1 = (ssl3_state_st *)(s->ex_data).dummy;
    if (psVar1 == (ssl3_state_st *)0x0) {
      return *(stack_st_X509_NAME **)(s->psk_server_callback + 0xa0);
    }
  }
  return (stack_st_X509_NAME *)psVar1;
}

