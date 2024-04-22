
uint32_t get_core_id(nonce_format_t nonce)

{
  nonce_format_t nonce_local;
  
  return (((nonce.v >> 0x10) << 0x11) >> 0x17) << 1 | nonce.v >> 0x1f;
}

