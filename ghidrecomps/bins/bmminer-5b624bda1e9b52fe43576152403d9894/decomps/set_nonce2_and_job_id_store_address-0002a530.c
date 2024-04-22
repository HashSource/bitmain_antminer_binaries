
/* WARNING: Unknown calling convention */

void set_nonce2_and_job_id_store_address(uint value)

{
  char tmp42 [2048];
  
  snprintf(tmp42,0x800,"%s: set NONCE2_AND_JOBID_STORE_ADDRESS is 0x%x\n",DAT_0002a560,value);
  _applog(7,tmp42,false);
  return;
}

