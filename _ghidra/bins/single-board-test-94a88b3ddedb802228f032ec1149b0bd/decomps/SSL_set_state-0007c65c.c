
void SSL_set_state(SSL *ssl,int state)

{
  ssl->state = state;
  return;
}

