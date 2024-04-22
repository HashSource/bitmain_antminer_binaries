
undefined4 Curl_ntlm_core_mk_lm_hash(undefined4 param_1,char *param_2,DES_cblock *param_3)

{
  size_t sVar1;
  size_t __n;
  undefined auStack_a8 [7];
  undefined auStack_a1 [9];
  DES_key_schedule DStack_98;
  
  sVar1 = strlen(param_2);
  if (sVar1 < 0xe) {
    __n = 0xe - sVar1;
  }
  else {
    sVar1 = 0xe;
    __n = 0;
  }
  Curl_strntoupper(auStack_a8,param_2,sVar1);
  memset(auStack_a8 + sVar1,0,__n);
  setup_des_key(auStack_a8,&DStack_98);
  DES_ecb_encrypt(DAT_0005f854,param_3,&DStack_98,1);
  setup_des_key(auStack_a1,&DStack_98);
  DES_ecb_encrypt(DAT_0005f854,param_3 + 1,&DStack_98,1);
  param_3[2][0] = '\0';
  param_3[2][1] = '\0';
  param_3[2][2] = '\0';
  param_3[2][3] = '\0';
  param_3[2][4] = '\0';
  return 0;
}

