
void clear_sock(pool *pool)

{
  pool *pool_local;
  ssize_t n;
  
  _mutex_lock(&pool->stratum_lock,"util.c","clear_sock",0x6e5);
  do {
    if (pool->sock == 0) {
      n = 0;
    }
    else {
      n = recv(pool->sock,pool->sockbuf,0x1ffc,0);
    }
  } while (0 < n);
  _mutex_unlock(&pool->stratum_lock,"util.c","clear_sock",0x6ee);
  clear_sockbuf(pool);
  return;
}

