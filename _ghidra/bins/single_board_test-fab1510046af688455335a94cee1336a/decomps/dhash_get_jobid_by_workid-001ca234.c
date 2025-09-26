
/* WARNING: Unknown calling convention */

uint32_t dhash_get_jobid_by_workid(uint32_t work_id)

{
  return nonce2_jobid_address[work_id * 0x10];
}

