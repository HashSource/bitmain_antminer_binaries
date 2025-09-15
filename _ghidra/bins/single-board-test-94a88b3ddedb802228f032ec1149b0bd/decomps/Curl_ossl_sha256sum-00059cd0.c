
void Curl_ossl_sha256sum(void *param_1,size_t param_2,uchar *param_3)

{
  SHA256_CTX SStack_80;
  
  SHA256_Init(&SStack_80);
  SHA256_Update(&SStack_80,param_1,param_2);
  SHA256_Final(param_3,&SStack_80);
  return;
}

