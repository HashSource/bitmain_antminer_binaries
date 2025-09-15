
/* WARNING: Unknown calling convention */

int parse_job_to_c5(uchar **buf,pool *pool,uint id)

{
  byte *__s;
  undefined4 uVar1;
  uint uVar2;
  ushort uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  uint __size;
  int iVar11;
  size_t __n;
  byte *pbVar12;
  uchar *puVar13;
  uchar **ppuVar14;
  int iVar15;
  bool bVar16;
  uint16_t crc;
  uint64_t nonce2;
  part_of_job part_job;
  char tmp42 [2048];
  
  part_job.token_type = 'R';
  part_job._9_1_ = part_job._9_1_ & 0xfe | (pool->swork).clean & 1U | 2;
  part_job.version = '\0';
  part_job.pool_nu = (uchar)(uint)parse_job_to_c5::pool_send_nu;
  part_job.asic_diff = '\x0f';
  part_job.job_id = id;
  hex2bin((uchar *)&part_job.bbversion,pool->bbversion,4);
  hex2bin(part_job.prev_hash,pool->prev_hash,0x20);
  hex2bin((uchar *)&part_job.nbit,pool->nbit,4);
  hex2bin((uchar *)&part_job.ntime,pool->ntime,4);
  puVar13 = pool->coinbase;
  nonce2._0_4_ = (undefined4)pool->nonce2;
  nonce2._4_4_ = *(undefined4 *)((int)&pool->nonce2 + 4);
  __n = pool->coinbase_len;
  part_job.nonce2_offset = (uint16_t)pool->nonce2_offset;
  part_job.coinbase_len = (uint16_t)__n;
  part_job.nonce2_bytes_num = (uint16_t)pool->n2size;
  part_job.nonce2_start_value._0_4_ = *(undefined4 *)(puVar13 + pool->nonce2_offset);
  part_job.nonce2_start_value._4_4_ = *(undefined4 *)(puVar13 + pool->nonce2_offset + 4);
  memcpy(&part_job.nonce2_start_value,&nonce2,pool->n2size);
  iVar10 = pool->merkles;
  part_job.merkles_num = (uint16_t)iVar10;
  iVar9 = __n + iVar10 * 0x20;
  __size = iVar9 + 0x52;
  __s = (byte *)malloc(__size);
  iVar11 = 1 - (int)__s;
  if ((byte *)0x1 < __s) {
    iVar11 = 0;
  }
  if (iVar11 != 0) {
    builtin_strncpy(tmp42,"Failed to malloc tmp_buf",0x18);
    tmp42[0x18] = '\0';
    _applog(3,tmp42,true);
    _quit(1);
    puVar13 = pool->coinbase;
    __n = pool->coinbase_len;
    iVar10 = pool->merkles;
  }
  part_job.length = iVar9 + 0x4a;
  memset(__s,0,__size);
  memcpy(__s,&part_job,0x50);
  memcpy(__s + 0x50,puVar13,__n);
  if (0 < iVar10) {
    pbVar12 = __s + __n + 0x50;
    iVar15 = 0;
    ppuVar14 = (pool->swork).merkle_bin + -1;
    do {
      ppuVar14 = ppuVar14 + 1;
      puVar13 = *ppuVar14;
      iVar15 = iVar15 + 1;
      uVar1 = *(undefined4 *)(puVar13 + 4);
      uVar4 = *(undefined4 *)(puVar13 + 8);
      uVar6 = *(undefined4 *)(puVar13 + 0xc);
      *(undefined4 *)pbVar12 = *(undefined4 *)puVar13;
      *(undefined4 *)(pbVar12 + 4) = uVar1;
      *(undefined4 *)(pbVar12 + 8) = uVar4;
      *(undefined4 *)(pbVar12 + 0xc) = uVar6;
      uVar1 = *(undefined4 *)(puVar13 + 0x14);
      uVar4 = *(undefined4 *)(puVar13 + 0x18);
      uVar6 = *(undefined4 *)(puVar13 + 0x1c);
      *(undefined4 *)(pbVar12 + 0x10) = *(undefined4 *)(puVar13 + 0x10);
      *(undefined4 *)(pbVar12 + 0x14) = uVar1;
      *(undefined4 *)(pbVar12 + 0x18) = uVar4;
      *(undefined4 *)(pbVar12 + 0x1c) = uVar6;
      pbVar12 = pbVar12 + 0x20;
    } while (iVar15 != iVar10);
  }
  if ((__size & 0xffff) == 2) {
    uVar3 = 0xffff;
  }
  else {
    uVar5 = 0xff;
    uVar2 = 0xff;
    pbVar12 = __s;
    do {
      pbVar8 = pbVar12 + 1;
      uVar7 = *pbVar12 ^ uVar2;
      uVar2 = uVar5 ^ ""[uVar7];
      uVar5 = (uint)""[uVar7];
      pbVar12 = pbVar8;
    } while (pbVar8 != __s + (iVar9 + 0x4fU & 0xffff) + 1);
    uVar3 = (ushort)uVar2 | (ushort)""[uVar7] << 8;
  }
  *(ushort *)(__s + iVar9 + 0x50) = uVar3;
  bVar16 = 0xfffffffe < (uint)parse_job_to_c5::pool_send_nu;
  parse_job_to_c5::pool_send_nu._0_4_ = (uint)parse_job_to_c5::pool_send_nu + 1;
  parse_job_to_c5::pool_send_nu._4_4_ = parse_job_to_c5::pool_send_nu._4_4_ + (uint)bVar16;
  puVar13 = (uchar *)malloc(__size);
  *buf = puVar13;
  if (iVar11 != 0) {
    builtin_strncpy(tmp42,"Failed to malloc buf",0x14);
    tmp42._20_4_ = tmp42._20_4_ & 0xffffff00;
    _applog(3,tmp42,true);
    _quit(1);
    puVar13 = *buf;
  }
  memcpy(puVar13,__s,__size);
  memcpy(last_job_buffer,__s,__size);
  free(__s);
  return __size;
}

