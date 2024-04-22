
/* WARNING: Unknown calling convention */

_Bool sock_full(pool *pool)

{
  _Bool _Var1;
  
  if (*pool->sockbuf != '\0') {
    return true;
  }
  _Var1 = socket_full(pool,0);
  return _Var1;
}

