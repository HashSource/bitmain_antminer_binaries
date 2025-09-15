
void Curl_md5it(uchar *param_1,char *param_2)

{
  size_t len;
  MD5_CTX MStack_6c;
  
  MD5_Init(&MStack_6c);
  strlen(param_2);
  len = curlx_uztoui();
  MD5_Update(&MStack_6c,param_2,len);
  MD5_Final(param_1,&MStack_6c);
  return;
}

