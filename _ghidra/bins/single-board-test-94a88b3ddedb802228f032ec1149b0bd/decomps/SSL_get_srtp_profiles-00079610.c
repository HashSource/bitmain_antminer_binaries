
stack_st_SRTP_PROTECTION_PROFILE * SSL_get_srtp_profiles(SSL *ssl)

{
  SSL *pSVar1;
  
  pSVar1 = ssl;
  if (((ssl != (SSL *)0x0) &&
      (pSVar1 = *(SSL **)&ssl->next_proto_negotiated_len, pSVar1 == (SSL *)0x0)) &&
     (ssl->psk_server_callback != (_func_3296 *)0x0)) {
    return *(stack_st_SRTP_PROTECTION_PROFILE **)(ssl->psk_server_callback + 0x1b4);
  }
  return (stack_st_SRTP_PROTECTION_PROFILE *)pSVar1;
}

