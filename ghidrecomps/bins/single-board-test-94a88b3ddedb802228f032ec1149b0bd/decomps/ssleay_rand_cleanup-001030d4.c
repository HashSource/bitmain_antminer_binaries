
void ssleay_rand_cleanup(void)

{
  OPENSSL_cleanse(state,0x413);
  state_num = 0;
  state_index = 0;
  OPENSSL_cleanse(md,0x14);
  md_count._0_4_ = 0;
  md_count._4_4_ = 0;
  entropy = 0;
  initialized = 0;
  return;
}

