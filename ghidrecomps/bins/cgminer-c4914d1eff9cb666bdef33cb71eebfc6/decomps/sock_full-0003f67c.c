
_Bool sock_full(pool *pool)

{
  _Bool _Var1;
  pool *pool_local;
  
  if (*pool->sockbuf == '\0') {
    _Var1 = socket_full(pool,0);
  }
  else {
    _Var1 = true;
  }
  return _Var1;
}

