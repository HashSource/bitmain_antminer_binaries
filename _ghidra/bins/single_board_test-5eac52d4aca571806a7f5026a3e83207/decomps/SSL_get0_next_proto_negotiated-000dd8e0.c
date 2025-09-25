
void SSL_get0_next_proto_negotiated(SSL *s,uchar **data,uint *len)

{
  uchar *puVar1;
  
  puVar1 = (uchar *)s[3].error;
  *data = puVar1;
  if (puVar1 != (uchar *)0x0) {
    puVar1 = (uchar *)s[3].error_code;
  }
  *len = (uint)puVar1;
  return;
}

