
void SSL_CTX_set_not_resumable_session_callback(SSL_CTX *param_1,_func_3520 *param_2)

{
  SSL_CTX_callback_ctrl(param_1,0x4f,param_2);
  return;
}

