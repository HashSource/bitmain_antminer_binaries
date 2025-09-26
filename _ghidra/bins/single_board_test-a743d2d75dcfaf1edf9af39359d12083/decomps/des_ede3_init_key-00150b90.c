
undefined4 des_ede3_init_key(int param_1,const_DES_cblock *param_2)

{
  DES_key_schedule *schedule;
  
  schedule = *(DES_key_schedule **)(param_1 + 0x60);
  schedule[3].ks[0].deslong[0] = 0;
  DES_set_key_unchecked(param_2,schedule);
  DES_set_key_unchecked(param_2 + 1,schedule + 1);
  DES_set_key_unchecked(param_2 + 2,schedule + 2);
  return 1;
}

