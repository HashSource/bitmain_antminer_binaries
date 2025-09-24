
uchar * SSL_SESSION_get_id(SSL_SESSION *s,uint *len)

{
  if (len != (uint *)0x0) {
    *len = *(uint *)(s->krb5_client_princ + 0xb8);
  }
  return s->krb5_client_princ + 0xbc;
}

