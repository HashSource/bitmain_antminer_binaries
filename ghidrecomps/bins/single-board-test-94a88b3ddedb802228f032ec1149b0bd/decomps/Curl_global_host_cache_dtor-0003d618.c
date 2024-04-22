
void Curl_global_host_cache_dtor(void)

{
  int iVar1;
  
  iVar1 = DAT_0003d62c;
  if (*(int *)(DAT_0003d62c + 0x18) != 0) {
    Curl_hash_destroy(DAT_0003d62c);
    *(undefined4 *)(iVar1 + 0x18) = 0;
  }
  return;
}

