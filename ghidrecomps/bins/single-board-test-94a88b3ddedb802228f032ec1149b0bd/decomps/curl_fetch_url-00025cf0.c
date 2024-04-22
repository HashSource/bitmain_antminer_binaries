
undefined4
curl_fetch_url(undefined4 param_1,undefined4 param_2,void **param_3,undefined4 param_4,
              undefined4 param_5)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = calloc(1,4);
  *param_3 = pvVar1;
  if (*param_3 == (void *)0x0) {
    fwrite("ERROR: Failed to allocate payload in curl_fetch_url",1,0x33,stderr);
    uVar2 = 2;
  }
  else {
    param_3[1] = (void *)0x0;
    curl_easy_setopt(param_1,0x2712,param_2);
    curl_easy_setopt(param_1,0x4e2b,0x25c59);
    curl_easy_setopt(param_1,0x2711,param_3);
    curl_easy_setopt(param_1,0x2722,
                     "Mozilla/5.0 (Windows NT 6.2; WOW64; rv:25.0) Gecko/20100101 Firefox/25.0");
    curl_easy_setopt(param_1,0xd,5);
    curl_easy_setopt(param_1,0x34,1);
    curl_easy_setopt(param_1,0x44,1);
    curl_easy_setopt(param_1,0x51,0);
    curl_easy_setopt(param_1,0x2771,param_4);
    curl_easy_setopt(param_1,0x29,0);
    curl_easy_setopt(param_1,0x20,0);
    curl_easy_setopt(param_1,0x2751,param_5);
    curl_easy_setopt(param_1,0x40,0);
    uVar2 = curl_easy_perform(param_1);
  }
  return uVar2;
}

