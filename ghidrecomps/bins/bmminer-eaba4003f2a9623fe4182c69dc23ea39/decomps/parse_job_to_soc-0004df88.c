
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int parse_job_to_soc(uchar **buf,pool *pool,uint id)

{
  uchar *puVar1;
  bool bVar2;
  uint id_local;
  pool *pool_local;
  uchar **buf_local;
  char tmp42 [2048];
  part_of_job part_job;
  uint64_t nonce2;
  uint16_t crc;
  uchar *tmp_buf;
  char *buf_hex;
  uint buf_len;
  int i;
  
  crc = 0;
  buf_len = 0;
  nonce2._0_4_ = 0;
  nonce2._4_4_ = 0;
  buf_hex = (char *)0x0;
  part_job.token_type = 'R';
  part_job.version = '\0';
  part_job.pool_nu = (uchar)(uint)parse_job_to_soc::pool_send_nu;
  part_job._9_1_ = part_job._9_1_ & 0xfe | (pool->swork).clean & 1U | 2;
  part_job.asic_diff = '\x0f';
  part_job.job_id = id;
  hex2bin((uchar *)&part_job.bbversion,pool->bbversion,4);
  hex2bin(part_job.prev_hash,pool->prev_hash,0x20);
  hex2bin((uchar *)&part_job.nbit,pool->nbit,4);
  hex2bin((uchar *)&part_job.ntime,pool->ntime,4);
  part_job.coinbase_len = (uint16_t)pool->coinbase_len;
  part_job.nonce2_offset = (uint16_t)pool->nonce2_offset;
  part_job.nonce2_bytes_num = (uint16_t)pool->n2size;
  nonce2._0_4_ = *(undefined4 *)&pool->nonce2;
  nonce2._4_4_ = *(undefined4 *)((int)&pool->nonce2 + 4);
  memcpy(&part_job.nonce2_start_value,pool->coinbase + pool->nonce2_offset,8);
  memcpy(&part_job.nonce2_start_value,&nonce2,pool->n2size);
  part_job.merkles_num = (uint16_t)pool->merkles;
  buf_len = pool->coinbase_len + pool->merkles * 0x20 + 0x52;
  tmp_buf = (uchar *)malloc(buf_len);
  if (tmp_buf == (uchar *)0x0) {
    tmp42[0] = s_Failed_to_malloc_tmp_buf_00078eb8[0];
    tmp42[1] = s_Failed_to_malloc_tmp_buf_00078eb8[1];
    tmp42[2] = s_Failed_to_malloc_tmp_buf_00078eb8[2];
    tmp42[3] = s_Failed_to_malloc_tmp_buf_00078eb8[3];
    tmp42[4] = s_Failed_to_malloc_tmp_buf_00078eb8[4];
    tmp42[5] = s_Failed_to_malloc_tmp_buf_00078eb8[5];
    tmp42[6] = s_Failed_to_malloc_tmp_buf_00078eb8[6];
    tmp42[7] = s_Failed_to_malloc_tmp_buf_00078eb8[7];
    tmp42[8] = s_Failed_to_malloc_tmp_buf_00078eb8[8];
    tmp42[9] = s_Failed_to_malloc_tmp_buf_00078eb8[9];
    tmp42[10] = s_Failed_to_malloc_tmp_buf_00078eb8[10];
    tmp42[11] = s_Failed_to_malloc_tmp_buf_00078eb8[11];
    tmp42[12] = s_Failed_to_malloc_tmp_buf_00078eb8[12];
    tmp42[13] = s_Failed_to_malloc_tmp_buf_00078eb8[13];
    tmp42[14] = s_Failed_to_malloc_tmp_buf_00078eb8[14];
    tmp42[15] = s_Failed_to_malloc_tmp_buf_00078eb8[15];
    tmp42[16] = s_Failed_to_malloc_tmp_buf_00078eb8[16];
    tmp42[17] = s_Failed_to_malloc_tmp_buf_00078eb8[17];
    tmp42[18] = s_Failed_to_malloc_tmp_buf_00078eb8[18];
    tmp42[19] = s_Failed_to_malloc_tmp_buf_00078eb8[19];
    tmp42[20] = s_Failed_to_malloc_tmp_buf_00078eb8[20];
    tmp42[21] = s_Failed_to_malloc_tmp_buf_00078eb8[21];
    tmp42[22] = s_Failed_to_malloc_tmp_buf_00078eb8[22];
    tmp42[23] = s_Failed_to_malloc_tmp_buf_00078eb8[23];
    tmp42[24] = (char)ram0x00078ed0;
    _applog(3,tmp42,true);
    _quit(1);
  }
  part_job.length = buf_len - 8;
  memset(tmp_buf,0,buf_len);
  memcpy(tmp_buf,&part_job,0x50);
  memcpy(tmp_buf + 0x50,pool->coinbase,pool->coinbase_len);
  for (i = 0; i < pool->merkles; i = i + 1) {
    memcpy(tmp_buf + pool->coinbase_len + i * 0x20 + 0x50,(pool->swork).merkle_bin[i],0x20);
  }
  crc = CRC16(tmp_buf,(short)buf_len - 2);
  memcpy(tmp_buf + (buf_len - 2),&crc,2);
  bVar2 = 0xfffffffe < (uint)parse_job_to_soc::pool_send_nu;
  parse_job_to_soc::pool_send_nu._0_4_ = (uint)parse_job_to_soc::pool_send_nu + 1;
  parse_job_to_soc::pool_send_nu._4_4_ = parse_job_to_soc::pool_send_nu._4_4_ + (uint)bVar2;
  puVar1 = (uchar *)malloc(buf_len);
  *buf = puVar1;
  if (tmp_buf == (uchar *)0x0) {
    tmp42[0] = s_Failed_to_malloc_buf_00078ed4[0];
    tmp42[1] = s_Failed_to_malloc_buf_00078ed4[1];
    tmp42[2] = s_Failed_to_malloc_buf_00078ed4[2];
    tmp42[3] = s_Failed_to_malloc_buf_00078ed4[3];
    tmp42[4] = s_Failed_to_malloc_buf_00078ed4[4];
    tmp42[5] = s_Failed_to_malloc_buf_00078ed4[5];
    tmp42[6] = s_Failed_to_malloc_buf_00078ed4[6];
    tmp42[7] = s_Failed_to_malloc_buf_00078ed4[7];
    tmp42[8] = s_Failed_to_malloc_buf_00078ed4[8];
    tmp42[9] = s_Failed_to_malloc_buf_00078ed4[9];
    tmp42[10] = s_Failed_to_malloc_buf_00078ed4[10];
    tmp42[11] = s_Failed_to_malloc_buf_00078ed4[11];
    tmp42[12] = s_Failed_to_malloc_buf_00078ed4[12];
    tmp42[13] = s_Failed_to_malloc_buf_00078ed4[13];
    tmp42[14] = s_Failed_to_malloc_buf_00078ed4[14];
    tmp42[15] = s_Failed_to_malloc_buf_00078ed4[15];
    tmp42[16] = s_Failed_to_malloc_buf_00078ed4[16];
    tmp42[17] = s_Failed_to_malloc_buf_00078ed4[17];
    tmp42[18] = s_Failed_to_malloc_buf_00078ed4[18];
    tmp42[19] = s_Failed_to_malloc_buf_00078ed4[19];
    tmp42[20] = (char)ram0x00078ee8;
    _applog(3,tmp42,true);
    _quit(1);
  }
  memcpy(*buf,tmp_buf,buf_len);
  memcpy(last_job_buffer,tmp_buf,buf_len);
  free(tmp_buf);
  return buf_len;
}

