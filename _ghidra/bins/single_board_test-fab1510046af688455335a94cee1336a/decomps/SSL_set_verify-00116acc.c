
void SSL_set_verify(SSL *s,int mode,callback *callback)

{
  s->verify_mode = mode;
  if (callback != (callback *)0x0) {
    s->verify_callback = (_func_3293 *)callback;
  }
  return;
}

