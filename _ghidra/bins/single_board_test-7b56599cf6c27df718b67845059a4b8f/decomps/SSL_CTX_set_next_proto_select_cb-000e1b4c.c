
void SSL_CTX_set_next_proto_select_cb(SSL_CTX *s,cb *cb,void *arg)

{
  s[1].sessions = (lhash_st_SSL_SESSION *)cb;
  s[1].session_cache_size = (ulong)arg;
  return;
}

