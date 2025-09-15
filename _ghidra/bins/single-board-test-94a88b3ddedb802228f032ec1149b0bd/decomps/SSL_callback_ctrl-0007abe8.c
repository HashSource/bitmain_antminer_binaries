
long SSL_callback_ctrl(SSL *param_1,int param_2,_func_3517 *param_3)

{
  long lVar1;
  
  if (param_2 != 0xf) {
    lVar1 = (*param_1->method->ssl_callback_ctrl)(param_1,param_2,(fp *)param_3);
    return lVar1;
  }
  param_1->msg_callback = (_func_3292 *)param_3;
  return 1;
}

