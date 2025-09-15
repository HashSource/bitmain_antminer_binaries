
undefined1 * Curl_global_host_cache_init(void)

{
  int iVar1;
  
  if (host_cache_initialized == 0) {
    iVar1 = Curl_hash_init(&hostname_cache,7,0x4cc99,0x4ccc9,0x3d5bd);
    if (iVar1 != 0) {
      return (undefined1 *)0x0;
    }
    host_cache_initialized = 1;
  }
  return &hostname_cache;
}

