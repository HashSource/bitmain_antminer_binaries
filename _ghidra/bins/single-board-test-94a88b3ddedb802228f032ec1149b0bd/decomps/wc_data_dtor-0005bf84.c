
void wc_data_dtor(int param_1)

{
  if (param_1 != 0) {
    Curl_ftp_parselist_data_free();
  }
  (*Curl_cfree)(param_1);
  return;
}

