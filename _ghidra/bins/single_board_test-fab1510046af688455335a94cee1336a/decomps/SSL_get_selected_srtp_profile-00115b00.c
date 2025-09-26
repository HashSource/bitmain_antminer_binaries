
SRTP_PROTECTION_PROFILE * SSL_get_selected_srtp_profile(SSL *s)

{
  return (SRTP_PROTECTION_PROFILE *)s->srtp_profiles;
}

