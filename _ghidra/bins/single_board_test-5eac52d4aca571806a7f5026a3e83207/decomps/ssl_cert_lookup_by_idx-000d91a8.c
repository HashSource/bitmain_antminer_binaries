
undefined1 * ssl_cert_lookup_by_idx(uint param_1)

{
  if (param_1 < 9) {
    return ssl_cert_info + param_1 * 8;
  }
  return (undefined1 *)0x0;
}

