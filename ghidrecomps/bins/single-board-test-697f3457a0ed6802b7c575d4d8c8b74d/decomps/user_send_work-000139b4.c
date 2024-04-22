
/* WARNING: Variable defined which should be unmapped: test_patten-local */
/* WARNING: Variable defined which should be unmapped: sno_valid-local */

void user_send_work(runtime_base_t *runtime,uint8_t *header,int sno_valid,int test_patten)

{
  int iVar1;
  int test_patten_local;
  int sno_valid_local;
  uint8_t *header_local;
  runtime_base_t *runtime_local;
  work_input work;
  int chainid;
  
  iVar1 = runtime->chain_id;
  memset(&work,0,0x92);
  work._2_1_ = work._2_1_ & 0xee | (byte)((sno_valid & 1U) << 4) | (byte)test_patten & 1;
  work.workid = runtime->total_work;
  runtime->total_work = work.workid + '\x01';
  memcpy(work.work,header,0x8c);
  work_list_insert(work.workid,work.work);
  (*runtime->send_work)(runtime->chain_status[iVar1].fd,&work.header_55);
  return;
}

