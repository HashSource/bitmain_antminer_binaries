
int hmac_get_url_message(char *port_name,char *user_id,char *key,char *payload,char *response_msg)

{
  size_t sVar1;
  size_t key_len;
  char *pcVar2;
  json_t *json;
  json_t *pjVar3;
  json_t *pjVar4;
  int iVar5;
  double dVar6;
  char *payload_local;
  char *key_local;
  char *user_id_local;
  char *port_name_local;
  char time_stamp_1 [48];
  json_error_t err;
  char tmp1 [2048];
  timeval stime;
  timeval tv_now;
  char signature_msg [65];
  uint8_t signature [32];
  uint8_t sig_message [100];
  char nonce [20];
  char get_url [1000];
  json_t *msg;
  int time_diff;
  json_t *offset;
  json_t *results;
  json_t *array;
  json_t *val;
  char *response;
  int i;
  
  memset(get_url,0,1000);
  nonce[0] = '\0';
  nonce[1] = '\0';
  nonce[2] = '\0';
  nonce[3] = '\0';
  nonce[4] = '\0';
  nonce[5] = '\0';
  nonce[6] = '\0';
  nonce[7] = '\0';
  nonce[8] = '\0';
  nonce[9] = '\0';
  nonce[10] = '\0';
  nonce[0xb] = '\0';
  nonce[0xc] = '\0';
  nonce[0xd] = '\0';
  nonce[0xe] = '\0';
  nonce[0xf] = '\0';
  nonce[0x10] = '\0';
  nonce[0x11] = '\0';
  nonce[0x12] = '\0';
  nonce[0x13] = '\0';
  memset(sig_message,0,100);
  memset(signature,0,0x20);
  memset(signature_msg,0,0x41);
  gettimeofday((timeval *)&tv_now,(__timezone_ptr_t)0x0);
  sprintf(nonce,"%ld",tv_now.tv_sec);
  strncat((char *)sig_message,port_name,99);
  sVar1 = strlen((char *)sig_message);
  strncat((char *)sig_message,user_id,99 - sVar1);
  sVar1 = strlen((char *)sig_message);
  strncat((char *)sig_message,nonce,99 - sVar1);
  sVar1 = strlen((char *)sig_message);
  key_len = strlen(key);
  hmac_sha256(signature,sig_message,sVar1,(uint8_t *)key,key_len);
  for (i = 0; i < 0x20; i = i + 1) {
    sprintf(signature_msg + i * 2,"%02x",(uint)signature[i]);
  }
  snprintf(get_url,1000,"%s/1?PortName=%s&Userid=%s&Nonce=%s&Signature=%s&json=%s",
           "http://mes.bitmain.vip:51611/api/Default/GetMes",port_name,user_id,nonce,signature_msg,
           payload);
  pcVar2 = http_get(get_url,false,false);
  if (pcVar2 == (char *)0x0) {
    if (response_msg != (char *)0x0) {
      strncpy(response_msg,"mes disconnect",100);
    }
    iVar5 = -1;
  }
  else {
    print_time_stamp((char *)&err,0x30);
    printf("%s ",&err);
    printf("%s: response messge:%s\n","hmac_get_url_message",pcVar2);
    snprintf(tmp1,0x800,"response messge:%s",pcVar2);
    log_to_file(tmp1,(char *)&err);
    json = json_loads(pcVar2,0,&err);
    free(pcVar2);
    if (json == (json_t *)0x0) {
      print_time_stamp(time_stamp_1,0x30);
      printf("%s ",time_stamp_1);
      printf("%s: JSON decode failed(%d): %s\n","hmac_get_url_message",err.line,err.text);
      snprintf(tmp1,0x800,"JSON decode failed(%d): %s",err.line,err.text);
      log_to_file(tmp1,time_stamp_1);
      iVar5 = 1;
    }
    else {
      if ((((json != (json_t *)0x0) && (json->type == JSON_ARRAY)) &&
          (pjVar3 = json_array_get(json,0), pjVar3 != (json_t *)0x0)) &&
         (pjVar3->type == JSON_OBJECT)) {
        pjVar4 = json_object_get(pjVar3,"results");
        if ((pjVar4 != (json_t *)0x0) && (pjVar4->type == JSON_STRING)) {
          pcVar2 = json_string_value(pjVar4);
          iVar5 = strncasecmp(pcVar2,"ok",2);
          if (iVar5 == 0) {
            print_time_stamp(time_stamp_1,0x30);
            printf("%s ",time_stamp_1);
            printf("%s: result ok\n","hmac_get_url_message");
            builtin_strncpy(tmp1,"result o",8);
            tmp1[8] = 'k';
            tmp1[9] = '\0';
            log_to_file(tmp1,time_stamp_1);
            json_decref(json);
            return 0;
          }
          pcVar2 = json_string_value(pjVar4);
          iVar5 = strncasecmp(pcVar2,"ng",2);
          if (((iVar5 == 0) && (pjVar4 = json_object_get(pjVar3,"offset"), pjVar4 != (json_t *)0x0))
             && (pjVar4->type == JSON_STRING)) {
            pcVar2 = json_string_value(pjVar4);
            dVar6 = atof(pcVar2);
            stime.tv_sec = 0;
            stime.tv_usec = 0;
            gettimeofday((timeval *)&stime,(__timezone_ptr_t)0x0);
            stime.tv_sec = stime.tv_sec + (int)(longlong)dVar6;
            settimeofday((timeval *)&stime,(timezone *)0x0);
            print_time_stamp(time_stamp_1,0x30);
            printf("%s ",time_stamp_1);
            printf("%s: result ng and set new time offset\n","hmac_get_url_message");
            builtin_strncpy(tmp1,"result ng and set new time offse",0x20);
            tmp1[0x20] = 't';
            tmp1[0x21] = '\0';
            log_to_file(tmp1,time_stamp_1);
            json_decref(json);
            return (int)(longlong)dVar6;
          }
        }
        pjVar3 = json_object_get(pjVar3,"msg");
        if ((pjVar3 != (json_t *)0x0) && (pjVar3->type == JSON_STRING)) {
          if (response_msg != (char *)0x0) {
            pcVar2 = json_string_value(pjVar3);
            strncpy(response_msg,pcVar2,100);
          }
          json_decref(json);
          return -2;
        }
      }
      json_decref(json);
      iVar5 = 1;
    }
  }
  return iVar5;
}

