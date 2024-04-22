
int SSL_set_cipher_list(SSL *s,char *str)

{
  _STACK *p_Var1;
  int iVar2;
  
  p_Var1 = (_STACK *)
           ssl_create_cipher_list
                     (*(undefined4 *)s->psk_server_callback,&s->cipher_list,&s->cipher_list_by_id,
                      str,s->cert);
  if (p_Var1 != (_STACK *)0x0) {
    iVar2 = sk_num(p_Var1);
    p_Var1 = (_STACK *)0x1;
    if (iVar2 == 0) {
      ERR_put_error(0x14,0x10f,0xb9,DAT_0007af10,0x56d);
      p_Var1 = (_STACK *)0x0;
    }
  }
  return (int)p_Var1;
}

