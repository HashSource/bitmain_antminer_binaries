
void site_blacklist_llist_dtor(undefined4 param_1,undefined4 *param_2)

{
  code *pcVar1;
  
  (*Curl_cfree)(*param_2);
  pcVar1 = Curl_cfree;
  *param_2 = 0;
  (*pcVar1)(param_2);
  return;
}

