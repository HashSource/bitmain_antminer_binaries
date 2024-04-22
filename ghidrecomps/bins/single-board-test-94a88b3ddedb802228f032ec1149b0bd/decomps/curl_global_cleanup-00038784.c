
void curl_global_cleanup(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_000387ac;
  if (*DAT_000387ac != 0) {
    iVar2 = *DAT_000387ac + -1;
    *DAT_000387ac = iVar2;
    if (iVar2 == 0) {
      Curl_global_host_cache_dtor();
      if (piVar1[1] << 0x1f < 0) {
        Curl_ssl_cleanup();
      }
      piVar1[1] = 0;
      return;
    }
  }
  return;
}

