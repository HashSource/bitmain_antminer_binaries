
void clear_sock(pool *pool)

{
  pool *pool_local;
  ssize_t n;
  
  _mutex_lock(&pool->stratum_lock,"util.c","clear_sock",0x721);
  do {
    if (pool->sock == 0) {
      n = 0;
    }
    else {
      n = recv(pool->sock,pool->sockbuf,0x1ffc,0);
    }
  } while (0 < n);
  _mutex_unlock(&pool->stratum_lock,"util.c","clear_sock",0x72a);
  clear_sockbuf(pool);
  return;
}

