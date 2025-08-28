
undefined1 * curl_version_info(void)

{
  if (initialized_22795 == '\0') {
    Curl_ssl_version(ssl_buffer_22796,0x50);
    DAT_00194afc = ssl_buffer_22796;
    DAT_00194b04 = zlibVersion();
    initialized_22795 = '\x01';
  }
  return &version_info;
}

