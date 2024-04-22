
void Curl_digest_cleanup(int param_1)

{
  Curl_sasl_digest_cleanup(param_1 + 0x85d8);
  Curl_sasl_digest_cleanup(param_1 + 0x85fc);
  return;
}

