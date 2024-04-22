
undefined4 add_url(void)

{
  total_urls = total_urls + 1;
  if (total_pools < total_urls) {
    add_pool();
  }
  return *(undefined4 *)(pools + (total_urls + 0x3fffffff) * 4);
}

