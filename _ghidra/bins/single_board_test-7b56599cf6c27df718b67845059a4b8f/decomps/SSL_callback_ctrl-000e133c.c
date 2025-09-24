
long SSL_callback_ctrl(SSL *param_1,int param_2,_func_3517 *param_3)

{
  long lVar1;
  
  if (param_2 == 0xf) {
    param_1->read_hash = (EVP_MD_CTX *)param_3;
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x000e1354. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (**(code **)(param_1->type + 0x6c))();
  return lVar1;
}

