
void SSL_set_verify(SSL *s,int mode,callback *callback)

{
  *(int *)&s[2].next_proto_negotiated_len = mode;
  if (callback != (callback *)0x0) {
    s[2].srtp_profiles = (stack_st_SRTP_PROTECTION_PROFILE *)callback;
  }
  return;
}

