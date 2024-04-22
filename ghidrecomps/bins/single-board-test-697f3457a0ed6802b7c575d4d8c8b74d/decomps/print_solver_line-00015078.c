
uint32_t print_solver_line(uint8_t *soln,uint8_t *header,int fixed_nonce_bytes,char *job_id)

{
  char *pcVar1;
  char *job_id_local;
  int fixed_nonce_bytes_local;
  uint8_t *header_local;
  uint8_t *soln_local;
  uint8_t buffer [1487];
  uint8_t *p;
  
  memcpy(buffer,header,0x8c);
  memcpy(buffer + 0x8c,&DAT_000346c4,3);
  memcpy(buffer + 0x8f,soln,0x540);
  printf("sol: %s ",job_id);
  printf("%02x%02x%02x%02x ",(uint)header[100],(uint)header[0x65],(uint)header[0x66],
         (uint)header[0x67]);
  pcVar1 = s_hexdump(header + fixed_nonce_bytes + 0x6c,0x20 - fixed_nonce_bytes);
  printf("%s ",pcVar1);
  pcVar1 = s_hexdump(buffer + 0x8f,0x540);
  printf("%s%s\n","fd4005",pcVar1);
  fflush(stdout);
  return 1;
}

