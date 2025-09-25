
void store_file_loader_deinit(void)

{
  ossl_store_unregister_loader_int(file_loader);
  return;
}

