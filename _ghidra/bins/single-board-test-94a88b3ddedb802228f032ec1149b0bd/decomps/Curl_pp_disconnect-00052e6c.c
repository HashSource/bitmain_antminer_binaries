
void Curl_pp_disconnect(undefined4 *param_1)

{
  (*Curl_cfree)(*param_1);
  *param_1 = 0;
  return;
}

