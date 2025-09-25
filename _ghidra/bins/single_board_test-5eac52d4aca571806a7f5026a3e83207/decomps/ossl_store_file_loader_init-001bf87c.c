
undefined4 ossl_store_file_loader_init(void)

{
  undefined4 uVar1;
  
  uVar1 = ossl_store_register_loader_int(&file_loader);
  OPENSSL_atexit(0x1be301);
  return uVar1;
}

