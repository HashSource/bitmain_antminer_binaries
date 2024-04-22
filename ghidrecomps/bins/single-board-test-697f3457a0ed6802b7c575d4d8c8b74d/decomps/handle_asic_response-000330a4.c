
void * handle_asic_response(void *args)

{
  int iVar1;
  void *args_local;
  char tmp42 [1024];
  uint8_t header [3];
  int p_header;
  int data_buf_wp;
  int data_buf_rp;
  int max;
  uint8_t *tmp;
  uint8_t *data_buf;
  int data_buf_len;
  uint8_t *receive_buf;
  int resp_nonce_len;
  int chainid;
  runtime_base_t *runtime;
  int i;
  int len;
  
  chainid = *(int *)((int)args + 0x6ec);
  len = 0;
  resp_nonce_len = *(int *)((int)args + 0x94) * *(int *)((int)args + 0x90);
  runtime = (runtime_base_t *)args;
  receive_buf = (uint8_t *)calloc(1,resp_nonce_len);
  data_buf_len = resp_nonce_len * 0x32;
  data_buf = (uint8_t *)calloc(data_buf_len,1);
  data_buf_rp = 0;
  data_buf_wp = 0;
  tmp = (uint8_t *)calloc(1,(runtime->asic_data_info).resp_frame_max_len);
  if (tmp == (uint8_t *)0x0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s calloc tmp failed\n","handle_asic_response");
      _applog(2,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  max = data_buf_len;
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"Start A New Asic Response.Chain Id:[%d]\n",chainid);
    _applog(2,tmp42,false);
  }
  do {
    do {
      while (runtime->start_recv == 0) {
        pthread_testcancel();
        usleep(100000);
      }
      usleep(500);
      memset(receive_buf,0,resp_nonce_len);
      len = uart_receive((uchar)runtime->chain_status[chainid].fd,receive_buf,resp_nonce_len);
      for (i = 0; i < len; i = i + 1) {
        data_buf[data_buf_wp] = receive_buf[i];
        add_point(&data_buf_wp,max);
      }
    } while (data_buf_rp == data_buf_wp);
    if (data_buf_rp < data_buf_wp) {
      iVar1 = -data_buf_rp;
    }
    else {
      iVar1 = data_buf_len - data_buf_rp;
    }
    len = data_buf_wp + iVar1;
    while (2 < len) {
      p_header = data_buf_rp;
      header[0] = '\0';
      header[1] = '\0';
      header[2] = '\0';
      for (i = 0; i < 3; i = i + 1) {
        header[i] = data_buf[p_header];
        add_point(&p_header,max);
      }
      if ((header[0] == 0xaa) && (header[1] == 'U')) {
        if ((header[2] & 0xf0) == 0xe0) {
          if (len < (runtime->asic_data_info).resp_nonce_frame_len) break;
          for (i = 0; i < (runtime->asic_data_info).resp_nonce_frame_len; i = i + 1) {
            tmp[i] = data_buf[data_buf_rp];
            add_point(&data_buf_rp,max);
          }
          len = len - (runtime->asic_data_info).resp_nonce_frame_len;
          (*runtime->nonce_handle)
                    (tmp,(runtime->asic_data_info).resp_nonce_frame_len,chainid,
                     runtime->addr_interval);
        }
        else if (header[2] == 0xcc) {
          if (len < (runtime->asic_data_info).resp_pm_len) break;
          for (i = 0; i < (runtime->asic_data_info).resp_pm_len; i = i + 1) {
            tmp[i] = data_buf[data_buf_rp];
            add_point(&data_buf_rp,max);
          }
          len = len - (runtime->asic_data_info).resp_pm_len;
          (*runtime->pm_handle)(tmp,(runtime->asic_data_info).resp_pm_len,(uint8_t)chainid);
        }
        else if (header[2] == 0xd0) {
          if (len < (runtime->asic_data_info).resp_pt_len) break;
          for (i = 0; i < (runtime->asic_data_info).resp_pt_len; i = i + 1) {
            tmp[i] = data_buf[data_buf_rp];
            add_point(&data_buf_rp,max);
          }
          len = len - (runtime->asic_data_info).resp_pt_len;
          (*runtime->pt_handle)(tmp,(runtime->asic_data_info).resp_pt_len,(uint8_t)chainid);
        }
        else {
          if (len < (runtime->asic_data_info).resp_reg_len) break;
          for (i = 0; i < (runtime->asic_data_info).resp_reg_len; i = i + 1) {
            tmp[i] = data_buf[data_buf_rp];
            add_point(&data_buf_rp,max);
          }
          len = len - (runtime->asic_data_info).resp_reg_len;
          (*runtime->reg_handle)(tmp,(runtime->asic_data_info).resp_reg_len,(uint8_t)chainid);
        }
      }
      else {
        add_point(&data_buf_rp,max);
        len = len + -1;
      }
    }
  } while( true );
}

