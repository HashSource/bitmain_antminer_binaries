
int bm174x_nonce_handle(uint8_t *str,int len,uint32_t chainid,int addr_interval)

{
  byte bVar1;
  uint32_t uVar2;
  byte chipid_00;
  int iVar3;
  int addr_interval_local;
  uint32_t chainid_local;
  int len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  int ret;
  uint8_t nonce_array_id;
  uint8_t nonceid;
  uint8_t chipid;
  uint8_t chipaddr;
  uint8_t index;
  
  bVar1 = str[2];
  chipid_00 = __aeabi_idiv(str[3],addr_interval);
  memcpy(g_nonce_list[chipid_00][0] + (bVar1 & 0xf),str + 2,len - 2);
  if ((bVar1 & 0xf) == 0xf) {
    iVar3 = bm174x_nonce_integrality(chipid_00,'\0',chainid);
    uVar2 = bm174x_nonce_handle::total_error;
    if (iVar3 < 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
        bm174x_nonce_handle::total_error = bm174x_nonce_handle::total_error + 1;
        snprintf(tmp42,0x400,"receive a error nonce. total = %u\n",uVar2);
        _applog(1,tmp42,false);
      }
      iVar3 = -1;
    }
    else {
      push_nonce(g_nonce[chipid_00]);
      iVar3 = 0;
    }
  }
  else {
    iVar3 = 1;
  }
  return iVar3;
}

