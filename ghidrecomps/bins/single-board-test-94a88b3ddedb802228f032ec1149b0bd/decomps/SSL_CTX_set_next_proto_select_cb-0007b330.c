
void SSL_CTX_set_next_proto_select_cb(SSL_CTX *s,cb *cb,void *arg)

{
  s[1].stats.sess_connect = (int)cb;
  s[1].stats.sess_connect_renegotiate = (int)arg;
  return;
}

