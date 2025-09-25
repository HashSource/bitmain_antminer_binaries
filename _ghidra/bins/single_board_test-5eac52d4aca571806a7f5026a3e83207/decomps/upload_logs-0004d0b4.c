
_Bool upload_logs(char *file_path)

{
  _Bool _Var1;
  size_t sVar2;
  size_t key_len;
  int32_t iVar3;
  json_t *object;
  json_t *pjVar4;
  json_t *value;
  json_t *value_00;
  json_t *value_01;
  json_t *value_02;
  json_t *value_03;
  json_t *value_04;
  json_t *value_05;
  json_t *value_06;
  char *post_str;
  int iVar5;
  char *file_path_local;
  uint8_t signature [32];
  char ip [32];
  uint8_t sig_message [100];
  char str_signature [100];
  test_info_t m_test_info;
  char time_str [24];
  int err_pos;
  char nonce [20];
  time_t rawtime;
  log_info_t m_info;
  char *json_str;
  int utf8_ck;
  json_t *jdata;
  json_t *jcompress;
  json_t *jip;
  json_t *jsn;
  json_t *jboard_name;
  json_t *jminer_type;
  json_t *jsignature;
  json_t *jnonce;
  json_t *jusrId;
  json_t *upload_data;
  char *SECRET;
  char *KEY;
  char *sn;
  char *board_name;
  char *miner_type;
  char *userId;
  ulonglong time_val;
  _Bool read_res;
  char *resp;
  int i;
  _Bool upload_succ;
  
  memset(&m_info,0,400);
  strcpy(m_info.path,file_path);
  pthread_mutex_lock((pthread_mutex_t *)&file_mutex);
  _Var1 = read_compress_log_file(&m_info);
  pthread_mutex_unlock((pthread_mutex_t *)&file_mutex);
  upload_succ = false;
  if (_Var1) {
    if (m_info.data == (char *)0x0) {
      upload_succ = false;
    }
    else {
      time(&rawtime);
      memset(&m_test_info,0,0x300);
      get_test_info(file_path,&m_test_info);
      iVar5 = rawtime >> 0x1f;
      snprintf(nonce,0x14,"%llu",rawtime * 1000,rawtime * 1000,
               (((((iVar5 << 5 | (uint)rawtime >> 0x1b) - iVar5) -
                 (uint)((uint)(rawtime * 0x20) < (uint)rawtime)) * 4 |
                (uint)(rawtime * 0x1f) >> 0x1e) + iVar5 + (uint)CARRY4(rawtime * 0x7c,rawtime)) * 8
               | (uint)(rawtime * 0x7d) >> 0x1d);
      printf("nonce:%s\n",nonce);
      memset(sig_message,0,100);
      memset(signature,0,0x20);
      sVar2 = strlen((char *)sig_message);
      strncat((char *)sig_message,m_test_info.fac,99 - sVar2);
      sVar2 = strlen((char *)sig_message);
      strncat((char *)sig_message,"f5ece2e3-9b84-4052-a34a-645d3b5900a6",99 - sVar2);
      sVar2 = strlen((char *)sig_message);
      strncat((char *)sig_message,nonce,99 - sVar2);
      sVar2 = strlen((char *)sig_message);
      key_len = strlen("7796B3FFF1ECBA69A3CCB913C48BBD45");
      hmac_sha256(signature,sig_message,sVar2,(uint8_t *)"7796B3FFF1ECBA69A3CCB913C48BBD45",key_len)
      ;
      for (i = 0; (uint)i < 0x20; i = i + 1) {
        snprintf(str_signature + i * 2,i * -2 + 100,"%02X",(uint)signature[i]);
      }
      memset(ip,0,0x20);
      memset(ip,0,0x20);
      iVar3 = get_ip(ip);
      if (iVar3 != 0) {
        strncpy(ip,"55.55.55.55",0x1f);
      }
      object = json_object();
      pjVar4 = json_string(m_test_info.fac);
      value = json_string(nonce);
      value_00 = json_string(str_signature);
      value_01 = json_string(m_test_info.miner_type);
      value_02 = json_string(m_test_info.boardname);
      value_03 = json_string(m_test_info.sn);
      value_04 = json_string(ip);
      value_05 = json_string("1");
      value_06 = json_string(m_info.data);
      json_object_set(object,"userId",pjVar4);
      json_object_set(object,"nonce",value);
      json_object_set(object,"signature",value_00);
      json_object_set(object,"minerType",value_01);
      json_object_set(object,"boardName",value_02);
      json_object_set(object,"sn",value_03);
      json_object_set(object,"ip",value_04);
      json_object_set(object,"isCompress",value_05);
      if (value_06 == (json_t *)0x0) {
        err_pos = -1;
        utf8_check_string_x(m_info.data,-1,&err_pos);
        pjVar4 = json_string_nocheck(m_info.data);
        if (pjVar4 != (json_t *)0x0) {
          json_object_set(object,"log",pjVar4);
        }
      }
      else {
        json_object_set(object,"log",value_06);
      }
      post_str = json_dumps(object,0x200);
      if (object != (json_t *)0x0) {
        json_delete(object);
      }
      if (post_str != (char *)0x0) {
        resp = (char *)0x0;
        time_str[0] = '\0';
        time_str[1] = '\0';
        time_str[2] = '\0';
        time_str[3] = '\0';
        time_str[4] = '\0';
        time_str[5] = '\0';
        time_str[6] = '\0';
        time_str[7] = '\0';
        time_str[8] = '\0';
        time_str[9] = '\0';
        time_str[10] = '\0';
        time_str[0xb] = '\0';
        time_str[0xc] = '\0';
        time_str[0xd] = '\0';
        time_str[0xe] = '\0';
        time_str[0xf] = '\0';
        time_str[0x10] = '\0';
        time_str[0x11] = '\0';
        time_str[0x12] = '\0';
        time_str[0x13] = '\0';
        time_str[0x14] = '\0';
        time_str[0x15] = '\0';
        time_str[0x16] = '\0';
        time_str[0x17] = '\0';
        get_format_time(time_str);
        iVar5 = strncmp("PT2",m_test_info.test_type,3);
        if (((iVar5 == 0) || (iVar5 = strncmp("SWEEP",m_test_info.test_type,5), iVar5 == 0)) ||
           (iVar5 = strncmp("PT3",m_test_info.test_type,3), iVar5 == 0)) {
          resp = post_request("https://mtcs.bitmain.vip:443/public/api/mtc/uploadPtTwo.json",
                              post_str);
        }
        else {
          iVar5 = strncmp("PT1new",m_test_info.test_type,6);
          if (iVar5 == 0) {
            resp = post_request("https://mtcs.bitmain.vip:443/public/api/mtc/uploadPtOne.json",
                                post_str);
          }
        }
        get_format_time(time_str);
        upload_succ = resp != (char *)0x0;
        if (upload_succ) {
          free(resp);
        }
        free(post_str);
      }
      free(m_info.data);
    }
  }
  return upload_succ;
}

