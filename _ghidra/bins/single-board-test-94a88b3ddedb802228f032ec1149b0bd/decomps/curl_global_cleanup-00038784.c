
void curl_global_cleanup(void)

{
  if (initialized != 0) {
    initialized = initialized + -1;
    if (initialized == 0) {
      Curl_global_host_cache_dtor();
      if (init_flags << 0x1f < 0) {
        Curl_ssl_cleanup();
      }
      init_flags = 0;
      return;
    }
  }
  return;
}

