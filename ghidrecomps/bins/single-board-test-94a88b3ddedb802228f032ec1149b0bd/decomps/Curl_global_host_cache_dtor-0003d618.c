
void Curl_global_host_cache_dtor(void)

{
  if (host_cache_initialized != 0) {
    Curl_hash_destroy(&hostname_cache);
    host_cache_initialized = 0;
  }
  return;
}

