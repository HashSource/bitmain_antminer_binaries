
void Curl_add_buffer_free(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    (*Curl_cfree)(*param_1);
  }
  (*Curl_cfree)(param_1);
  return;
}

