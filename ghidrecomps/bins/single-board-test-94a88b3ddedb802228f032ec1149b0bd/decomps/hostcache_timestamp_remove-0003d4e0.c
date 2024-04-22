
bool hostcache_timestamp_remove(int *param_1,int param_2)

{
  if (*(int *)(param_2 + 4) == 0) {
    return false;
  }
  return *param_1 <= param_1[1] - *(int *)(param_2 + 4);
}

