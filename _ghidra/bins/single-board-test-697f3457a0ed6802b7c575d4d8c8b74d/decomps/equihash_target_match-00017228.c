
_Bool equihash_target_match(uchar *result_value,uchar *target)

{
  uchar *target_local;
  uchar *result_value_local;
  int i;
  
  i = 0x1f;
  while( true ) {
    if (i < 0) {
      return true;
    }
    if (result_value[i] < target[i]) break;
    if (target[i] < result_value[i]) {
      return false;
    }
    i = i + -1;
  }
  return true;
}

