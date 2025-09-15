
void secure_zero_memory(void *v,size_t n)

{
  size_t n_local;
  void *v_local;
  
  (*secure_zero_memory::memset_v)(v,0,n);
  return;
}

