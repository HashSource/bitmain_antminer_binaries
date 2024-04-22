
int SSL_CTX_set_cipher_list(SSL_CTX *param_1,char *str)

{
  _STACK *p_Var1;
  int iVar2;
  
  p_Var1 = (_STACK *)
           ssl_create_cipher_list
                     (param_1->method,&param_1->cipher_list,&param_1->cipher_list_by_id,str,
                      param_1->cert);
  if (p_Var1 != (_STACK *)0x0) {
    iVar2 = sk_num(p_Var1);
    p_Var1 = (_STACK *)0x1;
    if (iVar2 == 0) {
      ERR_put_error(0x14,0x10d,0xb9,DAT_0007aec4,0x55c);
      p_Var1 = (_STACK *)0x0;
    }
  }
  return (int)p_Var1;
}

