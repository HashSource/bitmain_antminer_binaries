
/* WARNING: Unknown calling convention */

void save_base_domain_nonce_data(void)

{
  uint32_t len;
  
  get_domain_nonce_data(base_domain_nonce_buf,&len);
  return;
}

