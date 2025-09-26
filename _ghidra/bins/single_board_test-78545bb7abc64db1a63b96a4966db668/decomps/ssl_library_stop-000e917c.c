
void ssl_library_stop(void)

{
  if (stopped == 0) {
    stopped = 1;
    if (ssl_base_inited != 0) {
      ssl_comp_free_compression_methods_int();
      return;
    }
  }
  return;
}

