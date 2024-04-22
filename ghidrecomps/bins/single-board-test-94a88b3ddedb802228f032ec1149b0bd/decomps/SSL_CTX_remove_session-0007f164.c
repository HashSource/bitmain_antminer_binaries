
int SSL_CTX_remove_session(SSL_CTX *param_1,SSL_SESSION *c)

{
  int iVar1;
  
  if ((c != (SSL_SESSION *)0x0) && (c->session_id_length != 0)) {
    iVar1 = remove_session_lock_part_1(param_1,c,1);
    return iVar1;
  }
  return 0;
}

