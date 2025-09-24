
int SSL_get_verify_mode(SSL *s)

{
  return *(int *)&s[2].next_proto_negotiated_len;
}

