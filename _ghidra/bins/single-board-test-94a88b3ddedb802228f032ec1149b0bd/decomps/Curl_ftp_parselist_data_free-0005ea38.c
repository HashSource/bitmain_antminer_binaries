
void Curl_ftp_parselist_data_free(undefined4 *param_1)

{
  (*Curl_cfree)(*param_1);
  *param_1 = 0;
  return;
}

