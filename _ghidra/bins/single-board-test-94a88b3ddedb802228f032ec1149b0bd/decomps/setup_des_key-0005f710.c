
void setup_des_key(uchar *param_1,DES_key_schedule *param_2)

{
  uchar local_28;
  byte local_27;
  byte local_26;
  byte local_25;
  byte local_24;
  byte local_23;
  byte local_22;
  uchar local_21;
  
  local_28 = *param_1;
  local_25 = param_1[3] >> 3 | param_1[2] << 5;
  local_26 = param_1[2] >> 2 | param_1[1] << 6;
  local_21 = param_1[6] << 1;
  local_27 = param_1[1] >> 1 | local_28 << 7;
  local_23 = param_1[5] >> 5 | param_1[4] << 3;
  local_24 = param_1[4] >> 4 | param_1[3] << 4;
  local_22 = param_1[6] >> 6 | param_1[5] << 2;
  DES_set_odd_parity((DES_cblock *)&local_28);
  DES_set_key((const_DES_cblock *)&local_28,param_2);
  return;
}

