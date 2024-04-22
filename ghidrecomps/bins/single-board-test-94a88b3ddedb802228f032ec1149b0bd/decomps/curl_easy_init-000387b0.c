
undefined4 curl_easy_init(void)

{
  int iVar1;
  undefined4 local_c [3];
  
  if (((*DAT_000387d4 == 0) && (iVar1 = curl_global_init(3), iVar1 != 0)) ||
     (iVar1 = Curl_open(local_c), iVar1 != 0)) {
    local_c[0] = 0;
  }
  return local_c[0];
}

