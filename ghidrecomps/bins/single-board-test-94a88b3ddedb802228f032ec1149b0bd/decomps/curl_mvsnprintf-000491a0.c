
void curl_mvsnprintf(undefined *param_1,int param_2)

{
  undefined *local_14;
  int local_10;
  int local_c;
  
  local_10 = 0;
  local_14 = param_1;
  local_c = param_2;
  dprintf_formatf(&local_14,DAT_000491cc);
  if (local_c != 0) {
    if (local_c == local_10) {
      local_14[-1] = 0;
    }
    else {
      *local_14 = 0;
    }
  }
  return;
}

