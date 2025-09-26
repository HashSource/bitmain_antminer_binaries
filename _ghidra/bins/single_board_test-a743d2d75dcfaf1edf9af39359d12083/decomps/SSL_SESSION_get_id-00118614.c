
uchar * SSL_SESSION_get_id(SSL_SESSION *s,uint *len)

{
  if (len != (uint *)0x0) {
    *len = s->session_id_length;
  }
  return s->session_id;
}

