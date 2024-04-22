
void PostTestPattenTimeToServer(undefined4 param_1)

{
  char acStack_40c [1024];
  FILE *local_c;
  
  if (3 < log_level) {
    local_c = fopen(log_file,"a+");
    if (local_c != (FILE *)0x0) {
      fprintf(local_c,"%s:%d: test patten cost time: %d s\n","http.c",0x221,param_1);
    }
    fclose(local_c);
  }
  sprintf(acStack_40c,"posttesttime.do?minertype=S9-PLUS&minerID=%s&testtime=%d",FPGA_ID_str,param_1
         );
  PostMsgToTestPlatform(acStack_40c);
  return;
}

