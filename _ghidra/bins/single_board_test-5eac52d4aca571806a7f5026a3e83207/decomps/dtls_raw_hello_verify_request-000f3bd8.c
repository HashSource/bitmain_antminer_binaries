
int dtls_raw_hello_verify_request(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = WPACKET_put_bytes__(param_1,param_2,0xfeff,0,2);
  if ((iVar1 != 0) && (iVar1 = WPACKET_sub_memcpy__(param_1,param_2,param_3,1), iVar1 != 0)) {
    iVar1 = 1;
  }
  return iVar1;
}

