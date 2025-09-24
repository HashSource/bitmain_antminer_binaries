
void SSL_set_info_callback(SSL *ssl,cb *cb)

{
  ssl[2].srtp_profile = (SRTP_PROTECTION_PROFILE *)cb;
  return;
}

