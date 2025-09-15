
long SSL_CTX_callback_ctrl(SSL_CTX *param_1,int param_2,_func_3520 *param_3)

{
  long lVar1;
  
  if (param_2 != 0xf) {
    lVar1 = (*param_1->method->ssl_ctx_callback_ctrl)(param_1,param_2,(fp *)param_3);
    return lVar1;
  }
  param_1->msg_callback = (_func_3237 *)param_3;
  return 1;
}

