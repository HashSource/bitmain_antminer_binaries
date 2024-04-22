
void Curl_ossl_md5sum(void *param_1,size_t param_2,uchar *param_3)

{
  MD5_CTX MStack_6c;
  
  MD5_Init(&MStack_6c);
  MD5_Update(&MStack_6c,param_1,param_2);
  MD5_Final(param_3,&MStack_6c);
  return;
}

