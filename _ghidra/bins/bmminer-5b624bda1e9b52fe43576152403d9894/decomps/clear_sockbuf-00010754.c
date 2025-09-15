
/* WARNING: Unknown calling convention */

void clear_sockbuf(pool *pool)

{
  if (pool->sockbuf != (char *)0x0) {
    *pool->sockbuf = '\0';
  }
  return;
}

