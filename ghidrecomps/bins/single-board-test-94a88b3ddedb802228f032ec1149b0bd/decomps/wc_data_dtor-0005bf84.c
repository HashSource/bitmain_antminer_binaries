
void wc_data_dtor(int param_1)

{
  if (param_1 != 0) {
    Curl_ftp_parselist_data_free();
  }
  (**DAT_0005bf98)(param_1);
  return;
}

