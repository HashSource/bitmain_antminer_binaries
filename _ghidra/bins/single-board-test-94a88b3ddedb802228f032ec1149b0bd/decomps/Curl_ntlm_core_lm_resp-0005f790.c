
void Curl_ntlm_core_lm_resp(int param_1,const_DES_cblock *param_2,DES_cblock *param_3)

{
  DES_key_schedule DStack_90;
  
  setup_des_key(param_1,&DStack_90);
  DES_ecb_encrypt(param_2,param_3,&DStack_90,1);
  setup_des_key(param_1 + 7,&DStack_90);
  DES_ecb_encrypt(param_2,param_3 + 1,&DStack_90,1);
  setup_des_key(param_1 + 0xe,&DStack_90);
  DES_ecb_encrypt(param_2,param_3 + 2,&DStack_90,1);
  return;
}

