
int32_t sw_pt_send_work_super(uint32_t chain,void *args)

{
  bool bVar1;
  work *pwVar2;
  uchar uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  void *args_local;
  uint32_t chain_local;
  char tmp42 [256];
  work_cxt work_buf;
  work *work;
  work *works;
  uint32_t send_counter;
  uint32_t position;
  uint32_t count;
  uint32_t received_nonce_num;
  uint32_t *work_ptr;
  uint32_t pattern_num;
  uint32_t small_core_in_big_core;
  uint32_t big_core_num;
  uint32_t small_core_num;
  uint32_t asic_num;
  pattern_runtime_ctx *runtime;
  uint32_t send_nonce;
  uint32_t j;
  uint32_t i;
  uint32_t which_pattern;
  uint32_t which_core;
  uint32_t which_asic;
  
  iVar5 = *(int *)(*(int *)((int)args + 0x55708) + 0x18);
  uVar6 = *(uint *)(*(int *)((int)args + 0x55708) + 0x14);
  uVar7 = *(uint *)(*(int *)((int)args + 0x55708) + 0x1c);
  uVar8 = *(uint *)(*(int *)((int)args + 0x55708) + 0x20);
  send_nonce = 0;
  bVar1 = false;
  while (pwVar2 = pattern_info.works[0], !bVar1) {
    for (which_pattern = 0; which_pattern < uVar8; which_pattern = which_pattern + 1) {
      for (which_core = 0; which_core < uVar6; which_core = which_core + 1) {
        while (uVar3 = is_work_fifo_ready(**(uint32_t **)((int)args + 0x55708)), uVar3 == '\0') {
          usleep(100);
        }
        memset(&work_buf,0,0x214);
        work_buf.work_type = '\x01';
        work_buf.chain_id = (byte)**(undefined4 **)((int)args + 0x55708) | 0x80;
        work_buf.reserved1[0] = '\0';
        work_buf.reserved1[1] = '\0';
        uVar4 = which_pattern << 7;
        work_buf.work_count =
             uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | which_pattern << 0x1f
        ;
        for (i = 0; i < 0xc; i = i + 1) {
          work_buf.data[i] = pwVar2[which_core].pattern.data[i];
        }
        for (i = 0; i < uVar7; i = i + 1) {
          for (j = 0; j < 0x20; j = j + 1) {
            work_buf.midstate[i][j] = pwVar2[which_core].pattern.midstate[j];
          }
          send_nonce = send_nonce + 1;
        }
        for (i = 0; i < 0x85; i = i + 1) {
          *(uint *)(work_buf.reserved1 + i * 4 + -2) =
               *(int *)(work_buf.reserved1 + i * 4 + -2) << 0x18 |
               *(uint *)(work_buf.reserved1 + i * 4 + -2) >> 0x18 |
               (*(uint *)(work_buf.reserved1 + i * 4 + -2) & 0xff0000) >> 8 |
               (*(uint *)(work_buf.reserved1 + i * 4 + -2) & 0xff00) << 8;
        }
        set_TW_write_command((uint32_t *)&work_buf,0x214);
      }
    }
    bVar1 = true;
  }
  uVar6 = iVar5 * uVar8;
  if (uVar6 < send_nonce || uVar6 - send_nonce == 0) {
    snprintf(tmp42,0x100,"Send test %d pattern done",send_nonce);
    puts(tmp42);
  }
  else {
    snprintf(tmp42,0x100,"Send work num : %d, less than %d",send_nonce,iVar5 * uVar8);
    puts(tmp42);
  }
  usleep(10000000);
  return 0;
}

