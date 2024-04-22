
void Curl_conncache_destroy(int param_1)

{
  if (param_1 != 0) {
    Curl_hash_destroy();
    return;
  }
  return;
}

