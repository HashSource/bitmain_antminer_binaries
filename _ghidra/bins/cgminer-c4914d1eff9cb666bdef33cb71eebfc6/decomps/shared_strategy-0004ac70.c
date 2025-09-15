
/* WARNING: Unknown calling convention */

_Bool shared_strategy(void)

{
  _Bool _Var1;
  
  if ((pool_strategy == POOL_LOADBALANCE) || (pool_strategy == POOL_BALANCE)) {
    _Var1 = true;
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

