
/* WARNING: Unknown calling convention */

_Bool pool_unusable(pool *pool)

{
  if ((pool->idle == false) && (pool->enabled == POOL_ENABLED)) {
    if (pool->has_stratum == false) {
      return false;
    }
    if ((pool->stratum_active != false) && (pool->stratum_notify != false)) {
      return false;
    }
  }
  return true;
}

