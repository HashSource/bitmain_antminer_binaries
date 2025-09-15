
void mining_parse_job(char *str,uint8_t *target,int target_len,char *job_id,int job_id_len,
                     uint8_t *header,int header_len,int *fixed_nonce_bytes)

{
  uint32_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  char *job_id_local;
  int target_len_local;
  uint8_t *target_local;
  char *str_local;
  char tmp42 [1024];
  uint32_t i;
  uint32_t str_i;
  
  str_i = 0;
  for (i = 0; i < (uint)target_len; i = i + 1) {
    uVar2 = hex2val(str,str_i);
    uVar3 = hex2val(str,str_i + 1);
    target[i] = uVar3 + uVar2 * '\x10';
    str_i = str_i + 2;
  }
  if (str[str_i] != ' ') {
                    /* WARNING: Subroutine does not return */
    __assert_fail("str[str_i] == \' \'","bm174x/equihash-miner.c",0x152,"mining_parse_job");
  }
  i = 0;
  uVar1 = str_i;
  while ((str_i = uVar1 + 1, i < (uint)job_id_len && (str[str_i] != ' '))) {
    job_id[i] = str[str_i];
    i = i + 1;
    uVar1 = str_i;
  }
  if (str[str_i] != ' ') {
                    /* WARNING: Subroutine does not return */
    __assert_fail("str[str_i] == \' \'","bm174x/equihash-miner.c",0x158,"mining_parse_job");
  }
  if ((uint)job_id_len <= i) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("i < job_id_len","bm174x/equihash-miner.c",0x159,"mining_parse_job");
  }
  job_id[i] = '\0';
  i = 0;
  while ((str_i = uVar1 + 2, i < (uint)header_len && (str[str_i] != ' '))) {
    uVar2 = hex2val(str,str_i);
    uVar3 = hex2val(str,uVar1 + 3);
    header[i] = uVar3 + uVar2 * '\x10';
    i = i + 1;
    uVar1 = str_i;
  }
  if (str[str_i] != ' ') {
                    /* WARNING: Subroutine does not return */
    __assert_fail("str[str_i] == \' \'","bm174x/equihash-miner.c",0x160,"mining_parse_job");
  }
  str_i = uVar1 + 3;
  *fixed_nonce_bytes = 0;
  while ((i < (uint)header_len && (str[str_i] != '\0'))) {
    uVar2 = hex2val(str,str_i);
    uVar3 = hex2val(str,str_i + 1);
    header[i] = uVar3 + uVar2 * '\x10';
    i = i + 1;
    str_i = str_i + 2;
    *fixed_nonce_bytes = *fixed_nonce_bytes + 1;
  }
  if (str[str_i] != '\0') {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!str[str_i]","bm174x/equihash-miner.c",0x16b,"mining_parse_job");
  }
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
    snprintf(tmp42,0x400,"Randomizing %d bytes in nonce\n",(header_len - i) + -0xc);
    _applog(4,tmp42,false);
  }
  randomize(header + i,(header_len - i) + -0xc);
  memset(header + header_len + -0xc,0,0xc);
  return;
}

