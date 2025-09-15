
void Curl_version_init(void)

{
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 in_r3;
  
  curl_version();
  curl_version_info(3,extraout_r1,extraout_r2,in_r3);
  return;
}

