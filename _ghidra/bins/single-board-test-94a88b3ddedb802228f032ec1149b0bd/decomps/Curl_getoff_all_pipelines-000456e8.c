
void Curl_getoff_all_pipelines(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)*(byte *)(param_2 + 0x254);
  if (uVar3 != 0) {
    uVar3 = Curl_recvpipe_head();
  }
  uVar2 = (uint)*(byte *)(param_2 + 0x255);
  if (uVar2 != 0) {
    uVar2 = Curl_sendpipe_head(param_1,param_2);
  }
  iVar1 = Curl_removeHandleFromPipeline(param_1,*(undefined4 *)(param_2 + 0x25c));
  if ((iVar1 != 0) && (uVar3 != 0)) {
    Curl_pipeline_leave_read(param_2);
  }
  iVar1 = Curl_removeHandleFromPipeline(param_1,*(undefined4 *)(param_2 + 600));
  if ((iVar1 != 0) && (uVar2 != 0)) {
    Curl_pipeline_leave_write(param_2);
    return;
  }
  return;
}

