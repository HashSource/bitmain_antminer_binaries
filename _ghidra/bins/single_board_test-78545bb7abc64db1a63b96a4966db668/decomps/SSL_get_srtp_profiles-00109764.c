
stack_st_SRTP_PROTECTION_PROFILE * SSL_get_srtp_profiles(SSL *ssl)

{
  stack_st_SRTP_PROTECTION_PROFILE *psVar1;
  
  if (ssl == (SSL *)0x0) {
    psVar1 = (stack_st_SRTP_PROTECTION_PROFILE *)0x0;
  }
  else {
    psVar1 = (stack_st_SRTP_PROTECTION_PROFILE *)ssl[3].tlsext_debug_cb;
    if ((psVar1 == (stack_st_SRTP_PROTECTION_PROFILE *)0x0) && (ssl[3].method != (SSL_METHOD *)0x0))
    {
      return (stack_st_SRTP_PROTECTION_PROFILE *)ssl[3].method[4].ssl_ctrl;
    }
  }
  return psVar1;
}

