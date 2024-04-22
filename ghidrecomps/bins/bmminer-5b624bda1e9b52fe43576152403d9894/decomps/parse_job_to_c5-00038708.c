
/* WARNING: Unknown calling convention */

int parse_job_to_c5(uchar **buf,pool *pool,uint id)

{
  byte bVar1;
  uint *puVar2;
  byte *__s;
  uchar *tmp_buf;
  undefined4 uVar3;
  uint uVar4;
  ushort uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  int iVar12;
  int iVar13;
  size_t __size;
  int iVar14;
  size_t __n;
  undefined4 *puVar15;
  uchar *puVar16;
  uchar **ppuVar17;
  int iVar18;
  uint16_t crc;
  uint64_t nonce2;
  part_of_job part_job;
  char tmp42 [2048];
  byte *pbVar11;
  
  part_job.token_type = 'R';
  part_job._9_1_ = part_job._9_1_ & 0xfe | (pool->swork).clean & 1U | 2;
  part_job.version = '\0';
  part_job.pool_nu = (uchar)*(undefined4 *)(DAT_00038950 + 0x988);
  part_job.asic_diff = '\x0f';
  part_job.job_id = id;
  hex2bin((uchar *)&part_job.bbversion,pool->bbversion,4);
  hex2bin(part_job.prev_hash,pool->prev_hash,0x20);
  hex2bin((uchar *)&part_job.nbit,pool->nbit,4);
  hex2bin((uchar *)&part_job.ntime,pool->ntime,4);
  puVar16 = pool->coinbase;
  nonce2._0_4_ = *(undefined4 *)&pool->nonce2;
  nonce2._4_4_ = *(undefined4 *)((int)&pool->nonce2 + 4);
  __n = pool->coinbase_len;
  part_job.nonce2_offset = (uint16_t)pool->nonce2_offset;
  part_job.coinbase_len = (uint16_t)__n;
  part_job.nonce2_bytes_num = (uint16_t)pool->n2size;
  part_job.nonce2_start_value._0_4_ = *(undefined4 *)(puVar16 + pool->nonce2_offset);
  part_job.nonce2_start_value._4_4_ = *(undefined4 *)((int)(puVar16 + pool->nonce2_offset) + 4);
  memcpy(&part_job.nonce2_start_value,&nonce2,pool->n2size);
  iVar13 = pool->merkles;
  part_job.merkles_num = (uint16_t)iVar13;
  iVar12 = __n + iVar13 * 0x20;
  __size = iVar12 + 0x52;
  __s = (byte *)malloc(__size);
  iVar14 = 1 - (int)__s;
  if ((byte *)0x1 < __s) {
    iVar14 = 0;
  }
  if (iVar14 != 0) {
    tmp42._0_4_ = *DAT_00038964;
    tmp42._4_4_ = DAT_00038964[1];
    tmp42._8_4_ = DAT_00038964[2];
    tmp42._12_4_ = DAT_00038964[3];
    tmp42._16_4_ = DAT_00038964[4];
    tmp42._20_4_ = DAT_00038964[5];
    tmp42[24] = (char)DAT_00038964[6];
    _applog(3,tmp42,true);
    _quit(1);
    puVar16 = pool->coinbase;
    __n = pool->coinbase_len;
    iVar13 = pool->merkles;
  }
  part_job.length = iVar12 + 0x4a;
  memset(__s,0,__size);
  memcpy(__s,&part_job,0x50);
  memcpy(__s + 0x50,puVar16,__n);
  if (0 < iVar13) {
    puVar15 = (undefined4 *)(__s + __n + 0x50);
    iVar18 = 0;
    ppuVar17 = (pool->swork).merkle_bin + -1;
    do {
      ppuVar17 = ppuVar17 + 1;
      puVar9 = (undefined4 *)*ppuVar17;
      iVar18 = iVar18 + 1;
      uVar3 = puVar9[1];
      uVar6 = puVar9[2];
      uVar8 = puVar9[3];
      *puVar15 = *puVar9;
      puVar15[1] = uVar3;
      puVar15[2] = uVar6;
      puVar15[3] = uVar8;
      uVar3 = puVar9[5];
      uVar6 = puVar9[6];
      uVar8 = puVar9[7];
      puVar15[4] = puVar9[4];
      puVar15[5] = uVar3;
      puVar15[6] = uVar6;
      puVar15[7] = uVar8;
      puVar15 = puVar15 + 8;
    } while (iVar18 != iVar13);
  }
  puVar2 = DAT_00038954;
  if ((__size & 0xffff) == 2) {
    uVar5 = 0xffff;
  }
  else {
    uVar7 = 0xff;
    uVar4 = 0xff;
    pbVar11 = __s;
    do {
      pbVar10 = pbVar11 + 1;
      iVar13 = (*pbVar11 ^ uVar4) + DAT_00038960;
      uVar4 = uVar7 ^ *(byte *)(iVar13 + 0x7b8);
      bVar1 = *(byte *)(iVar13 + 0x8b8);
      uVar7 = (uint)bVar1;
      pbVar11 = pbVar10;
    } while (pbVar10 != __s + (iVar12 + 0x4fU & 0xffff) + 1);
    uVar5 = (ushort)uVar4 | (ushort)bVar1 << 8;
  }
  *(ushort *)(__s + iVar12 + 0x50) = uVar5;
  uVar4 = *puVar2;
  *puVar2 = uVar4 + 1;
  puVar2[1] = puVar2[1] + (uint)(0xfffffffe < uVar4);
  puVar16 = (uchar *)malloc(__size);
  *buf = puVar16;
  if (iVar14 != 0) {
    tmp42._0_4_ = *DAT_0003895c;
    tmp42._4_4_ = DAT_0003895c[1];
    tmp42._8_4_ = DAT_0003895c[2];
    tmp42._12_4_ = DAT_0003895c[3];
    tmp42._16_4_ = DAT_0003895c[4];
    tmp42[20] = (char)DAT_0003895c[5];
    _applog(3,tmp42,true);
    _quit(1);
    puVar16 = *buf;
  }
  memcpy(puVar16,__s,__size);
  memcpy(DAT_00038958,__s,__size);
  free(__s);
  return __size;
}

