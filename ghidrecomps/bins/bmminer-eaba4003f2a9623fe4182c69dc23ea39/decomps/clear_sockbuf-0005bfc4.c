
void clear_sockbuf(pool *pool)

{
  pool *pool_local;
  
  if (pool->sockbuf != (char *)0x0) {
    *pool->sockbuf = '\0';
  }
  return;
}

