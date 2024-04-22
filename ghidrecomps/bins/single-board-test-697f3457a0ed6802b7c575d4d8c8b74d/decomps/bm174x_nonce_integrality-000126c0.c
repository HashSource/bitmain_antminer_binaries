
int bm174x_nonce_integrality(uint8_t chipid,uint8_t nonce_array_id,int chainid)

{
  ushort uVar1;
  int iVar2;
  int chainid_local;
  uint8_t nonce_array_id_local;
  uint8_t chipid_local;
  char tmp42 [1024];
  uint16_t crc16;
  uint8_t *nonce_p;
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    uVar1 = CRC16_v1(g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i],0x59);
    crc16 = uVar1 >> 8 | uVar1 << 8;
    iVar2 = memcmp(&crc16,g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][i] + 0x59,2);
    if (iVar2 != 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        snprintf(tmp42,0x400,"%s CRC error. cal-crc=%x, chip-crc=%02x%02x\n",
                 "bm174x_nonce_integrality",(uint)crc16,
                 (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][0x59],
                 (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][0x5a]);
        _applog(0,tmp42,false);
      }
      return -1;
    }
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if ((g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][i][0] & 0xf) != i) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        snprintf(tmp42,0x400,"nonce is not continous i=%d\n",i);
        _applog(0,tmp42,false);
      }
      return -1;
    }
  }
  for (i = 0; i < 0xf; i = i + 1) {
    if (g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][1] !=
        g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i + 1][1]) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        snprintf(tmp42,0x400,"chip_addr is different %02x != %02x\n",
                 (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][1],
                 (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i + 1][1]);
        _applog(0,tmp42,false);
      }
      return -1;
    }
  }
  for (i = 0; i < 0xf; i = i + 1) {
    if (g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][2] !=
        g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i + 1][2]) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        snprintf(tmp42,0x400,"workID is different %02x != %02x\n",
                 (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][2],
                 (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i + 1][2]);
        _applog(0,tmp42,false);
      }
      return -1;
    }
  }
  i = 0;
  while( true ) {
    if (0xe < i) {
      nonce_p = (uint8_t *)(g_nonce + (uint)nonce_array_id + (uint)chipid);
      for (i = 0; i < 0xf; i = i + 1) {
        memcpy(nonce_p,g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][i] + 4,0x55);
        nonce_p = nonce_p + 0x55;
      }
      memcpy(nonce_p,g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][0xf] + 4,0x45);
      memcpy(g_nonce[(uint)nonce_array_id + (uint)chipid][0].chip_nonce,
             g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][0xf] + 0x55,4);
      g_nonce[(uint)nonce_array_id + (uint)chipid][0].chip_addr =
           g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][0xf][1];
      g_nonce[(uint)nonce_array_id + (uint)chipid][0].work_id =
           g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][0xf][2];
      g_nonce[(uint)nonce_array_id + (uint)chipid][0].nonce_id =
           g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][0xf][3];
      g_nonce[(uint)nonce_array_id + (uint)chipid][0].diff0 =
           g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][0xf][0x4c];
      memcpy(g_nonce[(uint)nonce_array_id + (uint)chipid][0].sha256,
             g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][0xf] + 0x4d,4);
      g_nonce[(uint)nonce_array_id + (uint)chipid][0].chain_id = (uint8_t)chainid;
      return 0;
    }
    if (g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][3] !=
        g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i + 1][3]) break;
    i = i + 1;
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
    snprintf(tmp42,0x400,"nonceID is different %02x != %02x chipid=%d\n",
             (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][3],
             (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i + 1][3],(uint)chipid);
    _applog(0,tmp42,false);
  }
  return -1;
}

