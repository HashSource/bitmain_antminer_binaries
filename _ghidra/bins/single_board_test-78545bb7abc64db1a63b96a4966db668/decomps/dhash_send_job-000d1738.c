
/* WARNING: Unknown calling convention */

int32_t dhash_send_job(dhash_job_info_t *job)

{
  byte *__s;
  undefined4 uVar1;
  char *value_00;
  uint uVar2;
  undefined4 *puVar3;
  uint32_t uVar4;
  byte *pbVar5;
  uint8_t *puVar7;
  size_t __size;
  uint32_t *puVar8;
  uint uVar9;
  size_t sVar10;
  byte *pbVar11;
  byte *pbVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint *puVar15;
  uint32_t value;
  uint32_t buf2 [8];
  byte *pbVar6;
  
  uVar9 = job->coinbase_len;
  buf2[0] = 0;
  buf2[1] = 0;
  buf2[2] = 0;
  buf2[3] = 0;
  buf2[4] = 0;
  buf2[5] = 0;
  buf2[6] = 0;
  buf2[7] = 0;
  puVar8 = job_start_address_1;
  if (current_job_start_address == job_start_address_1) {
    puVar8 = job_start_address_2;
  }
  if ((uVar9 & 0x3f) < 0x38) {
    __size = (uVar9 & 0xffffffc0) + 0x40;
  }
  else {
    __size = (uVar9 & 0xffffffc0) + 0x80;
  }
  __s = (byte *)malloc(__size);
  if (__s == (byte *)0x0) {
    return -4;
  }
  memset(__s,0,__size);
  pbVar11 = (byte *)((int)puVar8 + -1);
  memcpy(__s,job->coinbase,uVar9);
  uVar2 = uVar9 << 3;
  __s[uVar9] = 0x80;
  *(uint *)(__s + (__size - 4)) =
       uVar9 << 0x1b | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18;
  pbVar12 = __s + (__size - 8);
  pbVar12[0] = 0;
  pbVar12[1] = 0;
  pbVar12[2] = 0;
  pbVar12[3] = 0;
  pbVar12 = pbVar11;
  pbVar6 = __s;
  if (__size != 0) {
    do {
      pbVar5 = pbVar6 + 1;
      pbVar12 = pbVar12 + 1;
      *pbVar12 = *pbVar6;
      pbVar6 = pbVar5;
    } while (pbVar5 != __s + __size);
    pbVar12 = __s + -1;
    sVar10 = 0;
    do {
      pbVar11 = pbVar11 + 1;
      pbVar12 = pbVar12 + 1;
      if ((uint)*pbVar11 != (uint)*pbVar12) {
        printf("%s: coinbase_padding_in_ddr[%d] = 0x%x, but *(coinbase_padding + %d) = 0x%x",
               "dhash_send_job",sVar10,(uint)*pbVar11,sVar10,(uint)*pbVar12);
      }
      sVar10 = sVar10 + 1;
    } while (sVar10 != __size);
  }
  uVar9 = 0;
  puVar3 = (undefined4 *)((int)puVar8 + __size);
  if (job->merkles_num != 0) {
    do {
      puVar7 = job->merkle_bin + uVar9 * 0x20;
      uVar9 = uVar9 + 1;
      uVar13 = *(undefined4 *)(puVar7 + 4);
      uVar14 = *(undefined4 *)(puVar7 + 8);
      uVar1 = *(undefined4 *)(puVar7 + 0xc);
      *puVar3 = *(undefined4 *)puVar7;
      puVar3[1] = uVar13;
      puVar3[2] = uVar14;
      puVar3[3] = uVar1;
      uVar13 = *(undefined4 *)(puVar7 + 0x14);
      uVar14 = *(undefined4 *)(puVar7 + 0x18);
      uVar1 = *(undefined4 *)(puVar7 + 0x1c);
      puVar3[4] = *(undefined4 *)(puVar7 + 0x10);
      puVar3[5] = uVar13;
      puVar3[6] = uVar14;
      puVar3[7] = uVar1;
      puVar3 = puVar3 + 8;
    } while (uVar9 < job->merkles_num);
  }
  stop_generate_work_for_job();
  if (puVar8 == job_start_address_1) {
    value_00 = (char *)(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  }
  else {
    value_00 = "no_middlebox" + PHY_MEM_NONCE2_JOBID_ADDRESS + 0xc;
  }
  _set_job_start_address((uint32_t)value_00);
  _set_job_id(job->job_id);
  if (job->mid_auto_gen == 0) {
    set_block_header_version(job->bbversion,job->mid_state_num,job->version_mask);
  }
  else {
    set_block_header_version(job->bbversion,1,job->version_mask);
  }
  puVar7 = job->prev_hash;
  puVar15 = &value;
  buf2[0] = 0;
  buf2[1] = 0;
  buf2[2] = 0;
  buf2[3] = 0;
  buf2[4] = 0;
  buf2[5] = 0;
  buf2[6] = 0;
  buf2[7] = 0;
  pbVar12 = puVar7 + 3;
  do {
    pbVar11 = pbVar12 + 4;
    puVar15 = puVar15 + 1;
    *puVar15 = (uint)pbVar12[-1] << 0x10 | (uint)*pbVar12 << 0x18 | (uint)pbVar12[-3] |
               (uint)pbVar12[-2] << 8;
    pbVar12 = pbVar11;
  } while (pbVar11 != puVar7 + 0x23);
  set_pre_header_hash(buf2);
  _set_time_stamp(job->ntime);
  _set_target_bits(job->nbit);
  _set_coinbase_length_and_nonce2_length
            ((__size << 0x12) >> 0x18 |
             job->nonce2_offset << 0x10 | (uint)(byte)job->nonce2_bytes_num << 8);
  buf2[0] = (uint32_t)job->nonce2_start_value;
  buf2[1] = *(uint32_t *)((int)&job->nonce2_start_value + 4);
  set_work_nonce2(buf2);
  set_merkle_bin_number(job->merkles_num);
  _set_job_length(__size + job->merkles_num * 0x20 & 0xffe0);
  usleep(1000);
  uVar9 = 0x1ffff;
  if (job->send_work_timeout < 0x20000) {
    uVar9 = job->send_work_timeout;
  }
  _set_time_out_control(uVar9 | 0x80000000);
  uVar4 = job->new_block;
  if (job->mid_auto_gen == 0 && 1 < job->mid_state_num) {
    uVar2 = (job->mid_state_num & 0x1f) << 8;
    uVar9 = uVar4;
    if (uVar4 != 0) {
      uVar9 = 0;
      goto LAB_000d19e2;
    }
  }
  else {
    if (job->mid_auto_gen == 0) {
      uVar9 = 0;
    }
    else {
      uVar9 = 0x4000;
    }
    if (uVar4 == 0) {
      value = uVar4;
      fpga_read(0x23,&value);
      fpga_write(0x23,value & 0xffffe0bf | 0x8160 | uVar9);
      goto LAB_000d198e;
    }
    uVar2 = 0x100;
LAB_000d19e2:
    uVar4 = 0x80;
    flush_nonce3_buffer();
  }
  value = 0;
  fpga_read(0x23,&value);
  fpga_write(0x23,value & 0xffffe0bf | 0x8060 | uVar4 | uVar2 | uVar9);
LAB_000d198e:
  free(__s);
  current_job_start_address = puVar8;
  return 0;
}

