
int SCT_new_from_base64(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 in_stack_00000008;
  undefined4 in_stack_0000000c;
  void *local_20;
  void *local_1c;
  
  iVar1 = SCT_new();
  local_20 = (void *)0x0;
  local_1c = (void *)0x0;
  if (iVar1 == 0) {
    ERR_put_error(0x32,0x7f,0x41,"crypto/ct/ct_b64.c",0x4a);
    return 0;
  }
  iVar2 = SCT_set_version(iVar1,param_1);
  if (iVar2 == 0) {
    ERR_put_error(0x32,0x7f,0x73,"crypto/ct/ct_b64.c",0x53);
  }
  else {
    iVar2 = ct_base64_decode(param_2,&local_20);
    if (iVar2 < 0) {
      iVar2 = 0x59;
    }
    else {
      iVar2 = SCT_set0_log_id(iVar1,local_20);
      if (iVar2 == 0) goto LAB_0018f4ba;
      local_20 = (void *)0x0;
      iVar2 = ct_base64_decode(in_stack_00000008,&local_20);
      if (iVar2 < 0) {
        iVar2 = 0x62;
      }
      else {
        SCT_set0_extensions(iVar1,local_20);
        local_20 = (void *)0x0;
        iVar2 = ct_base64_decode(in_stack_0000000c,&local_20);
        if (-1 < iVar2) {
          local_1c = local_20;
          iVar2 = o2i_SCT_signature(iVar1,&local_1c);
          if (0 < iVar2) {
            CRYPTO_free(local_20);
            local_20 = (void *)0x0;
            SCT_set_timestamp(iVar1);
            iVar2 = SCT_set_log_entry_type(iVar1,param_3);
            if (iVar2 != 0) {
              return iVar1;
            }
          }
          goto LAB_0018f4ba;
        }
        iVar2 = 0x6a;
      }
    }
    ERR_put_error(0x32,0x7f,0x76,"crypto/ct/ct_b64.c",iVar2);
  }
LAB_0018f4ba:
  CRYPTO_free(local_20);
  SCT_free(iVar1);
  return 0;
}

