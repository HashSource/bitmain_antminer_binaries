
void hash_element_dtor(int param_1,int *param_2)

{
  code *pcVar1;
  
  (*Curl_cfree)(param_2[1]);
  param_2[1] = 0;
  if (*param_2 != 0) {
    (**(code **)(param_1 + 0xc))();
    *param_2 = 0;
  }
  pcVar1 = Curl_cfree;
  param_2[2] = 0;
  (*pcVar1)(param_2);
  return;
}

