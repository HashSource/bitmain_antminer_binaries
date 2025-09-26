
SSL_SESSION * SSL_get_session(SSL *ssl)

{
  return (SSL_SESSION *)ssl[2].tlsext_ticket_expected;
}

