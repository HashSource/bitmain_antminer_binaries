
/* WARNING: Unknown calling convention */

int32_t dhash_send_job(dhash_job_info_t *job)

{
  byte *__dest;
  undefined4 uVar1;
  byte *pbVar2;
  uint uVar3;
  uint32_t uVar4;
  byte *pbVar5;
  size_t __nmemb;
  byte *pbVar6;
  uint8_t *puVar7;
  uint uVar8;
  uint32_t *puVar9;
  uint32_t *puVar10;
  undefined4 uVar11;
  uint *puVar12;
  undefined4 uVar13;
  uint32_t *puVar14;
  uint32_t tmp;
  uint32_t buf2 [8];
  
  memset(buf2,0,0x20);
  uVar8 = job->coinbase_len;
  puVar14 = job_start_address_1;
  if (job_start_address_1 == current_job_start_address) {
    puVar14 = job_start_address_2;
  }
  if ((uVar8 & 0x3f) < 0x38) {
    __nmemb = (uVar8 & 0xffffffc0) + 0x40;
  }
  else {
    __nmemb = (uVar8 & 0xffffffc0) + 0x80;
  }
  __dest = (byte *)calloc(__nmemb,1);
  if (__dest == (byte *)0x0) {
    return -4;
  }
  memcpy(__dest,job->coinbase,uVar8);
  uVar3 = uVar8 << 3;
  __dest[uVar8] = 0x80;
  *(uint *)(__dest + (__nmemb - 4)) =
       uVar8 << 0x1b | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
  pbVar5 = __dest + (__nmemb - 8);
  pbVar5[0] = 0;
  pbVar5[1] = 0;
  pbVar5[2] = 0;
  pbVar5[3] = 0;
  if (__nmemb != 0) {
    pbVar5 = (byte *)((int)puVar14 + -1);
    pbVar2 = __dest;
    do {
      pbVar6 = pbVar2 + 1;
      pbVar5 = pbVar5 + 1;
      *pbVar5 = *pbVar2;
      pbVar2 = pbVar6;
    } while (pbVar6 != __dest + __nmemb);
    pbVar5 = __dest + -1;
    puVar9 = puVar14;
    do {
      pbVar5 = pbVar5 + 1;
      puVar10 = (uint32_t *)((int)puVar9 + 1);
      if ((uint)(byte)*puVar9 != (uint)*pbVar5) {
        printf("%s: coinbase_padding_in_ddr[%d] = 0x%x, but *(coinbase_padding + %d) = 0x%x",
               "dhash_send_job",(int)puVar9 - (int)puVar14,(uint)(byte)*puVar9,
               (int)puVar9 - (int)puVar14,(uint)*pbVar5);
      }
      puVar9 = puVar10;
    } while ((uint32_t *)((int)puVar14 + __nmemb) != puVar10);
  }
  if (job->merkles_num != 0) {
    uVar8 = 0;
    pbVar5 = (byte *)((int)puVar14 + __nmemb);
    do {
      puVar7 = job->merkle_bin + uVar8 * 0x20;
      uVar8 = uVar8 + 1;
      uVar13 = *(undefined4 *)(puVar7 + 4);
      uVar11 = *(undefined4 *)(puVar7 + 8);
      uVar1 = *(undefined4 *)(puVar7 + 0xc);
      *(undefined4 *)pbVar5 = *(undefined4 *)puVar7;
      *(undefined4 *)(pbVar5 + 4) = uVar13;
      *(undefined4 *)(pbVar5 + 8) = uVar11;
      *(undefined4 *)(pbVar5 + 0xc) = uVar1;
      uVar13 = *(undefined4 *)(puVar7 + 0x14);
      uVar11 = *(undefined4 *)(puVar7 + 0x18);
      uVar1 = *(undefined4 *)(puVar7 + 0x1c);
      *(undefined4 *)(pbVar5 + 0x10) = *(undefined4 *)(puVar7 + 0x10);
      *(undefined4 *)(pbVar5 + 0x14) = uVar13;
      *(undefined4 *)(pbVar5 + 0x18) = uVar11;
      *(undefined4 *)(pbVar5 + 0x1c) = uVar1;
      pbVar5 = pbVar5 + 0x20;
    } while (uVar8 < job->merkles_num);
  }
  stop_generate_work_for_job();
  if (job_start_address_1 == puVar14) {
    uVar4 = PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000;
  }
  else {
    uVar4 = PHY_MEM_NONCE2_JOBID_ADDRESS + 0x210000;
  }
  fpga_write(0x29,uVar4);
  fpga_read(0x29,&tmp);
  fpga_write(0x2c,job->job_id);
  fpga_read(0x2c,&tmp);
  if (job->mid_auto_gen == 0) {
    set_block_header_version(job->bbversion,job->mid_state_num,job->version_mask);
  }
  else {
    set_block_header_version(job->bbversion,1,job->version_mask);
  }
  puVar12 = &tmp;
  memset(buf2,0,0x20);
  pbVar2 = job->prev_hash;
  pbVar5 = pbVar2;
  do {
    pbVar6 = pbVar5 + 4;
    puVar12 = puVar12 + 1;
    *puVar12 = (uint)*pbVar5 | (uint)pbVar5[2] << 0x10 | (uint)pbVar5[3] << 0x18 |
               (uint)pbVar5[1] << 8;
    pbVar5 = pbVar6;
  } while (pbVar6 != pbVar2 + 0x20);
  set_pre_header_hash(buf2);
  fpga_write(0x2f,job->ntime);
  fpga_read(0x2f,&tmp);
  fpga_write(0x30,job->nbit);
  fpga_read(0x30,&tmp);
  fpga_write(0x24,(__nmemb << 0x12) >> 0x18 |
                  job->nonce2_offset << 0x10 | (uint)(byte)job->nonce2_bytes_num << 8);
  fpga_read(0x24,&tmp);
  buf2[0] = (uint32_t)job->nonce2_start_value;
  buf2[1] = *(uint32_t *)((int)&job->nonce2_start_value + 4);
  set_work_nonce2(buf2);
  set_merkle_bin_number(job->merkles_num);
  fpga_write(0x2a,__nmemb + job->merkles_num * 0x20 & 0xffff);
  fpga_read(0x2a,&tmp);
  usleep(1000);
  dhash_set_timeout(job->send_work_timeout);
  uVar4 = job->new_block;
  if (job->mid_state_num < 2 || job->mid_auto_gen != 0) {
    if (job->mid_auto_gen == 0) {
      uVar8 = 0;
    }
    else {
      uVar8 = 0x4000;
    }
    if (uVar4 == 0) {
      tmp = uVar4;
      fpga_read(0x23,&tmp);
      fpga_write(0x23,tmp & 0xffffe0bf | 0x8160 | uVar8);
      goto LAB_000c34a0;
    }
    uVar3 = 0x100;
LAB_000c34f4:
    uVar4 = 0x80;
    flush_nonce3_buffer();
  }
  else {
    uVar3 = (job->mid_state_num & 0x1f) << 8;
    uVar8 = uVar4;
    if (uVar4 != 0) {
      uVar8 = 0;
      goto LAB_000c34f4;
    }
  }
  tmp = 0;
  fpga_read(0x23,&tmp);
  fpga_write(0x23,tmp & 0xffffe0bf | 0x8060 | uVar4 | uVar3 | uVar8);
LAB_000c34a0:
  free(__dest);
  current_job_start_address = puVar14;
  return 0;
}

