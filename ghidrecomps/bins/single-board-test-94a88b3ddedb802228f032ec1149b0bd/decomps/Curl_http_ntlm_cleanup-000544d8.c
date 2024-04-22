
void Curl_http_ntlm_cleanup(int param_1)

{
  Curl_sasl_ntlm_cleanup(param_1 + 0x274);
  Curl_sasl_ntlm_cleanup(param_1 + 0x28c);
  Curl_ntlm_wb_cleanup(param_1);
  return;
}

